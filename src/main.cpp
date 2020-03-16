#include <iostream>
#include "Player.h"
#include "Attack.h"
#include "DBPokemon.h"
#include "Pokemon.h"
#include "Type.h"

int main(int argc, char *argv[]) {
	std::cout << "Bienvenue sur PokeC++ !" << std::endl;
	std::cout << "Choisissez un mode de jeu. (Entrez le chiffre associe)" << std::endl;

	std::cout << "[1] Liste des pokémons captures." << std::endl;
	std::cout << "[2] Equipe actuelle." << std::endl;
	std::cout << "[3] Partir dans les hautes herbes." << std::endl;
	std::cout << "[4] Soigner les Pokemons." << std::endl;

	int choice;

	do{
		std::cin >> choice;

		if(choice != 1 && choice !=2 && choice != 3 && choice != 4 || std::isnan(choice))
		{
			std::cout << "Choix invalide" << std::endl;
		}

	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

	std::cout << "end" << std::endl;
	// Player* a = new Player(1, "Mura");
	// std::cout << a->toString() << std::endl;
	// int32_t myId = a->getId();
	// std::cout << myId;
	// delete a;
	
}