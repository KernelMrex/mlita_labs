#ifndef MLITA_LABS_LAB1924_SIMPLEBIGINT_H
#define MLITA_LABS_LAB1924_SIMPLEBIGINT_H

#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class SimpleBigInt
{
public:
	explicit SimpleBigInt(const std::string& number)
		: m_digits(std::vector<uint8_t>())
	{
		std::for_each(number.begin(), number.end(), [this](char digit) {
			if (digit > '9' || digit < '0')
			{
				throw std::invalid_argument("Invalid value");
			}
			m_digits.insert(m_digits.begin(), digit - '0');
		});
	}

	friend std::ostream& operator<<(std::ostream& os, const SimpleBigInt& val)
	{
		os << val.toString();
		return os;
	}

	[[nodiscard]] std::string toString() const
	{
		std::stringstream ss;

		std::for_each(m_digits.rbegin(), m_digits.rend(), [&ss](uint8_t digit) {
			ss << (char)('0' + digit);
		});

		auto res = ss.str();

		return (res.length() > 1 && res[0] == '0') ? res.erase(0, 1) : res;
	}

	SimpleBigInt& operator-=(const SimpleBigInt& rhs)
	{
		bool carry = false;

		for (std::size_t i = 0; i < m_digits.size(); i++)
		{
			int t = m_digits[i] - (i < rhs.m_digits.size() ? rhs.m_digits[i] : 0) - (carry ? 1 : 0);
			carry = t < 0;
			if (carry)
			{
				t = 10 + t;
			}
			m_digits[i] = t;
		}

		return *this;
	}

	friend SimpleBigInt operator-(SimpleBigInt lhs, const SimpleBigInt& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

private:
	std::vector<uint8_t> m_digits;
};

#endif // MLITA_LABS_LAB1924_SIMPLEBIGINT_H
