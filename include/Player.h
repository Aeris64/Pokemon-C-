#ifndef PLAYER_INCLUDED_H
#define PLAYER_INCLUDED_H

#include <string>

class Player {
private:
    int id;
    std::string nom;
    // Liste pokémon capturé
    // Liste pokémon team

public:
    Player();
    Player(int id, std::string nom);
    Player(Player const& player);
    ~Player();

    /* getters */
    int getId();
    std::string getNom();
    
    /* setters */
    void setId(int id);
    void setNom(std::string nom);

    std::string toString();
};
#endif