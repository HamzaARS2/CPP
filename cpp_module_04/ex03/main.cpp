#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void    showInventory(ICharacter& character) {
    std::cout << "========= ["+ character.getName() + "] Inventory ===========" << std::endl;
    for (int i = 0; i < 4; i++) {
        AMateria* materia = character.getMateria(i);
        if (materia)
            std::cout << "slot[" << i << "] = " + materia->getType() << std::endl;
        else
            std::cout << "slot[" << i << "] = [Empty]" << std::endl;
    }
}

void    foo() {
    system("leaks -q interface");
}

int main() {
    atexit(foo);
    AMateria* iceMateria;
    AMateria* cureMateria;

    iceMateria = new Ice();
    cureMateria = new Cure();
    std::cout << "type: " + iceMateria->getType() << std::endl;
    std::cout << "type: " + cureMateria->getType() << std::endl;
    Character* klock = new Character("klock");
    iceMateria->use(*klock);
    cureMateria->use(*klock);

    klock->equip(iceMateria);
    klock->equip(cureMateria);
    klock->equip(iceMateria);
    klock->equip(cureMateria);
    klock->unequip(1);
    klock->equip(cureMateria);

    Character* glock = new Character(*klock);
    glock->unequip(1);
    showInventory(*glock);
    Character* block = new Character(*glock);
    showInventory(*block);

    Character assign;
    assign = *block;
    assign.unequip(2);
    std::cout << "assign" << std::endl;
    showInventory(assign);
    std::cout << "block" << std::endl;
    showInventory(*block);
    
    delete iceMateria;
    delete cureMateria;
    delete klock;
    delete glock;
    delete block;
}
