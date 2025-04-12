#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria* learnedMaterias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);

		MateriaSource&	operator=(const MateriaSource& other);

		// overridden methods
		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(String const& type);

		~MateriaSource();
};


#endif