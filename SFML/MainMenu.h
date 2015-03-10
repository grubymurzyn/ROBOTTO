#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include <list>
using namespace std;
using namespace sf;

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play };
	
	struct MenuItem
	 {
		public:
			Rect<int> rect;
			MenuResult action;
	 };
		
		MenuResult Show(sf::RenderWindow& window);
	
 private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	list<MenuItem> _menuItems;
};