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
    std::cout << std::endl;
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

Contact PhoneBook::searchContact(int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index!");
    return contacts[index];
}

int PhoneBook::getSize() {
    return this->size;
}