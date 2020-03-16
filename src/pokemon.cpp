#include "Pokemon.h"
#include "DBPokemon.h"

Pokemon::Pokemon()
{
    this->setId(0);
    this->setNom("");
    this->pv = 0;
    this->atk = 0;
    this->atkSp = 0;
    this->def = 0;
    this->defSp = 0;
    this->speed = 0;
    this->atk1 = new Attack();
    this->atk2 = new Attack();
    this->atk3 = new Attack();
    this->atk4 = new Attack();
    this->setType(new Type());
    this->selfCreatedAttack1 = 1;
    this->selfCreatedAttack2 = 1;
    this->selfCreatedAttack3 = 1;
    this->selfCreatedAttack4 = 1;
}

Pokemon::Pokemon(int32_t id, std::string nom, int32_t pv, int32_t atk, int32_t atkSp, int32_t def, int32_t defSp, int32_t speed, Attack* atk1, Attack* atk2, Attack* atk3, Attack* atk4, Type* type)
{
    this->setId(id);
    this->setNom(nom);
    this->pv = pv;
    this->atk = atk;
    this->atkSp = atkSp;
    this->def = def;
    this->defSp = defSp;
    this->speed = speed;
    this->atk1 = atk1;
    this->atk2 = atk2;
    this->atk3 = atk3;
    this->atk4 = atk4;
    this->setType(type);
}

Pokemon::Pokemon(Pokemon const& pokemon)
{
    this->setId(id);
    this->setNom(nom);
    this->atk = pokemon.atk;
    this->pv = pokemon.pv;
    this->atkSp = pokemon.atkSp;
    this->def = pokemon.def;
    this->defSp = pokemon.defSp;
    this->speed = pokemon.speed;
    this->atk1 = pokemon.atk1;
    this->atk2 = pokemon.atk2;
    this->atk3 = pokemon.atk3;
    this->atk4 = pokemon.atk4;
    this->setType(type);
}

/* getters */
int32_t Pokemon::getPv()
{
    return this->pv;
}

int32_t Pokemon::getAtk()
{
    return this->atk;
}

int32_t Pokemon::getAtkSp()
{
    return this->atkSp;
}

int32_t Pokemon::getDef()
{
    return this->def;
}

int32_t Pokemon::getDefSp()
{
    return this->defSp;
}

int32_t Pokemon::getSpeed()
{
    return this->speed;
}

Attack* Pokemon::getAtk1()
{
    return this->atk1;
}

Attack* Pokemon::getAtk2()
{
    return this->atk2;
}

Attack* Pokemon::getAtk3()
{
    return this->atk3;
}

Attack* Pokemon::getAtk4()
{
    return this->atk4;
}
DBPokemon* Pokemon::getDBPokemon()
{
    return new DBPokemon(this->id, this->nom, this->type);
}

/* setters */
void Pokemon::setPv(int32_t pv)
{
    this->pv = pv;
}

void Pokemon::setAtk(int32_t atk)
{
    this->atk = atk;
}

void Pokemon::setAtkSp(int32_t atkSp)
{
    this->atkSp = atkSp;
}

void Pokemon::setDef(int32_t def)
{
    this->def = def;
}

void Pokemon::setDefSp(int32_t defSp)
{
    this->defSp = defSp;
}

void Pokemon::setSpeed(int32_t speed)
{
    this->speed = speed;
}

void Pokemon::setAtk1(Attack* atk1)
{
    this->atk1 = atk1;
}

void Pokemon::setAtk2(Attack* atk2)
{
    this->atk2 = atk2;
}

void Pokemon::setAtk3(Attack* atk3)
{
    this->atk3 = atk3;
}

void Pokemon::setAtk4(Attack* atk4)
{
    this->atk4 = atk4;
}

std::string Pokemon::toString()
{
    return "Nom :\n " + this->getNom() + " " + this->getType()->getNom();
}

Pokemon::~Pokemon()
{
    if (this->selfCreatedAttack1)
        delete this->atk1;
    if (this->selfCreatedAttack2)
        delete this->atk2;
    if (this->selfCreatedAttack3)
        delete this->atk3;
    if (this->selfCreatedAttack4)
        delete this->atk4;
}