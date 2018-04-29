#include "Collision.h"

// check AABB
bool Collision::CheckBoundingBox(Sprites* s1, Sprites* s2)
{
	if (s1->GetCollisionBox().left + s1->GetCollisionBox().width < s2->GetCollisionBox().left)
		return false;
	if (s1->GetCollisionBox().left > s2->GetCollisionBox().left + s2->GetCollisionBox().width)
		return false;
	if (s1->GetCollisionBox().top + s1->GetCollisionBox().height < s2->GetCollisionBox().top)
		return false;
	if (s1->GetCollisionBox().top > s2->GetCollisionBox().top + s2->GetCollisionBox().height)
		return false;

	return true;
}

// check Sphere bounding collision
bool Collision::CheckBoundingSphere(Sprites* s1, Sprites* s2)
{
	// Get radius and centre of sprites.
	float radius1 = s1->getSize().x / 2;
	float radius2 = s2->getSize().x / 2;
	float xpos1 = s1->getPosition().x + radius1;
	float xpos2 = s2->getPosition().x + radius2;
	float ypos1 = s1->getPosition().y + radius1;
	float ypos2 = s2->getPosition().y + radius2;

	if (pow(xpos2 - xpos1, 2) + pow(ypos2 - ypos1, 2) < pow(radius1 + radius2, 2))
	{
		return true;
	}
	return false;
}