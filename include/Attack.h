#ifndef ATTACK_INCLUDED_H
#define ATTACK_INCLUDED_H

#include <string>

#include "Type.h"

class Attack {
private:
    int id;
    std::string nom;
    int power;
    int pp;
    int accuracy;
    Type* type;

public:
    Attack();
    Attack(int id, std::string nom, int power, int pp, int accuracy, Type* type);
    Attack(Attack const& attack);
    ~Attack();

    /* getters */
    int getId();
    std::string getNom();
    int getPower();
    int getPp();
    int getAccuracy();
    Type* getType();
    
    /* setters */
    void setId(int id);
    void setNom(std::string nom);
    void setPower(int power);
    void setPp(int pp);
    void setAccuracy(int accuracy);
    void setType(Type* type);

    std::string toString();
};
#endif