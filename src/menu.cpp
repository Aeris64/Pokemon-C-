#include "Menu.h"
#include "Pokemon.h"
#include "Attack.h"

Menu::Menu(){}

bool Menu::Battle(){
    // oooh. Vous rencontrez un pokémon au hasard !
    Pokemon* battlePokemon = getRandomPokemon();

    battlePokemon->toString();

    do{
        battlePokemon->setPv(battlePokemon->getPv()-10);
        battlePokemon->toString();
    } while(battlePokemon->getPv() > 0);

    battlePokemon->toString();

    return 1;
}

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

Attack* Menu::getRandomAttack(Type type){
    int32_t size = this->allAttacks.size();
    int32_t random = rand() % size;

    return getAttack(random);
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
        listeAtk.push_back(this->getRandomAttack());

    return new Pokemon(nationPokemon->getId(), nationPokemon->getNom(), pv, atk, atkSp, def, defSp, speed, listeAtk[0], listeAtk[1], listeAtk[2], listeAtk[3], nationPokemon->getType());
}

Pokemon* Menu::getRandomPokemon(DBPokemon dbPokemon){
    int32_t pv = rand() % 100 + 100;
    int32_t atk = rand() % 100;
    int32_t atkSp = rand() % 100;
    int32_t def = rand() % 100;
    int32_t defSp = rand() % 100;
    int32_t speed = rand() % 100;

    std::vector<Attack*> listeAtk;

    for (int i = 0; i < 4; i++)
        listeAtk.push_back(this->getRandomAttack());

    return new Pokemon(dbPokemon.getId(), dbPokemon.getNom(), pv, atk, atkSp, def, defSp, speed, listeAtk[0], listeAtk[1], listeAtk[2], listeAtk[3], dbPokemon.getType());
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