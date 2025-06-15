#include "MapBitcoinDB.hpp"
#include <vector>
#include <algorithm>
int main() {
    MapBitcoinDB db("data.csv");
    float value;
    try {
        db.initDatabase();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    db.getValue("2010-11-29", &value);
    // std::vector<int> v = {3,5,9,12,35,86,123};
    // std::cout << (*std::lower_bound(v.begin(), v.end(), 6)) << std::endl;
}