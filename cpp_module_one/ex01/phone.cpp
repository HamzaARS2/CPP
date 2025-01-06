#include "include/utils.h"
#include "include/PhoneBook.hpp"
#include "include/Contact.hpp"
#include "stdlib.h"

void    displayMenu() {
    std::cout << "| Main Menu |" << "\n\n";
    std::cout << "   * ADD" << std::endl;
    std::cout << "   * SEARCH" << std::endl;
    std::cout << "   * EXIT" << "\n\n";
    std::cout << " Enter your command here: ";
}

// Commands
void    runAddCommand(PhoneBook& phoneBook) {
    Contact contact;

    contact.setFirstName(requestInput("First name: "));
    contact.setLastName(requestInput("Last name: "));
    contact.setNickname(requestInput("Nickname: "));
    while (true) {
        String phoneNumber = requestInput("Phone number: ");
        if (contact.setPhoneNumber(phoneNumber))
            break;
    }
    contact.setDarkestSecret(requestInput("Darkest secret: "));
    phoneBook.addContact(contact);
}

void    runSearchCommand(PhoneBook phoneBook) {
    String index;

    phoneBook.displayContacts();
    while (true) {
        index = requestInput("Enter an index: ");
        if (isNumeric(index, true))
            break;
        std::cout << "Invalid type of index!" << std::endl;
    }
    try {
        Contact contact = phoneBook.searchContact(atoi(index.c_str()));
        contact.toString();
    } catch(std::out_of_range& e) {
        std::cout << e.what()
            << ": please enter an index between 0 and "
            << phoneBook.getSize() - 1 << " included" << std::endl;
            runSearchCommand(phoneBook);
    }
}

// void    foo() {
//     system("leaks -q phone");
// }

int main() {
    PhoneBook phoneBook;
    String command;

    // atexit(foo);
    while (true) {
        displayMenu();
        std::getline(std::cin, command);
        if (!checkCommand(command))
            continue;
        switch (command[0]) {
            case 'A':
                runAddCommand(phoneBook);
                break;
            case 'S':
                runSearchCommand(phoneBook);
                break;
            case 'E':
                return 0;
        }
    }
}