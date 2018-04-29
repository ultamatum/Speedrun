#pragma once
#include "Sprites.h"

// Static class provide collision detection functions.
class Collision
{
public:
	//AABB
	static bool CheckBoundingBox(Sprites* sp1, Sprites* sp2);
	// Bounding circle
	static bool CheckBoundingSphere(Sprites* sp1, Sprites* sp2);

};