#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2
{
private:
	int16_t m_integer{ 0 };
	int8_t m_decimal{ 0 };

public:
	FixedPoint2(int16_t integer = 0, int8_t decimal = 0) :
		m_integer{ integer }, m_decimal{ decimal }
	{
		while (m_decimal > 99)
		{
			m_decimal -= 100;
			m_integer += 1;
		}

		while (m_decimal < -99)
		{
			m_decimal += 100;
			m_integer -= 1;
		}

		if (m_integer < 0 && m_decimal > 0)
			m_decimal = -m_decimal;
		else if (m_integer > 0 && m_decimal < 0)
			m_integer = -m_integer;
	}

	FixedPoint2(double d)
	{
		m_integer = static_cast<int16_t>(d);
		
		m_decimal = static_cast<int8_t>(round(100 * (d - m_integer)));
	}
	
	operator double() const
	{
		return m_integer + 0.01 * m_decimal;
	}

	FixedPoint2 operator-()
	{
		return FixedPoint2(-m_integer, -m_decimal);
	}

	friend bool operator==(const FixedPoint2 &f1, const FixedPoint2 &f2);
	friend FixedPoint2 operator+(const FixedPoint2 &f1, const FixedPoint2 &f2);
	friend std::istream& operator>>(std::istream &in, FixedPoint2 &f1);
};

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &f)
{
	out << static_cast<double>(f);

	return out;
}

std::istream& operator>>(std::istream &in, FixedPoint2 &f1)
{
	double d;
	in >> d;
	f1 = FixedPoint2(d);

	return in;
}

bool operator==(const FixedPoint2 &f1, const FixedPoint2 &f2)
{
	return (f1.m_integer == f2.m_integer && f1.m_decimal == f2.m_decimal);
}

FixedPoint2 operator+(const FixedPoint2 &f1, const FixedPoint2 &f2)
{
	double d{ static_cast<double>(f1) + static_cast<double>(f2) };
	return FixedPoint2(d);
}


void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}