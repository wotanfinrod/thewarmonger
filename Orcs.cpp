#include <iostream>
#include <string>
#include "Orcs.h"
#include "Faction.h"
using namespace std;


void Orcs::PerformAttack()
{
    
    //If both enemy is alive
    if(this->firstEnemy->IsAlive() && this->secondEnemy->IsAlive()) 
    {

        int unitsFirstEnemy = (this->numOfUnits / 10) * 7 ;
        int unitsSecondEnemy =  this->numOfUnits - unitsFirstEnemy;  
        this->firstEnemy->ReceiveAttack(unitsFirstEnemy * this->attackPoint, 0);
        this->secondEnemy->ReceiveAttack(unitsSecondEnemy * this->attackPoint, 0);
    }

    //If only first enemy is alive
    else if (this->firstEnemy->IsAlive())
        this->firstEnemy->ReceiveAttack(this->attackPoint * this->numOfUnits, 0);

    //If only second enemy is alive
    else if (this->secondEnemy->IsAlive())
        this->secondEnemy->ReceiveAttack(this->attackPoint * this->numOfUnits, 0);
        
}

void Orcs::ReceiveAttack(int AP, int enemyFaction)
{
    int damageReceived;
    //If the attack comes from elves
    if(enemyFaction = 2)
        damageReceived = (AP / 4) * 3 ;

    //If the attack comes from dwarves
    else 
        damageReceived = (AP / 5) * 4 ;

    int unitsDead = damageReceived / this->healthPoint;
    this->numOfUnits -= unitsDead;
    this ->totalHealth = this->numOfUnits * healthPoint;

}

//
int Orcs::PurchaseWeapons(int weaponPointsIn)
{
    this->attackPoint += 2 * weaponPointsIn; //Attack point increased
    return weaponPointsIn * 20;
}

int Orcs::PurchaseArmors(int armorPointsIn)
{
    this->healthPoint += armorPointsIn * 2 ; // Health point increased
    this->totalHealth = this->healthPoint * this->numOfUnits; //Updated total healt point 
    return armorPointsIn ;
}

void Orcs::Print() const
{
    cout << "\"Stop running, you'll only die tired!\"" << endl;
        
    cout << right <<"Faction Name: "<<this->name << endl;    
    cout << "Status: ";
    if(this->aliveStat) cout << "Alive" << endl;
    else cout << "Defeated" << endl;
    cout << "Attack Point: " << this->attackPoint << endl;
    cout << "Health Point: " << this->healthPoint << endl;
    cout << "Unit Regen Number: " << this->unitRegNum << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}


