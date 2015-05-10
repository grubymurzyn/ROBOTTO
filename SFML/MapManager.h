#include "Player.h"
#include "Obstacle.h"
#include <fstream>
#pragma once
const int WIDTH = 180;												//wysokosc i szerokosc poziomu w kaflach
const int HEIGHT = 12;

class MapManager{
	int level;
	short LEVEL[HEIGHT][WIDTH];											//reprezentacja poziomu (za pomoca cyfr)
	Texture tiles[23];												//tekstury kafli
	Sprite vlevel[12][30];
	vector <Sprite> gameObjects;


public:
	MapManager(int);
	~MapManager();
	void updateMap();
	View getCamera();
	void drawMap(RenderWindow &);
	void moveCamera(Player,float);
	vector<Sprite> getMapObjects();
};
