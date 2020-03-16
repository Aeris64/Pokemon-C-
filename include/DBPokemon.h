#ifndef DBPOKEMON_INCLUDED_H
#define DBPOKEMON_INCLUDED_H

#include <string>

#include "Type.h"
#include "Attack.h"

class DBPokemon {
protected:
    int32_t id;
    std::string nom;
    Type* type;

    /* Sert de flag pour savoir si on a créé nous même l'auteur ou s'il a été créé via un pointeur passé en paramètre */
    int8_t selfCreatedType = 0;

public:
    DBPokemon();
    DBPokemon(int32_t id, std::string nom, Type* type);
    DBPokemon(DBPokemon const& dbPokemon);
    ~DBPokemon();

    /* getters */
    int32_t getId();
    std::string getNom();
    Type* getType();

    /* setters */
    void setId(int32_t id);
    void setNom(std::string nom);
    void setType(Type* Type);

    std::string toString();
};
#endif