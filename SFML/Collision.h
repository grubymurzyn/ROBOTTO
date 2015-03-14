#include"Robotto.h"
#include"Enviroment.h"
#include <vector>
class Collision{
public:
	static void isColiding(Robotto &robot, vector <Ground> V, Vector2f move){
		FloatRect X = robot.toColide();
		FloatRect Y = robot.toColide();
		X.left += move.x;
		Y.top += move.y;
		bool colX = false; bool colY = false;

		for (int i = 0; i < V.size(); i++)
			if (X.intersects(V[i].toColide()))
				colX = true;
			else if (Y.intersects(V[i].toColide()))
				colY = true;

		if (!colX)
			robot.VisibleGameObject::Move(Vector2f(move.x, 0));
		if (!colY)
			robot.VisibleGameObject::Move(Vector2f(0, move.y));
	};
};