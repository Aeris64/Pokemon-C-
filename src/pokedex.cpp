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
Type* tenebre = new Type(6, "Tenebres");
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
Attack* skill1 = new Attack(1,"Charge",30,30,90,normal);
Attack* skill2 = new Attack(2,"Flammeche",30,30,90,feu);
Attack* skill3 = new Attack(3,"Pistolet a O",30,30,90,eau);
Attack* skill4 = new Attack(4,"Balle graine",30,30,90,plante);
Attack* skill5 = new Attack(5,"Choc mental",30,30,90,psy);
Attack* skill6 = new Attack(6,"Feinte",30,30,90,tenebre);
Attack* skill7 = new Attack(7,"Eclair",30,30,90,elec);
Attack* skill8 = new Attack(8,"Draco-Fleches",30,30,90,dragon);
Attack* skill9 = new Attack(9,"Draco Meteores",100,5,70,dragon);
Attack* skill10 = new Attack(10,"Tranche-Herbe",45,15,90,plante);
Attack* skill11 = new Attack(11,"Bulles d'O",45,15,90,eau);
Attack* skill12 = new Attack(12,"Aqua-Jet",40,30,100,eau);
Attack* skill13 = new Attack(13,"Psyko",80,5,70,psy);
Attack* skill14 = new Attack(14,"Coupe-psyko",50,15,90,psy);
Attack* skill15 = new Attack(15,"Dracosouffle",50,15,90,dragon);
Attack* skill16 = new Attack(16,"Griffe acier",40,30,100,acier);
Attack* skill17 = new Attack(17,"Dracogriffe",40,15,70,dragon);
Attack* skill18 = new Attack(18,"Tete de fer",45,15,90,acier);
Attack* skill19 = new Attack(19,"Noeud Herbe",60,15,90,plante);
Attack* skill20 = new Attack(20,"Survinsecte",40,30,100,insecte);
Attack* skill21 = new Attack(21,"Rayon Signal",80,10,70,insecte);
Attack* skill22 = new Attack(22,"Tete de fer",45,15,90,acier);
Attack* skill23 = new Attack(23,"Coup Bas",80,15,90,tenebre);
Attack* skill24 = new Attack(24,"Encornebois",90,5,70,plante);
Attack* skill25 = new Attack(25,"Machouille",50,10,70,tenebre);
Attack* skill26 = new Attack(26,"Acrobatie",80,15,90,vol);
Attack* skill27 = new Attack(27,"Boutefeu",50,5,70,feu);
Attack* skill28 = new Attack(28,"Cru-aile",60,10,70,vol);
Attack* skill29 = new Attack(29,"Vent violent",90,5,90,vol);
Attack* skill30 = new Attack(30,"Poing de feu",60,15,70,feu);
Attack* skill31 = new Attack(31,"Belier",90,5,70,normal);
Attack* skill32 = new Attack(32,"Coup d'jus",50,15,90,elec);
Attack* skill33 = new Attack(33,"Fatal Foudre",90,5,70,elec);
Attack* skill34 = new Attack(34,"Force cachee",30,10,90,normal);
Attack* skill35 = new Attack(35,"Masse d'os",50,15,90,sol);
Attack* skill36 = new Attack(36,"Seisme",90,5,70,sol);
Attack* skill37 = new Attack(37,"Coud'boue",30,10,90,sol);
Attack* skill38 = new Attack(38,"Chatiment",50,15,90,spectre);
Attack* skill39 = new Attack(39,"Rayon spectral",90,5,70,spectre);
Attack* skill40 = new Attack(40,"Ombre portee",30,10,90,spectre);

play->addAttack(skill1);
play->addAttack(skill2);
play->addAttack(skill3);
play->addAttack(skill4);
play->addAttack(skill5);
play->addAttack(skill6);
play->addAttack(skill7);
play->addAttack(skill8);
play->addAttack(skill9);
play->addAttack(skill10);
play->addAttack(skill11);
play->addAttack(skill12);
play->addAttack(skill13);
play->addAttack(skill14);
play->addAttack(skill15);
play->addAttack(skill16);
play->addAttack(skill17);
play->addAttack(skill18);
play->addAttack(skill19);
play->addAttack(skill20);
play->addAttack(skill21);
play->addAttack(skill22);
play->addAttack(skill23);
play->addAttack(skill24);
play->addAttack(skill25);
play->addAttack(skill26);
play->addAttack(skill27);
play->addAttack(skill28);
play->addAttack(skill29);
play->addAttack(skill30);
play->addAttack(skill31);
play->addAttack(skill32);
play->addAttack(skill33);
play->addAttack(skill34);
play->addAttack(skill35);
play->addAttack(skill36);
play->addAttack(skill37);
play->addAttack(skill38);
play->addAttack(skill39);
play->addAttack(skill40);

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
DBPokemon* no15 = new DBPokemon(15, "Insecateur", insecte);
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