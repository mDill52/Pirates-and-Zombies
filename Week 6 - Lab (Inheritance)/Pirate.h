#pragma once

#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Pirate
{
protected:
	// attributes
	string name;
	static int numPirates;   // static or shared variable

public:
	// constructors and destructor
	Pirate();
	Pirate(string name);
	virtual ~Pirate();

	// behaviors
	virtual string toString();
	virtual string speak() = 0;   // pure virtual method -- abstract method
	
	// getters and setters
	string getName();
	void setName(string name);

	static int getNumPirates();	
};

