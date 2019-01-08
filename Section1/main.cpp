#include <iostream>
#include <string>
#include <cassert>

class Mystring
{
private:
	std::string m_string;

public:
	Mystring(const std::string string) : m_string{ string }
	{
	
	}

	std::string operator()(int start, int len);
};

std::string Mystring::operator()(int start, int len)
{
	std::string result{ "" };
	for (int i = 0; i < len; ++i)
	{
		result += m_string[start + i];
	}
	return result;
}

int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7, 5); // start at index 7 and return 5 characters

	return 0;
}