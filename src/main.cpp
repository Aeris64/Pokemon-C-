#include <iostream>
#include "Player.h"
#include "Attack.h"
#include "DBPokemon.h"
#include "Pokemon.h"
#include "Type.h"
#include "Menu.h"
#include "Pokedex.h"

int main(int argc, char *argv[]) {
	int createdIndex = 1;
	std::string playername;
	std::vector<Pokemon*> allCaughtPokemons;
	std::vector<Pokemon*> teamPokemons;
	Menu* play = initPokedex();

	std::cout << "Bienvenue sur PokeC++ !" << std::endl;
	std::cout << "Oh, on ne s'est jamais vu non ? ... Comment tu t'appelles ?" << std::endl;

	std::cin >> playername;

	Player* player = new Player(1, playername, allCaughtPokemons, teamPokemons);

	std::cout << "Bonjour, " << player->getNom() << std::endl;
	std::cout << "Votre aventure commence ici dans la region d'Ynov, cependant, l'aventure va etre rude, et vous allez affronter de serieux problemes administratifs ..." << std::endl;
	std::cout << "Avant de partir, tu devras faire face a de nombreux adversaires, et aux delais d'attentes de l'administration."<< std::endl;
	std::cout << "Choisi l'un de ces trois pokemons pour t'accompagner." << std::endl;
	std::cout << "[1] Salameche." << std::endl;
	std::cout << "[2] Carapuce." << std::endl;
	std::cout << "[3] Bulbizarre." << std::endl;


	int choice;


	do{
		std::cin >> choice;

		if(choice != 1 && choice !=2 && choice != 3)
		{
			std::cout << "Choix invalide" << std::endl;
		}

	}while(choice != 1 && choice != 2 && choice != 3);

	DBPokemon* selectedPkmn = play->getDBPokemon(choice - 1);
	std::string pkmnName = selectedPkmn->getNom();

	Pokemon* createdPkmn = new Pokemon();

	createdIndex++;

	std::cout << "Oh, tu as donc choisi " << pkmnName << "." << std::endl;
	std::cout << "Bonne chance. Tu vas en avoir besoin." << std::endl;
	std::cout << "___________________________________" << std::endl;

	std::cout << "Bonjour, "<< player->getNom() <<" Choisissez un mode de jeu. (Entrez le chiffre associe)" << std::endl;

	std::cout << "[1] Liste des pokemons captures." << std::endl;
	std::cout << "[2] Equipe actuelle." << std::endl;
	std::cout << "[3] Partir dans les hautes herbes." << std::endl;
	std::cout << "[4] Soigner les Pokemons." << std::endl;

	do{
		std::cin >> choice;

		if(choice != 1 && choice !=2 && choice != 3 && choice != 4)
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