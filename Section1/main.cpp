#include <iostream>
#include <cassert>

class IntArray
{
private:
	int* m_array;
	int m_size{ 0 };

public:
	IntArray(int x)
	{
		m_array = new int[x];
		m_size = x;
	}

	int& operator[](int x)
	{
		assert(x < m_size);

		return m_array[x];
	}

	IntArray(const IntArray &intArray)
	{
		delete[] m_array;
		
		m_size = intArray.m_size;
		m_array = new int[intArray.m_size];
		for (int i = 0; i < m_size; ++i)
		{
			m_array[i] = intArray.m_array[i];
		}
	}

	IntArray& operator=(const IntArray &intArray)
	{
		if (this == &intArray)
			return *this;

		delete[] m_array;

		m_size = intArray.m_size;
		m_array = new int[intArray.m_size];
		for (int i = 0; i < m_size; ++i)
		{
			m_array[i] = intArray.m_array[i];
		}

		return *this;
	}

	~IntArray()
	{
		delete[] m_array;
	}

	friend std::ostream& operator<<(std::ostream &out, IntArray &intArray);
};

std::ostream& operator<<(std::ostream &out, IntArray &intArray)
{
	for (int i = 0; i < intArray.m_size; ++i)
		out << intArray.m_array[i] << " ";
	
	return out;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}