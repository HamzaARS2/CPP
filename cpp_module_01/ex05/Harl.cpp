#include "Harl.hpp"


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
    void (Harl::*debug)(void);
    void (Harl::*info)(void);
    void (Harl::*warning)(void);
    void (Harl::*error)(void);
    // (void (Harl::)) strArray[2];


}