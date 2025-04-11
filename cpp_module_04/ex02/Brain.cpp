#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Default Idea";
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

void	Brain::setIdea(int index, const String& idea) {
	if (index < 0 || index >= 100)
		return;
	this->ideas[index] = idea;
}

String	Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
		return "";
	return this->ideas[index];
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}