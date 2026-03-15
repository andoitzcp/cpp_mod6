#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void);
void identify(Base* p);
void identify(Base& r);

Base* generate(void)
{
    int i = rand() % 3;

    return (
        (i == 0) ? (Base *) new A() :
        (i == 1) ? (Base *) new B() :
        (i == 2) ? (Base *) new C() :
        NULL);
}

void identify(Base* p)
{
	(dynamic_cast<A *>(p)) ? std::cout << "Type: A" << std::endl :
	(dynamic_cast<B *>(p)) ? std::cout << "Type: B" << std::endl :
	(dynamic_cast<C *>(p)) ? std::cout << "Type: C" << std::endl :
	std::cout << "Type: Unknown" << std::endl;
    return;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Type: A" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Type: B" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Type: C" << std::endl;
		return;
	} catch (std::exception &e) {}

	std::cout << "Type: Unknown" << std::endl;
}


int main(void)
{
    srand(std::time(NULL));
    Base *p = generate();
    identify(p);
    identify(*p);
    return 0;
}
