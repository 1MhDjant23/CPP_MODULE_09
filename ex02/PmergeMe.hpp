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
		void	printListBefore() const;
		void	printListAfter() const;
		// getters
		std::vector<int>&	getVList(){
			return this->vList;
		};
		std::deque<int>&	getDList(){
			return this->dList;
		};
		std::vector<std::pair<int, int> >&	getVPair(){
			return this->_vPair;
		};
		std::deque<std::pair<int, int> >&	getDPair(){
			return this->_dPair;
		};
		std::vector<int>&	getVMainChain(){
			return this->vMainChain;
		};
		std::deque<int>&	getDMainChain(){
			return this->dMainChain;
		};
		template <typename T>
		static void	insertionSort(T& arr, int start, size_t end);
		
		template <typename T>
		static void	mergeInserionSort(T& arr, size_t start, size_t end);

		template <typename LIST, typename PAIR>
		void	pairSort(LIST& list, PAIR& pair);

		template <typename CHAIN, typename PAIR>
		void	setMainChain(CHAIN& mainChain, PAIR& pair);

		static std::vector<size_t>	getJacobsthalOrder(size_t size);

		template <typename CHAIN, typename PAIR>
		void	insertSmallJacobsthal(CHAIN& mainChain, PAIR& _pair);

		bool	hasDuplicat() const;
		bool	parseInput(int arc, char **arg);
		PmergeMe(int ac, char **av);
		~PmergeMe(){
			// std::cout << "Destructor called" << std::endl;
			// std::cout << "vector size is : " << this->vMainChain.size() << std::endl;
			for (size_t i = 0; i < this->vMainChain.size(); i++)
			{
				std::cout << this->vMainChain[i] << " ";
			}
			std::cout << std::endl;
		};

};
#include "PmergeMe.tpp"


#endif
