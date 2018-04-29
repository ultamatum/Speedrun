// Map Class
// Builds and store level sections based on TileMap and TileSet

#pragma once
#include <math.h>
#include "Sprites.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	void LoadTexture(char* filename);
	void SetTileSet(std::vector<Sprites> ts);
	void SetTileMap(std::vector<int> tm, sf::Vector2u mapDimensions);
	void BuildLevel();

	void Render(sf::RenderWindow* window);
	std::vector<Sprites>* GetLevel(){ return &level; };

	void SetPosition(sf::Vector2f pos) { position = pos; };

	sf::Vector2u GetTileSetSize() { return texture.getSize(); };
	sf::Vector2u GetMapSize() { return mapSize; };

protected:
	std::vector<Sprites> tileSet;
	std::vector<int> tileMap;
	std::vector<Sprites> level;
	sf::Texture texture;
	sf::Vector2u mapSize;
	sf::Vector2f position;
};

