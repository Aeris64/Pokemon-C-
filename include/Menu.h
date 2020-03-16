#ifndef MENU_INCLUDED_H
#define MENU_INCLUDED_H

#include <string>
#include <vector>

#include "DBPokemon.h"
#include "Type.h"
#include "Attack.h"

class Menu {
private:
    std::vector<DBPokemon*> allPokemons;
    std::vector<Type*> allTypes;
    std::vector<Attack*> allAttacks;

public:
    Menu();

    bool Battle();

    /* getters */
    
    /* setters */
    void addPokemon(void* dbPokemon);
    void addType(void* type);
    void addAttack(void* attack);
};
#endif