#include "Player.h"
#include <iostream>

Player::Player() {};

Player::Player(Input* input, sf::Vector2f startPos)
{
	SetInput(input);
	setPosition(startPos);
	setSize(sf::Vector2f(32, 32));
	SetCollisionBox(0, 0, 32, 32);
	sType.SetType(Type::PLAYER);			//Special sprite type for the player

	scale = 150.f;
	speed = 50.f;
	gravity = 9.8f*scale;
}

Player::~Player() {}

void Player::Update(float dt)
{
	velocity.y += gravity * dt;								//Apply Gravity

	//Makes sure the player cant fall through the world
	if (getPosition().y >= 720 - getSize().y)
	{
		isJumping = false;
		setPosition(getPosition().x, 720 - getSize().y);
		velocity.y = 0;
	}

	if (velocity.y >= 700) velocity.y = 700;				//Creates a terminal velocity to stop player lagging out of environment

	Movement(dt);

	move(velocity*dt);										//Moves the player given all calculated velocities
}

void Player::Movement(float dt)
{
	direction = 0;											//Used to calculate the horizontal direction the player should go

	if (input->IsKeyDown(sf::Keyboard::D))
	{
		direction += 1;
	}

	if (input->IsKeyDown(sf::Keyboard::A))
	{
		direction -= 1;
	}

	if (input->IsKeyDown(sf::Keyboard::Space) && isJumping == false && velocity.y < 10)
	{
		velocity.y = -4.f * scale;
		isJumping = true;
	}
	else if (!input->IsKeyDown(sf::Keyboard::Space) && velocity.y < 0)
	{
		velocity.y *= 0.75;
	}

	velocity.x += (direction * speed);
	velocity.x *= 0.87f;
}

void Player::CollisionResponse(Sprites* sp)
{
	//Only reacts if the player collides with the map
	if ((sp->sType.GetType() == Type::MAP))
	{
		//Top collision check
		if ((GetCollisionBox().top + GetCollisionBox().height > sp->GetCollisionBox().top) && (GetCollisionBox().top + (GetCollisionBox().height / 16 * 5) < sp->GetCollisionBox().top) && (GetCollisionBox().left < sp->GetCollisionBox().left + sp->GetCollisionBox().width) && (GetCollisionBox().left + GetCollisionBox().width > sp->GetCollisionBox().left))
		{
			isJumping = false;
			velocity.y = 0;
			setPosition(getPosition().x, sp->getPosition().y - getSize().y);
		}
		//Left collision check
		else if (((GetCollisionBox().left + GetCollisionBox().width) > (sp->GetCollisionBox().left)) && (GetCollisionBox().left < sp->GetCollisionBox().left) && (GetCollisionBox().top + GetCollisionBox().height > sp->GetCollisionBox().top))
		{
			velocity.x = 0;
			setPosition(sp->getPosition().x - getSize().x, getPosition().y);
		}
		//Right collision check
		else if ((GetCollisionBox().left < sp->GetCollisionBox().left + sp->GetCollisionBox().width) && (GetCollisionBox().left + GetCollisionBox().width > sp->GetCollisionBox().left + sp->GetCollisionBox().width))
		{
			velocity.x = 0;
			setPosition(sp->getPosition().x + sp->getSize().x, getPosition().y);
		}
		//Bottom collision check
		else if ((GetCollisionBox().top < sp->GetCollisionBox().top + sp->GetCollisionBox().height) && (GetCollisionBox().top + GetCollisionBox().height > sp->GetCollisionBox().top + sp->GetCollisionBox().height) && (GetCollisionBox().left < sp->GetCollisionBox().left + sp->GetCollisionBox().width) && (GetCollisionBox().left + GetCollisionBox().width > sp->GetCollisionBox().left))
		{
			velocity.y = 0;
			setPosition(getPosition().x, sp->getPosition().y + sp->getSize().y);
		}
	}
}
