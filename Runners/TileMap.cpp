#include "TileMap.h"

// Constructor sets default position value.
TileMap::TileMap()
{
	position = sf::Vector2f(0, 0);
}

TileMap::~TileMap(){}

// Uses window pointer to render level/section. Tile by Tile.
void TileMap::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < (int)level.size(); i++)
	{
		window->draw(level[i]);
	}
}

void TileMap::LoadTexture(char* filename)
{
	texture.loadFromFile(filename);
}

// Stores provided TileSet
void TileMap::SetTileSet(std::vector<Sprites> ts)
{
	tileSet = ts;
}

// Stores provided TileMap
void TileMap::SetTileMap(std::vector<int> tm, sf::Vector2u mapDimensions)
{
	tileMap = tm;
	mapSize = mapDimensions;
}

// Builds level/section, by filling a vector with Tiles in order. TileMap provides the order, TileSet provides the inidividual Tiles.
void TileMap::BuildLevel()
{
	if (tileSet.size() > 0 && tileMap.size() > 0)
	{
		int x, y = 0;
		sf::Vector2f tileSize(tileSet[0].getSize().x, tileSet[0].getSize().y);

		for (int i = 0; i < (int)tileMap.size(); i++)
		{
			x = i % mapSize.x;
			y = (int)floor(i / mapSize.x);
			tileSet[tileMap[i]].setPosition(position.x + (x * tileSize.x), position.y + (y * tileSize.y));
			level.push_back(tileSet[tileMap[i]]);
			level[i].setTexture(&texture);
		}
	}
}