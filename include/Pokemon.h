#ifndef POKEMON_INCLUDED_H
#define POKEMON_INCLUDED_H

#include <string>

#include "DBPokemon.h"
#include "Attack.h"

class Pokemon : public DBPokemon {
private:
    int32_t atk;
    int32_t atkSp;
    int32_t def;
    int32_t defSp;
    int32_t speed;
    Attack* atk1;
    Attack* atk2;
    Attack* atk3;
    Attack* atk4;
    int8_t selfCreatedAttack1 = 0;
    int8_t selfCreatedAttack2 = 0;
    int8_t selfCreatedAttack3 = 0;
    int8_t selfCreatedAttack4 = 0;

public:
    // Pokemon();
    Pokemon(int32_t id, std::string nom, int32_t atk, int32_t atkSp, int32_t def, int32_t defSp, int32_t speed, Attack* atk1, Attack* atk2, Attack* atk3, Attack* atk4, Type* type);
    // Pokemon(Pokemon const& pokemon);
    ~Pokemon();

    /* getters */
    int32_t getAtk();
    int32_t getAtkSp();
    int32_t getDef();
    int32_t getDefSp();
    int32_t getSpeed();
    Attack* getAtk1();
    Attack* getAtk2();
    Attack* getAtk3();
    Attack* getAtk4();

    /* setters */
    void setAtk(int32_t Atk);
    void setAtkSp(int32_t AtkSp);
    void setDef(int32_t def);
    void setDefSp(int32_t defSp);
    void setSpeed(int32_t speed);
    void setAtk1(Attack* atk1);
    void setAtk2(Attack* atk2);
    void setAtk3(Attack* atk3);
    void setAtk4(Attack* atk4);

    std::string toString();
};
#endif