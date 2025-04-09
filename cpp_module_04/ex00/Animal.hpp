#ifndef ANIMAL_HPP
# define ANIMAL_HPP


#include <iostream>
typedef std::string String;

class Animal {
    protected:
        String type;

    public:
        Animal();
        Animal(const Animal& copy);

        Animal& operator=(const Animal& other);
        String  getType() const;
        virtual void    makeSound() const;
        ~Animal();
};



#endif