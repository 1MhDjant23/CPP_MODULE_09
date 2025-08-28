#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	try {
		PmergeMe	pm(ac, av);
		pm.pairSort();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	return EXIT_SUCCESS;
}