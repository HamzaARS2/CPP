#include "include/PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->size = 0;
    this->next = 0;
}

void    PhoneBook::addContact(Contact contact) {
    if (this->size >= 8 && this->next >= 8)
        this->next = 0;
    this->contacts[next++] = contact;
    if (size < 8) size++;
}

void    PhoneBook::displayContacts() {
    Contact::displayField("Index");
    Contact::displayField("First name");
    Contact::displayField("Last name");
    Contact::displayField("P.Number");

    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        Contact::displayField("__________");

    std::cout << std::endl;
    for (int i = 0; i < this->size; i++) {
        this->contacts[i].displayRow(i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}