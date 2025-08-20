#include "BitcoinExchange.hpp"

void    BitcoinExchange::setDataBase(const char* data) {
    std::ifstream   file(data);
    if (!file)
        throw excepFile();
    std::string line;
    size_t  pos;

    while (std::getline(file, line)) {
        pos = line.find(',');
        this->database[line.substr(0, pos)] = this->stof(line.substr(pos + 1, line.size());
        // std::cout << "-->" << line.substr(pos + 1, line.size()) << std::endl;


        // std::cout << line << std::endl;
    }
}

float   BitcoinExchange::stof(const std::string& str) {
    float   num;
    std::stringstream   ss(str);
    ss >> num;
    return num;
}

bool    validFile(const std::string& inpFile)
{    
    std::ifstream    file(inpFile.c_str());
    if ( inpFile.empty() || !file)
        return false;
    file.close();
    return true;
}
