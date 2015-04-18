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
	bool menu = false, top = false, bottom = false,left=false,right=false;
	Collision collision;
	int counter =0;
	float t = 0;
	Clock clock;
	const float gravity = 1;
	int groundHeight = 400, maxHeight = 150,actualHeight;
	static Vector2f velocity(Vector2f (0,0)),position;
	float jumpSpeed = 7.1f,moveSpeed = 100.1f;
	RectangleShape rect(Vector2f(20,20));
	rect.setPosition(256,256);
	rect.setFillColor(Color::Blue);
	vector<RectangleShape> obstacle_list;

	RectangleShape obstacle1(Vector2f(20, 20));
	obstacle1.setPosition(400, 380);
	obstacle1.setFillColor(Color::Red);
	obstacle_list.push_back(obstacle1);
	while (!menu)
	{
				float delta = clock.getElapsedTime().asSeconds() - t;
				t = clock.getElapsedTime().asSeconds();

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
					right = false;
					velocity.x = moveSpeed;
					if (Keyboard::isKeyPressed(Keyboard::Space) && counter < maxHeight){
						velocity.y -= jumpSpeed;
						++counter;
					}
					if (collision.checkIfCollision(rect, obstacle_list)) right = true;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
					left = false;
					velocity.x = -moveSpeed;
					if (Keyboard::isKeyPressed(Keyboard::Space) && counter < maxHeight){
						velocity.y -= jumpSpeed;
						++counter;
					}
					if (collision.checkIfCollision(rect, obstacle_list)) left = true;
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Space)) && counter < maxHeight){

				velocity.y -= jumpSpeed;
				++counter;
			}
			else{
				velocity.x = 0;
			}
			if ((rect.getPosition().y + rect.getSize().y < groundHeight || velocity.y < 0)){

				velocity.y += gravity;
				++counter;
			}

			else
			{

				counter = 0;
				rect.setPosition(rect.getPosition().x, groundHeight - rect.getSize().y);
				velocity.y = 0;
			}

			/*std::cout <<"COLLISION: "<<collision.checkIfCollision(rect,obstacle_list)<< endl;*/
			//std::cout << "POZYCJA: " << rect.getPosition().y + rect.getSize().y <<" "<<rect.getPosition().x<< endl;
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
