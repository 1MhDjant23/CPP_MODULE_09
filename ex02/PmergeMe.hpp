#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>

class	PmergeMe {
	private:
		static int	seuil;
		std::vector<int>					vect;
		std::vector<int>					mainChain;

		std::vector<std::pair<int, int> >	_pair;
		int				_unpair;
		PmergeMe&	operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);
		PmergeMe();
	public:
		static void	insertionSort(std::vector<int>& arr, size_t start, size_t end);
		static void	mergeInserionSort(std::vector<int>& arr, size_t start, size_t end);
		bool	hasDuplicat() const;
		bool	parseInput(int arc, char **arg);
		void	pairSort();
		void	setMainChain();
		PmergeMe(int ac, char **av);
		~PmergeMe(){};
};



#endif