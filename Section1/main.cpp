#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	static int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}

	void reduce()
	{
		int gcd{ Fraction::gcd(m_numerator, m_denominator) };
		m_numerator /= gcd;
		m_denominator /= gcd;
	}

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		reduce();
	}

	friend Fraction operator*(const Fraction &x, const Fraction &y);
	friend Fraction operator*(const Fraction &x, int y);
	friend Fraction operator*(int x, const Fraction &y);

	void print() const
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};

Fraction operator*(const Fraction &x, const Fraction &y)
{
	int numerator{ x.m_numerator * y.m_numerator };
	int denominator{ x.m_denominator * y.m_denominator };
	return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction &x, int y)
{
	return Fraction(x.m_numerator * y, x.m_denominator);
}

Fraction operator*(int x, const Fraction &y)
{
	return operator*(y, x);
}

int main()
{
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();
}