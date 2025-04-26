#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class AForm {
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
		class FormNotSignedExecption: public std::exception {
			public:
				const char* what() const throw();
		};
		AForm();
		AForm(const AForm& copy);
		AForm(String name, int gradeToSign, int gradeToExecute);

		AForm&	operator=(const AForm& other);

		void	beSigned(Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const& executor) const;
		virtual void	action() const = 0;

		String	getName() const;
		bool	getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		virtual ~AForm();
};

std::ostream&	operator<<(std::ostream& out, const AForm& aForm);


#endif