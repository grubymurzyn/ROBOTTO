#include "MapManager.h"
View camera(Vector2f(640, 360), Vector2f(1280, 720));

MapManager::MapManager(int lvl)
{
	char znak;
	std::ifstream plik;
	plik.open("data/level1.txt");


	for (int i = 0; i < 23; i++)
		tiles[i].loadFromFile("data/level1.png", sf::IntRect(0, i * 64, 64, 64));

	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++){
			plik >> znak;
			if ((znak - '\n') != 0)
				LEVEL[i][j] = znak - 'a';
			else{
				plik >> znak;
				LEVEL[i][j] = znak - 'a';
			}
		}
	}

	plik.close();
}

MapManager::~MapManager()
{
}

void MapManager::updateMap()
{
	int leftSide;									//pierwszy i ostatni kafel, ktory bedziemy wyswietlac (numer)
	int rightSide;

	leftSide = camera.getCenter().x / 64 - 11;  					//(11)15 - polowa liczby kafli, 64 - szerokosc kafla
	if (leftSide < 0)
		leftSide = 0;

	rightSide = camera.getCenter().x / 64 + 11;
	if (rightSide > WIDTH)
		rightSide = WIDTH;

	for (int i = 0; i < HEIGHT; i++){
		for (int j = leftSide, x = 0; j < rightSide; j++, x++) 	//x - numer kafla sprite'a, j - numer kafla mapy
		{
			vlevel[i][x].setPosition(j * 64, i * 64);
			cout << vlevel[i][x].getPosition().y << endl;
			vlevel[i][x].setTexture(tiles[LEVEL[i][j]]);
		}
	}
} 

void MapManager::drawMap(RenderWindow &window)
{
	for (int i = 0; i<12; i++){
		for (int j = 0; j < 30; j++)
			window.draw(vlevel[i][j]);

	}
}

View MapManager::getCamera(){
	return camera;
}

void MapManager::moveCamera(Player player ,float delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if ((player.getPosition()).x >= 700 && (player.getPosition()).x <= 10800)
			camera.move(player.getVelocity().x * delta, 0);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if ((player.getPosition()).x >= 700 && (player.getPosition()).x <= 10800)
			camera.move(player.getVelocity().x * delta, 0);
	}
}

vector <Sprite> MapManager::getMapObjects(){
	return gameObjects;
}