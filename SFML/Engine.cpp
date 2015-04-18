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
	Collision collision;
	int counter =0;
	float t = 0;
	Clock clock;
	const float gravity = 1;
	int groundHeight = 400, maxHeight = 100;
	static Vector2f velocity(Vector2f (0,0)),position;
	float jumpSpeed = 7.1f,moveSpeed = 100.1f;
	RectangleShape rect(Vector2f(20,20));
	rect.setPosition(256,256);
	rect.setFillColor(Color::Blue);
	vector<RectangleShape> obstacle_list;

	RectangleShape obstacle1(Vector2f(20, 20));
	obstacle1.setPosition(300, 300);
	obstacle1.setFillColor(Color::Red);
	obstacle_list.push_back(obstacle1);
	while (!menu)
	{

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				velocity.x = moveSpeed;
				if (Keyboard::isKeyPressed(Keyboard::Space) && counter <maxHeight){
					velocity.y -= jumpSpeed;
					++counter;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				velocity.x = -moveSpeed;
				if (Keyboard::isKeyPressed(Keyboard::Space) && counter <maxHeight){
					velocity.y -= jumpSpeed;
					++counter;
				}
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Space)) && counter <maxHeight){
					velocity.y -= jumpSpeed;
					++counter;
					
			}
			else{
				velocity.x = 0;
			}

			if (rect.getPosition().y + rect.getSize().y < groundHeight || velocity.y <0){
				
				velocity.y += gravity;
				++counter;
			}
			else
			{

				counter = 0;
				rect.setPosition(rect.getPosition().x, groundHeight - rect.getSize().y);
				velocity.y = 0;
			}

			float delta = clock.getElapsedTime().asSeconds() - t;
			t = clock.getElapsedTime().asSeconds();
			//std::cout <<"COLLISION: "<<collision.checkIfCollision(rect,obstacle_list)<< endl;
			std::cout << "COUNTER: " << counter << endl;
			rect.move(velocity.x*delta, velocity.y*delta);

	
			
		//KOLIZJA
			window.clear(Color(0,240,255));
			window.draw(rect);
			for each (RectangleShape obstacle  in obstacle_list)
			{
				window.draw(obstacle);
			}
			window.display();
	}
}
