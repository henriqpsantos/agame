#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "loop.h"
#include "physics.h"

enum DIRECTION {
		UP=0x0001,
		DOWN=0x0002,
		LEFT=0x0004,
		RIGHT=0x0008
};
int main()
{
    // object creation
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Neon Piss");

    // window.setFramerateLimit(60);
    int x1 = 100;
    int y1 = 100;

    int dxpos = 0;
    int dypos = 0;
    float xvel = .0f;
    float yvel = .0f;
    float xacc = .0f;
    float yacc = .0f;

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setRadius(15);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(5);
    circle.setPosition(x1, y1);

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
			if ((dir & UP) == UP) yacc = -baseacc;
			if ((dir & DOWN) == DOWN) yacc = baseacc;
			if ((dir & LEFT) == LEFT) xacc = -baseacc;
			if ((dir & RIGHT) == RIGHT) xacc = baseacc;

            // movement equations (time excluded for simplicity)
            xvel = xvel + xacc + xvel*drag;
            yvel = yvel + yacc + yvel*drag;
            dxpos = std::round(xvel + 0.5f*xacc);
            dypos = std::round(yvel + 0.5f*yacc);
            std::cout << xvel << " " << yvel << "\n";

            // move
            circle.move(dxpos, dypos);

            // reset
            yacc = .0f;
            xacc = .0f;
        }

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			quit = true;
		}
		if (quit) window.close();

		// clear the window
        window.clear();

        window.draw(circle);

        //end the current frame
        window.display();

    }
    return 0;
}
