#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

typedef std::string String;

class Weapon {
	private:
		String type;
	
	public:
		Weapon();
		Weapon(String type);
		const String& getType();
		void	setType(String type);
};




#endif