#include"Enviroment.h"

Ground::Ground(){};
Ground::Ground(Vector2f size){
	shape.setSize(size);
}
Ground::~Ground(){};
void Ground::setPosition(Vector2f position){
	shape.setPosition(position);
}