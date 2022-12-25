
#include "yellow.hpp"

YellowEnemy::YellowEnemy(sf::Vector2f pos) {
	model = sf::RectangleShape(sf::Vector2f(50, 50));

	position = pos;
	velocity = sf::Vector2f(0, 0);

	model.setFillColor(sf::Color::Yellow);
	model.setPosition(position);
	gravity = 0.001;
	on_ground = false;

	damage = 3;
	hp = 15;
}

YellowEnemy::~YellowEnemy()
{
}
