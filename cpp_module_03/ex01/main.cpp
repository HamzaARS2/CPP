#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Guardian");

    std::cout << "\n=== Testing Attack ===" << std::endl;
    scav.attack("EnemyBot");

    std::cout << "\n=== Testing Guard Mode ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Taking Damage ===" << std::endl;
    scav.takeDamage(30);

    std::cout << "\n=== Repairing ===" << std::endl;
    scav.beRepaired(20);

    std::cout << "\n=== Destroying ScavTrap ===" << std::endl;
    return 0;
}
