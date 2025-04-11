#include "Ice.hpp"
#include "Character.hpp"
int main() {
    AMateria* materia;
    
    materia = new Ice();
    std::cout << "type: " + materia->getType() << std::endl;
    ICharacter* ivan = new Character("ivan");
    materia->use(*ivan);
}
