#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	:filepath("input.txt"), db(MapBitcoinDB()) {
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

bool	BitcoinExchange::isValidEntry(const String& entry) const {
	if (entry.empty())
		return false;
	int delimiterCount = std::count(entry.begin(), entry.end(), '|');
	if (delimiterCount == 0 || delimiterCount > 1)
		return false;
	size_t pos = entry.find('|');
	if (entry[pos - 1] != 32 || entry[pos + 1] != 32)
		return false;
	while (pos < entry.length() && std::isspace(entry[pos + 1]))
		pos++;
	if (pos <= 0 || pos >= entry.length() - 1)
		return false;
	return true;
}

// bool	BitcoinExchange::isValidDateFormat(const String& entry) const {
// 	entry.
// }

void	BitcoinExchange::reportError(const String& msg, const String& entry) const {
	std::cerr << "Error: " + msg;
	if (!entry.empty())
		std::cerr << " => " + entry;
	std::cerr << std::endl;
}

bool	BitcoinExchange::parseEntry(const String& entry, std::pair<String, float>* pair) const {
	size_t pos = entry.find('|');
	char*	end;

    pair->first = entry.substr(0, pos);
	while (std::isspace(entry[pos + 1]))
		pos++;
    pair->second = std::strtod(entry.substr(pos + 1).c_str(), &end);
	if (*end != 0) {
		reportError("not a number", "");
		return false;
	}

	if (pair->second < 0) {
		reportError("not a positive number", "");
		return false;
	}
	if (pair->second > 1000) {
		reportError("too large number", "");
		return false;
	}
	return true;
}

void	BitcoinExchange::displayExchange(const String& date, float value, float dbValue) const {
	float exchangeRate = value * dbValue;
	std::cout << date + "=> " << value << " = " << exchangeRate << std::endl;
}

void	BitcoinExchange::processLine(const String& entry) const {
	if (!isValidEntry(entry)) {
		reportError("bad input", entry);
		return;
	}
	std::pair<String, float> entryPair;
	if (!parseEntry(entry, &entryPair))
		return;
	float dbValue;
	if (!db.getValue(entryPair.first, &dbValue)) {
		reportError("date not found", "");
		return;
	}
	displayExchange(entryPair.first, entryPair.second, dbValue);
}

void	BitcoinExchange::computeExchange()  {
	String entry;
	std::ifstream in;

	in.open(filepath.c_str());
	if (!in.is_open())
		throw std::runtime_error("Error: input file can't be opened.");
	std::getline(in, entry);
	while (std::getline(in, entry))
		processLine(entry);
	in.close();
}


BitcoinExchange::~BitcoinExchange() {}
