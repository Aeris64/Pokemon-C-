#ifndef MENU_INCLUDED_H
#define MENU_INCLUDED_H

#include <string>
#include <vector>

#include "DBPokemon.h"
#include "Type.h"
#include "Attack.h"
#include "Player.h"

class Menu {
private:
    std::vector<DBPokemon*> allPokemons;
    std::vector<Type*> allTypes;
    std::vector<Attack*> allAttacks;
    Player* player;

public:
    Menu();

    bool Battle();

    /* getters */
    std::vector<DBPokemon*> getAllPokemons();
    std::vector<Type*> getAllTypes();
    std::vector<Attack*> getAllAttacks();
    Player* getPlayer();

    DBPokemon* getDBPokemon(int32_t index);
    Type* getType(int32_t index);
    Attack* getAttack(int32_t index);

    DBPokemon* getRandomDBPokemon();
    Type* getRandomType();
    Attack* getRandomAttack();
    Attack* getRandomAttack(Type* type);

    Pokemon* getRandomPokemon();
    Pokemon* getRandomPokemon(DBPokemon* dbPokemon);

    bool getIntro();

    /* setters */
    void addPokemon(void* dbPokemon);
    void addType(void* type);
    void addAttack(void* attack);
    void setPlayer(Player* player);
};
#endif