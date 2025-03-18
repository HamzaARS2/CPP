#include "Zombie.hpp"

int	main() {
	int numberOfZombies = 0;
	Zombie* zombies = zombieHorde("Klock", numberOfZombies);
	for (int i = 0; i < numberOfZombies; i++)
		zombies[i].announce();
	delete []zombies;
}