#include <iostream>
#include "Player.h"
#include "Attack.h"
#include "DBPokemon.h"
#include "Pokemon.h"
#include "Type.h"
#include "Menu.h"

Menu* initPokedex() {


Menu* play = new Menu();

//(id, nom)
Type* eau = new Type(1, "Eau");
Type* feu = new Type(2, "Feu");
Type* plante = new Type(3, "Plante");
Type* elec = new Type(4, "Electrique");
Type* psy = new Type(5, "Psy");
Type* tenebre = new Type(6, "Ténèbres");
Type* dragon = new Type(7, "Dragon");
Type* normal = new Type(8, "Normal");
Type* sol = new Type(9, "Sol");
Type* vol = new Type(10, "Vol");
Type* insecte = new Type(11, "Insecte");
Type* acier = new Type(12, "Acier");
Type* spectre = new Type(13, "Spectre");

play->addType(eau);
play->addType(feu);
play->addType(plante);
play->addType(elec);
play->addType(psy);
play->addType(tenebre);
play->addType(dragon);
play->addType(normal);
play->addType(sol);
play->addType(vol);
play->addType(insecte);
play->addType(acier);
play->addType(spectre);

//(id, nom, puissance, pp, accuracy, type)
Attack* skill1 = new Attack(1,"Charge",20,30,90,normal);
Attack* skill2 = new Attack(2,"Flammèche",20,30,90,feu);
Attack* skill3 = new Attack(3,"Pistolet à O",20,30,90,eau);
Attack* skill4 = new Attack(4,"Balle graine",20,30,90,plante);
Attack* skill5 = new Attack(5,"Choc mental",20,30,90,psy);
Attack* skill6 = new Attack(6,"Feinte",20,30,90,tenebre);
Attack* skill7 = new Attack(7,"Eclair",20,30,90,elec);
Attack* skill8 = new Attack(8,"Draco-Flèches",20,30,90,dragon);
Attack* skill9 = new Attack(9,"Draco Météores",100,5,70,dragon);

play->addAttack(skill1);
play->addAttack(skill2);
play->addAttack(skill3);
play->addAttack(skill4);
play->addAttack(skill5);
play->addAttack(skill6);
play->addAttack(skill7);
play->addAttack(skill8);
play->addAttack(skill9);

//(id, nom, type)
DBPokemon* no1 = new DBPokemon(1, "Salameche", feu);
DBPokemon* no2 = new DBPokemon(2, "Carapuce", eau);
DBPokemon* no3 = new DBPokemon(3, "Bulbizarre", plante);
DBPokemon* no4 = new DBPokemon(4, "Pikachu", elec);
DBPokemon* no5 = new DBPokemon(5, "Abra", psy);
DBPokemon* no6 = new DBPokemon(6, "Medhyena", tenebre);
DBPokemon* no7 = new DBPokemon(7, "Evoli", normal);
DBPokemon* no8 = new DBPokemon(8, "Minidraco", dragon);
DBPokemon* no9 = new DBPokemon(9, "Kyogre", eau);
DBPokemon* no10 = new DBPokemon(10, "Groudon", sol);
DBPokemon* no11 = new DBPokemon(11, "Rayquaza", dragon);
DBPokemon* no12 = new DBPokemon(12, "Zigzaton", normal);
DBPokemon* no13 = new DBPokemon(13, "Hypotrempe", eau);
DBPokemon* no14 = new DBPokemon(14, "Mr. Mime", psy);
DBPokemon* no15 = new DBPokemon(15, "Insécateur", insecte);
DBPokemon* no16 = new DBPokemon(16, "Airmure", acier);
DBPokemon* no17 = new DBPokemon(17, "Suicune", eau);
DBPokemon* no18 = new DBPokemon(18, "Gardevoir", psy);
DBPokemon* no19 = new DBPokemon(19, "Skitty", normal);
DBPokemon* no20 = new DBPokemon(20, "Galekid", acier);
DBPokemon* no21 = new DBPokemon(21, "Altaria", vol);
DBPokemon* no22 = new DBPokemon(22, "Milobellus", eau);
DBPokemon* no23 = new DBPokemon(23, "Branette", spectre);

play->addPokemon(no1);
play->addPokemon(no2);
play->addPokemon(no3);
play->addPokemon(no4);
play->addPokemon(no5);
play->addPokemon(no6);
play->addPokemon(no7);
play->addPokemon(no8);
play->addPokemon(no9);
play->addPokemon(no10);
play->addPokemon(no11);
play->addPokemon(no12);
play->addPokemon(no13);
play->addPokemon(no14);
play->addPokemon(no15);
play->addPokemon(no16);
play->addPokemon(no17);
play->addPokemon(no18);
play->addPokemon(no19);
play->addPokemon(no20);
play->addPokemon(no21);
play->addPokemon(no22);
play->addPokemon(no23);

return play;
}