#include "BitcoinExchange.hpp"

void    BitcoinExchange::setDataBase(const char* data) {
    std::ifstream   file(data);
    if (!file)
        throw excepFile();
    std::string line;
    size_t  pos;

    while (std::getline(file, line)) {
        pos = line.find(',');
        this->database[line.substr(0, pos)] = this->stof(line.substr(pos + 1, line.size()));
    }
    database.erase("date");
    // std::map<std::string, float>::iterator it = database.find("date");
    // if (it == database.end())
    // {
    // }
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
    char    c;

    if (!fil || !fil.get(c))
        throw excepFile();
    while (std::getline(fil, line)) {
        parseInputFile   ps(line);
        ps.checkValidFormat();
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


/*----------- Parse Class ---------------*/

parseInputFile::parseInputFile(const std::string& str) : toParse(str) {
    this->trim(); /*trim whitespace*/
}

void    parseInputFile::checkValidFormat() const {
    std::string date;
    std::string price;
    size_t      pos = this->toParse.find_first_not_of('|');
    if (pos == std::string::npos)/* check if date-value separed by '|' */
        throw std::runtime_error("Invalid format");
    pos = this->toParse.find_first_not_of(' ');
    date = this->toParse.substr(pos, this->toParse.find('|'));
    
    std::cout << date<< std::endl;
}

std::string parseInputFile::trim() {
    size_t  start = this->toParse.find_first_not_of(" \t");
    size_t  end = this->toParse.find_last_not_of(" \t");
    return (start == std::string::npos ? "" : this->toParse.substr(start, end - start + 1));
}