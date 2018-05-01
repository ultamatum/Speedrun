#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "GameState.h"
#include <sstream>

//Class to manage gamestate for when the game ends
class GameOver
{
public:
	GameOver(sf::RenderWindow* hwnd, Input* input, GameState* gState, float* score);
	~GameOver();

	void HandleInput();
	void Update();
	void Render();

private:
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text gameOverText, scoreText, continueText;
	sf::FloatRect gameOverTextRect;
	Input* input;
	GameState* gameState;

	float* score;

	void BeginDraw();
	void EndDraw();
};

