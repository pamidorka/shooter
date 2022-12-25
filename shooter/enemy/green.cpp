
#include "green.hpp"

GreenEnemy::GreenEnemy(sf::Vector2f pos) {
	model = sf::RectangleShape(sf::Vector2f(50, 50));

	position = pos;
	velocity = sf::Vector2f(0, 0);

	model.setFillColor(sf::Color::Green);
	model.setPosition(position);
	gravity = 0.001;
	on_ground = false;

	damage = 1;
	hp = 15;
}

GreenEnemy::~GreenEnemy()
{
}
