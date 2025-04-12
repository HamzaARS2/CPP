#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->learnedMaterias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->learnedMaterias[i] = nullptr;
	
	for (int k = 0; k < 4; k++) {
		if (copy.learnedMaterias[k])
			this->learnedMaterias[k] = copy.learnedMaterias[k]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	
	for (int i = 0; i < 4; i++) {
		delete this->learnedMaterias[i];
		this->learnedMaterias[i] = nullptr;
	}
	for (int k = 0; k < 4; k++) {
		if (other.learnedMaterias[k])
			this->learnedMaterias[k] = other.learnedMaterias[k]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (!this->learnedMaterias[i]) {
			this->learnedMaterias[i] = materia->clone();
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(String const& type) {
	for (int k = 0; k < 4; k++) {
		if (this->learnedMaterias[k] && this->learnedMaterias[k]->getType() == type)
			return this->learnedMaterias[k]->clone();
	}
	return NULL;
}


MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int k = 0; k < 4; k++)
		delete this->learnedMaterias[k];
}