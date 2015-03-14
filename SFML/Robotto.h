#include"VisibleGameObject.h"

class Robotto :public VisibleGameObject{
	float speed = 100.f;
	bool goUP, goDOWN, goLEFT, goRIGHT;
public:
	Robotto();
	~Robotto();
	void Update();
	Vector2f Move(Time time);
};