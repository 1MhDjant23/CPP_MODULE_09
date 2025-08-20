#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
    if ( ac != 2 || !validFile(av[1]) ) {
        std::cerr << "Error: could not open file." << std::endl; exit(EXIT_FAILURE);
    }
    // std::cout << "--------------------" << std::endl;
    BitcoinExchange btc;
    try
    {
        btc.setDataBase(dataBase);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    
    return EXIT_SUCCESS;
}