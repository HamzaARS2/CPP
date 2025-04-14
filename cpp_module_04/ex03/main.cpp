#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void    showInventory(ICharacter& character) {
    std::cout << "========= ["+ character.getName() + "] Inventory ===========" << std::endl;
    for (int i = 0; i < 4; i++) {
        AMateria* materia = character.getMateria(i);
        if (materia)
        std::cout << "Slot[" << i << "] = " + materia->getType() << std::endl;
        else
        std::cout << "Slot[" << i << "] = [Empty]" << std::endl;
    }
    std::cout << "===================================" << std::endl;
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    src->learnMateria(ice);
    src->learnMateria(cure);
    Character* me = new Character("me");

    AMateria* learnedIce = src->createMateria("ice");
    AMateria* learnedCure = src->createMateria("cure");
    showInventory(*me);
    me->equip(learnedIce);
    me->equip(learnedIce);
    me->equip(learnedCure);
    me->equip(learnedIce);
    showInventory(*me);
    me->unequip(1);
    me->equip(learnedCure);
    me->unequip(2);
    showInventory(*me);
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(3);
    me->unequip(0);
    showInventory(*me);

    delete bob;
    delete me;
    delete src;
    delete ice;
    delete cure;
    return 0;
}