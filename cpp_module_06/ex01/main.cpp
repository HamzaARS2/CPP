#include "Serializer.hpp"

void	printData(Data* data) {
	std::cout << "id: " << data->id << std::endl;
	std::cout << "username: " << data->username << std::endl;
	std::cout << "email: " << data->email << std::endl;
	std::cout << "age: " << data->age << std::endl;
}

int main() {
	Data data = {101, "Fennec", "octane@gmail.com", 56};
	Data *ptr = &data;

	std::cout << "========== BEFORE ===========" << std::endl;
	printData(ptr);
	
	std::cout << "\nSerializing ..." << std::endl;
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "raw: " << raw << "" << std::endl;

	std::cout << "Deserializing ..." << std::endl;
	Data *deserializedData = Serializer::deserialize(raw);
	std::cout << "\n========== AFTER ===========" << std::endl;
	printData(deserializedData);

    return 0;
}