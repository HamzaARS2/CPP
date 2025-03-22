#include "Harl.hpp"


Harl::Harl() {
    this->array[0] = &(this->debug);
    this->array[1] = Harl::info;
    this->array[2] = Harl::warning;
    this->array[3] = Harl::error;
}

void    Harl::debug() {
    std::cout << "debug:I love having extra bacon for my \
    7XL-double-cheese-triple-pickle-specialketchup \
    burger. I really do!" << std::endl;

}
void    Harl::info() {
    std::cout << "info:I cannot believe adding extra bacon costs more money. \
    You didn’t put enough bacon in my burger! If you did, \
    I wouldn’t be asking for more!" << std::endl;

}
void    Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. \
    I’ve been coming for years, whereas you started \
    working here just last month." << std::endl;

}
void    Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now."
        << std::endl;

}

void    Harl::complain(String level) {
    String strLvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level.compare(strLvls[i])) {
            this->array[i];
            break;
        }
    }
}