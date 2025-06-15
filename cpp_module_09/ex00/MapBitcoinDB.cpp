#include "MapBitcoinDB.hpp"
#include <exception>
#include <algorithm>

MapBitcoinDB::MapBitcoinDB(const String& dbName): dbName(dbName) {}



void    MapBitcoinDB::initDatabase() {
    String entry; 
    std::ifstream inStream;

    inStream.open(dbName);
     if (!inStream.is_open())
        throw std::runtime_error("Error: database can't be opened.");
    std::getline(inStream, entry);
    while (std::getline(inStream, entry)) {
        std::pair<String, float> entryPair = splitEntry(entry);
        dbMap[entryPair.first] = entryPair.second;
    }
    inStream.close();
}


bool    MapBitcoinDB::getValue(const String& date, float* value) {
    std::map<String, float>::iterator it;
    it = dbMap.lower_bound(date);
    if ((*it).first != date)
        it--;
    std::cout << "key: " + (*it).first + " | value: " << (*it).second << std::endl;
    *value = (*it).second;
    return true;
}


std::pair<String, float>    MapBitcoinDB::splitEntry(const String& entry) const {
    std::pair<String, float> entryPair;
    size_t pos = entry.find(',');

    entryPair.first = entry.substr(0, pos);
    entryPair.second = std::atof(entry.substr(pos + 1).c_str());
    
    return entryPair;
}


MapBitcoinDB::~MapBitcoinDB() {
    
}