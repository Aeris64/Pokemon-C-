#ifndef POKEMON_INCLUDED_H
#define POKEMON_INCLUDED_H

#include <string>

#include "DBPokemon.h"
#include "Attack.h"

class Pokemon : public DBPokemon {
private:
    int atk;
    int atkSp;
    int def;
    int defSp;
    int speed;
    Attack* atk1;
    Attack* atk2;
    Attack* atk3;
    Attack* atk4;

public:
    Pokemon();
    Pokemon(int id, std::string nom, int atk, int atkSp, int def, int defSp, int speed, Attack* atk1, Attack* atk2, Attack* atk3, Attack* atk4, Type* type);
    Pokemon(Pokemon const& pokemon);
    ~Pokemon();

    /* getters */
    int getatk();
    int getatkSp();
    int getdef();
    int getdefSp();
    int getSpeed();
    Attack* getatk1();
    Attack* getatk2();
    Attack* getatk3();
    Attack* getatk4();

    /* setters */
    void setAtk(int Atk);
    void setAtkSp(int AtkSp);
    void setDef(int def);
    void setDefSp(int defSp);
    void setSpeed(int speed);
    void setatk1(Attack* atk1);
    void setatk2(Attack* atk2);
    void setatk3(Attack* atk3);
    void setatk4(Attack* atk4);

    std::string toString();
};
#endif