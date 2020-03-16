#include "Player.h"


Player::Player()
{
    this->nom = "";
}

Player::Player(int32_t id, std::string nom)
{
    this->nom = nom;
}

Player::Player(Player const& player)
{
    this->nom = player.nom;
}

/* getters */
std::string Player::getNom()
{
    return this->nom;
}

int32_t Player::getId()
{
    return this->id;
}

/* setters */
void Player::setNom(std::string nom)
{
    this->nom = nom;
}

void Player::setId(int32_t id)
{
    this->id = id;
}

std::string Player::toString()
{
    return "Player :\nnom: " + this->nom;
}

Player::~Player(){}