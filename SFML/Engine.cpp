#include "Engine.h"

Engine::Engine(sf::RenderWindow &win)
{
}


Engine::~Engine(void)
{
}
int Engine::runEngine(RenderWindow &window,Font font)
{
	bool menu = false;
	float t = 0;
	Clock clock;
	Player player;
	MapManager map(1);
	Text score ("WYNIK: 0",font,40);
	score.setColor(Color::Red);
	while (!menu)
	{
			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();
			map.moveCamera(player,delta);
			window.setView(map.getCamera());
			map.updateMap(player); 
			score.setPosition(map.getCamera().getCenter().x + 450, 10);
			ostringstream ss;
			ss << map.getScore();
			string wynik = ss.str();
			score.setString("WYNIK :" + wynik);

			player.update(delta, map.getObstacles(),window);
			window.clear(Color(181,181,181));
			window.draw(player);
			map.drawMap(window,&player);
			window.draw(score);
			window.display();
			if (player.getGlobalBounds().top > 850 || player.getGlobalBounds().left > 11000){
				menu = true;
				return map.getScore();
			}
	}
}
