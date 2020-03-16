#include <iostream>
#include "Menu.h"
#include "Pokemon.h"
#include "Attack.h"
#include "Player.h"

Menu::Menu(){}

/* getters */
DBPokemon* Menu::getDBPokemon(int32_t index){
    return this->allPokemons[index];
}

Type* Menu::getType(int32_t index){
    return this->allTypes[index];
}

Attack* Menu::getAttack(int32_t index){
    return this->allAttacks[index];
}

Player* Menu::getPlayer(){
    return this->player;
}

DBPokemon* Menu::getRandomDBPokemon(){
    int32_t size = this->allPokemons.size();
    int32_t random = rand() % size -1;
    return getDBPokemon(random);
}

Type* Menu::getRandomType(){
    int32_t size = this->allTypes.size();
    int32_t random = rand() % size;

    return getType(random);
}

Attack* Menu::getRandomAttack(){
    int32_t size = this->allAttacks.size();
    int32_t random = rand() % size;

    return getAttack(random);
}

Attack* Menu::getRandomAttack(Type* type){
    int32_t size = this->allAttacks.size();
    int32_t random = rand() % size;
    Attack* myAttack;
    bool boolean = false;

    do {
        int32_t random = rand() % size;
        myAttack = getAttack(random);
        if(myAttack->getType()->getId() == type->getId() || myAttack->getType()->getId() == 8)
            boolean = true;
    } while(!(boolean));

    return myAttack;
}

Pokemon* Menu::getRandomPokemon(){
    DBPokemon* nationPokemon = getRandomDBPokemon();
    std::srand(69);
    int32_t pv = rand() % 100 + 100;
    int32_t atk = rand() % 100;
    int32_t atkSp = rand() % 100;
    int32_t def = rand() % 100;
    int32_t defSp = rand() % 100;
    int32_t speed = rand() % 100;

    std::vector<Attack*> listeAtk;

    for (int i = 0; i < 4; i++)
        listeAtk.push_back(this->getRandomAttack(nationPokemon->getType()));

    return new Pokemon(nationPokemon->getId(), nationPokemon->getNom(), pv, atk, atkSp, def, defSp, speed, listeAtk[0], listeAtk[1], listeAtk[2], listeAtk[3], nationPokemon->getType());
}

Pokemon* Menu::getRandomPokemon(DBPokemon* dbPokemon){
    std::srand(42);
    int32_t pv = rand() % 100 + 100;
    int32_t atk = rand() % 100 + 1;
    int32_t atkSp = rand() % 100 + 1;
    int32_t def = rand() % 100 + 1;
    int32_t defSp = rand() % 100 + 1;
    int32_t speed = rand() % 100 + 1;

    std::vector<Attack*> listeAtk;
    for (int i = 0; i < 4; i++)
        listeAtk.push_back(this->getRandomAttack(dbPokemon->getType()));

    return new Pokemon(dbPokemon->getId(), dbPokemon->getNom(), pv, atk, atkSp, def, defSp, speed, listeAtk[0], listeAtk[1], listeAtk[2], listeAtk[3], dbPokemon->getType());
}

bool Menu::getIntro(){

    std::string playername;
	std::vector<Pokemon*> allCaughtPokemons;
	std::vector<Pokemon*> teamPokemons;

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

	DBPokemon* selectedPkmn = this->getDBPokemon(choice - 1);
	std::string pkmnName = selectedPkmn->getNom();

    Pokemon* starter = this->getRandomPokemon(selectedPkmn);

    player->addPokemonTeam(starter);

    this->player = player;

	std::cout << "Oh, tu as donc choisi " << pkmnName << "." << std::endl;
	std::cout << "Bonne chance. Tu vas en avoir besoin." << std::endl;
	std::cout << "______________________________________________________________________" << std::endl;

    return 1;
}

bool Menu::Battle(){
    // oooh. Vous rencontrez un pokémon au hasard !
    int choice;
    int randAccuracy;
    int pkmnAccur;
    int caughtChances = 30;
    int randCaught;
    bool forceEnd = false;

    Pokemon* battlePokemon = getRandomPokemon();
    
    Pokemon* yourPokemon = this->player->getPokemonTeam(0);
    
    battlePokemon->toString();

    std::cout << "Un " << battlePokemon->getNom() << " sauvage apparait !" << std::endl;
    std::cout << "Ton pokemon : " << yourPokemon->getNom() << "." << std::endl;

    do{
        std::cout << "PV de " << battlePokemon->getNom() << " : " << battlePokemon->getPv() << std::endl;
        std::cout << "PV de " << yourPokemon->getNom() << " : " << yourPokemon->getPv() << std::endl;

        if(battlePokemon->getPv() < 75){
            caughtChances = 45;
        }
        else if(battlePokemon->getPv() < 50){
            caughtChances = 75;
        }
        else if(battlePokemon->getPv() < 25){
            caughtChances = 90;
        }

        std::cout << "[1] Attaque" << std::endl;
        std::cout << "[2] Capture" << std::endl;
        std::cout << "[3] Changer de pokemon" << std::endl;
        std::cout << "[4] Fuite" << std::endl;

        std::cin >> choice;

        switch(choice){
            case 1:
                std::cout << "[1] " << yourPokemon->getAtk1()->getNom() << std::endl;
                std::cout << "[2] " << yourPokemon->getAtk2()->getNom() << std::endl;
                std::cout << "[3] " << yourPokemon->getAtk3()->getNom() << std::endl;
                std::cout << "[4] " << yourPokemon->getAtk4()->getNom() << std::endl;

                std::cin >> choice;

                switch(choice){
                    case 1:
                        randAccuracy = rand() % 100;
                        pkmnAccur = yourPokemon->getAtk1()->getAccuracy();

                        if(pkmnAccur > randAccuracy){
                            float damage = battlePokemon->setDamage(yourPokemon, yourPokemon->getAtk1());
                            // int damage = battlePokemon->getPv() - (yourPokemon->getAtk1()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50);
                            // battlePokemon->setPv(battlePokemon->getPv() - (yourPokemon->getAtk1()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50));

                            std::cout << yourPokemon->getAtk1()->getNom() << " inflige " << damage <<std::endl;
                        }
                        else{
                            std::cout << "Attaque ratee !" << std::endl;
                        }

                        break;
                    case 2:
                        randAccuracy = rand() % 100;
                        pkmnAccur = yourPokemon->getAtk2()->getAccuracy();

                        if(pkmnAccur > randAccuracy){
                            float damage = battlePokemon->setDamage(yourPokemon, yourPokemon->getAtk2());
                            // int damage = battlePokemon->getPv() - (yourPokemon->getAtk2()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50);
                            // battlePokemon->setPv(battlePokemon->getPv() - (yourPokemon->getAtk2()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50));

                            std::cout << yourPokemon->getAtk2()->getNom() << " inflige " << damage << std::endl;
                        }
                        else{
                            std::cout << "Attaque ratee !" << std::endl;
                        }
                        break;
                    case 3:
                        randAccuracy = rand() % 100;
                        pkmnAccur = yourPokemon->getAtk3()->getAccuracy();

                        if(pkmnAccur > randAccuracy){
                            float damage = battlePokemon->setDamage(yourPokemon, yourPokemon->getAtk3());
                            // int damage = battlePokemon->getPv() - (yourPokemon->getAtk3()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50);
                            // battlePokemon->setPv(battlePokemon->getPv() - (yourPokemon->getAtk3()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50));

                            std::cout << yourPokemon->getAtk3()->getNom() << " inflige " << damage << std::endl;
                        }
                        else{
                            std::cout << "Attaque ratee !" << std::endl;
                        }                    
                        break;
                    case 4:
                        randAccuracy = rand() % 100;
                        pkmnAccur = yourPokemon->getAtk4()->getAccuracy();

                        if(pkmnAccur > randAccuracy){
                            float damage = battlePokemon->setDamage(yourPokemon, yourPokemon->getAtk4());
                            // int damage = battlePokemon->getPv() - (yourPokemon->getAtk4()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50);
                            // battlePokemon->setPv(battlePokemon->getPv() - (yourPokemon->getAtk4()->getPower() * yourPokemon->getAtk()) / (battlePokemon->getDef() * 50));

                            std::cout << yourPokemon->getAtk4()->getNom() << " inflige " << damage << std::endl;
                        }
                        else{
                            std::cout << "Attaque ratee !" << std::endl;
                        }
                        break;
                }
                break;
            case 2:
                std::cout << player->getNom() << " lance une Pokeball !";
                randCaught = rand() % 100;

                if(caughtChances > randCaught){
                    std::cout << "Bravo ! Vous avez capturé un " << battlePokemon->getNom() << std::endl;
                    if(player->getPokemonTeam().size() >= 6){
                        player->addPokemonAll(battlePokemon);
                        std::cout << battlePokemon->getNom() << " a été envoyé dans le PC" << std::endl;
                    }
                    else{
                        player->addPokemonTeam(battlePokemon);
                        std::cout << battlePokemon->getNom() << " rejoint votre équipe !" << std::endl;
                    }
                    forceEnd = true;
                }
                else{
                    std::cout << "Ah, mince ! Presque !" << std::endl;
                }

                break;
            case 3:
                break;
            case 4:
                std::cout << "Vous fuyez le combat." << std::endl;
                forceEnd = true;
                break;
            default:
                std::cout << "Commande incorrecte" << std::endl;
                break;
        }
        battlePokemon->toString();
    } while(battlePokemon->getPv() > 0 && forceEnd != true);

    battlePokemon->toString();

    return 1;
}

bool Menu::MyTeam(){
    int idisplay;
    std::string choice;
    for(int i = 0 ; i<this->getPlayer()->getPokemonTeam().size() ; i++){
        idisplay = i + 1;
        Pokemon* actualPokemon = this->getPlayer()->getPokemonTeam(i);
        std::cout << "(" << idisplay << ")" << " " << actualPokemon->toString() << std::endl;
    }

    std::cout << "Voulez vous echanger un pokemon de votre jardin a votre equipe actuelle ? (y/n)" << std::endl;
    std::cin >> choice;

    if(choice == "y"){
        int switchNumber, chooseNumer;
        std::cout << "Veuillez choisir le numero de votre pokemon a echanger." << std::endl;
        std::cin >> switchNumber;
        
        std::cout << "Par lequel souhaitez-vous le remplacer ?." << std::endl;
        for(int i = 0 ; i<this->getPlayer()->getPokemonAll().size() ; i++){
            idisplay = i + 1;
            Pokemon* actualPokemon = this->getPlayer()->getPokemonAll(i);
            std::cout << "(" << idisplay << ")" << " " << actualPokemon->toString() << std::endl;
        }
        std::cout << "Veuillez choisir le numero de votre pokemon a echanger." << std::endl;
        std::cin >> chooseNumer;

        Pokemon* switchPokemon = this->getPlayer()->getPokemonTeam(switchNumber-1);
        Pokemon* choosePokemon = this->getPlayer()->getPokemonAll(chooseNumer-1);

        if(switchPokemon && choosePokemon){
            this->getPlayer()->setPokemonTeam(switchNumber-1, choosePokemon);
            this->getPlayer()->setPokemonAll(chooseNumer-1, switchPokemon);

            return 1;
        }

    } else {
        std::cout << "Annulation..." << std::endl;
        return 0;
    }

    return 1;
}

/* setters */
#ifndef FORWARD_DECLARATION
void Menu::addPokemon(void* pokemon)
{
    this->allPokemons.push_back(reinterpret_cast<DBPokemon*>(pokemon));
}
#else
void Menu::addPokemon(DBPokemon* pokemon)
{
    this->allPokemons.push_back(pokemon);
}
#endif /* FORWARD_DECLARATION */

#ifndef FORWARD_DECLARATION
void Menu::addType(void* type)
{
    this->allTypes.push_back(reinterpret_cast<Type*>(type));
}
#else
void Menu::addType(Type* type)
{
    this->allTypes.push_back(type);
}
#endif /* FORWARD_DECLARATION */

#ifndef FORWARD_DECLARATION
void Menu::addAttack(void* attack)
{
    this->allAttacks.push_back(reinterpret_cast<Attack*>(attack));
}
#else
void Menu::addAttack(Attack* attack)
{
    this->allAttacks.push_back(attack);
}
#endif /* FORWARD_DECLARATION */

void Menu::setPlayer(Player* player)
{
    this->player = player;
}