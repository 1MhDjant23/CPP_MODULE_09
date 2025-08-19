#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#define  dataBase "data.csv"

class BitcoinExchange {
    private:
        const std::map<std::string, float> database;
        const std::map<std::string, float> evaluateDb;
    public:
        void    setDataBase(const char* data);
        BitcoinExchange();
        ~BitcoinExchange();
    class excepFile : public std::exception {
        
    };

};

bool    validFile(const std::string& inpFile);

#endif