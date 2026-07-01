#include "Day2.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"

//
// Part B-1.1: Add a method definition for SpawnZombies
//
void Day2::SpawnZombies(PG2Graphics& engine, std::vector<Zombie>& mobs, const Player& p1) const
{
	int x, y;
	int px = p1.GetXPosition();
	int py = p1.GetYPosition();
	for (int i = 0; i < 5; i++)
	{
		do
		{
			x = rand() % 10;
			y = rand() % 10;
		} while (x == px and y == py);

		Zombie zeek(&engine, 0.5f, x, y);
		mobs.push_back(zeek);
	}
}


//
// Part B-2.1: Add a method definition for RenderZombies
//
void Day2::RenderZombies(const std::vector<Zombie>& mobs) const
{
	for (const Zombie& zeek : mobs)
	{
		zeek.Render();
	}
}


//
// Part B-3.1: Add a method definition for EraseZombies
//
int Day2::KillZombies(std::vector<Zombie>& mobs, const Player& p1) const
{
	int x1, y1;
	int x2 = p1.GetXPosition();
	int y2 = p1.GetYPosition();
	int erased = 0;
	for (int i = 0; i < mobs.size();)
	{
		x1 = mobs[i].GetXPosition();
		y1 = mobs[i].GetYPosition();
		float dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if (dist < 4)
		{
			mobs.erase(mobs.begin() + i);
			erased++;
		}
		else {
			i++;
		}
	}
	return erased;
}



void Day2::PartB(int option)
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		float scale = 0.25f;
		Player player(&engine, scale, 4, 4);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};
			GameObject::SetMap(map.mapData, 10, 10);

			std::vector<Zombie> mobs;
			//
			// Part B-1.3 Call SpawnZombies
			//
			SpawnZombies(engine, mobs, player);

			bool quit = false;
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
					{
						quit = true;
					}
					else if (e.type == SDL_KEYUP && e.key.repeat == 0)
					{
						if (e.key.keysym.sym == SDLK_SPACE)
						{
							if (option == 3)
							{
								//
								// Part B-3.3 Call KillZombies
								//
								KillZombies(mobs, player);
							}
						}
						else if (e.key.keysym.sym == SDLK_r)
						{
							mobs.clear();
							//
							// Part B-1.3 Call SpawnZombies
							//
							SpawnZombies(engine, mobs, player);
						}
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();

				//
				// Part B-2.3 call RenderZombies
				//
				RenderZombies(mobs);


				player.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}

