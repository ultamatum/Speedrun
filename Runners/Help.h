#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "GameState.h"

//Class to teach the player how to play with simple strings
class Help
{
public:
	Help(sf::RenderWindow* hwnd, Input* inpt, GameState* gState);
	~Help();

	void HandleInput();
	void Render();

private:
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text leftrightText, jumpText, pauseText, introText, returnText;
	Input* input;
	GameState* gameState;

	void BeginDraw();
	void EndDraw();
};

