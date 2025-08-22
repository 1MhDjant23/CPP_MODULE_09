#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>
#include <iomanip>
#define  dataBase "data.csv"

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
        parseInputFile(const std::string& str);
        bool    parseDate() const;
        ~parseInputFile(){};
};

bool    validFile(const std::string& inpFile);

#endif