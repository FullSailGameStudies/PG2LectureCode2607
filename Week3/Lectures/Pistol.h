#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int rounds, int magCap) :
		//call the base class ctor
		Weapon(range,damage),
		mRounds(rounds), 
		mMagCap(magCap)
	{
		//do NOT duplicate what the base ctor does
	}


	int Rounds() const { return mRounds; }
	int MagCapacity() const { return mMagCap; }

	void Rounds(int rounds)
	{
		if (rounds <= mMagCap)
			mRounds = rounds;
	}
	void MagCapacity(int magCap)
	{
		if (magCap > 0 && magCap <= 32)
			mMagCap = magCap;
	}


private:
	int mRounds, mMagCap;
};

