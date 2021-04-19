/*
Mark Dill
CIS247C
June 10, 2020
Week 6 Lab with Pirates
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>     // Sleep
#include "CaptainPirate.h"
#include "ZombiePirate.h"
using namespace std;

// prototypes
void displayPirate(Pirate* ptrPirate);

int main()
{
	// memory leak check  -- always do this if you use the new keyword
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif 

	// create a CaptainPirate object
	CaptainPirate capt1("RedBeard Rogers", "Chameleon");
	cout << capt1.toString() << endl;
	cout << "Number of Pirates so far: " << Pirate::getNumPirates() << endl;

	ZombiePirate zom1("Dead Shanks", 0);
	cout << zom1.toString() << endl;
	cout << "Number of Pirates so far: " << Pirate::getNumPirates() << endl;

	// compare the size of a pirate object with a pirate pointer
	cout << "\nSize of CaptainPirate: " << sizeof(capt1) << endl;
	cout << "Size of pointer: " << sizeof(&capt1) << endl;
	cout << endl;

	// create an array of Pirate pointers
	// and load child objects into the parent references (polmorphism)
	Pirate* pirates[3];
	pirates[0] = new CaptainPirate("GruffBeard", "Guinea Pig");
	pirates[1] = new CaptainPirate("Jack Sparrow", "Compass");
	pirates[2] = new ZombiePirate("Warm Meat Murray", 0);

	// display the pirates' information using a single method
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		displayPirate(pirates[i]);
	}

	// show the number of Pirates objects
	cout << "\nNumber of Pirate objects: " << Pirate::getNumPirates() << endl;
	// make the pirates speak using the polymorphic methods
	for (int i = 0; i < 2; i++)
	{
		cout << "\n" << pirates[i]->getName() + ":" << pirates[i]->speak() << endl;	
	}

	// lets have fun with the ZombiePirate
	cout << endl;
	cout << "Zombie Pirate Hunger Levels" << endl;
	cout << "---------------------------" << endl;

	for (int i = 0; i < 6; i++)
	{
		ZombiePirate* zp = dynamic_cast<ZombiePirate*>(pirates[2]);
		cout << "\nHunger Level: " << zp->getBrainHunger() << endl;
		cout << zp->speak() << endl;
		cout << endl;
		
		// increase the brain hunger
		zp->setBrainHunger(zp->getBrainHunger() + 1);

		// eats a brain at 5 level
		if (zp->getBrainHunger() >= 5)
		{
			cout << "\nThe Zombie ate a brain and became satisfied." << endl;
			//cout << endl;
			zp->setBrainHunger(0);
		}
		
		// pause 
		Sleep(2000);    // number of milliseconds
	}
	// clean the memory
	for  (int i = 0; i < 3; i++)
	{
		delete pirates[i];
	}
	//pause 
	cout << endl;
	system("pause");

	return 0;
}

void displayPirate(Pirate* ptrPirate)
{
	// show the parent stuff
	cout << "Name: " << ptrPirate->getName() << endl;

	// show the child stuff
	CaptainPirate* cp = dynamic_cast<CaptainPirate*>(ptrPirate);
	if (cp != nullptr)
	{
		cout << "\tPet: " << cp->getPet() << endl;
	}

	ZombiePirate* zp = dynamic_cast<ZombiePirate*>(ptrPirate);
	if (zp != nullptr)
	{
		cout << "\tBrain Hunger Level: " << zp->getBrainHunger() << endl;
	}
	// blank line
	cout << endl;
}
