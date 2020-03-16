#ifndef TYPE_INCLUDED_H
#define TYPE_INCLUDED_H

#include <string>

class Type {
private:
    int id;
    std::string nom;
    // Liste type faible
    // Liste type fort

public:
    Type();
    Type(int id, std::string nom);
    Type(Type const& type);
    ~Type();

    /* getters */
    int getId();
    std::string getNom();
    
    /* setters */
    void setId(int id);
    void setNom(std::string nom);

    std::string toString();
};
#endif