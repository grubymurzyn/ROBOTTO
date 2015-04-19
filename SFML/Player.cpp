#include"GameResources.h"
#include "Player.h"

Player::Player(void)
{
	loadFile("data/images/robotto.png");
	setAnimFrame(IntRect(0, 0, 96, 96));
	setPosition(Vector2f(1024/2,200));
	setCenter(Vector2f(48, 48));
	status = WAIT;
	isJumping = NO;

}


Player::~Player()
{
}

void Player::update(float delta)//DO ZROBIENIA
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

	if ((getPosition().y + getSize().height < groundHeight || velocity.y < 0)){
		isJumping = YES;
		if (velocity.y == 0) isFalling = true;
		velocity.y += gravity;
		++counter;
	}

	else
	{	
		isFalling = false;
		isJumping = NO;
		counter = 0;
		setPosition(Vector2f(getPosition().x, groundHeight - getSize().height));
		velocity.y = 0;
	}
	
	move(Vector2f(velocity.x*delta, velocity.y*delta)); 
	
	cout << "KLATKA:" << anim_clock.getElapsedTime().asSeconds()<< endl;
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
			setAnimFrame(IntRect(frame * 96, 0, 96, 96));
		}
		else if (status == LEFT && isJumping == NO){
			setAnimFrame(IntRect(frame * 96, 96, 96, 96));
		}
		else if (status == WAIT && isJumping == NO){
			setAnimFrame(IntRect(0, 192, 96, 96));
		}
		else if (status == WAIT && isJumping == YES){
			setAnimFrame(IntRect(frame* 96, 288, 96, 96));
		}
		else if (status == RIGHT && isJumping == YES){
			setAnimFrame(IntRect(frame * 96, 384, 96, 96));
		}
		else if (status == LEFT && isJumping == YES){
			setAnimFrame(IntRect(frame * 96, 480, 96, 96));
		}
		//x, y, szerokosc, wysokosc
		anim_clock.restart();
	}
}

void Player::stop()
{
	status = WAIT;
	frame = 0;
}



