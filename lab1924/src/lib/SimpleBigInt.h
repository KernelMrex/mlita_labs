#ifndef MLITA_LABS_LAB1924_SIMPLEBIGINT_H
#define MLITA_LABS_LAB1924_SIMPLEBIGINT_H

#include <sstream>
#include <string>
#include <vector>

class SimpleBigInt
{
public:
	SimpleBigInt(const std::string& number)
		: m_digits(std::vector<uint8_t>())
	{
		std::for_each(number.begin(), number.end(), [this](char digit) {
			m_digits.insert(m_digits.begin(),  digit - '0');
		});
	}

	std::string toString()
	{
		std::stringstream ss;

		std::for_each(m_digits.rbegin(), m_digits.rend(), [&ss](uint8_t digit) {
			ss << (char) ('0' + digit);
		});

		auto res = ss.str();

		return (res[0] == '0' && res.length() > 1) ? res.erase(0, 1) : res;
	}

	SimpleBigInt& operator-=(const SimpleBigInt& rhs) {
		bool carry = false;

		for (std::size_t i = 0; i < rhs.m_digits.size(); i++)
		{
			int t = m_digits[i] - rhs.m_digits[i] - (carry ? 1 : 0);

			carry = t < 0;
			if (carry)
			{
				t = 10 + t;
			}

			m_digits[i] = t;
		}

		for (std::size_t i = rhs.m_digits.size(); i < m_digits.size(); i++)
		{
			int t = m_digits[i] - (carry ? 1 : 0);
			carry = t < 0;
			if (carry)
			{
				t = 10 + t;
			}
			m_digits[i] = t;
		}

		return *this;
	}

	friend SimpleBigInt operator-(SimpleBigInt lhs, const SimpleBigInt& rhs) {
		lhs -= rhs;
		return lhs;
	}

private:
	std::vector<uint8_t> m_digits;
};

#endif // MLITA_LABS_LAB1924_SIMPLEBIGINT_H
