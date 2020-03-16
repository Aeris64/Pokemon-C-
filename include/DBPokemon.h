#ifndef DBPOKEMON_INCLUDED_H
#define DBPOKEMON_INCLUDED_H

#include <string>

#include "Type.h"
#include "Attack.h"

class DBPokemon {
private:
    int id;
    std::string nom;
    Type* type;

public:
    DBPokemon();
    DBPokemon(int id, std::string nom, Type* type);
    DBPokemon(DBPokemon const& dbPokemon);
    ~DBPokemon();

    /* getters */
    int getId();
    std::string getNom();
    Type* getType();

    /* setters */
    void setId(int id);
    void setNom(std::string nom);
    void setType(Type* Type);

    std::string toString();
};
#endif