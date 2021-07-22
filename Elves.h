#ifndef ELVES_H
#define ELVES_H

#include <string>
#include "Faction.h"

class Elves : public Faction
{

public:
    Elves(std::string nameIn, int numOfUnitsIn, int attackPointIn, int healthPointIn, int unitRegIn) : Faction(nameIn,numOfUnitsIn,attackPointIn,healthPointIn,unitRegIn){}; //Constructor
    void PerformAttack();
    void ReceiveAttack(int AP, int enemyFaction);
    int PurchaseWeapons(int weaponPointsIn);
    int PurchaseArmors(int armorPointsIn);
    void Print() const;
};

#endif