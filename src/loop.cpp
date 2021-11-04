#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "loop.h"


// EVENTUALLY DO (DIR & ENUM) == DIR to determine it

bool handleLoop()
{
	return false;
}

int handleEvents(void)
{
	int dir = 0x0000;
	bool W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	if (W ^ S)
	{
		if (S) dir |= DOWN;
		if (W) dir |= UP;
	}
	if (D ^ A)
	{
		if (D) dir |= RIGHT;
		if (A) dir |= LEFT;
	}
	return dir;
}

