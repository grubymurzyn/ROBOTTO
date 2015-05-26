#pragma once
#include "MapManager.h"

class Engine
{
public:
	Engine(sf::RenderWindow &win);
	~Engine(void);
	int runEngine(sf::RenderWindow &window);

private:
	Player player;
};

