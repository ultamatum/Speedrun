#pragma once
#include "Sprites.h"

//Class used to indentify the stars that are collected by the player
class Collectable : public Sprites
{
public:
	Collectable();
	Collectable(sf::Vector2f Pos);
	~Collectable();
};

