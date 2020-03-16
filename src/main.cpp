#include <iostream>
#include "Player.h"
#include "Attack.h"
#include "DBPokemon.h"
#include "Pokemon.h"
#include "Type.h"
#include "Menu.h"
#include "Pokedex.h"

int main(int argc, char *argv[]) {

	Menu* play = initPokedex();
	int choice;

	play->getIntro();

	do{

		std::cout << "Bonjour, "<< play->getPlayer()->getNom() <<" Choisissez un mode de jeu. (Entrez le chiffre associe)" << std::endl;

		std::cout << "[1] Liste des pokemons captures." << std::endl;
		std::cout << "[2] Equipe actuelle." << std::endl;
		std::cout << "[3] Partir dans les hautes herbes." << std::endl;
		std::cout << "[4] Soigner les Pokemons." << std::endl;
		std::cout << "[9] Exit" << std::endl;

		std::cin >> choice;

		switch(choice){
			case 1:
				for(int i = 0 ; i<play->getPlayer()->getPokemonAll().size() ; i++){
					Pokemon* actualPokemon = play->getPlayer()->getPokemonAll(i);
					std::cout << i << " " << actualPokemon->toString() << std::endl;
				}
				break;
			case 2:
				for(int i = 0 ; i<play->getPlayer()->getPokemonTeam().size() ; i++){
					Pokemon* actualPokemon = play->getPlayer()->getPokemonTeam(i);
					std::cout << i << " " << actualPokemon->toString() << std::endl;
				}
				break;
			case 3:
				play->Battle();
				break;
			case 4:
				break;
			case 9:
				break;
			default:
				std::cout << "Choix invalide" << std::endl;
				break;

		}

	} while(choice != 9);

	std::cout << "end" << std::endl;
	// Player* a = new Player(1, "Mura");
	// std::cout << a->toString() << std::endl;
	// int32_t myId = a->getId();
	// std::cout << myId;
	// delete a;
	
}