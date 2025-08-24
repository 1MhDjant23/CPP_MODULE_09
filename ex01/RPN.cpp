#include "RPN.hpp"

RPN::RPN() { return; }
RPN::~RPN() { return; }
RPN::RPN(const RPN& other) { *this = other; }
RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		this->_pile = other._pile;
	return *this;
}

void	RPN::evalRPN(const std::string& arg) {
	int		n = 0;
	char	op;
	std::istringstream	iss(arg);


	std::cout << arg << std::endl;
}
