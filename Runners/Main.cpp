#include <iostream>
#include "Level.h"
#include "GameOver.h"
#include "Input.h"
#include "GameState.h"

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Runners");

	//Global Game Variables
	float score;

	//Initialisation
	GameState gameState;
	Input input;
	Level level(&window, &input, &gameState, &score);
	GameOver gameOver(&window, &input, &gameState, &score);

	//Delta Time
	sf::Clock clock;
	float deltaTime;

	gameState.SetCurrentState(State::LEVEL);

	#pragma region Game Loop
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();				//Keeps track of time between frames

		#pragma region Window Event Handler
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();						//Closes window if x button pressed
				break;
			case sf::Event::Resized:
				//window.setSize(sf::Vector2u(1280, 720));		//May change back to this
				window.setView(sf::View(sf::FloatRect(0, 0, 1280, 720)));
				break;
			case sf::Event::KeyPressed:
				input.SetKeyDown(event.key.code);	//Updates the input class for when keys are pressed
				break;
			case sf::Event::KeyReleased:
				input.SetKeyUp(event.key.code);		//Updates the input class for when keys are released
				break;
			case sf::Event::MouseMoved:
				input.SetMousePosition(event.mouseMove.x, event.mouseMove.y);			//Updates the mouse in the input class
				break;
			case sf::Event::MouseButtonPressed:
				//Updates the input class for mouse buttons being pressed
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					input.SetMouseLeftDown(true);
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.SetMouseRightDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				//Updates the input class for mouse buttons being released
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					input.SetMouseLeftDown(false);
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.SetMouseRightDown(false);
				}
				break;
			default:
				//Don't handle other events
				break;
			}
		}
		#pragma endregion

		#pragma region Game State Handler
		//Chooses what to draw and update each frame
		switch (gameState.GetCurrentState())
		{
			case (State::MENU):

				break;
			case (State::LEVEL):
				level.HandleInput(deltaTime);
				level.Update(deltaTime);
				level.Render();
				break;
			case (State::GAMEOVER):
				gameOver.HandleInput();
				gameOver.Update();
				gameOver.Render();
				break;
			case (State::HELP):

				break;
		}
		#pragma endregion
	}

	#pragma endregion

	return 0;
}