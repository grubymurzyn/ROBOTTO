
#include "Game.h"
Duck Game::_duck;
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 500, 32), "Pang!");
	_duck.Load("images/duck2.png");
	_duck.SetPosition((1024 / 2) - 45, 200);

	_gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent))
	{

		switch (_gameState)
		{
		case Game::ShowingMenu:{
			ShowMenu();
			break;
		}
		case Game::ShowingSplash:{
			ShowSplashScreen();
			break;
		}
		case Game::Playing:
		{	
			_mainWindow.clear(sf::Color(sf::Color(0, 0, 0)));
			_duck.Draw(_mainWindow);
			_mainWindow.display();

			if (Keyboard::isKeyPressed(Keyboard::Space))
			{

				_duck.Jump();
				

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				_duck.Move(-5, 0);

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				_duck.Move(5, 0);

			}
			if (currentEvent.type == sf::Event::Closed)
			{
				_gameState = Game::Exiting;
			}
			break;
		}
		}
	}
}
void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}
void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
		case MainMenu::Exit:
			 _gameState = Game::Exiting;
			 break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}


Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;