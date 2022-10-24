#include "lib/InversionVector.h"
#include "lib/Permutation.h"
#include <iostream>

int main()
{
	// Читаем перестановку
	Permutation permutation;
	std::cin >> permutation;

	// Строим вектор инверсий для перестановки
	InversionVector inversionVector(permutation);

	// Выводим вектор инверсий
	std::cout << inversionVector << std::endl;

	// По вектору инверсий восстанавливаем перестановку
	Permutation reconstructedPermutation = inversionVector.GetPermutation(permutation.GetItems());

	// Выводим перестановку
	std::cout << reconstructedPermutation << std::endl;

	return EXIT_SUCCESS;
}