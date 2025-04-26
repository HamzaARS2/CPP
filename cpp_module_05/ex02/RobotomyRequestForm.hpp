#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP


#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		String target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm(String target);

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		
		// overridden function
		void	execute(Bureaucrat const& executor) const;

		~RobotomyRequestForm();
};


#endif