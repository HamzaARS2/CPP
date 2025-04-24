#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		String const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;

	public:
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		Form();
		Form(const Form& copy);
		Form(String name, int gradeToSign, int gradeToExecute);

		Form&	operator=(const Form& other);

		void	beSigned(Bureaucrat& bureaucrat);

		String	getName() const;
		bool	getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		~Form();
};

std::ostream&	operator<<(std::ostream& out, const Form& form);


#endif