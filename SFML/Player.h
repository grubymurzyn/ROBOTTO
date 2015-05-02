#pragma once
#include"GameObject.h"

class GameResources;

class Player : public GameObject
{
public:
	Player(void);
	~Player(void);
	bool isFalling = false;
	enum Status {
		RIGHT,
		WAIT,
		LEFT
	};
	enum IsJumping {
		YES,
		NO
	};
	void update(float);
	void stop();

protected:
	int animate_frame;

private:
	Vector2f velocity = Vector2f(0, 0);
	Status status;
	IsJumping isJumping;
	//jumpSPEED == RANDOM
	float jumpSpeed = 7.0f;
	float moveSpeed = 100.0f;
	size_t frame=0;
	Clock anim_clock;
};

