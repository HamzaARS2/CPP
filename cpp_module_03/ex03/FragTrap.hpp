#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(String name);

        void    highFivesGuys(void);

        ~FragTrap();
};


#endif