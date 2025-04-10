#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    int n = 10;
    Animal* animals = new Animal[n];

    // initializing animals
    for (int i = 0 ; i < n; i++)
        if (i >= n / 2)
            animals[i] = Dog();
        else
            animals[i] = Cat();
    // printing animals
    for (int i = 0; i < n; i++)
        std::cout << animals[i].getType() << std::endl;
    
    delete []animals;
    system("leaks -q brain");
    return 0;
}
