#include "PmergeMe.hpp"

size_t	PmergeMe::seuil = 16;

PmergeMe::PmergeMe(int ac, char **av) {
	if (ac <= 2)
		throw std::runtime_error("Error: not enough arguments.");
	if (!this->parseInput(ac, av))
		throw std::runtime_error("Error: invalid input.");
	if (isSorted(LIST))
	{
		std::cout << "The list is already sorted!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	printListBefore(); // Std out: Print the list before sorting
}

bool	PmergeMe::parseInput(int arc, char **arg) {
	for (int i = 1; i < arc; i++) {
		int					operand = 0;
		std::string			remainder;
		std::istringstream	iss(arg[i]);
		
		if (iss >> operand) {
			if (iss >> remainder) {
				std::cout << operand << remainder << std::endl;
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
	this->_unpair = -1;
	return true;
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

void	PmergeMe::printListBefore() const {
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vList.size(); i++)
		std::cout << this->vList[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printListAfter() const {
	if (this->isSorted(CHAIN))
	{
		std::cout << "After: ";
		for (size_t i = 0; i < this->vMainChain.size(); i++)
			std::cout << this->vMainChain[i] << " ";
		std::cout << std::endl;
		std::cout << "<<<<<< The list is sorted! >>>>>>>" << std::endl;
	}
	else
		std::cout << "Error: the list is not sorted!" << std::endl;
}

PmergeMe::~PmergeMe() {
	this->vList.clear();
	this->vMainChain.clear();
	this->_vPair.clear();
	this->dList.clear();
	this->dMainChain.clear();
	this->_dPair.clear();
}

bool	PmergeMe::isSorted(typeList containerType) const {
	if (containerType == CHAIN) {
		for (size_t i = 1; i < this->vMainChain.size(); i++) {
			if (this->vMainChain[i - 1] > this->vMainChain[i])
				return false;
		}
	}
	else if (containerType == LIST) {
		for (size_t i = 1; i < this->vList.size(); i++) {
			if (this->vList[i - 1] > this->vList[i])
				return false;
		}
	}
	return true;
}

// getters 
std::vector<int>&	PmergeMe::getVList(){
	return this->vList;
};

std::deque<int>&	PmergeMe::getDList(){
	return this->dList;
};

std::vector<std::pair<int, int> >&	PmergeMe::getVPair(){
	return this->_vPair;
};

std::deque<std::pair<int, int> >&	PmergeMe::getDPair(){
	return this->_dPair;
};

std::vector<int>&	PmergeMe::getVMainChain(){
	return this->vMainChain;
};

std::deque<int>&	PmergeMe::getDMainChain(){
	return this->dMainChain;
};