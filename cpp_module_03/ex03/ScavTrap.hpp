#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap {

    public:
        ScavTrap();
        ScavTrap(String name);

        // Redefined method
        void    attack(const String& target);
        void    guardGate();
        ~ScavTrap();
};

#endif