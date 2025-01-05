#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

typedef std::string String;

class PhoneBook {
	private:
		Contact contacts[8];
		int     size;
		int     next;

	public:
        PhoneBook();
		void	addContact(Contact contact);
		void	displayContacts();
		Contact createContact(
		        String nickname,
		        String firstName,
		        String lastName,
		        String phoneNumber,
		        String DarkestSecret
		        );
};





#endif