#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) { std::cerr << "Error: bad input\nUsage(e.g): ./RPN \"n1 n2 +\"." << std::endl;
		return EXIT_FAILURE;
	}
	try {
		RPN rpn;
		rpn.evalRPN(av[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}