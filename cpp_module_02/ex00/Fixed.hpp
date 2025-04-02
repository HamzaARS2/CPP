#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>

class Fixed {
    private:
        int fixedPoint;
        static const int fraction = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& object);

        Fixed&  operator=(const Fixed& other);
        int     getRawBits( void ) const;
        void    setRawBits(int const raw);

        ~Fixed();
};



#endif