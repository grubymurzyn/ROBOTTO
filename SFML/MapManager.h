#include "Player.h"
#include "Obstacle.h"
#include "Monsters.h"
#include "Gears.h"
#include <fstream>
#pragma once
const int WIDTH = 180;												//wysokosc i szerokosc poziomu w kaflach
const int HEIGHT = 12;
const int windowWIDTH = 25;

class MapManager{
	int level;
	int score=0;
	short LEVEL[HEIGHT][WIDTH];											//reprezentacja poziomu (za pomoca cyfr)
	Texture tiles[23];	
	Sprite	vlevel[12][30];												//tekstury kafli
	vector<Sprite*> obstacles;
	Gears gears;

public:
	MapManager(int);
	~MapManager();
	void updateMap(Player);
	View getCamera();

	void drawMap(RenderWindow &,Player *);
	void moveCamera(Player,float);
	int getScore();


	vector <Sprite*> getObstacles();
};
