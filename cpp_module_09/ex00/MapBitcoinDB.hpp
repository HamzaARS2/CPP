#ifndef MAP_BITCOIN_DB_HPP
# define MAP_BITCOIN_DB_HPP


#include <iostream>
typedef std::string String;
#include <map>
#include <fstream>

class MapBitcoinDB {
    public:
        const String dbName;
        std::map<String, float> dbMap;

        std::pair<String, float>    splitEntry(const String& entry) const;

    public:
        MapBitcoinDB(const String& dbName);
        
        void    initDatabase();
        // overidden methods
        bool    getValue(const String& date, float* value);

        ~MapBitcoinDB();
};


#endif