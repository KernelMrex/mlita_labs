#include "lib/BinaryHeap.h"
#include <iostream>

int main()
{
	BinaryHeap<int> heap;

	heap.Add(1);
	heap.Add(2);
	heap.Add(3);
	heap.Add(4);
	heap.Add(0);

	return EXIT_SUCCESS;
}