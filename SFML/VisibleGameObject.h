#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
using namespace sf;
using namespace std;

class VisibleGameObject{

public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(string filename);
	virtual void Draw(RenderWindow & window);
	virtual void SetPosition(Vector2f position);
	virtual void Move(Vector2f v);
	virtual FloatRect toColide();

private:
	Sprite _sprite;
	Texture _texture;
	string _filename;
	bool _isLoaded;

};