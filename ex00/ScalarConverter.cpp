#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>


std::string ScalarConverter::trimLiteral(const std::string& literal)
{
    size_t to = literal.length();
    while (--to > 0)
    {if (literal[to] != ' ')
            break ;
    }
    size_t from = 0;
    while (from < to)
    {
        if (literal[from] != ' ')
            break ;
        from++;
    }
    return literal.substr(from, from - to + 1);
}

void ScalarConverter::convert(const std::string& literal)
{
    std::string s = ScalarConverter::trimLiteral(literal);

    if (ScalarConverter::isChar(s))
        ScalarConverter::printChar(static_cast<char> (s[0]));
    else if (ScalarConverter::isInt(s))
        ScalarConverter::printInt(static_cast<int> (std::atoi(s.c_str())));
    else if (ScalarConverter::isFloat(s))
        ScalarConverter::printFloat(static_cast<float> (std::atof(s.c_str())));
    else if (ScalarConverter::isDouble(s))
        ScalarConverter::printDouble(static_cast<double> (std::atof(s.c_str())));
    else if (ScalarConverter::isPseudoLiteral(s))
        ScalarConverter::printPseudoLiteral(s);
    else
        std::cerr << "Invalid input" << std::endl;
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return literal.size() == 1 && std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
    //if (!ScalarConverter::isChar(literal))
    //    return false;
    if (literal.find_first_not_of("-0123456789") != std::string::npos)
        return false;
    size_t negPos = literal.find('-');
    if (negPos != 0 && negPos != std::string::npos)
        return false;
    size_t plusPos = literal.find('+');
    if (plusPos != 0 && plusPos != std::string::npos)
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.find_first_not_of("-0123456789.") != std::string::npos)
        return false;
    size_t negPos = literal.find('-');
    if (negPos != 0 && negPos != std::string::npos)
        return false;
    size_t plusPos = literal.find('+');
    if (plusPos != 0 && plusPos != std::string::npos)
        return false;
    size_t len =literal.length();
    int count = 0;
    size_t i = 0;
    while (i < len)
    {
        if (literal[i++] == '.')
            count++;
    }
    return count == 1;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.find_first_not_of("-0123456789.f") != std::string::npos)
        return false;
    size_t negPos = literal.find('-');
    if (negPos != 0 && negPos != std::string::npos)
        return false;
    size_t plusPos = literal.find('+');
    if (plusPos != 0 && plusPos != std::string::npos)
        return false;
    size_t len =literal.length();
    int count = 0;
    size_t i = 0;
    while (i < len)
    {
        if (literal[i++] == '.')
            count++;
    }
    return count == 1 && literal[len - 1] == 'f';
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return literal.compare("-inf") == 0
        || literal.compare("+inf") == 0
        || literal.compare("nan") == 0;
}

void ScalarConverter::printChar(char c)
{
    std::cout << "This is char" << std::endl;
    std::cout << "char: " << c << "\n"
              << "int: " << static_cast<int>(c) << "\n"
              << "float: " << static_cast<float>(c) << "f\n"
              << "double: " << static_cast<double>(c) << std::endl;
    return ;
}

void ScalarConverter::printInt(int i)
{
    std::cout << "This is int" << std::endl;
    std::cout << "char: " << static_cast<char>(i) << "\n"
              << "int: " << i << "\n"
              << "float: " << static_cast<float>(i) << "f\n"
              << "double: " << static_cast<double>(i) << std::endl;
    return ;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << "This is float" << std::endl;
    std::cout << "char: " << static_cast<char>(f) << "\n"
              << "int: " << static_cast<int>(f) << "\n"
              << "float: " << f << "f\n"
              << "double: " << static_cast<double>(f) << std::endl;
    return ;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "This is double" << std::endl;
    std::cout << "char: " << static_cast<char>(d) << "\n"
              << "int: " << static_cast<int>(d) << "\n"
              << "float: " << static_cast<float>(d) << "f\n"
              << "double: " << d << std::endl;
    return ;
}

void ScalarConverter::printPseudoLiteral(const std::string& pl)
{
    std::cout << "This is pseudo" << std::endl;
    std::cout << "char: Non displayable\n"
              << "int: " << pl << "\n"
              << "float: " << pl << "f\n"
              << "double: " << pl << std::endl;
    return ;
}
