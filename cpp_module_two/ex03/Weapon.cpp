#include "Weapon.hpp"

Weapon::Weapon() {
	this->type = "Don't have a weapon";
}

Weapon::Weapon(String type) {
	this->type = type;
}

const String&	Weapon::getType() {
	return this->type;
}

void	Weapon::setType(String type) {
	this->type = type;
}