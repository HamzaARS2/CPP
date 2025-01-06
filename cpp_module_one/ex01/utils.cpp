#include "include/utils.h"

bool    checkCommand(String command) {
    if (command == "ADD" || command == "SEARCH" || command == "EXIT")
        return true;
    std::cout << "Invalid command!\n";
    return false;
}

String  requestInput(String prompt) {
    String data;
    while (true) {
        std::cout << std::setw(15) << std::left << prompt ;
        std::getline(std::cin, data);
        if (!data.empty())
            break;
        std::cout << "This field cant be empty!" << std::endl;
    }
    return data;
}

bool    isNumeric(String str) {
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}