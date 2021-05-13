#include <SFML/Graphics.hpp>
#include "GameState.h"

int main()
{
	StateMachine stateMachine;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Zaba na ulicy", sf::Style::Default);

	stateMachine.SetWindow(&window);
	stateMachine.SetState(new GameState(&stateMachine)); //new Menu    ale teraz niech od razu przechodzi do gry

	sf::Clock timer;
	sf::Time elapsed;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		elapsed = timer.getElapsedTime();

		if (elapsed.asMicroseconds() > 16666)
		{
			window.clear();

			stateMachine.Update();
			//stateMachine.Render();

			window.display();
			timer.restart();
		}
	}

	return 0;
}