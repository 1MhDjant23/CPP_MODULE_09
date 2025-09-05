#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>
#include <exception>
#include <iomanip>
#include "ParseInputFile.hpp"
#define  dataBase "data.csv"
#define  HEADER_LINE "date | value"



class BitcoinExchange {
    private:
        std::map<std::string, float> database;
    	BitcoinExchange(const BitcoinExchange& other);
    	BitcoinExchange& operator=(const BitcoinExchange& other);
    public:
        void    setDataBase(const char* data);
        void    fileInterpreter(const char* file);
        float   stof(const std::string& str);
        void	exchange(bool stat, const std::string& line, const ParseInputFile& obj) const;
        BitcoinExchange();
        ~BitcoinExchange();
};

bool    validFile(const std::string& inpFile);

#endif