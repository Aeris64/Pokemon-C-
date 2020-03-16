#include "Menu.h"
#include "Pokemon.h"
#include "Attack.h"

Menu::Menu()
{

}

/* getters */

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