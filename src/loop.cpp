#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "loop.h"

int handleEvents(void)
{
	int dir = 0x0000;
	// Poll keys first
	bool W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	
	if (W ^ S)
	{
		if (S) {dir |= DOWN;}
		else dir |= UP;
	}

	if (D ^ A)
	{
		if (D) {dir |= RIGHT;}
		else dir |= LEFT;
		
	}
	return dir;
}


