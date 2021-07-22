#include <iostream>
#include <string>
#include "Dwarves.h"
#include "Faction.h"
using namespace std;

//Dwarves = 1 
void Dwarves::PerformAttack()
{

    //If both enemy is alive
    if(this->firstEnemy->IsAlive() && this->secondEnemy->IsAlive())
    {
        int unitsFirstEnemy = (this->numOfUnits/2);
        int unitsSecondEnemy = this->numOfUnits - unitsFirstEnemy;
        this->firstEnemy->ReceiveAttack(unitsFirstEnemy*this->attackPoint,1);
        this->secondEnemy->ReceiveAttack(unitsSecondEnemy*this->attackPoint,1);
    }

    //If only first enemy is alive
    else if (this->firstEnemy->IsAlive())
        this->firstEnemy->ReceiveAttack(this->attackPoint * this->numOfUnits, 1);

    //If only second enemy is alive
    else if (this->secondEnemy->IsAlive())
        this->secondEnemy->ReceiveAttack(this->attackPoint * this->numOfUnits,1);
}

void Dwarves::ReceiveAttack(int AP, int enemyFaction)
{
    int damageReceived = enemyFaction;

    int unitsDead = damageReceived / this->healthPoint;
    this->numOfUnits -= unitsDead;
    this ->totalHealth = this->numOfUnits * healthPoint;

}

int Dwarves::PurchaseWeapons(int weaponPointsIn)
{
    this->attackPoint += weaponPointsIn;
    return weaponPointsIn * 10 ; 
}

int Dwarves::PurchaseArmors(int armorPointsIn)
{
    this->healthPoint += armorPointsIn * 2 ;
    this->totalHealth = this->healthPoint * this->numOfUnits;
    return armorPointsIn * 3;
}

void Dwarves::Print() const
{
    cout << "\"Taste the power of our axes!\"" << endl;
    cout << "Faction Name: " <<  this->name << endl;
    cout << "Status: ";
    if(this->aliveStat) cout << "Alive" << endl;
    else cout << "Defeated" << endl;
    cout << "Attack Point: " << this->attackPoint << endl;
    cout << "Health Point: " << this->healthPoint << endl;
    cout << "Unit Regen Number: " << this->unitRegNum << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}