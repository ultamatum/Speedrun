#include "Player.h"
#include <iostream>

Player::Player() {};

Player::Player(Input* input, sf::Vector2f startPos)
{
	SetInput(input);
	setPosition(startPos);
	setSize(sf::Vector2f(32, 32));
	SetCollisionBox(0, 0, 32, 32);
	sType.SetType(Type::PLAYER);

	scale = 200.f;
	speed = 50.f;
	gravity = 9.8f*scale;
}

Player::~Player() {}

void Player::Update(float dt)
{
	//Apply Gravity
	velocity.y += gravity * dt;

	if (getPosition().y >= 720 - getSize().y)
	{
		isJumping = false;
		setPosition(getPosition().x, 720 - getSize().y);
		velocity.y = 0;
	}

	Movement(dt);

	move(velocity*dt);
}

void Player::Movement(float dt)
{
	direction = 0;

	if (input->IsKeyDown(sf::Keyboard::D))
	{
		direction += 1;
	}

	if (input->IsKeyDown(sf::Keyboard::A))
	{
		direction -= 1;
	}

	if (input->IsKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			velocity.y = -4.f * scale;
			isJumping = true;
		}
	}
	else if (!input->IsKeyDown(sf::Keyboard::Space) && velocity.y < 0)
	{
		velocity.y *= 0.75;
	}

	velocity.x += (direction * speed);
	velocity.x *= 0.9f;
}

void Player::CollisionResponse(Sprites* sp)
{
	if ((sp->sType.GetType() == Type::MAP))
	{
		if ((GetCollisionBox().top + GetCollisionBox().height > sp->GetCollisionBox().top) && (GetCollisionBox().top + (GetCollisionBox().height / 2) < sp->GetCollisionBox().top) && (GetCollisionBox().left < sp->GetCollisionBox().left + sp->GetCollisionBox().width) && (GetCollisionBox().left + GetCollisionBox().width > sp->GetCollisionBox().left))
		{
			isJumping = false;
			velocity.y = 0;
			setPosition(getPosition().x, sp->getPosition().y - getSize().y);
			std::cout << "TOP" << std::endl;
		} 
		else if (((GetCollisionBox().left + GetCollisionBox().width) > (sp->GetCollisionBox().left)) && (GetCollisionBox().left < sp->GetCollisionBox().left) && (GetCollisionBox().top + GetCollisionBox().height > sp->GetCollisionBox().top))
		{
			velocity.x = 0;
			setPosition(sp->getPosition().x - getSize().x, getPosition().y);
			std::cout << "RIGHT" << std::endl;
		}
		else if ((GetCollisionBox().left < sp->GetCollisionBox().left + sp->GetCollisionBox().width) && (GetCollisionBox().left + GetCollisionBox().width > sp->GetCollisionBox().left + sp->GetCollisionBox().width))
		{
			velocity.x = 0;
			setPosition(sp->getPosition().x + sp->getSize().x, getPosition().y);
			std::cout << "LEFT" << std::endl;
		}
		else if ((GetCollisionBox().top < sp->GetCollisionBox().top + sp->GetCollisionBox().height) && (GetCollisionBox().top + GetCollisionBox().height > sp->GetCollisionBox().top + sp->GetCollisionBox().height) && (GetCollisionBox().left < sp->GetCollisionBox().left + sp->GetCollisionBox().width) && (GetCollisionBox().left + GetCollisionBox().width > sp->GetCollisionBox().left))
		{
			velocity.y = 0;
			setPosition(getPosition().x, sp->getPosition().y + sp->getSize().y);
			std::cout << "BOTTOM" << std::endl;
		}
	}
}
