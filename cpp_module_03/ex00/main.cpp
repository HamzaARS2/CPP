#include "ClapTrap.hpp"


int main() {

    ClapTrap clapTrap("Klock");

    clapTrap.attack("Zombie");
    clapTrap.takeDamage(6);
    clapTrap.beRepaired(6);
    clapTrap.beRepaired(6);
    clapTrap.beRepaired(6);
    clapTrap.takeDamage(6);
}