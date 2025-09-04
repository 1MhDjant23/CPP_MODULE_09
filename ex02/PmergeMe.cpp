#include "PmergeMe.hpp"

size_t	PmergeMe::seuil = 5;

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
			this->vList.push_back(operand);
			this->dList.push_back(operand);
		}
		else
			throw std::runtime_error("Error: invalid input.");
	}
	if (this->hasDuplicat())
		throw std::runtime_error("Error: duplicated number!");
	this->_unpair = -1;
	return true;
}

bool	PmergeMe::hasDuplicat() const {
	for (size_t i = 0; i < this->vList.size(); i++)
	{
		for (size_t x = i + 1; x < this->vList.size(); x++)
		{
			if (this->vList[i] == this->vList[x])
				return true;
		}
	}
	return false;
}


std::vector<size_t>	PmergeMe::getJacobsthalOrder(size_t size) {
	std::vector<size_t>	Jacob(size + 2);
	if (size > 0)
		Jacob[0] = 0;
	if (size > 1)
		Jacob[1] = 1;
	size_t	k = 2;
	for (k = 2; k < size; k++)
	{
		if (Jacob[k - 1] + 2 * Jacob[k - 2] >= size)
			break;
		Jacob[k] = Jacob[k - 1] + 2 * Jacob[k - 2];
	}
	Jacob.erase(Jacob.begin(), Jacob.begin() + 2);
	k--;
	for (size_t i = 0; i < size; i++)
	{
		if (std::find(Jacob.begin(), Jacob.end(), i) == Jacob.end())
			Jacob[k++] = i;
	}
	return Jacob;
}


PmergeMe::PmergeMe(int ac, char **av) {
	if (ac < 3 || !this->parseInput(ac, av))
		throw std::runtime_error("Error: invalid input.");
    printListBefore(); // Std out: Print the list before sorting
}

void	PmergeMe::printListBefore() const {
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vList.size(); i++)
	{
		std::cout << this->vList[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printListAfter() const {
	std::cout << "After: ";
	for (size_t i = 0; i < this->vMainChain.size(); i++)
	{
		std::cout << this->vMainChain[i] << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < this->dMainChain.size(); i++)
	{
		std::cout << this->dMainChain[i] << " ";
	}
	std::cout << std::endl;
}