#include <iostream>
#include <string>
#include "Elves.h"
#include "Faction.h"
using namespace std;



//Elves = 2
void Elves::PerformAttack()
{


    //If both enemy is alive
    if(this->firstEnemy->IsAlive() && this->secondEnemy->IsAlive())
    {
        int unitsFirstEnemy = (this->numOfUnits / 5 ) * 3;  //Units for first enemy
        int unitsSecondEnemy = (this->numOfUnits - unitsFirstEnemy);

        int attackPointForOrc = ( this->attackPoint / 2) * 3; // %150 of attack point to orcs

        this->firstEnemy->ReceiveAttack(unitsFirstEnemy * attackPointForOrc,2);
        this->secondEnemy->ReceiveAttack(unitsSecondEnemy* this->attackPoint,2);
    }


    //If only first enemy is alive
    else if (this->firstEnemy->IsAlive())
    {
        int attackPointforOrc = (this->attackPoint / 2 ) * 3;
        this->firstEnemy->ReceiveAttack(attackPointforOrc * this->numOfUnits, 2);
    }
    
    //If only second enemy is alive
    else if (this->secondEnemy->IsAlive())
        this->secondEnemy->ReceiveAttack(this->attackPoint * this->numOfUnits,2);

}

void Elves::ReceiveAttack(const int AP, int enemyFaction)
{

    int damageReceived;
    
    //If attack comes from Orcs
    if(enemyFaction == 0)
       damageReceived = (AP/4) * 5; //Damage increased to %125
    

    //If attack comes from Dwarves
    else
        damageReceived = (AP / 4) * 3; //Damage decreased to %75

    int unitsDead = damageReceived / this->healthPoint; //Number of units dead
    this->numOfUnits -= unitsDead;                      //Update number of units
    this->totalHealth = this->numOfUnits * healthPoint; //Update total health of class
}

int Elves::PurchaseWeapons(const int weaponPointsIn)
{
    this->attackPoint += 2 * weaponPointsIn;
    return weaponPointsIn * 15;
}

int Elves::PurchaseArmors(const int armorPointsIn)
{

    this->healthPoint += armorPointsIn * 4 ;
    this->totalHealth = this->healthPoint * this->numOfUnits;
    return armorPointsIn * 5;
}

void Elves::Print() const
{
    cout << "\"You cannot reach our elegance.\"" << endl;
    cout << "Faction Name: " <<  this->name << endl;
    cout << "Status: ";
    if(this->aliveStat) cout << "Alive" << endl;
    else cout << "Defeated" << endl;
    cout << "Attack Point: " << this->attackPoint << endl;
    cout << "Health Point: " << this->healthPoint << endl;
    cout << "Unit Regen Number: " << this->unitRegNum << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}