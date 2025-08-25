#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <sstream>
#include <exception>
#include <stack>

class	RPN {
	private:
		std::stack<int>	_pile;
	public:
		RPN();
		~RPN();
		RPN&	operator=(const RPN& other);
		RPN(const RPN& other);
		void	evalRPN(const std::string& arg);
		void	calculate(const std::string& token);
		bool	isOperand(const std::string& token);
};

#endif