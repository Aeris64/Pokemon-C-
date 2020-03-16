#include "Attack.h"


Attack::Attack()
{
    this->nom = "";
    this->power = 0;
    this->pp = 0;
    this->accuracy = 0;
    this->type = new Type();
    this->selfCreatedType = 1;
}

Attack::Attack(int32_t id, std::string nom, int32_t power, int32_t pp, int32_t accuracy, Type* type)
{
    this->nom = nom;
    this->power = power;
    this->pp = pp;
    this->accuracy = accuracy;
    this->type = type;
}

Attack::Attack(Attack const& attack)
{
    this->nom = attack.nom;
    this->power = attack.power;
    this->pp = attack.pp;
    this->accuracy = attack.accuracy;
    this->type = attack.type;
}

/* getters */
std::string Attack::getNom()
{
    return this->nom;
}

int32_t Attack::getId()
{
    return this->id;
}

int32_t Attack::getPower()
{
    return this->power;
}

int32_t Attack::getPp()
{
    return this->pp;
}

int32_t Attack::getAccuracy()
{
    return this->accuracy;
}

Type* Attack::getType()
{
    return this->type;
}

/* setters */
void Attack::setNom(std::string nom)
{
    this->nom = nom;
}

void Attack::setId(int32_t id)
{
    this->id = id;
}

void Attack::setPower(int32_t power)
{
    this->power = power;
}

void Attack::setPp(int32_t pp)
{
    this->pp = pp;
}

void Attack::setAccuracy(int32_t accuracy)
{
    this->accuracy = accuracy;
}

void Attack::setType(Type* type)
{
    this->type = type;
}

std::string Attack::toString()
{
    return "Attaque :\n " + this->nom;
}

Attack::~Attack()
{
    if (this->selfCreatedType)
        delete this->type;
}