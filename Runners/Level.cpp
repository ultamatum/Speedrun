#include "Level.h"

using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* inpt)
{
	window = hwnd;
	input = inpt;

	player = Player(input, sf::Vector2f(100, 100));
	playerTexture.loadFromFile("gfx/MushroomTrans.png");
	player.setTexture(&playerTexture);

	if (!font.loadFromFile("font/arial.ttf")) { std::cout << "Error loading font\n"; }

	clockText.setFont(font);
	clockText.setCharacterSize(24);
	clockText.setFillColor(sf::Color::White);
	clockText.setOutlineColor(sf::Color::Black);

	#pragma region TileMap Creation
	tileMap.LoadTexture((char*)"gfx/marioTiles.png");

	Sprites tile;
	std::vector<Sprites> tiles;

	for (int i = 0; i < 54; i++)
	{
		tile.setSize(sf::Vector2f(32, 32));
		tile.SetCollisionBox(0, 0, 32, 32);
		tile.SetCollider(true);
		tile.sType.SetType(Type::MAP);
		tiles.push_back(tile);
	}

	tiles[0].SetCollider(false);

	for (int y = 0; y < tileMap.GetTileSetSize().y / 17; y++)
	{
		for (int x = 0; x < tileMap.GetTileSetSize().x / 17; x++)
		{
			tiles[x + (y * 9)].setTextureRect(sf::IntRect(17 * x, 17 * y, 16, 16));
		}
	}

	tileMap.SetTileSet(tiles);

	//Map Dimensions 
	sf::Vector2u mapSize(40, 23);
	std::vector<int> map = {
		11, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 11,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		33, 34, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 34, 32
	};

	tileMap.SetTileMap(map, mapSize);
	tileMap.SetPosition(sf::Vector2f(0, window->getSize().y - (mapSize.y * tiles[0].getSize().y)));
	tileMap.BuildLevel();
	#pragma endregion

	#pragma region Star Placement
	Collectable star;
	starTexture.loadFromFile("gfx/star.png");
	for (int i = 0; i < 1; i++)
	{
		star.setSize(sf::Vector2f(32, 32));
		star.SetCollisionBox(0, 0, 32, 32);
		star.SetCollider(true);
		star.sType.SetType(Type::COLLECTABLE);
		star.SetAlive(true);
		star.setTexture(&starTexture);
		stars.push_back(star);
	}

	stars[0].setPosition(200, 500);
	#pragma endregion
}

Level::~Level() {}

void Level::Update(float deltaTime)
{
	std::vector<Sprites>* world = tileMap.GetLevel();
	timer += clock.restart().asSeconds();

	clockText.setString(std::to_string((int)timer));
	sf::FloatRect textRect = clockText.getLocalBounds();
	clockText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	clockText.setPosition(sf::Vector2f(1280 / 2, 40));

	player.Update(deltaTime);	 

	#pragma region Collision Detection
	for (int i = 0; i < (int)world->size(); i++)
	{
		if ((*world)[i].IsCollider())
		{
			if (Collision::CheckBoundingBox(&player, &(*world)[i]))
			{
				player.CollisionResponse(&(*world)[i]);
			}
		}
	}

	for (int i = 0; i < (int)stars.size(); i++)
	{
		if (stars[i].IsAlive())
		{
			if (Collision::CheckBoundingBox(&player, &stars[i]))
			{
				stars[i].SetAlive(false);
				starCount++;
			}
		}
	}
	#pragma endregion

	if (starCount >= stars.size())
	{

	}
}

void Level::HandleInput(float deltaTime) {}

void Level::Render()
{
	BeginDraw();

	tileMap.Render(window);

	window->draw(player);

	window->draw(clockText);

	for (int i = 0; i < stars.size(); i++)
	{
		if (stars[i].IsAlive())
		{
			window->draw(stars[i]);
		}
	}

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
