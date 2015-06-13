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
	Player *player = new Player();
	Monsters *monsters = new Monsters;
	MapManager *map = new MapManager(1);
	Text score ("WYNIK: 0",font,40);
	score.setColor(Color::Red);
	while (!menu)
	{		
		//cout <<"X: "<<player->getPosition().x << endl;
		//cout <<"Y: "<<player->getPosition().y << endl;
			//KROK CZASOWY
			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();
			//PORUSZANIE MAPY
			map->moveCamera(*player,delta);
			window.setView(map->getCamera());

			//UPDATE MAPY WRAZ Z PRZEMIESZCZANIEM WYNIKU
			map->updateMap(*player); 
			score.setPosition(map->getCamera().getCenter().x + 450, 10);
			ostringstream ss;
			ss << map->getScore()+monsters->getPointsForMonsters();
			string wynik = ss.str();
			score.setString("WYNIK :" + wynik);

			// UPDATE GRACZA I  POTWOROW
			player->update(delta, map->getObstacles(),window);
			monsters->update(delta, window,player->getSprite());


			window.clear(Color(181,181,181));
			
			// RYSOWANIE OBIEKTOW GRY
			monsters->drawMonsters(window);
			window.draw(*player);
			map->drawMap(window, player);
			window.draw(score);
			window.display();

			// SPRAWDZENIE CZY GRA ZOSTALA ZAKONOCZONA GDY SPADL GRACZ || DOSZEDL DO KONCA MAPY || NATRAFIL NA POTWORA
			if (player->getGlobalBounds().top > 850 || player->getGlobalBounds().left > 11000 || monsters->killPlayer(player->getSprite())){
				menu = true;
				delete(player);
				delete(monsters);
				int a = map->getScore();
				delete(map);
				return a;
			}
	}
}
