#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = "Unknown FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(String name): ClapTrap(name) {
    std::cout << "FragTrap constructor called" + name << std::endl;
    this->hitPoints = 100;
    this->attackDamage = 30;
}


void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " + this->name + " requests a high five!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}