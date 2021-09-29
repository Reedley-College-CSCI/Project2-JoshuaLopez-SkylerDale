#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib> //Used to access the exit function, line 62
#include "Project.h"
#include "Projectp2.h"
using namespace std;

void Manager::setHeight(std::string setHe)
{
	height = setHe;
}

void Manager::setGender(std::string setGe)
{
	gender = setGe;
}

void Manager::setWeight(std::string setWe)
{
	weight = setWe;
}

void Manager::setDescription(std::string setDe)
{
	playerDescription = setDe;
}

void Manager::setName(std::string setNe)
{
	name = setNe;
}

std::string Manager::getHeight()
{
	return height;
}

std::string Manager::getGender()
{
	return gender;
}

std::string Manager::getWeight()
{
	return weight;
}

std::string Manager::getPassword()
{
	return password;
}

std::string Manager::getDescription()
{
	return playerDescription;
}

std::string Manager::getName()
{
	return name;
}

//Password will be provided for now
//Only the manager will have access to this data
//The manager will type in the information of the player info for future consideration to be a part of the franchise
void Manager::managerPassword()
{
	string input;
	cout << "Enter the manager's password!'" << getPassword() << "'" << endl;
	cout << "Enter the letter F if you would also like to exit the program: ";
	cin >> input;

		while (input != password)
		{
			if(input == "f" || input == "F")
			{
				exit(EXIT_SUCCESS);
			}
			cout << "Try again! Or enter F to exit the program: ";
			cin >> input;
		}
	
	string * name, * height, * gender, * weight, *playerDescription;
	const int size = 1;
	fstream outputFile("dodgersRecruitment.txt", ios::out | ios::app);
	
	name = new string[size];
	height = new string[size];
	gender = new string[size];
	weight = new string[size];
	playerDescription = new string[size];

	for (int count = 0; count < size; count++)
	{
		cout << "Enter his name: ";
		cin.ignore();
		getline(cin, name[count]);
		setName(name[count]);

		cout << "Enter his height: ";
		getline(cin, height[count]);
		setHeight(height[count]);

		cout << "Enter his gender: ";
		getline(cin, gender[count]);
		setGender(gender[count]);

		cout << "Enter his weight: ";
		getline(cin,weight[count]);
		setWeight(weight[count]);

		cout << "Enter his experience: ";
		getline(cin,playerDescription[count]);
		setDescription(playerDescription[count]);
	}
	
	for (int count = 0; count < size; count++)
	{
		outputFile << "Name: " << getName() << endl;
		outputFile << "Height: " << getHeight() << endl;
		outputFile << "Gender: " << getGender() << endl;
		outputFile << "Weight: " << getWeight() << endl;
		outputFile << "Description: " << getDescription() << endl;
		outputFile << endl;
	}

	delete[]name;
	delete[]height;
	delete[]gender;
	delete[]weight;
	delete[]playerDescription;
	outputFile.close();
}
/*
				*****updated*****
		Adding player only option
		Overriding display function 
*/
void Manager::display()
{
	cout << "------------------------" << endl;
	cout << "Menu Selection" << endl;
	cout << "1. View Players." << endl;
	cout << "2. Add Player." << endl;
	cout << "3. Remove Player." << endl;
	cout << "4. Manager ONLY option." << endl;
	cout << "5. Batting Statistics Library" << endl;
	cout << "6. Quit application." << endl;
	cout << "------------------------" << endl;
}