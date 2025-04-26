#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP


#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		String target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm(String target);

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		
		// overridden function
		void	execute(Bureaucrat const& executor) const;

		~PresidentialPardonForm();
};


#endif