#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>


std::string ScalarConverter::trimLiteral(const std::string& literal)
{
    std::string::const_iterator itb;
    for (itb = literal.begin(); itb != literal.end(); itb++)
    {
        if (!std::isspace(*itb))
            break ;
    }
    std::string::const_iterator ite;
    for (ite = literal.end(); ite != itb; ite--)
    {
        if (!std::isspace(*ite) && *ite != '\0' )
            break ;
    }
    std::string trimmed;
    return trimmed.assign(itb, ++ite);
}

int ScalarConverter::countChar(const std::string& s, char c)
{
    std::string::const_iterator it;
    int count = 0;
    for (it = s.begin(); it != s.end(); ++it)
    {
        if (*it == c)
            count++;
    }
    return (count);
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
    std::string::size_type otherChar = literal.find_first_not_of("-0123456789");
    std::string::size_type negPos = literal.find('-');
    std::string::size_type plusPos = literal.find('+');

    return otherChar == std::string::npos
        && (negPos == 0 || negPos == std::string::npos)
        && (plusPos == 0 || plusPos == std::string::npos);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    std::string::size_type otherChar = literal.find_first_not_of("-0123456789.");
    std::string::size_type negPos = literal.find('-');
    std::string::size_type plusPos = literal.find('+');
    int dotCount = ScalarConverter::countChar(literal, '.');

    return otherChar == std::string::npos
        && (negPos == 0 || negPos == std::string::npos)
        && (plusPos == 0 || plusPos == std::string::npos)
        && dotCount == 1;
}

bool ScalarConverter::isFloat(const std::string& literal)
{

    std::string::size_type otherChar = literal.find_first_not_of("-0123456789.f");
    std::string::size_type negPos = literal.find('-');
    std::string::size_type plusPos = literal.find('+');
    int dotCount = ScalarConverter::countChar(literal, '.');

    return otherChar == std::string::npos
        && (negPos == 0 || negPos == std::string::npos)
        && (plusPos == 0 || plusPos == std::string::npos)
        && dotCount == 1
        && *(literal.end() - 1) == 'f';
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return literal.compare("-inf") == 0
        || literal.compare("+inf") == 0
        || literal.compare("nan") == 0;
}

void ScalarConverter::printChar(char c)
{
    std::string ch = (c > 31 && c < 127) ? std::string(1, c) : "non printable";
    std::cout << "char: " << ch << "\n"
              << "int: " << static_cast<int>(c) << "\n"
              << "float: " << static_cast<float>(c) << "f\n"
              << "double: " << static_cast<double>(c) << std::endl;
    return ;
}

void ScalarConverter::printInt(int i)
{
    //std::string ch = std::isprint(i) ? std::string(1, i) : "non printable";
    std::string ch = (i > 31 && i < 127) ? std::string(1, i) : "non printable";
    std::cout << "char: " << ch << "\n"
              << "int: " << i << "\n"
              << "float: " << static_cast<float>(i) << "f\n"
              << "double: " << static_cast<double>(i) << std::endl;
    return ;
}

void ScalarConverter::printFloat(float f)
{
    std::string ch = (f > 31 && f < 127) ? std::string(1, f) : "non printable";
    std::cout << "char: " << ch << "\n"
              << "int: " << static_cast<int>(f) << "\n"
              << "float: " << f << "f\n"
              << "double: " << static_cast<double>(f) << std::endl;
    return ;
}

void ScalarConverter::printDouble(double d)
{
    std::string ch = (d > 31 && d < 127) ? std::string(1, d) : "non printable";
    std::cout << "char: " << ch << "\n"
              << "int: " << static_cast<int>(d) << "\n"
              << "float: " << static_cast<float>(d) << "f\n"
              << "double: " << d << std::endl;
    return ;
}

void ScalarConverter::printPseudoLiteral(const std::string& pl)
{
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: " << pl << "f\n"
              << "double: " << pl << std::endl;
    return ;
}
