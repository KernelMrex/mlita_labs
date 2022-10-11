#include "lib/SimpleBigInt.h"
#include <iostream>

int main()
{
	try
	{
		std::string rawA, rawB;

		std::cin >> rawA;
		SimpleBigInt a(rawA);

		std::cin >> rawB;
		SimpleBigInt b(rawB);

		std::cout << a << " - " << b << " = " << a - b << std::endl;
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << "Invalid value" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

