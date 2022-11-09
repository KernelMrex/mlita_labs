#ifndef MLITA_LABS_LAB185_WEIGHTEDGRAPH_H
#define MLITA_LABS_LAB185_WEIGHTEDGRAPH_H

#include <map>
#include <vector>

//template <class int, class int>
class WeightedGraph
{
	struct Transition
	{
		int toVertex;
		int weight;
	};

public:
	WeightedGraph()
		: m_verticesMap(std::unordered_map<int, std::vector<Transition>>())
	{
	}

	void AddEdge(int fromVertex, int toVertex, int weight)
	{
		auto it = m_verticesMap.find(fromVertex);
		if (it == m_verticesMap.end())
		{
			m_verticesMap.emplace(fromVertex, std::vector{Transition{.toVertex = toVertex, .weight=weight}});
			return;
		}

		it->second.emplace_back(Transition{.toVertex = toVertex, .weight=weight});
	};

	std::vector<Transition> GetVertexTransitions(int fromVertex) const
	{
		auto it = m_verticesMap.find(fromVertex);
		if (it == m_verticesMap.end())
		{
			return std::vector<Transition>{};
		}
		return it->second;
	}

private:
	std::unordered_map<int, std::vector<Transition>> m_verticesMap;
};

#endif // MLITA_LABS_LAB185_WEIGHTEDGRAPH_H
