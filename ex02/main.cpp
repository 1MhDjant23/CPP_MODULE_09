#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	try {
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> >>	pm(ac, av);
		pm.pairSort();
		pm.insertSmallJacobsthal();

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}