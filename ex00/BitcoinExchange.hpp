#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>
#define  dataBase "data.csv"

class BitcoinExchange {
    private:
        std::map<std::string, float> database;
        std::map<std::string, float> evaluateDb;
    public:
        void    setDataBase(const char* data);
        float   stof(const std::string& str);
        BitcoinExchange(){};
        ~BitcoinExchange(){};
    class excepFile : public std::exception {
        public:
            const char*	what() const _NOEXCEPT {
                return "ExceptionDetected: file error.";
            }
    };

};

bool    validFile(const std::string& inpFile);

#endif