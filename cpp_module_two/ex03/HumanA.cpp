
#include "HumanA.hpp"


HumanA::HumanA(String name, Weapon weapon) {
	this->name = name;
	this->weapon = weapon;
}

void	HumanA::attack() {
	std::cout << this->name 
		<< " attacks with their "
		<< this->weapon.getType()
		<< std::endl;
}

void	HumanA::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}

Weapon	HumanA::getWeapon() {
	return this->weapon;
}