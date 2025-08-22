#include "BitcoinExchange.hpp"

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
        throw std::runtime_error("Error: can't open file.");
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
    this->toParse = this->trim(); /*trim whitespace*/
}

void    parseInputFile::checkValidFormat() const {
    std::string date;
    std::string price;
    size_t      pos = this->toParse.find_first_not_of('|');
    if (pos == std::string::npos)/* check if date-value separed by '|' */
        throw std::runtime_error("Error: Invalid format");
    pos = this->toParse.find(' ');
    date = this->toParse.substr(0, pos);
    std::cout << date<< std::endl;
    this->parseDate();
    
}

std::string parseInputFile::trim() {
    size_t  start = this->toParse.find_first_not_of(" \t");
    size_t  end = this->toParse.find_last_not_of(" \t");

    return (start == std::string::npos ? "" : this->toParse.substr(start, end - start + 1));
}

bool    parseInputFile::parseDate() const {
    char    dash1, dash2;
    int year, month, day, dashCount = 0;

    std::istringstream  iss(this->toParse);
    for (size_t i = 0; i < 4; i++)
    {
        if (!std::isdigit(this->toParse[i]))
            throw std::runtime_error("Error: invalid year format.");
    }
    std::cout << this->toParse[4] <<  " is dash" << std::endl;


    // for (size_t i = 0; i < this->toParse.size(); i++) {
    //     if (this->toParse[i] == '-') {
    //         dashCount++;
    //     }
    //     else if (!std::isdigit(this->toPare[i]) || dashCount > 2)
    //         throw std::runtime_error("Error: invalid date format.");
        
    // }
    // for (size_t i = 4; i < 6; i++)
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
        throw std::runtime_error("Error: Invalid date format.");
    std::cout << year << " year!" << std::endl;
    return true;
}