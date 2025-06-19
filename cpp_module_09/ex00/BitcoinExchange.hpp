#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP


#include "MapBitcoinDB.hpp"

class BitcoinExchange {
	private:
		const String filepath;
		const MapBitcoinDB db;

		bool	isValidEntry(const String& entry) const;
		bool	isValidDateFormat(const String& entry) const;
    	bool	parseEntry(const String& entry, std::pair<String, float>* pair) const;
    	void	reportError(const String& msg, const String& entry) const;
    	void	processLine(const String& entry) const;
		void	displayExchange(const String& date, float value, float dbValue) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const String& filepath, MapBitcoinDB& db);
		BitcoinExchange(const BitcoinExchange& copy);

		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	computeExchange();


		~BitcoinExchange();
};

#endif