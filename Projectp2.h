#ifndef PROJECTP2_H
#define PROJECTP2_H
#include <string>
//Class Manager is inheriting from the base class, Class Person
class Manager : public Person
{
private:

	std::string playerDescription;
	std::string password = "1111";

public:

	void setHeight(std::string);
	void setGender(std::string);
	void setWeight(std::string);
	void setDescription(std::string);
	void setName(std::string);
	std::string getPassword();
	std::string getHeight();
	std::string getGender();
	std::string getWeight();
	std::string getDescription();
	std::string getName();
	void managerPassword();
	void display(); //overriding
};

#endif