
#include "Game.h"
Robotto Game::_robotto;
Time Game::TimeFromUpdate;
Clock Game::clock;
const  Time StepTime = sf::seconds(1.f / 500.f);
vector <Ground> V;
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 512, 32), "Pang!");
	TimeFromUpdate = Time::Zero;
	
	_robotto.Load("images/duck2.png");
	_robotto.SetPosition(Vector2f((1024 / 2) - 45, 100));


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
			Time time = clock.restart();
			TimeFromUpdate += time;
			_robotto.Update();

			while (TimeFromUpdate > StepTime)
			{
				TimeFromUpdate -= StepTime;
				sf::Event zdarzenie;
				while (_mainWindow.pollEvent(zdarzenie))
				{
					if (zdarzenie.type == sf::Event::Closed)
						_mainWindow.close();

				}
				Collision::isColiding(_robotto, V , _robotto.Move(StepTime));
			}

			_mainWindow.clear();
			_robotto.Draw(_mainWindow);
			
			for (int i = 0; i < V.size(); i++)
				V[i].Draw(_mainWindow);
			_mainWindow.display();

			
	
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