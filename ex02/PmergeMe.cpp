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

void	PmergeMe::pairSort() {
	std::cout << "---- sort ------------" << std::endl;
	size_t	i = 0;
	size_t	x = 0;
	if (this->vect.size() % 2 != 0) {
		this->_unpair = this->vect[this->vect.size() - 1];
		std::cout << "it's odd! unpair value is: " << this->_unpair << std::endl;
	}
	while (i < this->vect.size() - 1)
	{
		this->_pair.push_back(std::make_pair(this->vect[i], this->vect[i + 1] ));
		std::cout << this->_pair[x].first << " " << this->_pair[x].second << std::endl;
		x++;
		i += 2;
	}
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