#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
    if ( ac != 2 || !validFile(av[1]) ) {
        std::cerr << "Error: could not open file." << std::endl; exit(EXIT_FAILURE);
    }
    try
    {
   		BitcoinExchange btc;
        btc.setDataBase(dataBase);
        btc.fileInterpreter(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}