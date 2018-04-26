#include "Sprites.h"

Sprites::~Sprites(){}

Sprites::Sprites() : RectangleShape() {}

//Override this function to provide functionality
void Sprites::Update(float dt) {}

//Sets the velocity of the sprite
void Sprites::SetVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

void Sprites::SetVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

//Get sprite velocity
sf::Vector2f Sprites::GetVelocity()
{
	return velocity;
}

//Returns collision box + position, giving the collision box in the correct position
sf::FloatRect Sprites::GetCollisionBox()
{
	return sf::FloatRect(collisionBox.left + getPosition().x, collisionBox.top + getPosition().y, collisionBox.width, collisionBox.height);
}

// Reponse function, what the sprite does based on collision
// Colliding object is passed in for information
// e.g. compare sprite positions to determine new velocity direction.
// e.g. checking sprite type (world, enemy, bullet etc) so response is based on that.
void Sprites::CollisionResponse(Sprites * sp) {}

