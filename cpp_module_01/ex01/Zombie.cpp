#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Unnamed Zombie";
}

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed!" << std::endl;
}
Zombie::Zombie(String name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name
			  << " BraiiiiiiinnnzzzZ..."
			  << std::endl;
}

void Zombie::setName(String name)
{
	this->name = name;
}
String Zombie::getName()
{
	return this->name;
}