#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
    private:
        String name;

    public:
        DiamondTrap();
        DiamondTrap(String name);

        void    whoAmI();
        ~DiamondTrap();
};


#endif