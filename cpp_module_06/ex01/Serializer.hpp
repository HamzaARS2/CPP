#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


#include <iostream>
typedef std::string String;

struct Data {
	long id;
	String username;
	String email;
	int age;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& copy);

		Serializer&	operator=(const Serializer& other);

		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif