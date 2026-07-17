#include "Player.h"

//use a member initialization list to set the fields
//member initialization lists are preferred
Player::Player(const std::string& tag, int level, int health) :
	gamerTag_(tag), 
	level_(level),
	health_(health),
	name_(nullptr)
{
	//gamerTag_ = tag;//gamerTag_ will be initialized twice
	health = health_;//backwards

	name_ = new std::string("Bruce Wayne");
}
