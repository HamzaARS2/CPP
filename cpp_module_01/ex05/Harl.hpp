#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

typedef std::string String;

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

class Harl {
    private:
        void    (Harl::*array[4])(void);

        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
    public:
        Harl( void );
        void    complain(String level);
};



#endif