#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

typedef std::string String;

class Brain {
	private:
		String ideas[100];

	public:
		Brain();
		Brain(const Brain& copy);

		Brain&	operator=(const Brain& other);

		~Brain();
};


#endif