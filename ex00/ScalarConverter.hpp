#ifndef SCALARCONVERTER_H_
#define SCALARCONVERTER_H_

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& literal);

    private:
        static std::string trimLiteral(const std::string& literal);
        static int detectType(const std::string& literal);
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        static bool isPseudoLiteral(const std::string& literal);
        static void printChar(char c);
        static void printInt(int i);
        static void printFloat(float f);
        static void printDouble(double d);
        static void printPseudoLiteral(const std::string& pl);
};


#endif // SCALARCONVERTER_H_
