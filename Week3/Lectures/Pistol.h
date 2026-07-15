#pragma once
#include "Weapon.h"
#include <algorithm>
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int rounds, int magCap) :
		//call the base class ctor
		Weapon(range, damage),
		mRounds(rounds),
		mMagCap(magCap)
	{
		//do NOT duplicate what the base ctor does
	}

	Pistol operator+(const Pistol& other)
	{
		Pistol newPistol(mRange, mDamage,
			mRounds + other.mRounds,
			std::max(mMagCap, other.mMagCap));
		return newPistol;
	}

	//overriding:
	//step 2: add a new method to the child class with the SAME signature as the
	//	base method
	//optional: add the 'override' keyword so the compiler
	//	ensures that it is an actual override
	void showMe() override;

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

