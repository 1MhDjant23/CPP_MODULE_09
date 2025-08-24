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
	char	op;
	size_t	start = arg.find_first_not_of(' ');
	std::istringstream	iss(arg.substr(start, arg.find_last_not_of(' ') - start + 1));
	while (true) {
		int		n = 0;
		if (iss >> n)
			this->_pile.push(n);
		else if (iss >> op && (op == '+' || op == '-' || op == '*' || op == '/')) {
			if (this->_pile.size() < 2)
				throw std::runtime_error("Error: bad input.");
			int	n1, n2;
			n1 = this->_pile.top();
			this->_pile.pop();
			n2 = this->_pile.top();
			this->_pile.pop();
			if (op == '+')
				this->_pile.push(n1 + n2);
			else if (op == '-')
				this->_pile.push(n2 - n1);
			else if (op == '*')
				this->_pile.push(n1 * n2);
			else if (op == '/')
				this->_pile.push(n2 / n1);
		}
		else if (op != ' ')
			throw std::runtime_error("Error: bad input.");
		if (iss.empty())
	}

	std::cout << arg << std::endl;
}
