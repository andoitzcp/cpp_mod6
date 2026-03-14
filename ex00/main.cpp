#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    //std::cout << ScalarConverter::trimLiteral(argv[1]) << std::endl;
    ScalarConverter::convert(argv[1]);
}
