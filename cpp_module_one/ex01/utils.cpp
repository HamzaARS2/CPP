#include "include/utils.h"

bool    checkCommand(String command) {
    if (command == "ADD" || command == "SEARCH" || command == "EXIT")
        return true;
    std::cout << "Invalid command!\n";
    return false;
}

String  requestInput(String prompt) {
    String data;
    std::cout << std::setw(20) << prompt;
    std::cin >> data;
    return data;
}

bool    isNumeric(String str) {
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}