#include "PmergeMe.hpp"

int	PmergeMe::seuil = 5;

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
	for (size_t i = 0; i < this->_pair.size(); i++)
		this->mainChain.push_back(this->_pair[i].second);
	for (size_t i = 0; i < this->mainChain.size(); i++)
		std::cout << mainChain[i] << " " ;
	std::cout << std::endl;
	//sort mainChain using mergeInserionSort algorithm
	this->mergeInserionSort(this->mainChain, 0, this->mainChain.size() - 1);
	std::cout << "after sorting it .." << std::endl;
	for (size_t i = 0; i < this->mainChain.size(); i++) {
		std::cout << mainChain[i] << " " ;
	}
	std::cout << std::endl;
//	this->insertionSort(this->mainChain, 0, this->mainChain.size());
}

std::vector<int>	PmergeMe::getJacobsthalOrder(size_t size) {
	std::vector<int>	Jacob(size + 2);
	if (size > 0)
		Jacob[0] = 0;
	if (size > 1)
		Jacob[1] = 1;
	size_t	k = 2;
	for (k = 2; k < size; k++)
	{
		if (Jacob[k - 1] + 2 * Jacob[k - 2] > size)
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
void	PmergeMe::binarySearch() {

}

void	PmergeMe::insertSmallJacobsthal() {
	std::cout << "size is: " << _pair.size() << std::endl;
	const std::vector<int>	jacobIndex = PmergeMe::getJacobsthalOrder(_pair.size());
	std::cout << "inside --" << std::endl;
	int pos;
	for (size_t i = 0; i < jacobIndex.size(); i++)
	{
		int	small = _pair[jacobIndex[i]].first;
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), small);
		mainChain.insert(pos, small);
	}
	if (_unpair != -1)
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), _unpair)
		mainChain.insert(pos, _unpair);
	}
}


void	PmergeMe::insertionSort(std::vector<int>& arr, size_t start, size_t end) {
	for (size_t i = start + 1; i <= end; i++)
	{
		int	key = arr[i];
		int	j = i - 1;
		while (j >= start && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::mergeInserionSort(std::vector<int>& arr, size_t start, size_t end) {
	if (end - start + 1 <= PmergeMe::seuil) {
		PmergeMe::insertionSort(arr, start, end);
		return ;
	}
	int		midll = start + (end - start) / 2;
	mergeInserionSort(arr, start, midll);
	mergeInserionSort(arr, midll + 1, end);

	std::vector<int>	tmp(end - start + 1);
	size_t	i = start;
	size_t	j = midll + 1;
	size_t	k = 0;
    while (i <= midll && j <= end)
    	tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	while (i <= midll) tmp[k++] = arr[i++];
	while (j <= end) tmp[k++] = arr[j++];
	for (k = 0; k < tmp.size(); k++)
		arr[start + k] = tmp[k];
}

PmergeMe::PmergeMe(int ac, char **av) {
	if (ac < 3 || !this->parseInput(ac, av))
		throw std::runtime_error("Error: invalid input.");
}