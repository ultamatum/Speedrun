#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow* hwnd, Input* inpt, GameState* gState, float* scre)
{
	window = hwnd;
	input = inpt;
	gameState = gState;
	score = scre;

	//loading the font for the game over screen
	if (!font.loadFromFile("font/arial.ttf")) { std::cout << "Error loading font\n"; }

	#pragma region Text Creation
	//Creates the Game over text
	gameOverText.setFont(font);																//Sets the font for the text
	gameOverText.setCharacterSize(36);														//Sets the character size
	gameOverText.setFillColor(sf::Color::Red);												//Sets the text colour
	gameOverText.setOutlineThickness(2);													//Sets the border thickness
	gameOverText.setOutlineColor(sf::Color::Black);											//Sets the border colour
	gameOverText.setString("You Win! You completed the course in:");						//Sets the text to display
	gameOverTextRect = gameOverText.getLocalBounds();										//Gets the rect of the text to be able to center it
	gameOverText.setOrigin(gameOverTextRect.left + gameOverTextRect.width / 2, gameOverTextRect.top + gameOverTextRect.height / 2);		//Centers the origin for the text
	gameOverText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y / 2);										//Positions the text in the center of the screen

	//Create the score text																														//Creates the score text (created in update as 
	scoreText.setFont(font);
	scoreText.setCharacterSize(48);
	scoreText.setFillColor(sf::Color::Red);
	scoreText.setOutlineThickness(2);
	scoreText.setOutlineColor(sf::Color::Black);
	
	//Create the continue text
	continueText.setFont(font);
	continueText.setCharacterSize(36);
	continueText.setFillColor(sf::Color::Red);
	continueText.setOutlineThickness(2);
	continueText.setOutlineColor(sf::Color::Black);
	continueText.setString("Press esc to return to the menu");
	sf::FloatRect continueTextRect = continueText.getLocalBounds();
	continueText.setOrigin(continueTextRect.left + continueTextRect.width / 2, continueTextRect.top + continueTextRect.height / 2);
	continueText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y - continueTextRect.height * 1.5);
	#pragma endregion
}

GameOver::~GameOver() {}

void GameOver::HandleInput() 
{
	//if escape is pressed return to the menu;
	if (input->IsKeyDown(sf::Keyboard::Escape))
	{
		gameState->SetCurrentState(State::MENU);
		input->SetKeyUp(sf::Keyboard::Escape);
	}
}

void GameOver::Update()
{
	std::ostringstream ss;		//String buffer to convert numbers to string
	ss << *score << " seconds!";
	scoreText.setString(ss.str());
	sf::FloatRect scoreTextRect = scoreText.getLocalBounds();
	scoreText.setOrigin(scoreTextRect.left + scoreTextRect.width / 2, scoreTextRect.top + scoreTextRect.height / 2);
	scoreText.setPosition(window->getView().getSize().x / 2, window->getView().getSize().y / 2 + gameOverTextRect.height + (scoreTextRect.height / 2));
}

void GameOver::Render()
{
	BeginDraw();

	window->draw(gameOverText);

	window->draw(scoreText);

	window->draw(continueText);

	EndDraw();
}

void GameOver::BeginDraw()
{
	window->clear(sf::Color(101, 148, 238, 255));
}

void GameOver::EndDraw()
{
	window->display();
}

