#pragma once
#include <SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include<iostream>
static const float gravity = 1;
static const int groundHeight = 680, maxHeight = 150;
static float counter = 0;




using namespace sf;
using namespace std;
class GameObject :public Drawable
{
private:
	 Texture texture;
	 Sprite sprite;

public:
	GameObject();
	~GameObject();
	virtual bool loadFile(String);
	virtual void setAnimFrame(IntRect&);
	virtual void setPosition(Vector2f);
	virtual Vector2f getPosition();
	virtual FloatRect getSize();
	virtual void setCenter(Vector2f);
	virtual Vector2f getCenter();
	virtual void draw(RenderTarget&,RenderStates) const;
	virtual void move(Vector2f);
	virtual FloatRect getGlobalBounds();

};

