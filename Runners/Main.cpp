#include <iostream>
#include "Level.h"
#include "Input.h"
#include "GameState.h"

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Runners");

	//Initialisation
	GameState gameState;
	Input input;
	Level level(&window, &input);

	//Delta Time
	sf::Clock clock;
	float deltaTime;

	gameState.SetCurrentState(State::LEVEL);

	#pragma region Game Loop
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		#pragma region Window Event Handler
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//window.setSize(sf::Vector2u(1280, 720));		//May change back to this
				window.setView(sf::View(sf::FloatRect(0, 0, 1280, 720)));
				break;
			case sf::Event::KeyPressed:
				input.SetKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				input.SetKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				input.SetMousePosition(event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
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
		switch (gameState.GetCurrentState())
		{
			case (State::MENU):

				break;
			case (State::LEVEL):
				level.HandleInput(deltaTime);
				level.Update(deltaTime);
				level.Render();

				std::cout << window.getSize().y << std::endl;
				break;
			case (State::CREDITS):

				break;
		}
		#pragma endregion
	}

	#pragma endregion

	return 0;
}