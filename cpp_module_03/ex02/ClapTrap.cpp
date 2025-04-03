#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap constructor called" << std::endl;
    this->name = "Unknown";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(String name) {
    std::cout << "ClapTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

void    ClapTrap::attack(const String& target) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
        return;
    std::cout << "ClapTrap " + this->name + " attacks " + target 
        + ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;

}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints <= 0) // already dead!
        return;
    this->hitPoints -= amount;
    if (this->hitPoints < 0) 
        this->hitPoints = 0;
    std::cout << "ClapTrap " + this->name + " took " << amount << " of damage" 
        << ", causing hit points drop to " << this->hitPoints << " hit points!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0) // dead or exhausted
        return;
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " + this->name + " repaired "<< amount 
    << " of hit points, causing increase to " << this->hitPoints
    << " hit points" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}