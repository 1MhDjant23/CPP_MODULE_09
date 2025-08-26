#include "PmergeMe.hpp"

bool	PmergeMe::parseInput(int arc, char **arg) {
	for (int i = 1; i < arc; i++) {
		int					operand = 0;
		std::istringstream	iss(arg[i]);
		if (iss >> operand) {
			if (operand < 0)
				throw	std::runtime_error("Error: negative number.");
			this->vect.push_back(operand);
		}
		else
			throw std::runtime_error("Error: invalid input.");
	}
	return true;
}

PmergeMe::PmergeMe(int ac, char **av) {
	if (ac < 3 || !this->parseInput(ac, av))
		throw std::runtime_error("Error: invalid input.\nUsage: ./PmergeMe n1 n2 n3 ...n^n");
	else
	{
		for (int i = 0; i < this->vect.size(); i++)
			std::cout << vect[i] << " " ;
	}
		std::cout << std::endl;
}