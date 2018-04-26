#pragma once
#include "Sprites.h"

class Player : public Sprites
{
public:
	Player();
	~Player();

	void Update(float dt);

private:
	void Movement(float dt);
};

