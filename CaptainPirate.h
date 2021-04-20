#pragma once

#include "Pirate.h"

class CaptainPirate : public Pirate
{
private:
	// attributes
	string pet;

public:
	// constructor and destructor
	CaptainPirate();
	CaptainPirate(string name, string pet);
    ~CaptainPirate();

	// behaviors
	string toString();
	string speak();

	// getters and setters
	string getPet();
	void setPet(string pet);
};

