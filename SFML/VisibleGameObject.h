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
	virtual void SetPosition(float x, float y);
	virtual void Move(float x, float y);

private:
	Sprite _sprite;
	Texture _texture;
	string _filename;
	bool _isLoaded;

};