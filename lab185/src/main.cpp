#include "lib/BinaryHeap.h"
#include "lib/Deijkstra.h"
#include "lib/WeightedGraph.h"
#include <iostream>

int main()
{
	BinaryHeap<int> heap([](int v1, int v2) { return v1 > v2; });

	int amountOfCities, amountOfRoads, startCity, endCity;

	WeightedGraph weightedGraph;

	//WeightedGraph<int, int> weightedGraph;

	std::cin >> amountOfCities >> amountOfRoads >> startCity >> endCity;
	for (int i = 0; i < amountOfRoads; ++i)
	{
		int roadFrom, roadTo, roadDistance;
		std::cin >> roadFrom >> roadTo >> roadDistance;
		weightedGraph.AddEdge(roadFrom, roadTo, roadDistance);
		weightedGraph.AddEdge(roadTo, roadFrom, roadDistance);
	}

	auto res = Dijkstra(weightedGraph, amountOfCities, startCity, endCity);

	if (!res.has_value())
	{
		std::cout << "No" << std::endl;
		return EXIT_SUCCESS;
	}

	std::cout << res->first << std::endl;
	for (auto city : res->second)
	{
		std::cout << city << ' ';
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
