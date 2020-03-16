#include "Pokemon.h"
#include "DBPokemon.h"

Pokemon::Pokemon()
{
    this->atk = 0;
    this->atkSp = 0;
    this->def = 0;
    this->defSp = 0;
    this->speed = 0;
    this->atk1 = new Attack();
    this->atk2 = new Attack();
    this->atk3 = new Attack();
    this->atk4 = new Attack();
    this->selfCreatedAttack1 = 1;
    this->selfCreatedAttack2 = 1;
    this->selfCreatedAttack3 = 1;
    this->selfCreatedAttack4 = 1;
}

Pokemon::Pokemon(int32_t atk, int32_t atkSp, int32_t def, int32_t defSp, int32_t speed, Attack* atk1, Attack* atk2, Attack* atk3, Attack* atk4) : DBPokemon
{
    this->id = id;
    this->atk = atk;
    this->atkSp = atkSp;
    this->def = def;
    this->defSp = defSp;
    this->speed = speed;
    this->atk1 = atk1;
    this->atk2 = atk2;
    this->atk3 = atk3;
    this->atk4 = atk4;
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