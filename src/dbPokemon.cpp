#include "DBPokemon.h"


DBPokemon::DBPokemon()
{
    this->id = 0;
    this->nom = "";
    this->type = new Type();
    this->selfCreatedType = 1;
}

DBPokemon::DBPokemon(int32_t id, std::string nom, Type* type)
{
    this->id = id;
    this->nom = nom;
    this->type = type;
}

DBPokemon::DBPokemon(DBPokemon const& dbPokemon)
{
    this->id = dbPokemon.id;
    this->nom = dbPokemon.nom;
    this->type = dbPokemon.type;
}

/* getters */
int32_t DBPokemon::getId()
{
    return this->id;
}

std::string DBPokemon::getNom()
{
    return this->nom;
}

Type* DBPokemon::getType()
{
    return this->type;
}

/* setters */
void DBPokemon::setId(int32_t id)
{
    this->id = id;
}

void DBPokemon::setNom(std::string nom)
{
    this->nom = nom;
}

void DBPokemon::setType(Type* type)
{
    if (this->selfCreatedType)
        delete this->type;
        
    this->selfCreatedType = 0;
    this->type = type;
}

std::string DBPokemon::toString()
{
    return "DBPokemon :\nnom: " + this->nom;
}

DBPokemon::~DBPokemon()
{
    if (this->selfCreatedType)
        delete this->type;
}