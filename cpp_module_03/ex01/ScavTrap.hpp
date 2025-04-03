#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {

    public:
        ScavTrap();
        ScavTrap(String name);

        // Overridden method
        void    attack(const String& target);
        void    guardGate();
        ~ScavTrap();
};

#endif