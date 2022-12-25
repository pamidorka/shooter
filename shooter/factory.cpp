#include "factory.hpp"

#include <exception>

Factory::Factory(char difficulty) {
	switch (difficulty) {
	case 0x00:
		split_one = 0.7f;
		split_two = 0.9f;
		break;
	case 0x01:
		split_one = 0.4f;
		split_two = 0.8f;
		break;
	case 0x02:
		split_one = 0.3f;
		split_two = 0.7f;
		break;
	default:
		throw std::invalid_argument("unknown difficulty");
	}
}

Factory::~Factory() {

}

Enemy Factory::GiveMe(sf::Vector2f pos) {
	float chance = rand() / (float)RAND_MAX;

	if (chance < split_one) {
		return GreenEnemy(pos);
	} 
	else if (chance < split_two) {
		return YellowEnemy(pos);
	}
	else {
		return RedEnemy(pos);
	}

}
