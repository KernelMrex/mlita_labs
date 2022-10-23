#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <istream>
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

	friend std::ostream& operator<< (std::ostream& out, Permutation& permutation)
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
};

#endif // PERMUTATION_H
