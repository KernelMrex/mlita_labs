#ifndef INVERSIONVECTOR_H
#define INVERSIONVECTOR_H

#include "Permutation.h"

class InversionVector
{
	friend std::ostream& operator<<(std::ostream& out, InversionVector& permutation)
	{
		bool isFirst = true;
		for (auto item : permutation.m_items)
		{
			if (!isFirst)
			{
				out << ' ';
			}
			isFirst = false;

			out << item;
		}

		return out;
	}

public:
	InversionVector(const Permutation& permutation)
		: m_items(std::vector<int>(permutation.GetSize()))
	{
		auto permutationItems = permutation.GetItems();

		for (int i = 0; i < permutationItems.size(); i++)
		{
			int biggerItems = 0;
			for (int j = 0; j < i; ++j)
			{
				if (permutationItems[j] > permutationItems[i])
				{
					biggerItems++;
				}
			}
			m_items[i] = biggerItems;
		}
	}

	[[nodiscard]] Permutation GetPermutation() const
	{
		std::vector<int> numberPool(m_items.size());
		for (int i = 0; i < m_items.size(); i++)
		{
			numberPool.push_back(i + 1);
		}
		return std::move(GetPermutation(numberPool));
	}

	[[nodiscard]] Permutation GetPermutation(std::vector<int> numberPool) const
	{
		std::vector<int> result(m_items.size());

		std::sort(numberPool.begin(), numberPool.end());

		std::list<int> sortedNumberPool(numberPool.begin(), numberPool.end());

		for (int i = m_items.size() - 1; i >= 0; i--)
		{
			auto posToRemove = (numberPool.size() - 1) - m_items[i];
			auto it = numberPool.begin(); std::advance(it, posToRemove);

			result[i] = *it;
			numberPool.erase(it);
		}

		return std::move(Permutation(result));
	}

private:
	std::vector<int> m_items;
};

#endif // INVERSIONVECTOR_H
