#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "loop.h"
#include "physics.h"

int main()
{
    // object creation
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Neon Piss");

    // window.setFramerateLimit(60);
    int x1 = 100;
    int y1 = 100;

    int dxpos = 0;
    int dypos = 0;
	const float squirt = 1.0f/1.41421356f;
    float xvel = .0f;
    float yvel = .0f;
    float xacc = .0f;
    float yacc = .0f;

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Blue);
    circle.setRadius(15);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(2);
    circle.setPosition(x1, y1);

    
    sf::RectangleShape platform;
    platform.setSize(sf::Vector2f(1000, 50));
    platform.setOutlineColor(sf::Color::Red);
    platform.setOutlineThickness(5);
    platform.setPosition(10, 600);

	float deltaTime = 0.0f;

	sf::Clock clock;
    bool quit = false;

    const float timestep = 1.0f/144.0f; //up to 144Hz

    // Loop to keep window updating
    while (window.isOpen())
    {
			
        deltaTime += clock.restart().asSeconds();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed) quit = true;
        }

		int dir;
        while(deltaTime >= timestep)
        {
            deltaTime -= timestep;
			dir = handleEvents();
			if (dir & UP)	 yacc -= baseacc + gravity;
			if (dir & DOWN)	 yacc += baseacc;
			if (dir & LEFT)	 xacc -= baseacc;
			if (dir & RIGHT) xacc += baseacc;

			// Acceleration is consistent in diagonals
			if (((dir & UP) || (dir & DOWN)) && ((dir & LEFT) || (dir & RIGHT))) 
            {
				xacc = xacc * squirt;
				yacc = yacc * squirt;
			}
			// NOTE(h): Aqui podemos ter um dt = deltatime?
            // movement equations (time excluded for simplicity)
            xvel = xvel + xacc + xvel*drag;
            yvel = yvel + (yacc + gravity) + yvel*drag;
            dxpos = std::round(xvel + 0.5f*xacc);
            dypos = std::round(yvel + 0.5f*yacc);


			/* std::cout << K << "\n"; */
            std::cout << xvel << " " << yvel << "\n";

            // this is just to test gravity
            if (circle.getGlobalBounds().intersects(platform.getGlobalBounds()) && dypos > 0)
            {
                dypos = 0;
            }

            // one move <3
            circle.move(dxpos, dypos);

            // reset
            yacc = .0f;
            xacc = .0f;
        }

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
			quit = true;
		}
		if (quit) window.close();

		// clear the window
        window.clear();

        // NOTE(l): criar linked list para drawables e iterar?
        window.draw(circle);
        window.draw(platform);

        //end the current frame
        window.display();

    }
    return 0;
}
