#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

float deltaTime = 0.0f;
bool handleLoop(float step)
{
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed) return true;
        }

        deltaTime += clock.restart().asSeconds();

        while(deltaTime >= timestep)
        {
            deltaTime -= timestep;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                circle.move(15, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                circle.move(-15, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                circle.move(0, -15);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                circle.move(0, 15);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				return true;
            }
        }
}
