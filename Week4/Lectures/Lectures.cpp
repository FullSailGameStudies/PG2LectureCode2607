#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>

//
//3 basic steps for File I/O
//1) open the file
//		where is the file?
//		what mode to open it in? (text, binary, read, write, both, append)
//2) read/write to the file
//3) CLOSE the file
//		good programming practice: ASAP. 

int main(int argc, char* args[])
{
	// Write a CSV file
	//
	// 1) open the file
	//	  where the file is?
	//		path to the file
	//		- full paths
	//		- relative paths
	std::string path = "C:/temp/2607/";
	std::string fileName = "2607.csv";
	std::string finalPath = path + fileName;

	//write a csv file
	//use the ofstream class
	//  'o' stands for output (writing)
	// creates the file if it does not exists
	// overwrite if the file does exists
	// it will NOT create the path.
	//	the path MUST exists before trying to open the file.
	//1) open the file
	//		MUST check if it worked
	std::ofstream outFile(finalPath);
	char delimiter = '?';
	if (outFile.is_open())
	{
		//2) write to the file
		outFile << "Batman is the GOAT!\n";
		outFile << 4.2 << delimiter << true << delimiter << 13 << "\n";
		outFile << "Aquaman smells.";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) CLOSE the file
	outFile.close();

    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
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
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}