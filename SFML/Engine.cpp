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
	RectangleShape rect,rect2,rect3;
	rect.setFillColor(Color::Black);
	rect2.setFillColor(Color::Black);
	rect3.setFillColor(Color::Black);
	rect.setPosition(Vector2f(500, 200));
	rect2.setPosition(Vector2f(200, 300));
	rect3.setPosition(Vector2f(100, 100));
	rect.setSize(Vector2f(50, 50));
	rect2.setSize(Vector2f(50, 50));
	rect3.setSize(Vector2f(50, 50));
	vector <RectangleShape> object_list;
	object_list.push_back(rect);
	object_list.push_back(rect2);
	object_list.push_back(rect3);
	while (!menu)
	{
			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();

			player.update(delta,object_list);

			window.clear(Color(0,240,255));
			background.draw(window);
			for each (rect in object_list)
			{
				window.draw(rect);
			}
			window.draw(obstacle);
			window.draw(player);
			window.display();
	}
}
