
#include "Player.h"

Player::Player(void)
{
	if (!texture.loadFromFile("data/images/player-move.png"))
	{
		return;
	}

	sprite.setTexture(texture);
	sprite.setRotation(90);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));
	sprite.setPosition(1024 / 2 , 250);
	sprite.setOrigin(32, 32);

	status = WAIT;

	frame = 0;
	moveSpeed = 50.5;
	jumpSpeed = 1.0f;
}


Player::~Player()
{
}

void Player::update(Vector2f destination)//DO ZROBIENIA
{
	Vector2f norm = destination;
	double rot = atan2(norm.y, norm.x);
	rot = rot * 180.f / M_PI;
	Clock anim_clock;
	sprite.setRotation(rot);

	if (anim_clock.getElapsedTime() > sf::seconds(0.09f))
	{
		if (status == WAIT) return;
		if (frame < 7 /*liczba klatek animacji*/)
			frame++;
		else
			frame = 0; //zapetlanie animacji

		sprite.setTextureRect(IntRect(frame * 64, 0, 64, 64));
		//x, y, szerokosc, wysokosc
		anim_clock.restart();
	}
}

void Player::stop()
{
	status = WAIT;
	frame = 0;
}
void Player::go(float delta)
{
	status = GO;

	float rotacja = sprite.getRotation();
	double vx = sin((rotacja * M_PI) / 180.0f);
	double vy = -cos((rotacja * M_PI) / 180.0f);

	sprite.move(moveSpeed*vx*delta, moveSpeed*vy*delta);
}



