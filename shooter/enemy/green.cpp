
#include "green.hpp"

GreenEnemy::GreenEnemy(sf::Vector2f pos) : Enemy("green.png") {
	model = sf::RectangleShape(sf::Vector2f(50, 50));

	position = pos;
	velocity = sf::Vector2f(0, 0);

	model.setPosition(position);
	gravity = 0.001;
	on_ground = false;

	damage = 1;
	hp = 15;
}

GreenEnemy::~GreenEnemy()
{
}
