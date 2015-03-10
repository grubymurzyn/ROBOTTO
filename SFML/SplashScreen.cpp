#include"SplashScreen.h"


void SplashScreen::Show(RenderWindow& renderWindow){
	Texture texture;
	if (texture.loadFromFile("images/SplashScreen.png") != true){
		return;
	}

	Sprite sprite(texture);
	renderWindow.draw(sprite);
	renderWindow.display();

	Event event;
	while (true){
		while (renderWindow.pollEvent(event))
		{
			if (event.type == Event::EventType::KeyPressed || event.type == Event::EventType::MouseButtonPressed || event.type == Event::EventType::Closed){
				return;
			}
		}

	}


}