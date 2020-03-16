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
    int32_t random = rand() % size;

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
        delete myAttack;
        int32_t random = rand() % size;
        Attack* myAttack = getAttack(random);
        if(myAttack->getType()->getId() == type->getId() || myAttack->getType()->getId() == 8)
            boolean = true;
    } while(!(boolean));
    return myAttack;
}

Pokemon* Menu::getRandomPokemon(){
    DBPokemon* nationPokemon = getRandomDBPokemon();
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
    int32_t pv = rand() % 100 + 100;
    int32_t atk = rand() % 100;
    int32_t atkSp = rand() % 100;
    int32_t def = rand() % 100;
    int32_t defSp = rand() % 100;
    int32_t speed = rand() % 100;

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
	std::cout << "___________________________________" << std::endl;

    return 1;
}

bool Menu::Battle(){
    // oooh. Vous rencontrez un pokémon au hasard !
    Pokemon* battlePokemon = getRandomPokemon();
    
    Pokemon* yourPokemon = this->player->getPokemonTeam(1);
    
    battlePokemon->toString();

    std::cout << "Un " << battlePokemon->getNom() << " sauvage apparait !";
    std::cout << "Ton pokémon : " << yourPokemon->getNom() << ".";

    do{
        battlePokemon->setPv(battlePokemon->getPv()-10);
        battlePokemon->toString();
    } while(battlePokemon->getPv() > 0);

    battlePokemon->toString();

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
