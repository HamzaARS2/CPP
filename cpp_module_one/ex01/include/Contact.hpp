#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

typedef std::string String;

class Contact {
	private:
		String nickname;
		String firstName;
		String lastName;
		String phoneNumber;
		String darkestSecret;
	public:
        // Default Constructor
		Contact();
        // Second Constructor
		Contact(String nickname, String firstName, String lastName, String phoneNumber, String darkestSecret);

		// Print class fields
		void	toString();

		// Display row of object data prefixed by index
		void    displayRow(int index);

        // Displays the given field
        static void displayField(String field);

        bool    isUndefined();

		// Setters
		void    setNickname(String nickname);
		void    setFirstName(String firstName);
		void    setLastName(String lastName);
		bool    setPhoneNumber(String phoneNumber);
		void    setDarkestSecret(String darkestSecret);
};

#endif