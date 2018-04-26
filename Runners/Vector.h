#pragma once
#include "SFML\System\Vector2.hpp"
#include <math.h>

class Vector
{
public:
	// Added as no function for normalising vectors
	static sf::Vector2f Normalise(const sf::Vector2f &source);
	//Vector magnitude
	static float Magnitude(sf::Vector2f vec);

private:
	Vector();
	~Vector();
};

