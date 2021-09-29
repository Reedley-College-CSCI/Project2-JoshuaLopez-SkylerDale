#ifndef PROJECT_H
#define PROJECT_H


class Person
{
protected:
	std::string player;
	std::string position;
	std::string height;
	std::string gender;
	std::string weight;
	std::string name;
	int size, age;
public:

	void display();
	void displayDodgersText();
	void addPlayer();
	void deletePlayer();
};
#endif