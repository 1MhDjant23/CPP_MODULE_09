#include "PmergeMe.hpp"

bool	PmergeMe::parseInput(int arc, char **arg) {
	for (int i = 1; i < arc; i++) {
		int					operand = 0;
		std::string			remainder;
	
		std::istringstream	iss(arg[i]);
		if (iss >> operand) {
			if (iss >> remainder) {
				std::cout << remainder << std::endl;
				throw std::runtime_error("Error: bad operand!");
			}
			if (operand < 0)
				throw	std::runtime_error("Error: negative number.");
			this->vect.push_back(operand);
		}
		else
			throw std::runtime_error("Error: invalid input.");
	}
	if (this->hasDuplicat())
		throw std::runtime_error("Error: duplicated number!");
	return true;
}

bool	PmergeMe::hasDuplicat() const {
	for (size_t i = 0; i < this->vect.size(); i++)
	{
		for (size_t x = i + 1; x < this->vect.size(); x++)
		{
			if (this->vect[i] == this->vect[x])
				return true;
		}
	}
	return false;
}

void	PmergeMe::pairSort() {
	size_t	i = 0;
	size_t	x = 0;
	if (this->vect.size() % 2 != 0)
		this->_unpair = this->vect[this->vect.size() - 1];
	while (i < this->vect.size() - 1) {
		this->_pair.push_back(std::make_pair(this->vect[i], this->vect[i + 1] ));
		std::cout << this->_pair[x].first << " " << this->_pair[x].second << std::endl;
		x++;
		i += 2;
	}
	this->vect.clear();
	std::cout << "[--- sorting -----]" << std::endl;
	std::cout << "[--- size -----]" << this->_pair.size() << std::endl;
	for (size_t i = 0; i < this->_pair.size(); i++) {
		if (this->_pair[i].first > this->_pair[i].second) {
			int	tmp = this->_pair[i].first;
			this->_pair[i].first = this->_pair[i].second;
			this->_pair[i].second = tmp;
		}
		
		std::cout << this->_pair[i].first << " " << this->_pair[i].second << std::endl;
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