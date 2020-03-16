#include "Player.h"


Player::Player()
{
    this->nom = "";
}

Player::Player(std::string nom)
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

/* setters */
void Player::setNom(std::string nom)
{
    this->nom = nom;
}

std::string Player::toString()
{
    return "Auteur :\nnom: " + this->nom;
}

Player::~Player(){}