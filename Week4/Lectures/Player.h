#pragma once
#include <fstream>
#include <string>

class Player
{
public:

	Player() : worldX(0), worldY(0), name("Bruce") {}

	//
	// Part B-1.1
	//

	//
	// Part B-2.1
	//
	
	//
	// Part B-2.3
	//

	//Serializing: 
	//	saving the state of the object
	//  serialize to a file, to memory, to another process...
	void SerializeCSV(std::ofstream& outFile, char delimiter);

	//Deserializing
	//   loading the state of the object
	//	doesn't care where the data is coming from
	//  doesn't need to know where
	//  it just needs to csv data
	void DeserializeCSV(const std::string& csvData, char delimiter);

	Player(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}

	void MoveLeft() { worldX--; }
	void MoveRight() { worldX++; }
	void MoveUp() { worldY--; }
	void MoveDown() { worldY++; }

	void GetPosition(int& x, int& y)
	{
		x = worldX;
		y = worldY;
	}

	void Info();
private:
	std::string name;
	int worldX, worldY;
};

