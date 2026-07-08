#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenToFind) const
{
	int index = NOT_FOUND;
	for (int i = 0; i < lights.size(); i++)
	{
		if (greenToFind == lights[i].green)
		{
			index = i;
			break;
		}
	}
    return index;
}
