#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include <list>
#include"MainMenu.h"
#include"SplashScreen.h"
#include"Duck.h"

using namespace std;
using namespace sf;

class Game{
public:
	void Start();
private:
	static bool IsExiting();
	static void GameLoop();


	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static Duck _duck;

};