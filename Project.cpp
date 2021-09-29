#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Project.h"
#include "Projectp2.h"
using namespace std;

void Person::display() // Displaying the menu to the user.
{
	cout << "------------------------" << endl;
	cout << "Menu Selection" << endl;
	cout << "1. View Players." << endl;
	cout << "2. Add Player." << endl;
	cout << "3. Remove Player." << endl;
	cout << "4. Quit application." << endl;
	cout << "------------------------" << endl;
}

void Person::displayDodgersText() // Displaying the players from the text
{
	string names;
	fstream inputFile("dodgersStats.txt", ios::in);

	while (inputFile >> names)
	{
		getline(inputFile, names);
		cout << names << endl;
	}

	
	inputFile.close();
}

void Person::addPlayer() // Adding players to the text
{
	string* player, * position;
	int size, *age;
	fstream outputFile("dodgersStats.txt", ios::out | ios::app);
	
	
	cout << "How many players would you like to add?: ";
	cin >> size;

		while (size < 0)
		{
			cout << "Please enter a positive number." << endl;
			cin >> size;
		}

	position = new string[size];
	player = new string[size];
	age = new int[size];
	


	for (int count = 0; count < size; count++)
	{
		cout << "Name: ";
		cin.ignore();
		getline(cin, player[count]);
		
		cout << "Positon i.e(C = cather, P = Pitcher): ";
		getline(cin, position[count]);
		
		cout << "Age: ";
		cin >> age[count];
	}

	for (int count = 0; count < size; count++)
	{
		outputFile << endl;
		outputFile << "Name: " << player[count] << endl;
		outputFile << "Pos: " << position[count] << endl;
		outputFile << "Age: " << age[count] << endl;
	}

	delete[]position;
	delete[]player;
	delete[]age;
	outputFile.close();
}


void Person::deletePlayer() //Deleting sentences/name inside the text File that has been typed.
{
	string deleteName, readLine;

	cin.ignore(55, '\n');
	fstream inputFile("dodgersStats.txt", ios::in);
	fstream outputFile("newDodgersStats.txt", ios::out);

	cout << "Which player would you like to delete? Type in the full name: ";
	getline(cin, deleteName);

	//while loops reads each line until it reaches the end of the file
	//If line user inputed is read it will get that line and the next two and not output them into new file
	while (!inputFile.eof())
	{
		getline(inputFile, readLine);
		if (readLine != "Name: " + deleteName)
		{
			outputFile << readLine << endl;
		}
		else
		{
			getline(inputFile, readLine);
			getline(inputFile, readLine);
		}
	}
	

	inputFile.close();
	outputFile.close();
	
	// deleting original file to rename text document
	remove("dodgersStats.txt");
	//renaming a new text document
	rename("newDodgersStats.txt", "dodgersStats.txt");
}