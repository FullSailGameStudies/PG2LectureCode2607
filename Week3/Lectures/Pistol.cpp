#include "Pistol.h"
#include <iostream>

//overriding:
//step 3: create the new definition
void Pistol::showMe()
{
	//WAYS to override:
	//1) FULL override
	//		we ONLY want the child behavior
	//		do NOT call the base method
	//2) EXTENSION override
	//		we want the base + child behavior
	//		call the base method

	Weapon::showMe();//call the base method
	std::cout << "\tRounds: " << mRounds << "\tMagazine Capacity: " << mMagCap << "\n";
}
