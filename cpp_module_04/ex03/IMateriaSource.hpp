#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(String const& type) = 0;
};


#endif