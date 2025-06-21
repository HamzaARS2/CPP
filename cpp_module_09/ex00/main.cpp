#include "BitcoinExchange.hpp"


int main(int ac, char **av) {
    if (ac <= 1) {
        std::cerr << "missing input file" << std::endl;
        return 1;
    }
    MapBitcoinDB db("data.csv");
    try {
        db.initDatabase();
        BitcoinExchange btc(String(av[1]), db);
        btc.computeExchange();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}