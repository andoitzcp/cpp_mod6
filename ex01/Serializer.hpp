#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif // SERIALIZER_H_
