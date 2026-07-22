#include "Player.h"
#include "Console.h"
#include <iomanip>
#include <sstream>

//
// Part B-1.2
//

//
// Part B-2.2
//

//this file should ONLY be responsible for 
//writing the data
//it should NOT open the file or close the file
void Player::SerializeCSV(std::ofstream& outFile, char delimiter)
{
	//step 2) write to the file
	outFile << name << delimiter << worldX << delimiter << worldY;
}

void Player::Info()
{
	Console::SetCursorPosition(0, 12);
	std::cout << "POSITION: " << std::setw(7) << std::right << worldX << "," << worldY;
}