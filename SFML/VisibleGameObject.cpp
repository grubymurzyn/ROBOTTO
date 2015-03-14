#include"VisibleGameObject.h"

VisibleGameObject::VisibleGameObject():_isLoaded(false){
}
VisibleGameObject::~VisibleGameObject(){

}
void VisibleGameObject::Load(std::string filename)
{
	if (_texture.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::SetPosition(Vector2f position)
{
	if (_isLoaded)
	{
		_sprite.setPosition(position);
	}
}
void VisibleGameObject::Move(Vector2f v){
	if (_isLoaded){
		_sprite.move(v);
	}
}
FloatRect VisibleGameObject::toColide(){
	if (_isLoaded){
		return _sprite.getGlobalBounds();
	}
}