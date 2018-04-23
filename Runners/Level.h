#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Level
{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void HandleInput();
	void Update();
	void Render();

private:
	sf::RenderWindow* window;
	void BeginDraw();
	void EndDraw();
};

