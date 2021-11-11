#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "loop.h"
#include "physics.h"
#include "entity.h"

int main()
{
    // object creation
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Neon Piss");

    // window.setFramerateLimit(60);
    int dxpos = 0;
    int dypos = 0;

	const float squirt = 1.0f/1.41421356f;
    float xvel = .0f;
    float yvel = .0f;
    float xacc = .0f;
    float yacc = .0f;

	// CLEANUP(h): Move this to a setupEntities function to load player and enemy data
    sf::CircleShape enem;
    enem.setFillColor(sf::Color::Red);
    enem.setRadius(5);
    enem.setOutlineColor(sf::Color::White);
    enem.setOutlineThickness(1);
    enem.setPosition(700,400);

    sf::CircleShape play;
    play.setFillColor(sf::Color::Blue);
    play.setRadius(15);
    play.setOutlineColor(sf::Color::White);
    play.setOutlineThickness(2);
    play.setPosition(100,100);

    sf::RectangleShape plat;
    plat.setSize(sf::Vector2f(1000, 50));
    plat.setOutlineColor(sf::Color::Red);
    plat.setOutlineThickness(5);
    plat.setPosition(10, 600);

	// Sprites instead of shapes?
	Entity enemy(&enem);
	Entity player(&play);
	Entity platform(&plat);

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

		unsigned int dir;
        while(deltaTime >= timestep)
        {
            deltaTime -= timestep;
			dir = handleEvents();
			if (dir & UP) yacc -= baseacc + gravity;
			else if (dir & DOWN) yacc += baseacc;

			if (dir & LEFT)	 xacc -= baseacc;
			else if (dir & RIGHT) xacc += baseacc;

			// FIXME(h): Does this work?
			// Exactly 2 directions are pressed
			if (__builtin_popcount(dir) > 1)
            {
				xacc = xacc * squirt;
				yacc = yacc * squirt;
				std::cout << __builtin_popcount(dir) << "\n";
			}

			// NOTE(h): Aqui podemos ter um dt = deltatime?
            // movement equations (time excluded for simplicity)
            xvel = xvel + xacc + xvel*drag;
            yvel = yvel + (yacc + gravity) + yvel*drag;
            dxpos = std::round(xvel + 0.5f*xacc);
            dypos = std::round(yvel + 0.5f*yacc);

            std::cout << xvel << " " << yvel << "\n";

			// FIXME(h): I broke this :(
            if (false) // player.getGlobalBounds().intersects(platform.getGlobalBounds()) && dypos > 0)
            {
                dypos = 0;
            }


			// FIXME(h): I broke this :(
            if ( false) //player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
            {
				// NOTE: AUTOQUIT :)
                quit = true;
            }
            // one move <3
            player.move(dxpos, dypos);

            // reset
            yacc = .0f;
            xacc = .0f;
        } // Physics code

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
			quit = true;
		}

		if (quit) window.close();

		// NOTE(h): RENDERING BEGINS
        window.clear();
        // NOTE(l): criar linked list para drawables e iterar?
		// FIXME(h): Entity linked list ^ to draw

		window.draw(*player.getShape());
		window.draw(*enemy.getShape());
		window.draw(*platform.getShape());

        //end the current frame
        window.display();
    }
    return 0;
}
