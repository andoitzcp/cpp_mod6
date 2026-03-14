#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

void printData(Data *d)
{
    std::cout << "Printing data...\n"
              << "i = " << d->i << "\n"
              << "Finshed printing data." << std::endl;
}

int main(void)
{
    Data d = {.i = 10};
    printData(&d);
    uintptr_t raw = Serializer::serialize(&d);
    Data *p = Serializer::deserialize(raw);
    printData(p);
    return 0;
}
