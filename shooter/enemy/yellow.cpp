
#include "yellow.hpp"

YellowEnemy::YellowEnemy(sf::Vector2f pos) : Enemy("yellow.png") {
	model = sf::RectangleShape(sf::Vector2f(50, 50));

	position = pos;
	velocity = sf::Vector2f(0, 0);

	model.setPosition(position);
	gravity = 0.001;
	on_ground = false;

	damage = 3;
	hp = 20;
}

YellowEnemy::~YellowEnemy() {

}
