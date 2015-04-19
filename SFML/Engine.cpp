#include "Engine.h"
#include<iostream>

Engine::Engine(sf::RenderWindow &win)
{
}


Engine::~Engine(void)
{
}
void Engine::runEngine(RenderWindow &window)
{
	bool menu = false;
	float t = 0;
	Clock clock;
	Player player;	Background background;
	Obstacle obstacle;
	while (!menu)
	{
			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();

			player.update(delta);

			window.clear(Color(0,240,255));
			background.draw(window);
			window.draw(obstacle);
			window.draw(player);
			window.display();
	}
}
