#include "include/utils.h"
#include "include/PhoneBook.hpp"
#include "include/Contact.hpp"

void    displayMenu() {
    std::cout << "| Main Menu |" << "\n\n";
    std::cout << "   *ADD" << std::endl;
    std::cout << "   *SEARCH" << std::endl;
    std::cout << "   *EXIT" << "\n\n";
    std::cout << " Enter your command here: ";
}

// Commands
void    runAddCommand(PhoneBook& phoneBook) {
    Contact contact;

    String firstName = requestInput("First name: ");
    contact.setFirstName(firstName);
    String lastName = requestInput("Last name: ");
    contact.setLastName(lastName);
    String nickName = requestInput("Nickname: ");
    contact.setNickname(nickName);
    while (true) {
        String phoneNumber = requestInput("Phone Number: ");
        if (contact.setPhoneNumber(phoneNumber))
            break;
        std::cout << "Invalid phone number, try again!" << std::endl;
    }
    String darkestSecret = requestInput("Darkest secret: ");
    contact.setDarkestSecret(darkestSecret);
    // TODO: add a method to the contact class for checking if all fields are empty.
    if (!contact.isUndefined())
        phoneBook.addContact(contact);
}

void    runSearchCommand(PhoneBook phoneBook) {
    phoneBook.displayContacts();
}


int main() {
    PhoneBook phoneBook;
    String command;

    while (true) {
        displayMenu();
        std::cin  >> command;
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