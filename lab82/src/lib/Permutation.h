#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <istream>
#include <sstream>
#include <map>
#include <vector>

class Permutation
{
	friend std::istream& operator>> (std::istream& in, Permutation& permutation)
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

public:
	Permutation()
		: m_items(std::vector<int>())
	{}

	void AddElement(int value)
	{
		m_items.push_back(value);
	}

private:
	std::vector<int> m_items;
};

#endif // PERMUTATION_H
