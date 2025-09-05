#include "PmergeMe.hpp"
#include "TimeTracker.hpp"

int	main(int ac, char **av) {
	try {
		PmergeMe	pm(ac, av);
		TimeTracker	timer;
		// sorting using vector
		pm.pairSort(pm.getVList(), pm.getVPair(), timer);
		pm.setMainChain(pm.getVMainChain(), pm.getVPair());
		pm.insertSmallJacobsthal(pm.getVMainChain(), pm.getVPair(), timer);
		pm.printListAfter();
		timer.displayElapsedTime(VECTOR, ac - 1);
		// reset timer
		timer.reset();
		// sorting using deque
		pm.pairSort(pm.getDList(), pm.getDPair(), timer);
		pm.setMainChain(pm.getDMainChain(), pm.getDPair());
		pm.insertSmallJacobsthal(pm.getDMainChain(), pm.getDPair(), timer);
		timer.displayElapsedTime(DEQUE, ac - 1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}