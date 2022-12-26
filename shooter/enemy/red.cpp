
#include "red.hpp"

RedEnemy::RedEnemy(sf::Vector2f pos) : Enemy("red.png") {
	model = sf::RectangleShape(sf::Vector2f(50, 50));

	position = pos;
	velocity = sf::Vector2f(0, 0);
	
	model.setPosition(position);
	gravity = 0.001;
	on_ground = false;

	damage = 5;
	hp = 30;
}

RedEnemy::~RedEnemy() {

}


