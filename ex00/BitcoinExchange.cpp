#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { return ;}
BitcoinExchange::~BitcoinExchange() { return ;}

void    BitcoinExchange::setDataBase(const char* data) {
    std::ifstream   file(data);
    if (!file)
        throw std::runtime_error("Error: can't open file.");
    std::string line;
    size_t  pos;
    while (std::getline(file, line)) {
        pos = line.find(',');
        this->database[line.substr(0, pos)] = this->stof(line.substr(pos + 1, line.size()));
    }
    database.erase("date");
    file.close();
}

float   BitcoinExchange::stof(const std::string& str) {
    float   num;
    std::stringstream   ss(str);
    ss >> num;
    return num;
}

void    BitcoinExchange::fileInterpreter(const char* file) {
    std::ifstream   fil(file);
    std::string     line;
    size_t			start = 0;
    size_t			end = 0;
    std::string		temp;

    if (!fil)
        throw std::runtime_error("Error: can't open file.");
    while (line.empty())
    	std::getline(fil, line);
    start = line.find_first_not_of(" \t");
    end = line.find_last_not_of(" \t");
    temp = line.substr(start, end - start + 1);
    if ("date | value" != temp)
    	throw std::runtime_error("Error: bad header.");
    while (std::getline(fil, line)) {
        ParseInputFile   ps(line);
        if (ps.getToParse().empty())
        	continue ;
        this->exchange(ps.checkValidFormat(), line, ps);
    }
}

void	BitcoinExchange::exchange(bool stat, const std::string& line, const ParseInputFile& obj) const {
	if (stat == false) { std::cout << "Error: bad input => " << line << std::endl; return; }
	if (obj.getValue() < 0) { std::cout << "Error: not a positive number." << std::endl; return; }
	if (obj.getValue() > 1000) { std::cout << "Error: too large a number." << std::endl; return; }
	std::map<std::string, float>::const_iterator it = this->database.lower_bound(obj.getDate());
	if (it->first == obj.getDate() || it->first == this->database.begin()->first)
		std::cout << it->first << " => " << obj.getValue() << " = " << it->second * obj.getValue() << std::endl;
	else {
		it--;
		std::cout << it->first << " => " << obj.getValue() << " = " << it->second * obj.getValue() << std::endl;
	}
}
