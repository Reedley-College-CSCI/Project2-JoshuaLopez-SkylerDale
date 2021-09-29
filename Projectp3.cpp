#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Project.h"
#include "Projectp2.h"
#include "Projectp3.h"
using namespace std;

HitBatting::HitBatting()
{
	size = 0;
	string numbers;
	inputFile.open("dodgersHittingStats.txt", ios::in);


	while (!inputFile.eof())
	{
		getline(inputFile, numbers);
		size++;
	}
	size = size / 3;
	playerBatting = new HitStats[size];

	inputFile.close();
}
void HitBatting::readFile()
{
	inputFile.open("dodgersHittingStats.txt", ios::in);
	for (int count = 0; count < size; count++)
	{
		getline(inputFile, playerBatting[count].name);
		inputFile >> playerBatting[count].hits;
		inputFile >> playerBatting[count].hr;
		inputFile.ignore();
	}
	inputFile.close();
}
void HitBatting::addingPlayer()
{
	string* name;
	int* hits, * hr, arraySize, choice;

	outputFile.open("dodgersHittingStats.txt", ios::out);

	cout << "How many players would you like to add?: ";
	cin >> arraySize;

	while (arraySize < 0)
	{
		cout << "Please enter a positive number." << endl;
		cin >> arraySize;
	}

	name = new string[arraySize];
	hits = new int[arraySize];
	hr = new int[arraySize];


	HitStats* newPlayerBatting = new HitStats[size + arraySize];
	for (int count = 0; count < size; count++)
	{
		newPlayerBatting[count] = playerBatting[count];
	}

	for (int count = size; count < size + arraySize; count++)
	{
		cout << "Name: ";
		cin.ignore();
		getline(cin, newPlayerBatting[count].name);

		cout << "Hits: ";
		cin >> newPlayerBatting[count].hits;

		cout << "Home Runs: ";
		cin >> newPlayerBatting[count].hr;
	}

	playerBatting = newPlayerBatting;
	size = size + arraySize;

	for (int count = 0; count < size; count++)
	{
		outputFile << playerBatting[count].name << endl;
		outputFile << playerBatting[count].hits << endl;
		outputFile << playerBatting[count].hr << endl;
	}

	delete[]name;
	delete[]hits;
	delete[]hr;
	outputFile.close();
}
void HitBatting::removePlayer()
{
	string deleteName, readLine;

	cin.ignore(55, '\n');
	outputFile.open("dodgersHittingStats.txt", ios::out);

	cout << "Which player would you like to delete? Type in the full name: ";
	getline(cin, deleteName);

	HitStats* newPlayerBatting = new HitStats[size - 1];
	for (int count = 0; count < size; count++)
	{
		if (playerBatting[count].name != deleteName)
		{
			newPlayerBatting[count] = playerBatting[count];
		}
	}
	playerBatting = newPlayerBatting;
	size--;
	//while loops reads each line until it reaches the end of the file
	//If line user inputed is read it will get that line and the next two and not output them into new file

	for (int count = 0; count < size; count++)
	{
		outputFile << playerBatting[count].name << endl;
		outputFile << playerBatting[count].hits << endl;
		outputFile << playerBatting[count].hr << endl;
	}

	outputFile.close();
}
void HitBatting::displayFile()
{
	{
		readFile();
		int choice;
		cout << setprecision(2) << fixed << showpoint;
		for (int count = 0; count < size; count++)
		{
			cout << "Name: " << playerBatting[count].name << endl;
			cout << "Hits: " << playerBatting[count].hits << endl;
			cout << "Home Runs: " << playerBatting[count].hr << endl;
			playerBatting[count].battingAvg = static_cast<float>(playerBatting[count].hits) / static_cast<float>(playerBatting[count].hr);
			cout << "Batting Average: " << playerBatting[count].battingAvg << endl;
		}
		cout << "Would you like to add a player? Enter 0 if no, Enter 1 if yes. ";
		cin >> choice;

		while (choice < 0 || choice > 1)
		{
			cout << "Enter the value 1 or 0" << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			addingPlayer();
		}


		cout << "Would you like to remove a player? Type in 1 if yes or 0 if no. ";
		cin >> choice;
		if (choice == 1)
		{
			removePlayer();
		}

	}
}