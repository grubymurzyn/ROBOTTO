#include"VisibleGameObject.h"

class Robotto :public VisibleGameObject{
	
	float speed = 10.f;
public:
	void Load(string name);
	void Draw(RenderWindow& renderwindow);
};