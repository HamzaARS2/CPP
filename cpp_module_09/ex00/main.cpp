#include "BitcoinExchange.hpp"

#include <vector>
#include <algorithm>
int main() {
    MapBitcoinDB db("data.csv");
    try {
        db.initDatabase();
        BitcoinExchange btc("input.txt", db);
        btc.computeExchange();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}