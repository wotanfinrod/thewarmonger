


#ifndef FACTION_H
#define FACTION_H

#include <string>

//### ABSTRACT CLASS ### 
class Faction{ 

protected:
std::string name;
Faction* firstEnemy;
Faction* secondEnemy;
int attackPoint;
int numOfUnits;
int healthPoint;
int totalHealth;
int unitRegNum;
bool aliveStat;


public:
    Faction(std::string nameIn, int numOfUnitsIn, int attackPointIn, int healthPointIn, int unitRegIn); //Constructor
    ~Faction(); //Destructor
    void AssignEnemies(Faction* firstEnemyIn, Faction* secondEnemyIn);
    virtual void PerformAttack() = 0; //Pure virtual
    virtual void ReceiveAttack(int AP, int enemyFaction) = 0; // !!! For enemyFaction, 0 = Orcs, 1 = Dwarves, 2 = Elves
    virtual int PurchaseWeapons(int weaponPointsIn) =0; //Pure virtual
    virtual int PurchaseArmors(int armorPointsIn) =0; //Pure virtual
    virtual void Print() const ;

    void EndTurn();

    //GETTERS - SETTERS
    bool IsAlive(){return this->aliveStat;}
    //


};

#endif