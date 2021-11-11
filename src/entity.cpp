#include <SFML/Graphics.hpp>
#include "entity.h"

Entity::Entity (sf::Shape * shape)
{
	this->shape = shape;
}

void Entity::move(int dx, int dy)
{
	this->shape->move(dx, dy);
}

sf::Shape * Entity::getShape()
{
	return this->shape;
}

