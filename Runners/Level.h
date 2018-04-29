#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "TileMap.h"
#include "Player.h"
#include "Collectable.h"
#include "Collision.h"

class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* inpt);
	~Level();

	void HandleInput(float deltaTime);
	void Update(float deltaTime);
	void Render(); 

private:
	sf::RenderWindow* window;
	sf::Texture playerTexture;
	sf::Texture starTexture;
	sf::Font font;
	sf::Text clockText;
	sf::Clock clock;
	Input* input;
	TileMap tileMap;
	Player player;
	std::vector<Collectable> stars;

	int starCount;
	float timer;

	void BeginDraw();
	void EndDraw();
};

