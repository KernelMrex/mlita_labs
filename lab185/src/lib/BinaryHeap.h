#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <functional>
#include <list>
#include <vector>

template <class T>
class BinaryHeap
{
public:
	BinaryHeap()
		: m_values(std::vector<T>())
		, m_lessFn([](T v1, T v2) -> bool { return v1 < v2; })
	{
	}

	explicit BinaryHeap(std::function<bool(T v1, T v2)> lessFn)
		: m_values(std::vector<T>())
		, m_lessFn(lessFn)
	{
	}

	void Add(T value)
	{
		m_values.push_back(value);

		int curPos = m_values.size() - 1;
		int parentPos = (curPos - 1) / 2;

		while (curPos > 0 && m_lessFn(m_values[parentPos], m_values[curPos]))
		{
			std::swap(m_values[parentPos], m_values[curPos]);

			curPos = parentPos;
			parentPos = (curPos - 1) / 2;
		}
	}

	T Top() const
	{
		return m_values[0];
	}

	void Pop()
	{
		if (m_values.empty())
		{
			return;
		}

		m_values[0] = m_values[m_values.size() - 1];
		m_values.pop_back();

		SiftUp(0);
	}

	bool Empty() const
	{
		return m_values.empty();
	}

private:
	std::vector<T> m_values;
	std::function<bool(T v1, T v2)> m_lessFn;

	void SiftUp(std::size_t curPos)
	{
		if (m_values.empty())
		{
			return;
		}

		while (true)
		{
			auto leftPos = curPos * 2 + 1;
			auto rightPos = curPos * 2 + 2;

			auto largestPos = curPos;

			if (leftPos < m_values.size() && m_lessFn(m_values[largestPos], m_values[leftPos]))
			{
				largestPos = leftPos;
			}

			if (rightPos < m_values.size() && m_lessFn(m_values[largestPos], m_values[rightPos]))
			{
				largestPos = rightPos;
			}

			if (largestPos == curPos)
			{
				break;
			}

			std::swap(m_values[curPos], m_values[largestPos]);
			curPos = largestPos;
		}
	}
};

#endif // BINARYHEAP_H
