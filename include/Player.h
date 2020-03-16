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
    Pokemon* getPokemonTeam(int32_t index);
    Pokemon* getPokemonAll(int32_t index);

    std::vector<Pokemon*> getPokemonTeam();
    std::vector<Pokemon*> getPokemonAll();
    
    /* setters */
    void setId(int32_t id);
    void setNom(std::string nom);
    void setPokemonTeam(int32_t index, Pokemon* pokemon);
    void setPokemonAll(int32_t index, Pokemon* pokemon);

    void addPokemonTeam(void* pokemon);
    void addPokemonAll(void* pokemon);

    std::string toString();
};
#endif