#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"

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
	void BeginDraw();
	void EndDraw();
};

