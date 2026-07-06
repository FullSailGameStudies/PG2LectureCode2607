#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>

//there are AT LEAST 2 loops in a recursive loop
//- going "out" loop
//- coming "back" loop (unwinding the stack)
void DoIt(int i)
{
	//ALL recursive loops REQUIRE an exit condition (or base case)
	if(i < 10) //loop while i < 10
	{
		std::cout << i << " ";
		DoIt(i + 1);//recursive case
		std::cout << i << " ";
	}
}//ends the method

int main(int argc, char* args[])
{
	//2 kinds of loops:
	//   determinate loops (you know how many times it will loop)
	// indeterminate loops (you don't how many times it will loop)
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 1) 
			continue;//jump to the '}' of the loop
		std::cout << i;
		
		if (i == 5)
		{
			break;//exits the loop early
		}
		//DoIt(i);
	}
	srand(static_cast<unsigned int>(time(NULL)));
	DoIt(0);

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}