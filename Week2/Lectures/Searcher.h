#pragma once
#include <vector>
#include "Light.h"

const int NOT_FOUND = -1;

class Searcher
{
public:
	//
	// Part B-1
	//
	/// <summary>
	/// Searches the vector using the linear search algorithm
	/// </summary>
	/// <param name="lights">the vector to search</param>
	/// <param name="greenToFind">the value to find</param>
	/// <returns>-1 if not found, the index if found</returns>
	int LinearSearch(const std::vector<Light>& lights, int greenToFind) const;
};

