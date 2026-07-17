#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Player.h>
#include <Color.h>
#include "Pistol.h"
#include "Knife.h"
#include <vector>


//overload on the types of the parameters
float Add(float n1, float n2)
{
	return n1 + n2;
}
int Add(int n1, int n2)
{
	return n1 + n2;
}
//overload on the # of parameters
int Add(int n1, int n2, int n3)
{
	return n1 + n2 + n3;
}


void Counter()
{
	static int count = 0;
	std::cout << count << " ";
	count++;
}
int main(int argc, char* args[])
{
	//for (int count = 0; count < 10; count++)
	//{
	//	Counter();
	//}

	//these are all stack variables
	int n2 = 10;
	int n = 5;
	int& nRef = n;
	nRef = n2;//only copies n2 to nRef (n)
	int* pNum;// = &n;
	pNum = &n2;//pNum now points to n2. points to a stack variable
	//modern C++ uses smart pointers (shared_ptr and unique_ptr)
	//*ptr means "dereference" the pointer
	//	go to the memory address and get the value
	std::cout << *pNum << "\n";

	Pistol* ptrGun = new Pistol(100, 50, 6, 15);
	Pistol pewpew(200, 100, 5, 15);
	Pistol p2(100, 50, 6, 15);
	Pistol p3 = pewpew + p2;

	ptrGun->showMe();
	delete ptrGun;
	ptrGun = nullptr;
	if (ptrGun != nullptr)
		ptrGun->showMe();

	//heap memory
	//separate section of computer memory
	//use '=new' operator to reserve space in the heap
	{
		int* pNum2;//pNum2 is a stack variable
		pNum2 = new int(25);//points pNum2 to HEAP memory
		//shallow copy (only copying memory locations)
		int* pNum3 = pNum2;//2 variables now point to 25
		//MUST delete it
		delete pNum2;
	}//pNum2 is removed from the stack
	//heap memory can last longer than a method call
	//heap memory is allocated UNTIL you delete it
	//you MUST delete heap memory when you're done with it
	//it does not happen automatically!!!!!!

	//to leak memory means it can't be cleaned up

	Pistol* pGun = &p3;//& on the right-hand side means "address-of"
	pGun->showMe();//use the '->' notation for pts to class objects
	(*pGun).showMe();

	//cannot create objects of abstract base class types
	//Weapon wpn(50, 100);
	//wpn.showMe();
	pewpew.showMe();

	int sum = Add(5, 2);
	sum = Add(5, 2, 7);
	sum = Add(5.0f, 4.1f);

	Color clr;
	clr.red = 255;
	clr.green = clr.blue = 0;
	clr.alpha = 255;

	{
		Player p1;//calling the default ctor
		p1.SetGamerTag("BWayne173");
		p1.Level(1);
		std::cout << p1.GetGamerTag() << " " << p1.Level() << "\n";
	}//the destructor of p1 will be called when it goes out of scope

	Player* player2 = new Player();
	delete player2;//the destructor will be called

	std::string hello = "Hello Week 3!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	//UPCASTING:
	//	cast the pointer from the DERIVED type (Pistol or Knife)
	//  to the BASE type (Weapon)
	//  ALWAYS safe
	{
		std::vector<Weapon*> inventory;//stores memory locations
		Knife stabby(3, 10, true);
		inventory.push_back(new Pistol(100, 50, 6, 15));//copies the address-of pistol to a weapon pointer
		inventory.push_back(new Knife(3, 10, true));
		std::cout << "\n\nJohn Wick's Inventory:\n";
		for (auto& wpn : inventory)
		{
			wpn->showMe();//runtime polymorphism here!!
		}

		//delete all of the heap weapons
		for (int i = 0; i < inventory.size(); i++)
		{
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}//inventory goes out of scope


	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}