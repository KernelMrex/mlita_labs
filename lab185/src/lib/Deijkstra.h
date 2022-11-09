#ifndef DEIJKSTRA_H
#define DEIJKSTRA_H

#include "BinaryHeap.h"
#include "WeightedGraph.h"
#include <limits>
#include <ranges>

static std::vector<int> BuildPath(std::vector<int> path, int endingVertex, int startingVertex)
{
	std::vector<int> res;

	while (endingVertex != startingVertex)
	{
		res.insert(res.begin(), endingVertex);
		endingVertex = path[endingVertex];
	}

	res.insert(res.begin(), startingVertex);

	return res;
}

std::optional<std::pair<int, std::vector<int>>> Dijkstra(
	const WeightedGraph& graph,
	int amountOfVertices,
	int startingVertex,
	int endingVertex)
{
	using Pair = std::pair<int, int>;

	std::vector<int> distancesToVertices(amountOfVertices + 1, std::numeric_limits<int>::max());
	std::vector<int> path(amountOfVertices + 1, -1);
	distancesToVertices[startingVertex] = 0;

	BinaryHeap<Pair> queue([](Pair p1, Pair p2) -> bool {
		return p1.first < p2.first;
	});

	queue.Add({ 0, startingVertex });

	while (!queue.Empty())
	{
		auto [curDistance, fromVertex] = queue.Top();
		queue.Pop();

		if (curDistance > distancesToVertices[fromVertex])
		{
			continue;
		}

		for (auto transition : graph.GetVertexTransitions(fromVertex))
		{
			auto toVertex = transition.toVertex;
			auto edgeWeight = transition.weight;
			if (distancesToVertices[toVertex] > distancesToVertices[fromVertex] + edgeWeight)
			{
				distancesToVertices[toVertex] = distancesToVertices[fromVertex] + edgeWeight;
				path[toVertex] = fromVertex;
				queue.Add({ distancesToVertices[toVertex], toVertex });
			}
		}
	}

	if (distancesToVertices[endingVertex] == std::numeric_limits<int>::max())
	{
		return std::nullopt;
	}

	return {std::make_pair(distancesToVertices[endingVertex], BuildPath(path, endingVertex, startingVertex))};
}

#endif // DEIJKSTRA_H
