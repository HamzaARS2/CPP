#include "Character.hpp"
#include "Ice.hpp"

Character::Character() {
    std::cout << "Character constructor called" << std::endl;
    this->name = "Unnamed";
}

Character::Character(String name) {
    this->name = name;
}

Character::Character(const Character& copy) {
    std::cout << "Character copy constructor called" << std::endl;
    this->name = copy.name;
    
    for (int i = 0; i < 4; i++)
        delete this->materias[i];
    
    for (int k = 0; k < 4 && copy.materias[k] != NULL ; k++) {
        if (copy.materias[k]->getType() == "ice")
            this->materias[k] = new Ice();
        // else
            // TODO
            
    }
}

Character&  Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->name = other.name;
    for (int i = 0; i < 4; i++)
        delete this->materias[i];
    
    for (int k = 0; k < 4 && other.materias[k] != NULL ; k++) {
        if (other.materias[k]->getType() == "ice")
            this->materias[k] = new Ice();
        // else
            // TODO
    }
    return *this;
}

void    Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i ++) {
        if (this->materias[i] == NULL)
            this->materias[i] = m;
    }
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    if (this->materias[idx] == NULL)
        return;
    // TODO: handle how you will save the unequiped materias!
    this->materias[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3)
        return;
    if (this->materias[idx] == NULL)
        return;
    this->materias[idx]->use(target);
}

String const&  Character::getName() const {
    return this->name;
}


Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
}
