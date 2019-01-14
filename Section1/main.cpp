#include <iostream>

template<class T>
class Pair1
{
private:
	T m_first, m_second;

public:
	Pair1(const T& first, const T& second)
		: m_first{ first }, m_second{ second }
	{
	}

	T& first()
	{
		return m_first;
	}

	const T& first() const
	{
		return m_first;
	}

	T& second()
	{
		return m_second;
	}

	const T& second() const
	{
		return m_second;
	}
};

int main()
{
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}