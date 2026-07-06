#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

class SampleClass
{
public:
	//default parameter
	//default argument
	//optional parameter
	//optional argument
	static int DoIt(int num2,int num = 0)
	{
		std::cout << "Done it. " << num << "\n";
		return 5;
	}
	void PrintMe(const std::string& message)
	{
		std::cout << message;
	}

};

//pass by value (COPY)
// num is a new variable.
// it gets its value when the method is called
// that value is COPIED in to it

//pass by reference (ALIAS)
//WHEN?
//	1) the method needs to change the variable
//		in the other scope
//  2) we want to prevent a copy
//		criteria? if it's a class, pass by reference
void Incrementer(int& num)
{
	num++;
	std::cout << num << "\n";
}

const float PI = 3.1415;

void Info(const std::vector<int>& nums)
{
	//size() - # of items in the vector
	//capacity() - length of internal aray
	//size() <= capacity()
	std::cout << nums.size() << ": " << nums.capacity() << "\n";
}
int main(int argc, char* args[])
{
	SampleClass sample;
	sample.PrintMe("Hello Gotham!");

	SampleClass::DoIt(10);
	std::string myMalfunction = Input::GetString("What is your malfunction?");

	int number = 5, num2 = 15;
	int& numRef = number;//an alias to number
	numRef = 10;
	numRef = num2;
	Incrementer(number);
	std::cout << number << "\n";
	std::vector<int> nums;// { 1, 2, 3, 4, 5, 6, 6, 8, 6 };
	nums.resize(10);
	nums.reserve(10);//sets the capacity to 10
	Info(nums);//size = 0   capacity = 0
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
		Info(nums);
	}
	//remove 6 from nums
	//we need an iterator
	//an iterator is an object that points into the vector
	//it also knows how to move through the container
	//vector.begin() - iterator to the first item
	//vector.end() - iterator to the item AFTER the last item
	//vector.erase(iterator);
	nums.erase(nums.begin() + 5);

	for (int i = 0; i < nums.size();i++)
	{
		if (nums[i] == 6)
		{
			nums.erase(nums.begin() + i);
			i--;
		}
	}
	//OR...
	for (int i = 0; i < nums.size(); )
	{
		if (nums[i] == 6)
		{
			nums.erase(nums.begin() + i);			
		}
		else
		{
			i++;
		}
	}
	//OR...
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] == 6)
		{
			nums.erase(nums.begin() + i);
		}
	}

	for (std::vector<int>::iterator it = nums.begin(); it != nums.end() ; )
	{
		//* - "dereferences" the "pointer"
		//  give me what you're pointing to
		if (*it == 6)
		{
			it = nums.erase(it);
		}
		else {
			it++;
		}
	}

	//range-based for (foreach)
	for (int& n : nums)
	{
		std::cout << n << "\n";
	}


	Day2 day2;

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::WriteLine("Here is my message on one line.", ConsoleColor::Cyan);
			Console::Write("Here is my 2nd message on one line.", ConsoleColor::Cyan, ConsoleColor::Yellow);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			std::string name = Input::GetString("What is your name?");
			std::cout << "Your name is " << name << "?\n";
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			int age = Input::GetInteger("What is your age?", 1, 120);
			std::cout << "Your age is " << age << "? Weird.\n";
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

