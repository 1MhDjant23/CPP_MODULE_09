#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	try {
		// PmergeMe<std::vector<int>, std::vector<std::pair<int, int> >>	pm(ac, av);
		PmergeMe	pm(ac, av);
		// pm.parseInput(ac, av);
		// sorting using vector
		pm.pairSort(pm.getVList(), pm.getVPair());
		pm.setMainChain(pm.getVMainChain(), pm.getVPair());
		pm.insertSmallJacobsthal(pm.getVMainChain(), pm.getVPair());
		//sorting using deque
		pm.pairSort(pm.getDList(), pm.getDPair());
		pm.setMainChain(pm.getDMainChain(), pm.getDPair());
		pm.insertSmallJacobsthal(pm.getDMainChain(), pm.getDPair());
		pm.printListAfter();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}