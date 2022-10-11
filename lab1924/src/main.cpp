#include "lib/SimpleBigInt.h"
#include <iostream>

int main()
{
	SimpleBigInt a("1000000000100000");
	SimpleBigInt b("3");

	std::cout << a.toString() << " - " << b.toString() << " = " << (a - b).toString() << std::endl;
	return EXIT_SUCCESS;
}

