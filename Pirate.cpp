#include "Pirate.h"

// initialize your static variables here
int Pirate::numPirates = 0;   // static or shared variable

Pirate::Pirate()
{
	name = "unknown";

	numPirates++;   // increment the count
}

Pirate::Pirate(string name)
{
	setName(name);

	numPirates++;
}

Pirate::~Pirate()
{
	numPirates--;   // decrement the count
}

string Pirate::toString()
{
	return "\nName: " + name;
}

string Pirate::getName()
{
	return name;
}

void Pirate::setName(string name)
{
	if (name.length() > 0)
		this->name = name;
	else
		this->name = "unknown";
}

int Pirate::getNumPirates()
{
	return numPirates;
}
