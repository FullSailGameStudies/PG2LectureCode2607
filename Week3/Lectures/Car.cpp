#include "Car.h"


//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


//non-static methods:
//  there is a hidden field called 'this'
//  'this' is a pointer to the object the method was called on
//	can access non-static AND static members
std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}
