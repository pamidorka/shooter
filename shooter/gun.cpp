
#include "gun.hpp"

Gun::~Gun() {

}

int Gun::GetDmg() {
	return damage;
}

void Gun::Cooldown() {
	if (clock.getElapsedTime().asMilliseconds() >= delay) {
		can_shoot = true;
	}
}

bool Gun::CanShoot() {
	return can_shoot;
}

void Gun::Reset() {
	can_shoot = false;
	clock.restart();
}
