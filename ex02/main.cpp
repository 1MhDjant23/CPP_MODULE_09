#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	try {
		PmergeMe	pm(ac, av);
		// pm.pairSort();//dived all numbers to pairs and sort each pair
		std::vector<int>	v = pm.getJacobsthalOrder(6);
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << "index: " << v[i] << std::endl;
		}
		
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
//	std::vector<int> v;
//	v.push_back(10);
//	v.push_back(4);
//	v.push_back(6);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(8);
//	v.push_back(5);
//	v.push_back(9);
//	v.push_back(3);
//	v.push_back(7);
//	v.push_back(44);
//	v.push_back(0);
//	PmergeMe::mergeInserionSort(v, 0, v.size() - 1);

//	for (size_t i = 0; i < v.size(); i++)
//		std::cout << v[i] << " ";
//	std::cout << std::endl;

	return EXIT_SUCCESS;
}