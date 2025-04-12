#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() {
    std::cout << "Character constructor called" << std::endl;
    this->name = "Unnamed";
    for (int i = 0; i < 4; i++)
        this->materias[i] = nullptr;
}

Character::Character(String name) {
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->materias[i] = nullptr;
}

Character::Character(const Character& copy) {
    std::cout << "Character copy constructor called" << std::endl;
    this->name = copy.name;
    
    for (int i = 0; i < 4; i++)
        this->materias[i] = nullptr;

    for (int k = 0; k < 4 ; k++) {
        if (copy.materias[k])
            this->materias[k] = copy.materias[k]->clone();
    }
}

Character&  Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->name = other.name;

    for (int i = 0; i < 4; i++) {
        delete this->materias[i];
        this->materias[i] = nullptr;
    }
    
    for (int k = 0; k < 4 ; k++) {
        if (other.materias[k])
            this->materias[k] = other.materias[k]->clone();
    }
    return *this;
}

void    Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i ++) {
        if (this->materias[i] == NULL) {
            this->materias[i] = m->clone();
            return;
        }
    }
    // Inventory full
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    if (this->materias[idx] == nullptr)
        return;
    // TODO: handle how you will save the unequiped materias!
    delete this->materias[idx];
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

AMateria* Character::getMateria(int idx) const {
    if (idx < 0 || idx > 3)
        return NULL;
    return this->materias[idx];
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete this->materias[i];
    }
}
