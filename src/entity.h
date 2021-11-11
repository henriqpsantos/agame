#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity
{
	private:
		sf::Shape * shape;
	public:
		Entity(sf::Shape *);
		sf::Shape * getShape();
		void move(int, int);
};



