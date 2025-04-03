#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = "Unknown ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(String name) {
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

void    ScavTrap::attack(const String& target) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
        return;
    std::cout << "ScavTrap " + this->name + " attacks " + target 
        + ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;

}
void    ScavTrap::guardGate() {
    std::cout << "ScavTrap activated Gate Keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}