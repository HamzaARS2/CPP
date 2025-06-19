#include "MapBitcoinDB.hpp"
#include <exception>
#include <algorithm>

MapBitcoinDB::MapBitcoinDB(): dbName("data.csv") {}
MapBitcoinDB::MapBitcoinDB(const String& dbName): dbName(dbName) {}



void    MapBitcoinDB::initDatabase() {
    String entry; 
    std::ifstream inStream;

    inStream.open(dbName.c_str());
     if (!inStream.is_open())
        throw std::runtime_error("Error: database can't be opened.");
    std::getline(inStream, entry);
    while (std::getline(inStream, entry)) {
        std::pair<String, float> entryPair = splitEntry(entry);
        dbMap[entryPair.first] = entryPair.second;
    }
    inStream.close();
}


bool    MapBitcoinDB::getValue(String date, float* value) const {
    std::map<String, float>::const_iterator it;

    if (dbMap.empty())
        return false;
    it = dbMap.lower_bound(date);
    if (it == dbMap.begin() && (*it).first != date)
        return false;
    if (it == dbMap.end() || (*it).first != date)
        it--;
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