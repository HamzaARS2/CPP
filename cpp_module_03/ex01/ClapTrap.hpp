#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

typedef std::string String;

class ClapTrap {
    protected:
        String  name;
        int     hitPoints;
        int     energyPoints;
        int     attackDamage;

    public:
        ClapTrap();
        ClapTrap(String name);

        void    attack(const String& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        
        ~ClapTrap();
};


#endif