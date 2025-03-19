
#include "HumanB.hpp"


HumanB::HumanB(String name) {
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::attack() {

	std::cout << this->name 
		<< " attacks with their "
		<< (this->weapon ? this->weapon->getType() : "hands")
		<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

Weapon	HumanB::getWeapon() {
	return *(this->weapon);
}