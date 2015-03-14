#include"Robotto.h"
Robotto::Robotto(){

}
Robotto::~Robotto(){

}
void Robotto::Update(){
	goUP = false; goDOWN = false;
	goLEFT = false; goRIGHT = false;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		goUP = true;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		goDOWN = true;
	if (Keyboard::isKeyPressed(Keyboard::Left))
		goLEFT = true;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		goRIGHT = true;
}
Vector2f Robotto::Move(Time time){
		Vector2f v(0, 0);
		if (goUP)
			v.y -= speed;
		if (goDOWN)
			v.y += speed;
		if (goLEFT)
			v.x -= speed;
		if (goRIGHT)
			v.x += speed;

		return v * time.asSeconds();
}