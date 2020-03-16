#ifndef PLAYER_INCLUDED_H
#define PLAYER_INCLUDED_H

#include <string>
#include <vector>

#include "Pokemon.h"

class Player {
private:
    int32_t id;
    std::string nom;
    std::vector<Pokemon*> teamPokemon;
    std::vector<Pokemon*> myPokemon;

public:
    Player();
    Player(int32_t id, std::string nom, std::vector<Pokemon*> teamPokemon, std::vector<Pokemon*> myPokemon);
    Player(Player const& player);
    ~Player();

    /* getters */
    int32_t getId();
    std::string getNom();
    
    /* setters */
    void setId(int32_t id);
    void setNom(std::string nom);

    std::string toString();
};
#endif