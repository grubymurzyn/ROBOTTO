#pragma once
#include "Engine.h"
#include<Windows.h>
#include<string>

using namespace std;
using namespace sf;
class Game
{
public:
	Game(void);
	~Game(void);

	void runGame();
	void single();

protected:
	enum GameState { MENU, GAME, GAME_OVER, END };
	GameState state;

private:
	Font font;
	RenderWindow window;
	void menu();
};

