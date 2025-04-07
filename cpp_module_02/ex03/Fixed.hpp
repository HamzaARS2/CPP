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
        
        bool    operator>(const Fixed other) const;
        bool    operator<(const Fixed other) const;
        bool    operator>=(const Fixed other);
        bool    operator<=(const Fixed other);
        bool    operator==(const Fixed other);
        bool    operator!=(const Fixed other);

        Fixed    operator+(const Fixed other);
        Fixed    operator-(const Fixed other);
        Fixed    operator*(const Fixed other);
        Fixed    operator/(const Fixed other);

        Fixed    operator++(int); // Post-increment
        Fixed    operator++(); // Pre-increment
        Fixed    operator--(int); // Post-decrement
        Fixed    operator--(); // Pre-decrement

        static Fixed&   min(Fixed& object1, Fixed& object2);
        static const Fixed&   min(const Fixed& object1, const Fixed& object2);
        
        static Fixed&   max(Fixed& object1, Fixed& object2);
        static const Fixed&   max(const Fixed& object1, const Fixed& object2);

        int     getRawBits( void ) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        
        ~Fixed();
    };
    std::ostream& operator<<(std::ostream &out, const Fixed &fixed);



#endif