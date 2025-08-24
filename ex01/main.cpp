#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) { std::cerr << "Error: bad input\nUsage(e.g): ./RPN \"n1 n2 +\"." << std::endl; return EXIT_FAILURE; }
	RPN rpn;
	rpn.evalRPN(av[1]);
	return EXIT_SUCCESS;
}