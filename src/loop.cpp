#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


// EVENTUALLY DO (DIR & ENUM) == DIR to determine it
enum DIRECTION {
		UP=0x0001,
		DOWN=0x0002,
		LEFT=0x0004,
		RIGHT=0x0008
};

bool handleLoop()
{
	return false;
}

int handleEvents(void)
{
	int dir = 0x0000;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dir |= RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		dir |= LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dir |= UP;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir |= DOWN;
	}
	return dir;
}
