#include "Harl.hpp"


Harl::Harl() {
    this->array[0] = &Harl::debug;
    this->array[1] = &Harl::info;
    this->array[2] = &Harl::warning;
    this->array[3] = &Harl::error;
}

void Harl::debug() {
    std::cout << "[ DEBUG ]\nMore bacon makes everything better!\n" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\nExtra bacon shouldn't cost extra!\n" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI deserve free bacon for being a loyal customer!\n" << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\nGet me the manager. Now!\n" << std::endl;
}


void    Harl::complain(String level) {
    String strLvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            if (level == strLvls[k]) {
                (this->*array[k])();
                return ;
            }
        }
    }
}