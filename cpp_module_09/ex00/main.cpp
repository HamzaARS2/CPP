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

    // std::vector<int> v = {3,5,9,12,35,86,123};
    // std::cout << (*std::lower_bound(v.begin(), v.end(), 6)) << std::endl;
}