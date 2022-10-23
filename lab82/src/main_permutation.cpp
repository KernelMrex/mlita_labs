#include "lib/Permutation.h"
#include <iostream>

int main()
{
	// Читаем перестановку
	Permutation p;
	std::cin >> p;

	// Получаем следующие перестановки
	auto nextPermutations = p.GetNextPermutations();

	// Выводим следуюзие перестановки
	for (auto nextPermutation : nextPermutations)
	{
		std::cout << nextPermutation << std::endl;
	}

	return EXIT_SUCCESS;
}