#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    int n = 10;
    Animal* animals[n];

    // initializing animals
    for (int i = 0 ; i < n; i++)
        if (i >= n / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    // printing animals
    for (int i = 0; i < n; i++)
        animals[i]->makeSound();
        
    std::cout << "============ TESTING DEEP COPY =============" << std::endl;
        
    Cat*  original = new Cat();
    Cat* copy = new Cat(*original);


    copy->getBrain().setIdea(0, "Updated idea!!!!!!!");
        
    std::cout << "original first idea: " + original->getBrain().getIdea(0) << std::endl;
    std::cout << "copy first idea: " + copy->getBrain().getIdea(0) << std::endl;

    delete original;
    delete copy;
    for (int i = 0; i < n; i++)
        delete animals[i];
    return 0;
}
