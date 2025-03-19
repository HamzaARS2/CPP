

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

typedef std::string String;

class Zombie {
	private:
		String name;
	public:
		Zombie(String name);
		~Zombie();
		void	announce( void );
};

Zombie*	newZombie(String name);
void	randomChump(String name);






#endif