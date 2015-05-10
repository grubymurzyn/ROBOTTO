#pragma once
#include"Collision.h"
class Player : public Collision
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
	void update(float, vector<Sprite>);
	void stop();
	Vector2f getVelocity();

protected:
	int animate_frame;

private:
	Vector2f velocity = Vector2f(0, 0);
	Status status;
	IsJumping isJumping;
	//jumpSPEED == RANDOM
	float actualHeight = 680;
	float jumpSpeed = 7.0f;
	float moveSpeed = 100.0f;
	float tempVelocityY =0;
	size_t frame=0;
	Clock anim_clock;
};

