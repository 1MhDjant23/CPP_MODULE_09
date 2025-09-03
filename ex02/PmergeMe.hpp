#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>

class	PmergeMe {
	private:
		static int	seuil;
		std::vector<int>					list;
		std::vector<int>					mainChain;

		std::vector<std::pair<int, int> >	_pair;
		int				_unpair = -1;
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
		void	insertSmallJacobsthal();
		static std::vector<int>	getJacobsthalOrder(size_t size);
		PmergeMe(int ac, char **av);
		~PmergeMe(){
		};
};



#endif