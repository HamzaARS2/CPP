#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	for (int i = 0; i < 4; i++)
		this->learnedMaterias[i] = NULL;
	
	for (int k = 0; k < 4; k++) {
		if (copy.learnedMaterias[k])
			this->learnedMaterias[k] = copy.learnedMaterias[k]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other)
		return *this;
	
	for (int i = 0; i < 4; i++) {
		delete this->learnedMaterias[i];
		this->learnedMaterias[i] = NULL;
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

AMateria*	MateriaSource::getMateria(int idx) const {
	if (idx < 0 || idx > 3)
		return NULL;
	return this->learnedMaterias[idx];
}


MateriaSource::~MateriaSource() {
	for (int k = 0; k < 4; k++)
		delete this->learnedMaterias[k];
}