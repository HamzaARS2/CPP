

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

typedef std::string String;

class Zombie {
	private:
		String name;
	public:
		Zombie();
		Zombie(String name);
		~Zombie();
		void	announce( void );
		void	setName(String name);
		String	getName();
};

Zombie* zombieHorde(String name, int N);

#endif