#include "CaptainPirate.h"

CaptainPirate::CaptainPirate() : Pirate()
{
	pet = "unknown";
}

CaptainPirate::CaptainPirate(string name, string pet) : Pirate(name)
{
	setPet(pet);
}

CaptainPirate::~CaptainPirate()
{
	// nothing to destroy
}

string CaptainPirate::speak()
{
	return "\nYaaarr! This be my pet " + pet + ", savvy! \nWhy is the Rum gone?? Yo ho ho and really bad eggs!";
}

string CaptainPirate::toString()
{
	return Pirate::toString() + ", Pet: " + pet;
}

string CaptainPirate::getPet()
{
	return pet;
}

void CaptainPirate::setPet(string pet)
{
	if (pet.length() > 0)
		this->pet = pet;
	else
		this->pet = "unknown";
}
