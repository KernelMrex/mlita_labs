#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <iostream>
#include <istream>
#include <list>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

class Permutation
{
	friend std::istream& operator>>(std::istream& in, Permutation& permutation)
	{
		std::string s;
		std::getline(in, s);

		std::stringstream ss(s);

		for (int newItem = 0; ss >> newItem;)
		{
			permutation.AddElement(newItem);
		}

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, Permutation& permutation)
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
	Permutation()
		: m_items(std::vector<int>())
	{
	}

	explicit Permutation(std::vector<int> items)
		: m_items(std::move(items))
	{
	}

	[[nodiscard]] std::vector<int> GetItems() const
	{
		return m_items;
	}

	void AddElement(int value)
	{
		m_items.push_back(value);
	}

	[[nodiscard]] std::vector<Permutation> GetNextPermutations() const
	{
		std::vector<Permutation> results;
		Permute(results, m_items, std::vector<int>());
		return results;
	}

	Permutation operator*(const Permutation& y) const
	{
		if (m_items.size() != y.m_items.size())
		{
			throw std::invalid_argument("permutation sizes must be equal");
		}

		std::vector<int> result(m_items.size());

		for (int i = 0; i < m_items.size(); ++i)
		{
			result[i] = y.m_items.size() > m_items[i] - 1 ? y.m_items[m_items[i] - 1] : 0;
		}

		return Permutation(result);
	}

private:
	std::vector<int> m_items;

	static void Permute(std::vector<Permutation>& result, std::vector<int> arr, const std::vector<int>& memo)
	{
		int cur;

		for (int i = 0; i < arr.size(); i++)
		{
			cur = arr[i];
			arr.erase(arr.begin() + i);

			if (arr.empty())
			{
				std::vector<int> resultItem(memo);
				resultItem.push_back(cur);
				result.emplace_back(resultItem);
			}

			std::vector<int> newMemo(memo);
			newMemo.push_back(cur);

			Permute(result, arr, newMemo);

			arr.insert(arr.begin() + i, cur);
		}
	}
};

#endif // PERMUTATION_H
