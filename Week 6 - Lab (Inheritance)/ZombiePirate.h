#pragma once

#include "Pirate.h"

class ZombiePirate : public Pirate
{
private:
	// attributes
	short brainHunger;

public:
	// constructors and destructor
	ZombiePirate();
	ZombiePirate(string name, short brainHunger);
	virtual ~ZombiePirate();

	// behaviors
	string toString();
	string speak();

	// getters and setters
	short getBrainHunger();
	void setBrainHunger(short brainHunger);
};

