#pragma once
#include "GameObject.h"
class Collision :public GameObject
{

public:
	Collision();
	~Collision();
	template <typename T> T colidingObject(vector<T>);
	virtual bool checkIfCollision(vector<Sprite>);
	virtual bool checkIfCollisionBottom(vector<Sprite>);
	virtual bool checkIfCollisionTop(vector<Sprite>);
	virtual bool checkIfCollisionLeft(vector<Sprite>);
	virtual bool checkIfCollisionRight(vector<Sprite>);
	
};


