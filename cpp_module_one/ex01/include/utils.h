#ifndef PHONE_H
# define PHONE_H

#include "PhoneBook.hpp"
#include "Contact.hpp"

// Utils.
bool    checkCommand(String command);
String  requestInput(String prompt);
bool    isNumeric(String str);
#endif