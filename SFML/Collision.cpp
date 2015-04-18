#include "Collision.h"


Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::checkIfCollision(RectangleShape player, vector<RectangleShape> object_list){
	

	for each (RectangleShape object in object_list)
	{	


		if (player.getGlobalBounds().intersects(object.getGlobalBounds()))return true;

			
	}
	return 0;
}

