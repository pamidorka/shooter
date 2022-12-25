
#include "ak.hpp"

AK::AK() {
	damage = 4;
	delay = 150.0;
}

AK::~AK() {

}

std::string AK::GetGunName() const {
	return "AK";
}
