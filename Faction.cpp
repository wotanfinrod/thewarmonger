#include <iostream>
#include <string>
#include "Faction.h"
using namespace std;


Faction::~Faction() //Destructor
{
    delete firstEnemy;
    delete secondEnemy;
}


Faction::Faction(string nameIn, int numOfUnitsIn, int attackPointIn, int healthPointIn, int unitRegIn)
{
    this->name = nameIn;
    this->numOfUnits = numOfUnitsIn;
    this->attackPoint = attackPointIn;
    this->healthPoint = healthPointIn;
    this->unitRegNum = unitRegIn;
    this->aliveStat = true;
    this->totalHealth = numOfUnitsIn * healthPointIn;


}

void Faction::AssignEnemies(Faction* firstEnemyIn, Faction* secondEnemyIn)
{
    this->firstEnemy = firstEnemyIn;
    this->secondEnemy= secondEnemyIn;
}

void Faction::Print() const
{

    cout << "Faction Name: " <<  this->name << endl;
    cout << "Status: ";
    if(this->aliveStat) cout << "Alive" << endl;
    else cout << "Defeated" << endl;
    cout << "Attack Point: " << this->attackPoint << endl;
    cout << "Health Point: " << this->healthPoint << endl;
    cout << "Unit Regen Number: " << this->unitRegNum << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;

}

void Faction::EndTurn()
{
    if(numOfUnits < 0) this->numOfUnits = 0;
    if (numOfUnits == 0) this->aliveStat = false;
}