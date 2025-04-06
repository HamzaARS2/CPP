#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap constructor called" << std::endl;
    this->name = "Unknown DiamondTrap";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(String name)
    : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name) {
        std::cout << "DiamondTrap constructor called" << std::endl;
        this->name = name;
        this->hitPoints = FragTrap::hitPoints;
        this->energyPoints = ScavTrap::energyPoints;
        this->attackDamage = FragTrap::attackDamage;
    }

void    DiamondTrap::whoAmI() {
    std::cout << "My name is " << this->name << " and my clap trap name is " 
        << ClapTrap::name << std::endl;
}


DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;

}