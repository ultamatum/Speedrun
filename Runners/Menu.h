#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "Level.h"
#include "GameState.h"

class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* input, GameState* gState, Level* level);
	~Menu();

	void HandleInput();
	void Update();
	void Render();

private:
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text options[3];							//Text items for the 3 menu options
	sf::Text title;									//May be temporary if I can get photoshop working
	Input* input;
	Level* level;
	GameState* gameState;
	int selected = 0;								//Int to store which option is currently selected

	enum options { START, HELP, EXIT };				//Enum to keep track of which text items are which

	void BeginDraw();
	void EndDraw();
};

