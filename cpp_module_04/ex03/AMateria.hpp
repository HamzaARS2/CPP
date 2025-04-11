#ifndef AMATERIA_HPP
# define AMATERIA_HPP


#include <iostream>
typedef std::string String;
#include "ICharacter.hpp"



class AMateria {
    protected:
        const String type;

    public:
        AMateria(String const& type);

        String const& getType() const;

        virtual AMateria* clone() const = 0;
        virtual void    use(ICharacter& target);

        virtual ~AMateria();
};

#endif