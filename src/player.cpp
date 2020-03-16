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

Pokemon* Player::getPokemonTeam(int32_t index)
{
    return this->teamPokemon[index];
}

Pokemon* Player::getPokemonAll(int32_t index)
{
    return this->myPokemon[index];
}

std::vector<Pokemon*> Player::getPokemonTeam()
{
    return this->teamPokemon;
}

std::vector<Pokemon*> Player::getPokemonAll()
{
    return this->myPokemon;
}

#ifndef FORWARD_DECLARATION
void Player::addPokemonTeam(void* pokemon)
{
    this->teamPokemon.push_back(reinterpret_cast<Pokemon*>(pokemon));
}
#else
void Player::addPokemonTeam(Pokemon* pokemon)
{
    this->teamPokemon.push_back(pokemon);
}
#endif /* FORWARD_DECLARATION */

#ifndef FORWARD_DECLARATION
void Player::addPokemonAll(void* pokemon)
{
    this->myPokemon.push_back(reinterpret_cast<Pokemon*>(pokemon));
}
#else
void Player::addPokemonAll(Pokemon* pokemon)
{
    this->myPokemon.push_back(pokemon);
}
#endif /* FORWARD_DECLARATION */

/* setters */
void Player::setId(int32_t id)
{
    this->id = id;
}

void Player::setNom(std::string nom)
{
    this->nom = nom;
}

void Player::setPokemonTeam(int32_t index, Pokemon* pokemon){
    this->teamPokemon[index] = pokemon;
}

void Player::setPokemonAll(int32_t index, Pokemon* pokemon){
    this->myPokemon[index] = pokemon;
}

std::string Player::toString()
{
    return "Player :\nnom: " + this->nom;
}

Player::~Player(){}