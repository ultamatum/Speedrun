#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "TileMap.h"
#include "Player.h"

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
	sf::Texture texture;
	Input* input;
	TileMap tileMap;
	Player player;

	void BeginDraw();
	void EndDraw();
};

