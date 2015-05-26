#include "Engine.h"

Engine::Engine(sf::RenderWindow &win)
{
}


Engine::~Engine(void)
{
}
int Engine::runEngine(RenderWindow &window)
{
	bool menu = false;
	float t = 0;
	Clock clock;
	Player player;
	MapManager map(1);
	while (!menu)
	{
			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();
			map.moveCamera(player,delta);
			window.setView(map.getCamera());
			map.updateMap(player); 
			player.update(delta, map.getObstacles(),window);
			window.clear(Color(181,181,181));
			window.draw(player);
			map.drawMap(window,&player);
			window.display();
			if (player.getGlobalBounds().top > 850 || player.getGlobalBounds().left > 11000){
				menu = true;
				return map.getScore();
			}
	}
}
