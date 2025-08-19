#include "BitcoinExchange.hpp"



int main (int ac, char **av) {
    if ( ac != 2 || !validFile(av[1]) )
        std::cerr << "Error: could not open file." << std::endl; exit(EXIT_FAILURE);
    

    
    return EXIT_SUCCESS;
}