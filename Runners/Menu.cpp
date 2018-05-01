#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* inpt, GameState* gState, Level* lvl)
{
	window = hwnd;
	input = inpt;
	gameState = gState;
	level = lvl;

	if (!font.loadFromFile("font/arial.ttf")) { std::cout << "Error loading font\n"; }

	//Loops through and initialises every option with a position and values
	for (int i = 0; i < 3; i++)
	{
		options[i].setFont(font);
		options[i].setCharacterSize(72);
		options[i].setFillColor(sf::Color::White);
		options[i].setOutlineThickness(3);
		options[i].setOutlineColor(sf::Color::Black);

		switch (i)
		{
			case options::START:
				options[i].setString("Start");
				break;
			case options::HELP:
				options[i].setString("Help");
				break;
			case options::EXIT:
				options[i].setString("Quit");
				break;
		}

		sf::FloatRect textRect = options[i].getLocalBounds();
		options[i].setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
		options[i].setPosition(window->getView().getSize().x / 2, (window->getView().getSize().y / 2 + 30 + (120 * i)));
	}

	title.setFont(font);
	title.setCharacterSize(250);
	title.setFillColor(sf::Color::Red);
	title.setOutlineThickness(3);
	title.setOutlineColor(sf::Color::Black);
	title.setString("RUNNERS");
	sf::FloatRect textRect = title.getLocalBounds();
	title.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	title.setPosition(window->getView().getSize().x / 2, (window->getView().getSize().y / 4));
}

Menu::~Menu() {}

void Menu::HandleInput()
{
	if (input->IsKeyDown(sf::Keyboard::W) || input->IsKeyDown(sf::Keyboard::Up))
	{
		input->SetKeyUp(sf::Keyboard::W);
		input->SetKeyUp(sf::Keyboard::Up);
		selected--;
	}

	if (input->IsKeyDown(sf::Keyboard::S) || input->IsKeyDown(sf::Keyboard::Down))
	{
		input->SetKeyUp(sf::Keyboard::S);
		input->SetKeyUp(sf::Keyboard::Down);
		selected++;
	}

	if (input->IsKeyDown(sf::Keyboard::Return))
	{
		input->SetKeyUp(sf::Keyboard::Return);

		switch (selected)
		{
			case options::START:
				level->Reset();
				gameState->SetCurrentState(State::LEVEL);
				break;
			case options::HELP:
				gameState->SetCurrentState(State::HELP);
				break;
			case options::EXIT:
				window->close();
				break;
		}
	}
}

void Menu::Update()
{
	if (selected < 0) selected = 2;
	else if (selected > 2) selected = 0;

	for (int i = 0; i < 3; i++)
	{
		options[i].setFillColor(selected == i ? sf::Color::Red : sf::Color::White);
	}
}

void Menu::Render()
{
	BeginDraw();

	for (int i = 0; i < 3; i++)
	{
		window->draw(options[i]);
	}

	window->draw(title);

	EndDraw();
}

void Menu::BeginDraw()
{
	window->clear(sf::Color(101, 148, 238, 255));
}

void Menu::EndDraw()
{
	window->display();
}
