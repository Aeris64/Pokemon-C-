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
	int idisplay;

	play->getIntro();

	for(int j = 0 ; j < 3 ; j++){
		Pokemon* randomBeginsPokemon = play->getRandomPokemon();
		play->getPlayer()->addPokemonAll(randomBeginsPokemon);
	}

	do{

		std::cout << "Bonjour, "<< play->getPlayer()->getNom() <<" Choisissez un mode de jeu. (Entrez le chiffre associe)" << std::endl;

		std::cout << "[1] Liste des pokemons captures." << std::endl;
		std::cout << "[2] Equipe actuelle." << std::endl;
		std::cout << "[3] Partir dans les hautes herbes." << std::endl;
		std::cout << "[4] Soigner les Pokemons." << std::endl;
		std::cout << "[9] Exit" << std::endl;
		std::cout << "______________________________________________________________________" << std::endl;

		std::cin >> choice;

		switch(choice){
			case 1:
				for(int i = 0 ; i<play->getPlayer()->getPokemonAll().size() ; i++){
					idisplay = i + 1;
					Pokemon* actualPokemon = play->getPlayer()->getPokemonAll(i);
					std::cout << "(" << idisplay << ")" << " " << actualPokemon->toString() << std::endl;
				}
				break;
			case 2:
				play->MyTeam();
				// for(int i = 0 ; i<play->getPlayer()->getPokemonTeam().size() ; i++){
				// 	idisplay = i + 1;
				// 	Pokemon* actualPokemon = play->getPlayer()->getPokemonTeam(i);
				// 	std::cout << "(" << idisplay << ")" << " " << actualPokemon->toString() << std::endl;
				// }
				break;
			case 3:
				play->Battle();
				break;
			case 4:
				for(int i = 0 ; i<play->getPlayer()->getPokemonTeam().size() ; i++){
					play->getPlayer()->getPokemonTeam(i)->setPv(play->getPlayer()->getPokemonTeam(i)->getPvMax());
				}
				std::cout << "Tout les pokemons de l'equipe ont ete soignes." << std::endl;
				for(int i = 0 ; i<play->getPlayer()->getPokemonAll().size() ; i++){
					play->getPlayer()->getPokemonAll(i)->setPv(play->getPlayer()->getPokemonAll(i)->getPvMax());
				}			
				std::cout << "Tout les pokemons du PC ont ete soignes." << std::endl;					
				break;
			case 9:
				break;
			default:
				std::cout << "Choix invalide" << std::endl;
				break;
		}

		std::cout << "______________________________________________________________________" << std::endl;

	} while(choice != 9);

	std::cout << "end" << std::endl;
	// Player* a = new Player(1, "Mura");
	// std::cout << a->toString() << std::endl;
	// int32_t myId = a->getId();
	// std::cout << myId;
	// delete a;
	
}