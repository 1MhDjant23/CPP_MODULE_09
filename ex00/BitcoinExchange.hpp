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
#define  HEADER_LINE "date | value"

class parseInputFile {
    private:
    	std::string date;
    	float	value;
        std::string toParse;
        parseInputFile(){};
    public:
        std::string trim();
        const std::string& getToParse() const;
        bool    checkValidFormat() ;
        bool    parseDate(const std::string& date) const;
        void	setValue(float value);
        const float	getValue() const;
        const std::string& getDate() const;
        void	setDate(const std::string& date);
        parseInputFile(const std::string& str);
        ~parseInputFile(){};
};

class BitcoinExchange {
    private:

        std::map<std::string, float> database;
        std::map<std::string, float> evaluateDb;
    public:
        void    setDataBase(const char* data);
        void    fileInterpreter(const char* file);
        float   stof(const std::string& str);
        void	exchange(bool stat, const std::string& line, const parseInputFile& obj) const;
        BitcoinExchange(){};
        ~BitcoinExchange(){};

};


bool    validFile(const std::string& inpFile);

#endif