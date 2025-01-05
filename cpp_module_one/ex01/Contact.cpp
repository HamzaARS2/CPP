#include "include/Contact.hpp"
#include "include/utils.h"

Contact::Contact() {
	this->nickname = "Undefined";
	this->firstName = "Undefined";
	this->lastName = "Undefined";
	this->phoneNumber = "Undefined";
	this->darkestSecret = "Undefined";
}

Contact::Contact(
	String nickname,
	String firstName,
	String lastName,
	String phoneNumber,
	String darkestSecret) {
	this->nickname = nickname;
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void    Contact::displayField(String field) {
    if (field.size() > 10) {
        field = field.substr(0, 10);
        field[field.size() - 1] = '.';
    }
    // Setting a specific width.
    std::cout << std::setw(10);
    std::cout << field << "|";
}


void    Contact::displayRow(int index) {
    String data[] = {this->firstName, this->lastName, this->nickname};
    // Printing index.
    std::cout << std::setw(10);
    std::cout << index << "|";
    // Display fields of a row
    for (int i = 0; i < 3; i++) {
        Contact::displayField(data[i]);
    }
}

bool    Contact::isUndefined() {
    String data[] = {firstName, lastName, nickname, phoneNumber, darkestSecret};
    for (int i = 0; i < 5; i++) {
        if (data[i] != "Undefined")
            return false;
    }
    return true;
}

// Builder Setters
void    Contact::setNickname(String nickname) {
    this->nickname = nickname;
}

void    Contact::setFirstName(String firstName) {
    this->firstName = firstName;
}

void    Contact::setLastName(String lastName) {
    this->lastName = lastName;
}

bool    Contact::setPhoneNumber(String phoneNumber) {
    if (!isNumeric(phoneNumber))
        return false;
    this->phoneNumber = phoneNumber;
    return true;
}

void    Contact::setDarkestSecret(String darkestSecret) {
    this->darkestSecret = darkestSecret;
}

void	Contact::toString() {
	std::cout << "nickname: " << nickname << "\n"
			<< "First Name: " << firstName << "\n"
			<< "Last Name: " << lastName << "\n"
			<< "Phone Number: " << phoneNumber << "\n"
			<< "Darkest Secret: " << darkestSecret
			<< std::endl;
}
