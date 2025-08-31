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
		x++;
		i += 2;
	}
	this->vect.clear();
	for (size_t i = 0; i < this->_pair.size(); i++) {
		if (this->_pair[i].first > this->_pair[i].second) {
			int	tmp = this->_pair[i].first;
			this->_pair[i].first = this->_pair[i].second;
			this->_pair[i].second = tmp;
		}
	}
	// Insert main Chain for larger numbers in each pairs
	this->setMainChain();
}

void	PmergeMe::setMainChain() {
	for (size_t i = 0; i < this->_pair.size(); i++) {
		this->mainChain.push_back(this->_pair[i].second);
	}
	for (size_t i = 0; i < this->mainChain.size(); i++) {
		std::cout << this->mainChain[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "insertion sort ==> " << std::endl;
	this->insertionSort(this->mainChain, 0, this->mainChain.size());

}
void	PmergeMe::insertionSort(std::vector<int>& vect, size_t start, size_t end) {
	for (size_t i = start + 1; i < end; i++)
	{
		int	key = vect[i];
		int	j = i - 1;
		while (j >= start && vect[j] > key)
		{
			vect[j + 1] = vect[j];
			j--;
		}
		vect[j + 1] = key;
	}
	for (size_t i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av) {
	if (ac < 3 || !this->parseInput(ac, av))
		throw std::runtime_error("Error: invalid input.");
}