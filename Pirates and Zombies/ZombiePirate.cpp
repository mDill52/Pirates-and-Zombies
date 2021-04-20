#include "ZombiePirate.h"

ZombiePirate::ZombiePirate() : Pirate()
{
    brainHunger = 0;
}

ZombiePirate::ZombiePirate(string name, short brainHunger) : Pirate (name)
{
    setBrainHunger(brainHunger);
}

ZombiePirate::~ZombiePirate()
{
    // nothing to destroy
}

string ZombiePirate::toString()
{
    return Pirate::toString() + " Brain Hunger= " + to_string(brainHunger);
}

string ZombiePirate::speak()
{
    // Hunger levels
    switch (brainHunger)
    {
    case 0:
        return "Just ate a brain, gonna wander for a bit.";
        break;
    case 1:
        return "Getting a little hungry....Need to start looking for brains.";
        break;
    case 2:
    case 3:  return "Getting very hungry...need a brain ASAP";
        break;
    case 4:
    case 5:
        return "BRAINS!!! NEED BRAINS NOW!!!" " GGRRRGUHGHG.....";
        break;
    default:
        return "Error, Something went wrong.";
        break;
    }
}

    short ZombiePirate::getBrainHunger()
{
    return brainHunger;
}

void ZombiePirate::setBrainHunger(short brainHunger)
{
    if (brainHunger < 0)
        this->brainHunger = 0;
    else if (brainHunger >= 0 && brainHunger <= 5)
        this->brainHunger = brainHunger;
    else
        this->brainHunger = 5;
}
