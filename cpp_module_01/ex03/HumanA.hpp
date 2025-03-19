#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

typedef std::string String;

class HumanA {
	private:
		String name;
		Weapon& weapon;
	
	public:
		HumanA(String name, Weapon& weapon);
		void	attack();
		void	setWeapon(Weapon weapon);
		Weapon	getWeapon();
};



#endif