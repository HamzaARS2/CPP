#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP


#include <iostream>
typedef std::string String;

class WrongAnimal {
    protected:
        String type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);

        WrongAnimal& operator=(const WrongAnimal& other);
        String  getType() const;
        void    makeSound() const;
        virtual ~WrongAnimal();
};



#endif