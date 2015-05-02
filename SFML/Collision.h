#pragma once
#include "GameObject.h"
class Collision :public GameObject
{

public:
	Collision();
	~Collision();
	template <typename T> T colidingObject(vector<T>);
	virtual bool checkIfCollision(vector<RectangleShape>);
	virtual bool checkIfCollisionBottom(vector<RectangleShape>);
	virtual bool checkIfCollisionTop(vector<RectangleShape>);
};


