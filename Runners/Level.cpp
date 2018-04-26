#include "Level.h"

using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* inpt)
{
	window = hwnd;
	input = inpt;

	#pragma region TileMap Creation
	tileMap.LoadTexture((char*)"gfx/marioTiles.png");

	Sprites tile;
	std::vector<Sprites> tiles;

	for (int i = 0; i < 7; i++)
	{
		tile.setSize(sf::Vector2f(32, 32));
		tile.SetCollisionBox(0, 0, 32, 32);
		tile.SetCollider(true);
		tiles.push_back(tile);
	}

	tiles[0].SetCollider(false);
	tiles[0].setTextureRect(sf::IntRect(187, 51, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16));
	tiles[2].setTextureRect(sf::IntRect(17, 0, 16, 16));
	tiles[3].setTextureRect(sf::IntRect(34, 0, 16, 16));
	tiles[4].setTextureRect(sf::IntRect(0, 34, 16, 16));
	tiles[5].setTextureRect(sf::IntRect(17, 34, 16, 16));
	tiles[6].setTextureRect(sf::IntRect(34, 34, 16, 16));

	tileMap.SetTileSet(tiles);

	//Map Dimensions 
	sf::Vector2u mapSize(10, 6);
	std::vector<int> map = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 3, 0, 0, 0, 0, 0,
		1, 2, 3, 4, 6, 1, 2, 3, 0, 0,
		4, 5, 6, 0, 0, 4, 5, 6, 0, 0
	};

	tileMap.SetTileMap(map, mapSize);
	tileMap.SetPosition(sf::Vector2f(0, window->getSize().y - (mapSize.y * tiles[0].getSize().y)));
	tileMap.BuildLevel();
	#pragma endregion
}

Level::~Level() {}

void Level::Update(float deltaTime)
{

}

void Level::HandleInput(float deltaTime)
{

}

void Level::Render()
{
	BeginDraw();

	tileMap.Render(window);

	EndDraw();
}

void Level::BeginDraw()
{
	window->clear(sf::Color(101, 148, 238, 255));
}

void Level::EndDraw()
{
	window->display();
}
