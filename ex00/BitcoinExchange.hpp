#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>
#include <iomanip>
#define  dataBase "data.csv"
#define  ERROR "Error: invalid date format."

class BitcoinExchange {
    private:

        std::map<std::string, float> database;
        std::map<std::string, float> evaluateDb;
    public:
        void    setDataBase(const char* data);
        void    fileInterpreter(const char* file);
        float   stof(const std::string& str);
        BitcoinExchange(){};
        ~BitcoinExchange(){};

};

class parseInputFile {
    private:
        std::string toParse;
        parseInputFile(){};
    public:
        std::string trim();
        void    checkValidFormat() const;
        void    parseDate(const std::string& date) const;
        parseInputFile(const std::string& str);
        ~parseInputFile(){};
};

bool    validFile(const std::string& inpFile);

#endif