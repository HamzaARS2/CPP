#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

    public:
        WrongCat();
        WrongCat(const WrongCat& copy);

        WrongCat& operator=(const WrongCat& other);
        void    makeSound() const;
        ~WrongCat();
};



#endif
