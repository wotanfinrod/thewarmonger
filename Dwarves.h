#ifndef DWARVES_H
#define DWARVES_H

#include <string>
#include "Faction.h"

class Dwarves : public Faction
{


public:
    Dwarves(std::string nameIn, int numOfUnitsIn, int attackPointIn, int healthPointIn, int unitRegIn) : Faction(nameIn,numOfUnitsIn,attackPointIn,healthPointIn,unitRegIn){}; //Constructor
    void PerformAttack();
    void ReceiveAttack(int AP, int enemyFaction);
    int PurchaseWeapons(int weaponPointsIn);
    int PurchaseArmors(int armorPointsIn);
    void Print() const;
};


#endif