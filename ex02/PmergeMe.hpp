#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include "TimeTracker.hpp"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>

class	PmergeMe {
	private:
		static size_t	seuil;
		// vector data members
		std::vector<int>			vList;
		std::vector<int>			vMainChain;
		std::vector<std::pair<int, int> >	_vPair;
		// deque data members
		std::deque<int>			dList;
		std::deque<int>			dMainChain;
		std::deque<std::pair<int, int> >	_dPair;
		int				_unpair;

		PmergeMe&	operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);
		PmergeMe();
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		// methods to print the list before and after sorting
		void	printListBefore() const;
		void	printListAfter() const;
		// getters
		std::vector<int>&	getVList();
		std::deque<int>&	getDList();
		std::vector<std::pair<int, int> >&	getVPair();
		std::deque<std::pair<int, int> >&	getDPair();
		std::vector<int>&	getVMainChain();
		std::deque<int>&	getDMainChain();
		// sorting methods
		template <typename T>
		static void	insertionSort(T& arr, int start, size_t end);
		
		template <typename T>
		static void	mergeInserionSort(T& arr, size_t start, size_t end);

		template <typename LIST, typename PAIR>
		void	pairSort(LIST& list, PAIR& pair, TimeTracker& chrono);

		template <typename CHAIN, typename PAIR>
		void	setMainChain(CHAIN& mainChain, PAIR& pair);

		static std::vector<size_t>	getJacobsthalOrder(size_t size);

		template <typename CHAIN, typename PAIR>
		void	insertSmallJacobsthal(CHAIN& mainChain, PAIR& _pair, TimeTracker& chrono);
		// utility methods
		bool	isSorted(typeList containerType) const;
		bool	parseInput(int arc, char **arg);
};
#include "PmergeMe.tpp"

#endif
