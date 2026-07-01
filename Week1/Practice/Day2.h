#pragma once
#include <vector>
#include "Target.h"
#include "Map.h"
#include "Zombie.h"
#include "Player.h"

class Day2
{
public:

	void PartB(int option = 1);

	const std::string& NameOfDay() { return nameOfDay; }
private:
	std::string nameOfDay;
	//
	// Part B-1.1: Add a method declaration for SpawnZombies
	//
	void SpawnZombies(PG2Graphics& engine, std::vector<Zombie>& mobs,const Player& p1) const;

	//
	// Part B-2.1: Add a method declaration for RenderZombies
	//
	void RenderZombies(const std::vector<Zombie>& mobs) const;

	//
	// Part B-3.1: Add a method declaration for KillZombies
	//
	int KillZombies(std::vector<Zombie>& mobs,const Player& p1) const;
};

