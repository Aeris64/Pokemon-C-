#include "Player.h"

Player::Player()
{
    this->id = 0;
    this->nom = "";
}

Player::Player(int32_t id, std::string nom, std::vector<Pokemon*> teamPokemon, std::vector<Pokemon*> myPokemon)
{
    this->id = id;
    this->nom = nom;

    int32_t size = teamPokemon.size();

    for (int i = 0; i < size; i++)
        this->teamPokemon.push_back(teamPokemon[i]);

    size = myPokemon.size();

    for (int i = 0; i < size; i++)
        this->myPokemon.push_back(myPokemon[i]);
}

Player::Player(Player const& player)
{
    this->nom = player.nom;
}

/* getters */
int32_t Player::getId()
{
    return this->id;
}

std::string Player::getNom()
{
    return this->nom;
}

/* setters */
void Player::setId(int32_t id)
{
    this->id = id;
}

void Player::setNom(std::string nom)
{
    this->nom = nom;
}

std::string Player::toString()
{
    return "Player :\nnom: " + this->nom;
}

Player::~Player(){}