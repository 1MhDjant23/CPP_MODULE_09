#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>
template <class T, class PAIR>
class	PmergeMe {
	private:
		static int	seuil;
		T			list;
		T			mainChain;

		PAIR	_pair;
		int				_unpair = -1;
		PmergeMe&	operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);
		PmergeMe();
	public:
		static void	insertionSort(T& arr, size_t start, size_t end);
		static void	mergeInserionSort(T& arr, size_t start, size_t end);
		bool	hasDuplicat() const;
		bool	parseInput(int arc, char **arg);
		void	pairSort();
		void	setMainChain();
		void	insertSmallJacobsthal();
		static T	getJacobsthalOrder(size_t size);
		PmergeMe(int ac, char **av);
		~PmergeMe(){
		};
};



#endif