#include "M4.hpp"

M4::M4() {
	damage = 3;
	delay = 120.0;
}

M4::~M4() {

}

std::string M4::GetGunName() const {
    return "M4";
}
