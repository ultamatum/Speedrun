#pragma once
#include "Sprites.h"

class Collectable : public Sprites
{
public:
	Collectable();
	Collectable(sf::Vector2f Pos);
	~Collectable();
};

