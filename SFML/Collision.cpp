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


bool Collision::checkIfCollision(vector<Sprite> object_list){
	

	for each (Sprite object in object_list)
	{	


		if (getGlobalBounds().intersects(object.getGlobalBounds()))return true;

			
	}
	return false;
}

bool Collision::checkIfCollisionTop(vector <Sprite> object_list){

	if (checkIfCollision(object_list)){
		Sprite object = colidingObject(object_list);
		if (getPosition().y > object.getPosition().y) return true;
		else return false;
	}
	else{
		return false;
	}
}

bool Collision::checkIfCollisionBottom(vector <Sprite> object_list){

	if (checkIfCollision(object_list)){
		Sprite object = colidingObject(object_list);
		if (getPosition().y < object.getPosition().y) return true;
		else return false;
	}
	else{
		return false;
	}
}

bool Collision::checkIfCollisionLeft(vector <Sprite> object_list){
	if (checkIfCollision(object_list)){
		Sprite object = colidingObject(object_list);
		if (getPosition().x < object.getPosition().x) return true;
		else return false;
	}
	else{
		return false;
	}
}


bool Collision::checkIfCollisionRight(vector <Sprite> object_list){
	if (checkIfCollision(object_list)){
		Sprite object = colidingObject(object_list);
		if (getPosition().x > object.getPosition().x) return true;
		else return false;
	}
	else{
		return false;
	}
}

