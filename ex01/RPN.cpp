#include "RPN.hpp"

RPN::RPN() { return; }
RPN::~RPN() { return; }
RPN::RPN(const RPN& other) { *this = other; }
RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		this->_pile = other._pile;
	return *this;
}

void	RPN::calculate(const std::string& token) {
	if (this->_pile.size() < 2)
		throw std::runtime_error("Error: expression invalid.");
	int	n1, n2;
	n1 = this->_pile.top();
	this->_pile.pop();
	n2 = this->_pile.top();
	this->_pile.pop();
	if (token == "+")
		this->_pile.push(n2 + n1);
	else if (token == "-")
		this->_pile.push(n2 - n1);
	else if (token == "*")
		this->_pile.push(n2 * n1);
	else if (token == "/") {
		if (n1 == 0)
			throw std::runtime_error("Error: division by zero.");
		this->_pile.push(n2 / n1);
	}
}
bool	RPN::isOperand(const std::string& token) {
	std::istringstream	iss(token);
	int					operand;
	if (iss >> operand) {
		this->_pile.push(operand);
		return true;
	}
	return false;
}

void	RPN::evalRPN(const std::string& arg) {
	size_t	start = arg.find_first_not_of(' ');
	std::istringstream	iss(arg.substr(start, arg.find_last_not_of(' ') - start + 1));
	std::string			token;

	while (iss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/")
			this->calculate(token);
		else if (!this->isOperand(token))
			throw std::runtime_error("Error");
	}
	if (this->_pile.size() == 1)
		std::cout << this->_pile.top() << std::endl;
	else
		throw std::runtime_error("Error: expression invalid.");
}
