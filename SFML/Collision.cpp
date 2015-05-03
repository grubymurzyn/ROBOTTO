#include "Collision.h"


Collision::Collision()
{
}


Collision::~Collision()
{
}

template <class T> T Collision::colidingObject(vector<T> object_list){
	for each (T object in object_list)
	{


		if (getGlobalBounds().intersects(object.getGlobalBounds()))return object;


	}
}


bool Collision::checkIfCollision(vector<RectangleShape> object_list){
	

	for each (RectangleShape object in object_list)
	{	


		if (getGlobalBounds().intersects(object.getGlobalBounds()))return true;

			
	}
	return false;
}

bool Collision::checkIfCollisionTop(vector <RectangleShape> object_list){

	if (checkIfCollision(object_list)){
		RectangleShape object = colidingObject(object_list);
		if (getPosition().y > object.getPosition().y) return true;
		else return false;
	}
	else{
		return false;
	}
}

bool Collision::checkIfCollisionBottom(vector <RectangleShape> object_list){

	if (checkIfCollision(object_list)){
		RectangleShape object = colidingObject(object_list);
		if (getPosition().y < object.getPosition().y) return true;
		else return false;
	}
	else{
		return false;
	}
}

bool Collision::checkIfCollisionLeft(vector <RectangleShape> object_list){
	if (checkIfCollision(object_list)){
		RectangleShape object = colidingObject(object_list);
		if (getPosition().x < object.getPosition().x) return true;
		else return false;
	}
	else{
		return false;
	}
}


bool Collision::checkIfCollisionRight(vector <RectangleShape> object_list){
	if (checkIfCollision(object_list)){
		RectangleShape object = colidingObject(object_list);
		if (getPosition().x > object.getPosition().x) return true;
		else return false;
	}
	else{
		return false;
	}
}

