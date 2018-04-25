#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* inpt)
{
	window = hwnd;
	input = inpt;
}

Level::~Level() {}

void Level::Update()
{

}

void Level::HandleInput()
{

}

void Level::Render()
{
	BeginDraw();

	EndDraw();
}

void Level::BeginDraw()
{
	window->clear(sf::Color::Black);
}

void Level::EndDraw()
{
	window->display();
}
