#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <algorithm>
#include <optional>
#include <unordered_set>

template <class VertexIndexType, class EdgeWeightType>
class WeightedGraph
{
public:
	class WeightedEdge
	{
	public:
		WeightedEdge(VertexIndexType fromVertex, VertexIndexType toVertex)
			: m_fromVertex(fromVertex)
			, m_toVertex(toVertex)
		{
		}

		WeightedEdge(const WeightedEdge& other)
			: m_fromVertex(other.m_fromVertex)
			, m_toVertex(other.m_toVertex)
			, m_weight(other.m_weight)
		{
		}

		WeightedEdge(VertexIndexType fromVertex, VertexIndexType toVertex, EdgeWeightType weight)
			: m_fromVertex(fromVertex)
			, m_toVertex(toVertex)
			, m_weight(weight)
		{
		}

		[[nodiscard]] VertexIndexType getFromVertex() const
		{
			return m_fromVertex;
		}

		[[nodiscard]] VertexIndexType getToVertex() const
		{
			return m_toVertex;
		}

		[[nodiscard]] EdgeWeightType getWeight() const
		{
			return m_weight;
		}

		bool operator==(const WeightedEdge& other) const
		{
			return (m_fromVertex == other.m_fromVertex && m_toVertex == other.m_toVertex);
		}

		bool operator>(const WeightedEdge& other) const
		{
			return m_weight > other.getWeight();
		}

		bool operator<(const WeightedEdge& other) const
		{
			return m_weight < other.getWeight();
		}

		struct HashFunction
		{
			std::size_t operator()(const WeightedEdge& edge) const
			{
				std::size_t fromVertexHash = std::hash<VertexIndexType>()(edge.m_fromVertex);
				std::size_t toVertexHash = std::hash<VertexIndexType>()(edge.m_toVertex) << 1;
				return fromVertexHash ^ toVertexHash;
			}
		};

	private:
		VertexIndexType m_fromVertex;
		VertexIndexType m_toVertex;
		EdgeWeightType m_weight;
	};

	WeightedGraph()
		: m_edges(){};

	void AddEdge(VertexIndexType fromVertex, VertexIndexType toVertex, EdgeWeightType weight)
	{
		m_edges.insert(WeightedEdge(fromVertex, toVertex, weight));
	};

	void RemoveEdge(VertexIndexType fromVertex, VertexIndexType toVertex)
	{
		m_edges.erase(WeightedEdge(fromVertex, toVertex));
	};

	WeightedEdge GetEdge(VertexIndexType fromVertex, VertexIndexType toVertex)
	{
		auto foundEdge = std::find(m_edges.begin(), m_edges.end(), WeightedEdge(fromVertex, toVertex));
		if (foundEdge == m_edges.end())
		{
			throw std::runtime_error("Can not update not existing edge");
		}
		return *foundEdge;
	}

	void UpdateEdge(VertexIndexType fromVertex, VertexIndexType toVertex, EdgeWeightType weight)
	{
		auto foundEdge = GetEdge(fromVertex, toVertex);
		m_edges.insert(WeightedEdge(foundEdge.getFromVertex(), foundEdge.getToVertex(), weight));
	};

	std::optional<EdgeWeightType> GetDistanceBetweenRelatedVertices(VertexIndexType fromVertex, VertexIndexType toVertex) const
	{
		auto edge = m_edges.find(WeightedEdge(fromVertex, toVertex));
		return edge != m_edges.end() ? (std::optional<EdgeWeightType>){ edge->getWeight() } : std::nullopt;
	}

	std::unordered_set<VertexIndexType> GetRelatedVertices(VertexIndexType fromVertex) const
	{
		std::unordered_set<VertexIndexType> relatedVertices;
		for (auto edge : m_edges)
		{
			if (edge.getFromVertex() == fromVertex)
			{
				relatedVertices.insert(edge.getToVertex());
			}
		}
		return relatedVertices;
	};

	WeightedEdge FindMinEdge() const
	{
		return *std::min_element(m_edges.begin(), m_edges.end());
	}

private:
	std::unordered_set<WeightedEdge, typename WeightedEdge::HashFunction> m_edges{};
};

#endif // WEIGHTED_GRAPH_H