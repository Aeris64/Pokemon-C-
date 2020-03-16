#include "Menu.h"
#include "Pokemon.h"
#include "Attack.h"

Type::Type()
{
    this->id = 0;
    this->nom = "";
}

Type::Type(int32_t id, std::string nom)
{
    this->id = id;
    this->nom = nom;
}

Type::Type(Type const& type)
{
    this->id = type.id;
    this->nom = type.nom;
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