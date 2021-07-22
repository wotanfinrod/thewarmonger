#ifndef MERCHANT_H
#define MERCHANT_H

#include <string>
#include "Faction.h"

class Merchant{

    //Factions
    Faction* first_faction; //Orcs assigned later
    Faction* second_faction; //Dwarves assigned later
    Faction* third_faction;  //Elves assigned later

    const int weapon_point_start;
    const int armor_point_start;

    int revenue;
    int weapon_point;
    int armor_point;

    public:
    Merchant(int startingWeaponPoints, int startingArmorPoints) : weapon_point_start(startingWeaponPoints), armor_point_start(startingArmorPoints), revenue(0), armor_point(startingArmorPoints), weapon_point(startingWeaponPoints){};
    ~Merchant(); //Destructor
    void AssignFactions(Faction* firstIn, Faction* secondIn, Faction* thirdIn);
    bool SellWeapons(std::string factionIn, int weaponPointIn);
    bool SellArmors(std::string factionIn, int armorPointIn);
    void EndTurn();

    //GETTERS-SETTERS
    int GetRevenue(){return this->revenue;}
    int GetWeaponPoints(){return this->weapon_point;}
    int GetArmorPoints(){return this->armor_point;}

    //

};













#endif