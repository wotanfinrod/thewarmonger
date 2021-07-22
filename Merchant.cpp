#include <iostream>
#include <string>
#include "Merchant.h"
#include "Faction.h"
using namespace std;


Merchant::~Merchant() //Destructor
{
 delete first_faction;
 delete second_faction;
 delete third_faction;
}

void Merchant::AssignFactions(Faction* firstIn, Faction* secondIn, Faction* thirdIn)
{
    this->first_faction = firstIn; //Orcs
    this->second_faction = secondIn; //Dwarves
    this->third_faction = thirdIn;  //Elves

}

bool Merchant::SellWeapons(string factionIn, int weaponPointIn)
{

    int gold = 0;

    //If there is not enough weapon point
    if(this->weapon_point < weaponPointIn)
    {
        cerr << "You try to sell more weapons than you have in possession.";
        return 0;
    }


    if(factionIn == "Orcs") 
    {
        if(this->first_faction->IsAlive())
           gold = this->first_faction->PurchaseWeapons(weaponPointIn);

        else
        {
            cerr << "The faction you want to sell weapons is dead!";
            return 0;
        }

    }

    else if(factionIn == "Dwarves")
    {
        if(this->second_faction->IsAlive())
           gold =  this->second_faction->PurchaseWeapons(weaponPointIn);

        else
        {
            cerr << "The faction you want to sell weapons is dead!";
            return 0;
        }
    }
    else    //Elves
    {
        if(this->third_faction->IsAlive())
            gold = this->third_faction->PurchaseWeapons(weaponPointIn);

        else
        {
            cerr << "The faction you want to sell weapons is dead!";
            return 0;
        }
    }

    this->revenue += gold;
    this->weapon_point -= weaponPointIn;
    cout << "Weapons sold!";
    return 1;


}

bool Merchant::SellArmors(string factionIn, int armorPointIn)
{
    int gold = 0;

    //If there is not enough armor point
    if(this->armor_point < armorPointIn)
    {
        cerr << "You try to sell more armors than you have in possession.";
        return 0;
    }

    if(factionIn == "Orcs") 
    {
        if(this->first_faction->IsAlive())
            gold = this->first_faction->PurchaseArmors(armorPointIn);

        else
        {
            cerr << "The faction you want to sell armors is dead!";
            return 0;
        }

    }

    else if(factionIn == "Dwarves")
    {
        if(this->second_faction->IsAlive())
           gold = this->second_faction->PurchaseArmors(armorPointIn);

        else
        {
            cerr << "The faction you want to sell armors is dead!";
            return 0;
        }
    }
    else    //Elves
    {
        if(this->third_faction->IsAlive())
           gold = this->third_faction->PurchaseArmors(armorPointIn);

        else
        {
            cerr << "The faction you want to sell armors is dead!";
            return 0;
        }
    }

    this->revenue += gold;
    this->armor_point -= armorPointIn;
    cout << "Armors sold!";
    return 1;

}

void Merchant::EndTurn()
{
    this->armor_point = armor_point_start;
    this->weapon_point = weapon_point_start;
}