//main

#include "Faction.h"
#include "Orcs.h"
#include "Dwarves.h"
#include "Elves.h"
#include "Merchant.h"

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void WaitForKeyPress() {
	getchar();
	getchar();
}


void PrintMenu(const int& day, Merchant& merchant) {
	cout << endl << "Battle of the Three Armies - Day " << day << endl;
	cout << "Revenue: " << merchant.GetRevenue() << endl;
	cout << "Weapon Points Left: " << merchant.GetWeaponPoints() << " | Armor Points Left: " << merchant.GetArmorPoints() << endl;
	cout << endl << "----CHOOSE AN ACTION----" << endl;
	cout << "1-   Print faction information" << endl;
	cout << "2-   Sell weapons" << endl;
	cout << "3-   Sell armors" << endl;
	cout << "4-   End the day" << endl;
	cout << "5-   End the game" << endl;
	cout << "6-   Quit game" << endl;
	cout << "Your action: ";
}

// Method to print battlefield's status that would be called at the end of each day and start of a game
void PrintBattlefieldStats(int& day, Merchant& merchant, Faction& orcs, Faction& dwarves, Faction& elves) {
	cout << endl << "---------------------------------" << endl;;
	cout << "Battle of The Three Armies" << endl << endl;
	// Calls Merchant class' GetRevenue() method to print total revenue at that point
	cout << "Total Revenue: " << merchant.GetRevenue() << endl;

	// Call each class' Print() method to print their status
	cout << endl << "FACTIONS" << endl;
	cout << "--------------ORCS---------------" << endl;
	orcs.Print();
	cout << "-------------DWARVES-------------" << endl;
	dwarves.Print();
	cout << "--------------ELVES--------------" << endl;
	elves.Print();
	cout << "---------------------------------" << endl;;
}

// Method to print information of faction or factions depending on player's choice
void PrintInformationMenu(Merchant& merchant, Faction& orcs, Faction& dwarves, Faction& elves) {
	int choice;
	cout << endl << "----CHOOSE FACTION(S)----" << endl;
	cout << "1-   Orcs" << endl;
	cout << "2-   Dwarves" << endl;
	cout << "3-   Elves" << endl;
	cout << "4-   All" << endl;
	cout << "5-   Back" << endl;
	cout << "Your choice: ";
	cin >> choice;

	bool actionEnded = false;
	if (!actionEnded) {
		// Regarding player's choice calls a faction's or all three faction's Print() method
		switch (choice) {
		case 1:
			cout << endl << "-------------ORCS---------------" << endl;
			orcs.Print();
			cout << endl << "Press any key to continue." << endl;
			WaitForKeyPress();

			actionEnded = true;
			break;
		case 2:
			cout << endl << "-------------DWARVES-------------" << endl;
			dwarves.Print();
			cout << endl << "Press any key to continue." << endl;
			WaitForKeyPress();

			actionEnded = true;
			break;
		case 3:
			cout << endl << "--------------ELVES--------------" << endl;
			elves.Print();
			cout << endl << "Press any key to continue." << endl;
			WaitForKeyPress();

			actionEnded = true;
			break;
		case 4:
			cout << endl << "--------------ORCS---------------" << endl;
			orcs.Print();
			cout << "-------------DWARVES-------------" << endl;
			dwarves.Print();
			cout << "--------------ELVES--------------" << endl;
			elves.Print();
			cout << endl << "Press any key to continue." << endl;
			WaitForKeyPress();

			actionEnded = true;
			break;
		case 5:
			actionEnded = true;
			break;
		default:
			cout << "Please enter a valid choice: ";
			cin >> choice;

			actionEnded = false;
			break;
		}
	}
}

// Method for merchant to sell weapons to factions that are assigned to him
void SellWeaponMenu(Merchant& merchant) {
	cout << endl << "Available weapon points for today: " << merchant.GetWeaponPoints() << endl;
	int choice;
	cout << "----CHOOSE FACTION TO SELL WEAPONS----" << endl;
	cout << "1-   Orcs" << endl;
	cout << "2-   Dwarves" << endl;
	cout << "3-   Elves" << endl;
	cout << "4-   Back" << endl;
	cout << "Your choice: ";
	cin >> choice;

	bool transactionSuccessful = false;
	while (!transactionSuccessful) {
		// Regarding player's choice calls a merchant's SellWeapons() method. Keep in mind of method parameters
		switch (choice) {
		case 1:
			while (!transactionSuccessful) {
				cout << endl << "----Selling weapons to Orcs----" << endl;

				int weaponPoints;
				cout << "Available weapon points for today: " << merchant.GetWeaponPoints() << endl;
				cout << "Enter weapon points you want to sell (To cancel enter 0): ";
				cin >> weaponPoints;

				transactionSuccessful = weaponPoints == 0 ? true : merchant.SellWeapons("Orcs", weaponPoints);
			}
			break;
		case 2:
			while (!transactionSuccessful) {
				cout << endl << "----Selling weapons to Dwarves----" << endl;

				int weaponPoints;
				cout << "Available weapon points for today: " << merchant.GetWeaponPoints() << endl;
				cout << "Enter weapon points you want to sell (To cancel enter 0): ";
				cin >> weaponPoints;

				transactionSuccessful = weaponPoints == 0 ? true : merchant.SellWeapons("Dwarves", weaponPoints);
			}
			break;
		case 3:
			while (!transactionSuccessful) {
				cout << endl << "----Selling weapons to Elves----" << endl;

				int weaponPoints;
				cout << "Available weapon points for today: " << merchant.GetWeaponPoints() << endl;
				cout << "Enter weapon points you want to sell (To cancel enter 0): ";
				cin >> weaponPoints;

				transactionSuccessful = weaponPoints == 0 ? true : merchant.SellWeapons("Elves", weaponPoints);
			}
			break;
		case 4:
			transactionSuccessful = true;
			break;
		default:
			cout << "Please enter a valid choice: ";
			cin >> choice;

			transactionSuccessful = false;
			break;
		}
	}

	cout << endl << "Press any key to continue." << endl;
	WaitForKeyPress();
}

// Method for merchant to sell weapons to factions that are assigned to him
void SellArmorMenu(Merchant& merchant) {
	cout << endl << "Available weapon points for today: " << merchant.GetArmorPoints() << endl;
	int choice;
	cout << "----CHOOSE FACTION TO SELL WEAPONS----" << endl;
	cout << "1-   Orcs" << endl;
	cout << "2-   Dwarves" << endl;
	cout << "3-   Elves" << endl;
	cout << "4-   Back" << endl;
	cout << "Your choice: ";
	cin >> choice;

	bool transactionSuccessful = false;
	while (!transactionSuccessful) {
		// Regarding player's choice calls a merchant's SellWeapons() method. Keep in mind of method parameters
		switch (choice) {
		case 1:
			while (!transactionSuccessful) {
				cout << endl << "----Selling armors to Orcs----" << endl;

				int armorPoints;
				cout << "Available armor points for today: " << merchant.GetArmorPoints() << endl;
				cout << "Enter armor points you want to sell (To cancel enter 0): ";
				cin >> armorPoints;

				transactionSuccessful = armorPoints == 0 ? true : merchant.SellArmors("Orcs", armorPoints);
			}
			break;
		case 2:
			while (!transactionSuccessful) {
				cout << endl << "----Selling armors to Dwarves----" << endl;

				int armorPoints;
				cout << "Available armor points for today: " << merchant.GetArmorPoints() << endl;
				cout << "Enter armor points you want to sell (To cancel enter 0): ";
				cin >> armorPoints;

				transactionSuccessful = armorPoints == 0 ? true : merchant.SellArmors("Dwarves", armorPoints);
			}
			break;
		case 3:
			while (!transactionSuccessful) {
				cout << endl << "----Selling armors to Elves----" << endl;

				int armorPoints;
				cout << "Available armor points for today: " << merchant.GetArmorPoints() << endl;
				cout << "Enter armor points you want to sell (To cancel enter 0): ";
				cin >> armorPoints;

				transactionSuccessful = armorPoints == 0 ? true : merchant.SellArmors("Elves", armorPoints);
			}
			break;
		case 4:
			transactionSuccessful = true;
			break;
		default:
			cout << "Please enter a valid choice: ";
			cin >> choice;

			transactionSuccessful = false;
			break;
		}
	}

	cout << endl << "Press any key to continue." << endl;
	WaitForKeyPress();
}

// Method to perform an action player had chosen from PrintMenu() method
void PerformAction(int& day, int& numOfFactionsAlive, bool& playAgain, bool& gameContinue, Merchant& merchant, Faction& orcs, Faction& dwarves, Faction& elves, int& action) {
	bool actionEnded = false;
	while (!actionEnded) {
		switch (action) {
		case 1:
			PrintInformationMenu(merchant, orcs, dwarves, elves);

			actionEnded = true;
			break;
		case 2:
			SellWeaponMenu(merchant);

			actionEnded = true;
			break;
		case 3:
			SellArmorMenu(merchant);

			actionEnded = true;
			break;
		case 4:
			// If player chose "End Turn" action
			// Merchant ends his turn
			merchant.EndTurn();

			// If factions are alive they perform their attack with PerformAttack() method
			if (orcs.IsAlive()) orcs.PerformAttack();
			if (dwarves.IsAlive()) dwarves.PerformAttack();
			if (elves.IsAlive()) elves.PerformAttack();

			// If factions are alive they end their turn and update their status with ther EndTurn() method
			if (orcs.IsAlive()) orcs.EndTurn();
			if (dwarves.IsAlive()) dwarves.EndTurn();
			if (elves.IsAlive()) elves.EndTurn();

			// Updates the number of factions alive to control if the game is ended
			numOfFactionsAlive = 0;
			if (orcs.IsAlive()) numOfFactionsAlive++;
			if (dwarves.IsAlive()) numOfFactionsAlive++;
			if (elves.IsAlive()) numOfFactionsAlive++;

			// Prints current status of the battlefield
			PrintBattlefieldStats(day, merchant, orcs, dwarves, elves);

			// Increments the day
			day++;

			actionEnded = true;
			break;
		case 5: // If player chose to end the game print battlefield status and end the game
			PrintBattlefieldStats(day, merchant, orcs, dwarves, elves);
			cout << endl << "Game ended!";
			gameContinue = false;

			actionEnded = true;
			break;
		case 6: // If player chose to quit the game print battlefield status and quit the game
			PrintBattlefieldStats(day, merchant, orcs, dwarves, elves);
			cout << endl << "Thank you for playing!";
			playAgain = false;

			actionEnded = true;
			break;
		default:
			cout << "Please enter a valid choice: ";
			cin >> action;

			actionEnded = false;
			break;
		}
	}
}

int main() {
	cout << "--------THE WARMONGER: A NEW DIMENSION--------" << endl;
	bool playAgain = true;
	do {
		bool gameContinue = true;

		// Initializing each warring faction with their own constructor
		// They will behave like Faction(name, numOfUnits, attackPoint, healthPoint, unitRegen)
		Orcs orcs("Orcs", 40, 20, 200, 10);
		Dwarves dwarves("Dwarves", 50, 40, 300, 5);
		Elves elves("Elves", 30, 20, 120, 15);

		// Each enemy factions assigned to their respective enemies
		orcs.AssignEnemies(&elves, &dwarves);
		dwarves.AssignEnemies(&orcs, &elves);
		elves.AssignEnemies(&orcs, &dwarves);

		// Initialize merhant with starting weapon and armor points: Merchant(startingWeaponPoints, startingArmorPoints)
		Merchant merchant(10, 10);
		// Assign warring factions to the merchant
		merchant.AssignFactions(&orcs, &dwarves, &elves);

		// Initialize day and number of factions alive values
		int day = 0;
		int numOfFactionsAlive = 3;

		// Print battlefield status in the start of the war
		PrintBattlefieldStats(day, merchant, orcs, dwarves, elves);

		day++;
		int action = 0;
		while (playAgain && gameContinue && numOfFactionsAlive > 1) {
			// Print the menu after each action
			PrintMenu(day, merchant);
			cin >> action;
			PerformAction(day, numOfFactionsAlive, playAgain, gameContinue, merchant, orcs, dwarves, elves, action);
		}

		// If only one faction left and game ended print the winning faction's status
		if (numOfFactionsAlive == 1) {
			gameContinue = false;

			if (orcs.IsAlive()) {
				cout << endl << "----Orcs have won the war.----" << endl;
				orcs.Print();
			}
			else if (dwarves.IsAlive()) {
				cout << endl << "----Dwarves have won the war.----" << endl;
				dwarves.Print();
			}
			else if (elves.IsAlive()) {
				cout << endl << "----Elves have won the war.----" << endl;
				elves.Print();
			}
		}

		// If game ended since only one faction left alive print "Game ended!"
		if (numOfFactionsAlive == 1) cout << endl << "Game ended!";
		// Print end game status
		cout << endl << day << " days have passed." << endl;
		cout << merchant.GetRevenue() << " golds earned." << endl;

		if (playAgain && !gameContinue) { // Check if player wants to play the game again
			int replay;
			cout << endl << "If you want to play again, enter \"1\". Else, enter \"0\": ";
			cin >> replay;

			if (replay != 1) {
				playAgain = false;
			}
		}

	} while (playAgain);

	return 0;
}
