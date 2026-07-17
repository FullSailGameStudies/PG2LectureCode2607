#pragma once
class Weapon
{
protected:
	int mRange;
	int mDamage;

public:
	
	Weapon(int range, int damage);
	virtual ~Weapon() = default;

	//overriding:
	//step 1: mark the BASE method as 'virtual'
	//	this tells the compiler it MIGHT be overridden by a derived class
	virtual void showMe();


	//make this a PURE virtual function
	//1) mark it as 'virtual'
	//2) assign it a value of 0
	//every class that inherits from Weapon and that 
	//does NOT override calcDamage will ALSO be abstract
	virtual int calcDamage() = 0;

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

