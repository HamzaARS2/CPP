#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

typedef std::string String;

class HumanB {
	private:
		String name;
		Weapon weapon;
	
	public:
		HumanB(String name);
		void	attack();
		void	setWeapon(Weapon weapon);
		Weapon	getWeapon();
};



#endif