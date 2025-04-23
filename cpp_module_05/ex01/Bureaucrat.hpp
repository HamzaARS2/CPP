#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

typedef std::string String;

class Bureaucrat {

	private:
		const String name;
		int grade;

	public:
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(String name, int grade);

		Bureaucrat&	operator=(const Bureaucrat& other);
		
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);

		String	getName() const;
		int		getGrade() const;

		~Bureaucrat();
};
std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif