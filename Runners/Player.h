#pragma once
#include "Sprites.h"
#include "Input.h"

//Class for player logic and control
class Player : public Sprites
{
public:
	Player();
	Player(Input* input, sf::Vector2f startPos);
	~Player();

	void Update(float dt);
	void CollisionResponse(Sprites* sp);
private:
	float gravity;
	float speed;
	float scale;

	int direction;

	bool isJumping = true;

	void Movement(float dt);
};

