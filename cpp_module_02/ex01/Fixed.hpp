#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <math.h>

class Fixed {
    private:
        int rawBits;
        static const int fraction;
    
    public:
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed& object);

        Fixed&  operator=(const Fixed& other);
        int     getRawBits( void ) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        
        ~Fixed();
    };
    std::ostream& operator<<(std::ostream &out, const Fixed &fixed);



#endif