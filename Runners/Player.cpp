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

	#pragma region Animations
	idle.AddFrame(sf::IntRect(0, 0, 11, 11));
	idle.AddFrame(sf::IntRect(0, 0, 11, 11));
	idle.SetLooping(false);
	
	for (int i = 0; i < 4; i++)
	{
		walk.AddFrame(sf::IntRect(11 * i, 11, 11, 11));
	}
	walk.SetFrameSpeed(1.f / 7.14f);
	walk.SetLooping(true);

	for (int i = 0; i < 2; i++)
	{
		jump.AddFrame(sf::IntRect(11 * i, 22, 11, 11));
	}
	jump.SetFrameSpeed(1.f / 5.5f);
	jump.SetLooping(true);

	currentAnim = &idle;
	currentAnim->Reset();
	currentAnim->SetPlaying(true);
	setTextureRect(currentAnim->GetCurrentFrame());
	#pragma endRegion
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

	currentAnim->SetPlaying(true);
	currentAnim->Animate(dt);
	setTextureRect(currentAnim->GetCurrentFrame());
}

void Player::Movement(float dt)
{
	direction = 0;											//Used to calculate the horizontal direction the player should go

	if (input->IsKeyDown(sf::Keyboard::D))
	{
		direction += 1;

		if (currentAnim != &walk)
		{
			currentAnim = &walk;
			currentAnim->SetFlipped(false);					//Have to make sure animation is flipped so no moonwalking
			idle.SetFlipped(false);							//Makes sure player doesnt just turn around whenever no buttons are pressed
			currentAnim->Reset();
		}
	}

	if (input->IsKeyDown(sf::Keyboard::A))
	{
		direction -= 1;

		if (currentAnim != &walk)
		{
			currentAnim = &walk;
			currentAnim->SetFlipped(true);					//Have to make sure animation is flipped so no moonwalking
			idle.SetFlipped(true);							//Makes sure player doesnt just turn around whenever no buttons are pressed
			currentAnim->Reset();
		}
	}

	//If a / d isnt pressed then animation is idle
	if (direction == 0)
	{
		if (currentAnim != &idle)
		{
			currentAnim = &idle;
			currentAnim->Reset();
		}
	}

	if (input->IsKeyDown(sf::Keyboard::Space) && isJumping == false && velocity.y < 10)
	{
		velocity.y = -4.f * scale;
		isJumping = true;

		if (currentAnim != &jump)
		{
			currentAnim = &jump;
			currentAnim->Reset();
		}
	}
	else if (!input->IsKeyDown(sf::Keyboard::Space) && velocity.y < 0)
	{
		velocity.y *= 0.75;

		if (currentAnim != &jump)
		{
			currentAnim = &jump;
			currentAnim->Reset();
		}
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
