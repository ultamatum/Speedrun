#include "Level.h"

using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* inpt, GameState* gState, float* scre)
{
	window = hwnd;
	input = inpt;
	score = scre;
	gameState = gState;

	//Create player
	player = Player(input, sf::Vector2f(100, 100));
	playerTexture.loadFromFile("gfx/MushroomTrans.png");
	player.setTexture(&playerTexture);

	//Creating the text for the timer
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
		tile.setSize(sf::Vector2f(32, 32));			//Each tile is at 2x scale
		tile.SetCollisionBox(0, 0, 32, 32);
		tile.SetCollider(true);
		tile.sType.SetType(Type::MAP);				//Using sprite labels for easy collision checks
		tiles.push_back(tile);
	}

	tiles[0].SetCollider(false);					//Tile 0 is used for air

	//Auto load every texture in the file
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
	//A number representation of the map each number indicates the ID of the tile from the sheet
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
		12, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		12, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
		33, 34, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 34, 32
	};

	tileMap.SetTileMap(map, mapSize);
	tileMap.SetPosition(sf::Vector2f(0, window->getSize().y - (mapSize.y * tiles[0].getSize().y)));
	tileMap.BuildLevel();
	#pragma endregion

	#pragma region Star Placement
	Collectable star;
	starTexture.loadFromFile("gfx/star.png");

	//Creating all stars and putting them in the list
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
	std::vector<Sprites>* world = tileMap.GetLevel();														//Create a vector of the world (for collision checks)
	if (!starsCollected) timer += clock.restart().asSeconds();												//Update the timer to have an accurate count of how long the level has been played

	clockText.setString(std::to_string((int)timer));														//Update the timer string
	sf::FloatRect textRect = clockText.getLocalBounds();													
	clockText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);			//Setting the origin of the text to the center so I can center it on the screen
	clockText.setPosition(sf::Vector2f(1280 / 2, 40));

	player.Update(deltaTime);

	#pragma region Collision Detection
	//Check if the player collides with the world
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

	//Check if the player collides with any stars
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

	*score = (int)timer;

	//Checks if the game should end
	if (starCount >= stars.size())
	{
		starsCollected = true;
		*score = (int)timer;
		gameState->SetCurrentState(State::GAMEOVER);
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
