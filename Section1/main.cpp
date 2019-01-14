#include <iostream>
#include <string>

template<class T1, class T2>
class Pair
{
private:
	T1 m_first;
	T2 m_second;

public:
	Pair(const T1 &first, const T2 &second)
		: m_first{ first }, m_second{ second }
	{
	}

	T1& first()
	{
		return m_first;
	}

	const T1& first() const
	{
		return m_first;
	}

	T2& second()
	{
		return m_second;
	}

	const T2& second() const
	{
		return m_second;
	}
};

template<class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& first, const T& second)
		: Pair<std::string, T>(first, second)
	{
	}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}