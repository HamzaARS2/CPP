#include "Harl.hpp"


Harl::Harl() {
    this->array[0] = &Harl::debug;
    this->array[1] = &Harl::info;
    this->array[2] = &Harl::warning;
    this->array[3] = &Harl::error;
}

void Harl::debug() {
    std::cout << "DEBUG: More bacon makes everything better!" << std::endl;
}

void Harl::info() {
    std::cout << "INFO: Extra bacon shouldn't cost extra!" << std::endl;
}

void Harl::warning() {
    std::cout << "WARNING: I deserve free bacon for being a loyal customer!" << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: Get me the manager. Now!" << std::endl;
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