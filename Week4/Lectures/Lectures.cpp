#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream> //for ofstream and ifstream
#include "Player.h"
#include <sstream>//for stringstream

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
	std::string path = "";// "C:/temp/2607/";
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
		outFile << 4.2 << delimiter << "true" << delimiter << 13 << "\n";
		outFile << "Aquaman smells.";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) CLOSE the file
	outFile.close();


	//READING csv data
	//1) open the file
	//	std::ifstream - 'i' input
	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//2) reading the file
		std::string line;
		//reads the stream until it reaches
		// a '\n' OR the end of the stream
		std::getline(inFile, line);
		std::cout << line << "\n";

		//read the next line
		std::getline(inFile, line);
		std::cout << line << "\n";
		//PARSE the line
		//  read the data from the string
		//convert the line string into a stream
		std::stringstream lineStream(line);
		std::string data;
		//reads until it reaches a delimiter
		//OR the end of the stream
		std::getline(lineStream, data, delimiter);
		//convert the string to the proper type
		double dVal = std::stod(data);
		std::cout << dVal << "\n";

		//try-catch
		//after the try block, add at least 1 catch block
		//to handle the possible exceptions
		//don't put try-catches everywhere
		//it is somewhat 'expensive'
		std::getline(lineStream, data, delimiter);
		try
		{
			//put the code that MIGHT throw an exception
			//into a 'try' block
			bool bVal = std::stoi(data);
			std::cout << bVal << "\n";
		}
		//put the more SPECIFIC exceptions first
		//followed by the more GENERAL exceptions
		catch (const std::exception& ex)
		{
			std::cout << "Error parsing data: " << data << "\n";
			std::cout << ex.what() << "\n";
		}

		std::getline(lineStream, data, delimiter);
		int iVal = std::stoi(data);
		std::cout << iVal << "\n";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) CLOSE the file
	inFile.close();


	Player p1;
	//1) open the file
	finalPath = path + "player.csv";
	std::ofstream playerFile(finalPath);
	if (playerFile.is_open())
	{
		p1.SerializeCSV(playerFile, delimiter);
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) CLOSE the file
	playerFile.close();


	std::ifstream inPlayerFile(finalPath);
	if (inPlayerFile.is_open())
	{
		std::string playerLine;
		std::getline(inPlayerFile, playerLine);
		//2 approaches:
		//initialize an existing object
		p1.DeserializeCSV(playerLine, delimiter);

		//OR, initialize a new Player object
		Player p2(playerLine, delimiter);
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) CLOSE the file
	inPlayerFile.close();

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