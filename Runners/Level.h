#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "TileMap.h"

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
	Input* input;
	TileMap tileMap;

	void BeginDraw();
	void EndDraw();
};

