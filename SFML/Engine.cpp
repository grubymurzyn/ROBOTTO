#include "Engine.h"

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
	Player player;
	MapManager map(1);
	while (!menu)
	{
			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();

			player.update(delta,map.getMapObjects());

			map.moveCamera(player,delta);
			window.setView(map.getCamera());
			map.updateMap();
			window.clear(Color(0,240,255));
			window.draw(player);
			map.drawMap(window);
			window.display();
	}
}
