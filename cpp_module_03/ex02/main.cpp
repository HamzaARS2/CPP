#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Guardian");

    std::cout << "\n=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Destroyer");

    std::cout << "\n=== Testing ScavTrap Attack ===" << std::endl;
    scav.attack("Bandit");

    std::cout << "\n=== Testing FragTrap Attack ===" << std::endl;
    frag.attack("Raider");

    std::cout << "\n=== Testing ScavTrap Guard Mode ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Testing FragTrap High Five ===" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n=== ScavTrap Taking Damage ===" << std::endl;
    scav.takeDamage(40);

    std::cout << "\n=== FragTrap Taking Damage ===" << std::endl;
    frag.takeDamage(50);

    std::cout << "\n=== Repairing FragTrap ===" << std::endl;
    frag.beRepaired(30);

    std::cout << "\n=== Destroying Objects ===" << std::endl;
    return 0;
}
