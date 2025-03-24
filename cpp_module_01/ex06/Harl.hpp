#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
typedef std::string String;

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define OTHER 4

class Harl {
    private:
        void    (Harl::*array[5])(void);

        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
        void    other( void );
        void    checkLevel(int lvl);
    public:
        Harl( void );
        void    complain(String level);
};



#endif