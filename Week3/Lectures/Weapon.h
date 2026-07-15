#pragma once
class Weapon
{
protected:
	int mRange;
	int mDamage;

public:
	
	Weapon(int range, int damage);

	//overriding:
	//step 1: mark the BASE method as 'virtual'
	//	this tells the compiler it MIGHT be overridden by a derived class
	virtual void showMe();


	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

