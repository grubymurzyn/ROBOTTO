#pragma once

#include <SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace sf;
using namespace std;

class Player : public Drawable
{
public:
	Player(void);
	~Player(void);

	enum Status {
		GO,
		WAIT
	};

	Vector2f getPosition();
	Status getStatus();

	void update(Vector2f);

	void stop();
	void go(float);
	Sprite sprite;

protected:
	int animate_frame;

private:

	Texture texture;

	Status status;
	float jumpSpeed;
	float moveSpeed;
	size_t frame;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		//rysowanie obiektow, które sk³adaj¹ siê na narysowanie naszej postaci
		target.draw(sprite);
	}
};

