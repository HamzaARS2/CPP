#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP


#include "MapBitcoinDB.hpp"

class BitcoinExchange {
	private:
		const String filepath;
		MapBitcoinDB db;

	public:
		BitcoinExchange();
		BitcoinExchange(const String& filepath, MapBitcoinDB& db);
		BitcoinExchange(const BitcoinExchange& copy);

		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	computeExchange();

		~BitcoinExchange();
};

#endif