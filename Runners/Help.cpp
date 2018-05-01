#include "Help.h"

Help::Help(sf::RenderWindow* hwnd, Input* inpt, GameState* gState)
{
	window = hwnd;
	input = inpt;
	gameState = gState;

	sf::FloatRect textRect;

	if (!font.loadFromFile("font/arial.ttf")) { std::cout << "Error loading font\n"; }


	//Simple repetetive code to setup each line of text and place it correctly on the screen
	#pragma region Left / Right Text Setup
	leftrightText.setFont(font);
	leftrightText.setCharacterSize(36);
	leftrightText.setFillColor(sf::Color::Red);
	leftrightText.setOutlineThickness(2);
	leftrightText.setOutlineColor(sf::Color::Black);
	leftrightText.setString("Use A / D to move Left / Right");
	textRect = leftrightText.getLocalBounds();
	leftrightText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	leftrightText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y / 4);
	#pragma endregion

	#pragma region Jump Text Setup
	jumpText.setFont(font);
	jumpText.setCharacterSize(36);
	jumpText.setFillColor(sf::Color::Red);
	jumpText.setOutlineThickness(2);
	jumpText.setOutlineColor(sf::Color::Black);
	jumpText.setString("Use SPACE to Jump");
	textRect = jumpText.getLocalBounds();
	jumpText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	jumpText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y / 4 * 1.5);
	#pragma endregion

	#pragma region Pause Text Setup
	pauseText.setFont(font);
	pauseText.setCharacterSize(36);
	pauseText.setFillColor(sf::Color::Red);
	pauseText.setOutlineThickness(2);
	pauseText.setOutlineColor(sf::Color::Black);
	pauseText.setString("Use P to Pause the game");
	textRect = pauseText.getLocalBounds();
	pauseText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	pauseText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y / 4 * 2);
	#pragma endregion

	#pragma region Intro Text Setup
	introText.setFont(font);
	introText.setCharacterSize(36);
	introText.setFillColor(sf::Color::Red);
	introText.setOutlineThickness(2);
	introText.setOutlineColor(sf::Color::Black);
	introText.setString("Collect all the stars as fast as possible to win!");
	textRect = introText.getLocalBounds();
	introText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	introText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y / 4 * 2.5);
	#pragma endregion

	#pragma region Return Text Setup
	returnText.setFont(font);
	returnText.setCharacterSize(36);
	returnText.setFillColor(sf::Color::Red);
	returnText.setOutlineThickness(2);
	returnText.setOutlineColor(sf::Color::Black);
	returnText.setString("Press esc to return to the menu");
	textRect = returnText.getLocalBounds();
	returnText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	returnText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y - textRect.height * 1.5);
	#pragma endregion
}

Help::~Help(){}

void Help::HandleInput()
{
	//If escape is pressed return to the menu
	if (input->IsKeyDown(sf::Keyboard::Escape))
	{
		input->SetKeyUp(sf::Keyboard::Escape);
		gameState->SetCurrentState(State::MENU);
	}
}

void Help::Render()
{
	BeginDraw();

	window->draw(leftrightText);

	window->draw(jumpText);

	window->draw(pauseText);

	window->draw(introText);

	window->draw(returnText);
	
	EndDraw();
}

void Help::BeginDraw()
{
	window->clear(sf::Color(101, 148, 238, 255));
}

void Help::EndDraw()
{
	window->display();
}