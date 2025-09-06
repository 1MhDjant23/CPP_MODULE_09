#ifndef __ParseInputFile_HPP__
#define __ParseInputFile_HPP__

#include <iostream>
#include <sstream>
#include <fstream>

class ParseInputFile {
    private:
    	std::string date;
    	float	value;
        std::string toParse;
        ParseInputFile();
        ParseInputFile(const ParseInputFile& obj);
        ParseInputFile& operator=(const ParseInputFile& obj);
    public:
        const 	std::string& getToParse() const;
        bool    checkValidFormat() ;
        bool    parseDate(const std::string& date) const;
        void	setValue(float value);
        float	getValue() const;
        const	 std::string& getDate() const;
        void	setDate(const std::string& date);
        ParseInputFile(const std::string& str);
        std::string trim();
        ~ParseInputFile();
};
bool    isFileEmpty(std::ifstream& stream);

#endif