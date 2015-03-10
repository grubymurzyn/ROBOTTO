#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	
	 //Load menu image from file
	 Texture texture;
	 texture.loadFromFile("images/MainMenu.png");
	 Sprite sprite(texture);
	 //Setup clickable regions

	 //Play menu item coordinates
	 MenuItem playButton;
	 playButton.rect.top = 50;
	 playButton.rect.width = 1023;
	 playButton.rect.left = 0;
	 playButton.rect.height= 100;
	 playButton.action = Play;
	 
	 //Exit menu item coordinates
	 MenuItem exitButton;
	 exitButton.rect.left = 0;
	 exitButton.rect.width = 1023;
	 exitButton.rect.top = 150;
     exitButton.rect.height = 100;
	 exitButton.action = Exit;
		
	 _menuItems.push_back(playButton);
	 _menuItems.push_back(exitButton);
	
	 window.draw(sprite);
	 window.display();
	
		  return GetMenuResponse(window);
 }

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	list<MenuItem>::iterator it;

	 for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	 {
		Rect<int> menuItemRect = (*it).rect;
		if ((menuItemRect.height + menuItemRect.top) > y && menuItemRect.top < y && menuItemRect.left < x && (menuItemRect.width  + menuItemRect.width) > x)
	    {
			return (*it).action;
		}
	  }
		return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	Event menuEvent;

	 while (true)
	 {
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				 return Exit;
			}
		}
	 }
}