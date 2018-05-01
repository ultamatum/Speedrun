#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "TileMap.h"
#include "Player.h"
#include "Collectable.h"
#include "Collision.h"
#include "GameState.h"

class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* inpt, GameState* gState, float* score);
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
	GameState* gameState;
	TileMap tileMap;
	Player player;
	std::vector<Collectable> stars;

	int starCount;							//Used to keep count of how many stars are collected
	bool starsCollected = false;			//Keeps track if all stars are collected
	float timer;
	float* score;

	void BeginDraw();
	void EndDraw();
};

