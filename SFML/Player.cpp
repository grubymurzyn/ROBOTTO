#include "Player.h"

Player::Player(void)
{
	loadFile("data/images/robotto.png");
	setAnimFrame(IntRect(24, 0, 48, 96));
	setPosition(Vector2f(1024/2,200));
	setCenter(Vector2f(24, 48));
	status = WAIT;
	isJumping = NO;


}


Player::~Player()
{
}

void Player::update(float delta, vector<Sprite> object_list)//DO ZROBIENIA
{
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		velocity.x = moveSpeed;
		status = RIGHT;
		if (Keyboard::isKeyPressed(Keyboard::Space) && counter*delta < maxHeight*delta){
			velocity.y -= jumpSpeed;
			isJumping = YES;
			++counter;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		velocity.x = -moveSpeed;
		status = LEFT;
		if (Keyboard::isKeyPressed(Keyboard::Space) && counter*delta < maxHeight*delta){
			velocity.y -= jumpSpeed;
			isJumping = YES;
			++counter;
		}
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Space)) && counter*delta < maxHeight*delta){
		velocity.y -= jumpSpeed;
		isJumping = YES;
		++counter;
	}
	else{
		velocity.x = 0;
		status = WAIT;
	}
	
	/*************************************
	   SPRAWDZANIE KOLIZJI I JEJ OBS£UGA
	*************************************/
	if (checkIfCollisionTop(object_list)){
		velocity.y = 0;
		cout << "TOP" << endl;
		if (checkIfCollisionLeft(object_list)){
			cout << "TOP && LEFT" << endl;
			if (velocity.x > 0) {
				velocity.x = 0;
			}
			if (isJumping == YES){
				tempVelocityY += gravity;
				velocity.y = tempVelocityY;
				cout << "TOP && LEFT && IS JUMPING " << endl;
			}
		}
		else if (checkIfCollisionRight(object_list)){
			cout << "TOP && RIGHT" << endl;
			if (velocity.x < 0) {
				velocity.x = 0;
			}
			if (isJumping == YES){
				tempVelocityY += gravity;
				velocity.y = tempVelocityY;
				cout << "TOP && LEFT && IS JUMPING " << endl;
			}
		}
	}
	
	if (checkIfCollisionBottom(object_list)){
		counter = 0;
		actualHeight = getPosition().y + getSize().height;
		cout << "BOTTOM" << endl;
	}
	else if (!checkIfCollisionBottom(object_list) && actualHeight != groundHeight){
		actualHeight = groundHeight;
	}

	if ((getPosition().y + getSize().height < actualHeight || velocity.y < 0)){
		isJumping = YES;
		if (velocity.y == 0) isFalling = true;
		velocity.y += gravity;
		++counter;
	} 
	else
	{
		isFalling = false;
		tempVelocityY = 0;
		isJumping = NO;
		counter = 0;
		setPosition(Vector2f(getPosition().x, actualHeight - getSize().height));
		velocity.y = 0;
	}

	move(Vector2f(velocity.x*delta, velocity.y*delta));
	
	
	if (anim_clock.getElapsedTime() > sf::seconds(0.09f))
	{
		if (isJumping == NO && status != WAIT){
			if (frame < 5)
			frame++;
			else frame = 0;
		}
		else if (isJumping == YES && status==WAIT){
			if (isFalling)
				frame = 1;
			else frame = 0;
		}
		else if (isJumping == YES && status != WAIT){
			if (isFalling)
				frame = 2;
			else frame = 1;
		}


		if (status == RIGHT && isJumping == NO){
			setAnimFrame(IntRect(frame * 96 + 24, 0, 48, 96));
		}
		else if (status == LEFT && isJumping == NO){
			setAnimFrame(IntRect(frame * 96 + 24, 96, 48, 96));
		}
		else if (status == WAIT && isJumping == NO){
			setAnimFrame(IntRect(24, 192, 48, 96));
		}
		else if (status == WAIT && isJumping == YES){
			setAnimFrame(IntRect(frame* 96 + 24, 288, 48, 96));
		}
		else if (status == RIGHT && isJumping == YES){
			setAnimFrame(IntRect(frame * 96 + 24, 384, 52, 96));
		}
		else if (status == LEFT && isJumping == YES){
			setAnimFrame(IntRect(frame * 96 + 20, 480, 52, 96));
		}
		anim_clock.restart();
	}
}

Vector2f Player::getVelocity(){
	return velocity;
}

void Player::stop()
{
	status = WAIT;
	frame = 0;
}



