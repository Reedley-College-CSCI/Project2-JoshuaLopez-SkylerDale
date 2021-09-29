#ifndef PROJECTP3_H
#define PROJECTP3_H
#include <string>
#include <fstream>
using namespace std;

class HitBatting
{
private:
	int size;
	fstream inputFile;
	fstream outputFile;

	//Declaring struct HitStats
	struct HitStats
	{
		string name;
		int hits = 0;
		int hr = 0;
		float battingAvg = 0.0;
	};
	HitStats* playerBatting;


public:
	//The HitBatting() Constructor opens the file, counts how many lines of text there is and divides it by 3
	//To grab the "size" of the dynamic array, also is implemented inside our for loops
	HitBatting();

	//Reading inside the file 
	void readFile();

	//Giving the user an option to add a player
	void addingPlayer();

	//Giving the user an option to remove a player
	void removePlayer();

	//Displaying the file and also dividing the two integers by making them float data types to get a decimal value
	void displayFile();
};

#endif
