#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		String target;

	public:
		class FileOpenException: public std::exception {
			public:
				const char* what() const throw();
		};
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(String target);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		
		// overridden function
		void	action() const;

		static AForm*	create(String target);
		
		~ShrubberyCreationForm();
};


#endif