#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	//EXTENSION override (call the base)
	Weapon::showMe();
	std::cout << "\t Is Serrated? ";
	std::cout << ((mIsSerrated) ? "true" : "false") << "\n";
}

int Knife::calcDamage()
{
	return Weapon::calcDamage();
}
