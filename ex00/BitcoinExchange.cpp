#include "BitcoinExchange.hpp"

void    BitcoinExchange::setDataBase(const char* data) {
    std::ifstream   file(data);
    if (file)
    {
        /* code */
    }
    
}

bool    validFile(const std::string& inpFile)
{    
    std::ifstream    file(inpFile.c_str());
    if ( inpFile.empty() || !file)
        return false;
    file.close();
    return true;
}
