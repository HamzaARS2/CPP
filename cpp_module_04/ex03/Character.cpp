#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() {
    this->name = "Unnamed";
    for (int i = 0; i < 4; i++)
        this->materias[i] = NULL;
    for (int k = 0; k < 50; k++)
        this->droppedMaterias[k] = NULL;
    std::cout << "Character ["+ this->name +"] created!" << std::endl;
}

Character::Character(String name) {
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->materias[i] = NULL;
    for (int k = 0; k < 50; k++)
        this->droppedMaterias[k] = NULL;
    std::cout << "Character ["+ this->name +"] created!" << std::endl;
}

Character::Character(const Character& copy) {
    this->name = copy.name;
    
    for (int i = 0; i < 4; i++)
        this->materias[i] = NULL;
    for (int k = 0; k < 50; k++)
        this->droppedMaterias[k] = NULL;

    for (int k = 0; k < 4 ; k++) {
        if (copy.materias[k])
            this->materias[k] = copy.materias[k]->clone();
    }
    std::cout << "Character ["+ this->name +"] created!" << std::endl;
}

Character&  Character::operator=(const Character& other) {
    if (this == &other)
        return *this;
    this->name = other.name;

    for (int i = 0; i < 4; i++) {
        delete this->materias[i];
        this->materias[i] = NULL;
    }
    
    for (int k = 0; k < 4 ; k++) {
        if (other.materias[k])
            this->materias[k] = other.materias[k]->clone();
    }
    return *this;
}

void    Character::equip(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i ++) {
        if (this->materias[i] == NULL) {
            this->materias[i] = m->clone();
            std::cout << this->materias[i]->getType() + "["<< i << "] equiped!" << std::endl;
            return;
        }
    }
    // Inventory full
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    if (this->materias[idx] == NULL)
        return;

    std::cout << this->materias[idx]->getType() + "[" << idx << "] unequiped!" << std::endl;
    for (int k = 0; k < 50; k++) {
        if (this->droppedMaterias[k] == NULL) {
            this->droppedMaterias[k] = this->materias[idx];
            break;
        }
        else if (k == 49)
            delete this->materias[idx];
    }
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
    for (int i = 0; i < 4; i++)
        delete this->materias[i];
    for (int k = 0; k < 50; k++)
        delete this->droppedMaterias[k];
    std::cout << "Character ["+ this->name +"] destroyed!" << std::endl;
}
