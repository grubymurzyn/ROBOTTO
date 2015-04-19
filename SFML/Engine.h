#pragma once
#include "Player.h"
#include"Background.h"

class Engine
{
public:
	Engine(sf::RenderWindow &win);
	~Engine(void);

	void runEngine(sf::RenderWindow &window);

private:
	Player player;
};

