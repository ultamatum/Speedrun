#include "Level.h"
#include "Input.h"

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Runners");

	//Initialisation
	Input input;
	Level level(&window, &input);

	//Delta Time
	sf::Clock clock;
	float deltaTime;

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
				window.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
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

		level.HandleInput(deltaTime);
		level.Update(deltaTime);
		level.Render();
	}

#pragma endregion

	return 0;
}