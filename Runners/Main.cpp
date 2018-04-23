#include "Level.h"

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Runners");
	
	//Initialise level object
	Level level(&window);

	//Game Loop
	while (window.isOpen())
	{
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
				default:
					//Don't handle other events
					break;
			}
		}
		level.HandleInput();
		level.Update();
		level.Render();
	}

	return 0;
}