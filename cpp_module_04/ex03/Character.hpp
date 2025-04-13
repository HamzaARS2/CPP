#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter {
    public:
        String name;
        AMateria* materias[4];
        AMateria* droppedMaterias[50];
    
    public:
        Character();
        Character(String name);
        Character(const Character& copy);

        Character&  operator=(const Character& other);
        
        // overriden methods
        String  const& getName() const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
        
        AMateria*   getMateria(int idx) const;

        ~Character();
};


#endif