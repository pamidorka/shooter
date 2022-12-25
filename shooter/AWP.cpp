#include "AWP.hpp"

AWP::AWP() {
	damage = 20;
	delay = 500.0;
}

AWP::~AWP() {

}

std::string AWP::GetGunName() const {
	return "AWP";
}