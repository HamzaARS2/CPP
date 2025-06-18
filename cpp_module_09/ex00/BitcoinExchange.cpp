#include "BitcoinExchange.hpp"
#include <cstdlib>
BitcoinExchange::BitcoinExchange(): filepath("unset") {
	// this->db = MapBitcoinDB("data.csv");
}

BitcoinExchange::BitcoinExchange(const String& filepath, MapBitcoinDB& db)
	:filepath(filepath), db(db) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy): filepath(copy.filepath) {
	*this = copy;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other)
		return *this;
	return *this;
}

std::pair<String, float>    splitEntry(const String& entry) {
    std::pair<String, float> entryPair;
    size_t pos = entry.find('|');

    entryPair.first = entry.substr(0, pos);
    entryPair.second = atof(entry.substr(pos + 1).c_str());
    
    return entryPair;
}

void	BitcoinExchange::computeExchange()  {
	String entry;
	std::ifstream in;

	in.open(filepath.c_str());
	if (!in.is_open())
		throw std::runtime_error("Error: input file can't be opened.");
	std::getline(in, entry);
	while (std::getline(in, entry)) {
		float dbValue;
		std::pair<String, float> entryPair = splitEntry(entry);
		this->db.getValue(entryPair.first, &dbValue);
		std::cout << entryPair.first + " => " << entryPair.second << " = " << entryPair.second * dbValue << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange() {}
