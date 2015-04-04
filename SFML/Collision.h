#pragma once

#include"Player.h"

class Collision
{
public:
	Collision();
	~Collision();
	bool checkIfCollision(RectangleShape,vector<RectangleShape>);
};


