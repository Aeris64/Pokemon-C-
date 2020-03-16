#include "Type.h"


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
int32_t Type::getId()
{
    return this->id;
}

std::string Type::getNom()
{
    return this->nom;
}

/* setters */
void Type::setId(int32_t id)
{
    this->id = id;
}

void Type::setNom(std::string nom)
{
    this->nom = nom;
}

std::string Type::toString()
{
    return "Type :\nnom: " + this->nom;
}

Type::~Type(){}