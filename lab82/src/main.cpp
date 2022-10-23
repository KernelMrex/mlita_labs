#include "lib/Permutation.h"
#include <iostream>

int main()
{
	// Читаем перестановку A
	Permutation a;
	std::cin >> a;

	// Читаем перестановку B
	Permutation b;
	std::cin >> b;

	// Умножаем A * B = C
	Permutation c = a * b;

	// Выводим результат
	// std::cout << c << std::endl;

	return EXIT_SUCCESS;
}