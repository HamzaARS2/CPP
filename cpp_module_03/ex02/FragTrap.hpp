#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP


#include "ScavTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        FragTrap();
        FragTrap(String name);

        void    highFivesGuys(void);

        ~FragTrap();
};


#endif