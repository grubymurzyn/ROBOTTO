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
	void update(float, vector<Sprite*>,RenderWindow &);
	void stop();
	Vector2f getVelocity();

protected:
	int animate_frame;

private:
	Vector2f velocity = Vector2f(0, 0);
	Status status;
	int score=0;
	IsJumping isJumping;
	//jumpSPEED == RANDOM
	float actualHeight = groundHeight;
	float lastHeight = 0;
	float jumpSpeed = 400.0f;
	float moveSpeed = 150.0f;
	float tempVelocityY =0;
	size_t frame=0;
	void updateCollision(Sprite*);
	Clock anim_clock;
};

