#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <list>
#include <vector>

template <class T>
class BinaryHeap
{
public:
	BinaryHeap()
		: m_values(std::vector<T>())
	{
	}

	void Add(T value)
	{
		m_values.push_back(value);

		int curPos = m_values.size() - 1;
		int parentPos = (curPos - 1) / 2;

		while (curPos > 0 && m_values[curPos] > m_values[parentPos])
		{
			std::swap(m_values[parentPos], m_values[curPos]);

			curPos = parentPos;
			parentPos = (curPos - 1) / 2;
		}
	}

private:
	std::vector<T> m_values;
};

#endif // BINARYHEAP_H
