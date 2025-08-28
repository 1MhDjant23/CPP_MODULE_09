#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>

class	PmergeMe {
	private:
		std::vector<int>					vect;
		std::vector<std::pair<int, int> >	_pair;
		int				_unpair;
		PmergeMe&	operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);
		PmergeMe();
	public:
		bool	parseInput(int arc, char **arg);
		void	pairSort();
		PmergeMe(int ac, char **av);
		~PmergeMe(){};
};



#endif