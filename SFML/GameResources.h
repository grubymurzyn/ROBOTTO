
#include"Obstacle.h"
#include"Background.h"
static const float gravity = 1;
static const int groundHeight = 400, maxHeight = 150;
static float counter = 0;

class GameResources {
public:
	Obstacle obstacle;
	Background background;

};