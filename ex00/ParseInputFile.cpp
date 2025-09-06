#include "ParseInputFile.hpp"

ParseInputFile::~ParseInputFile() { return ; }
ParseInputFile::ParseInputFile(const std::string& str) : toParse(str) { this->toParse = this->trim(); /*trim whitespace*/ }
const std::string&	ParseInputFile::getToParse() const { return this->toParse; }
bool    ParseInputFile::checkValidFormat() {
    std::string date;
    std::string price;
    size_t      pos = this->toParse.find_first_not_of('|');
    if (pos == std::string::npos)/* check if date-value separed by '|' */
        return false;
    pos = this->toParse.find(' ');
    if (pos == std::string::npos || this->toParse[pos + 1] != '|' || this->toParse[pos + 2] != ' ' || (!std::isdigit(this->toParse[pos + 3]) && this->toParse[pos + 3] != '-'))
        return false;
    date = this->toParse.substr(0, pos);
    if (!this->parseDate(date))
    	return false;
    this->setDate(date);
    pos += 3;
    if (pos == std::string::npos)
    	return false;
    price  = this->toParse.substr(pos, this->toParse.length() - pos);
    if (price.empty())
    	return false;
    std::istringstream  iss(price);
    float   value = 0;
    if (!(iss >> value) || !iss.eof())
	    return false;
	this->setValue(value);
	return true;
}


std::string ParseInputFile::trim() {
    size_t  start = this->toParse.find_first_not_of(" \t");
    size_t  end = this->toParse.find_last_not_of(" \t");

    return (start == std::string::npos ? "" : this->toParse.substr(start, end - start + 1));
}

/*------ getter and setter ----------*/
bool    ParseInputFile::parseDate(const std::string& date) const {
    char    dash1, dash2;
    int year, month, day;

    std::istringstream  iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
    	return false;
    return true;
}
void	ParseInputFile::setValue(float value) {	this->value = value; }
float	ParseInputFile::getValue() const { return this->value; }
void    ParseInputFile::setDate(const std::string& date) { this->date = date; }
const std::string&	ParseInputFile::getDate() const { return date; }
/*-------- other functions --------*/

bool    validFile(const std::string& inpFile)
{    
    std::ifstream    file(inpFile.c_str());
    if (!file.is_open())
        return false;
    if (!isFileEmpty(file)) {
        std::cerr << "Error: empty file." << std::endl;
        exit(EXIT_SUCCESS);
    }
    file.close();
    return true;
}
bool    isFileEmpty(std::ifstream& stream) {    
    char    c;
    while (stream.get(c))
    {
        if (!std::isspace(static_cast<unsigned char>(c)))
            return true;
    }
    return false;
}
