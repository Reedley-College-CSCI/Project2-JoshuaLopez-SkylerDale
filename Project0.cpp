//Group: Joshua Lopez, Skyler Dale
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Project.h"
#include "Projectp2.h"
#include "Projectp3.h"
using namespace std;


int main()
{
	Person info;
	Manager playerInfo;
	HitBatting stats;
	
	int choice;

	do
	{
		//Displaying players and giving user choice
		playerInfo.display();
		cout << "Enter the number: ";
		cin >> choice;
		while (choice < 1 || choice >6)
		{
			cout << "Please enter a number within the range of choices!" << endl;
			info.display();
			cin >> choice;
		}
			switch (choice)
			{
			case 1:
			{
				cout << "You are viewing the players on the Dodgers team." << endl;
				//Displaying names on text file
				info.displayDodgersText();
				break;
			}
			case 2:
			{
				cout << "You have selected to add a new player!" << endl;

				//Adding player to text file
				info.addPlayer();

				break;
			}
			case 3:
			{
				cout << "You have selected to remove a player!" << endl;
				cout << "Here are the players on team!" << endl;
				info.displayDodgersText();
				//Removing a player from the text file
				info.deletePlayer();
				break;
			}
			case 4:
			{
				cout << "Welcome to the Dodgers Recruitment Page!" << endl; 
				playerInfo.managerPassword();
				break;
			}
			case 5:
			{
				cout << "Welcome to the Batting Statistics Library!" << endl;
				stats.displayFile();
				break;
			}
			case 6:
			{
				//Ending program
				cout << "Good Bye!";
				break;
			}
			}
	} while (choice != 6);

	return 0;
}