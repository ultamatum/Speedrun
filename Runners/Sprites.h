#pragma once
#include "SFML\Graphics.hpp"
#include "Input.h"

class Sprites : public sf::RectangleShape
{
public:
	Sprites();
	~Sprites();

	virtual void Update(float dt);

	//Sprite Speed and direction
	void SetVelocity(sf::Vector2f vel);
	void SetVelocity(float vx, float vy);
	sf::Vector2f GetVelocity();

	//Sprite state
	bool IsAlive() { return alive; };
	void SetAlive(bool b) { alive = b; };

	//For sprite collision
	bool IsCollider() { return collider; };
	void SetCollider(bool b) { collider = b; };
	sf::FloatRect GetCollisionBox() { return collisionBox; };
	void SetCollisionBox(float x, float y, float width, float height) { collisionBox = sf::FloatRect(x, y, width, height); };
	void SetCollisionBox(sf::FloatRect fr) { collisionBox = fr; };
	virtual void UpdateCollisionBox();
	virtual void CollisionResponse(Sprites* sp);

	//Input component
	void SetInput(Input* in) { input = in; };

protected:
	// Sprite properties
	sf::Vector2f velocity;
	bool alive;

	// Collision vars
	sf::FloatRect collisionBox;
	bool collider;

	// input component
	Input* input;
};

