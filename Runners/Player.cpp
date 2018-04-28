#include "Player.h"
#include <iostream>

Player::Player() {};

Player::Player(Input* input, sf::Vector2f startPos)
{
	SetInput(input);
	setPosition(startPos);
	setSize(sf::Vector2f(32, 32));

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
