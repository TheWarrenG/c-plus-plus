#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string make, std::string model)
		: m_make(make), m_model(model)
	{
	}

	friend bool operator== (const Car &c1, const Car &c2);
	friend bool operator!= (const Car &c1, const Car &c2);
	friend bool operator< (const Car &c1, const Car &c2);
	friend std::ostream& operator<<(std::ostream &out, const Car&c1);
};

bool operator== (const Car &c1, const Car &c2)
{
	return (c1.m_make == c2.m_make &&
		c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}

bool operator< (const Car &c1, const Car &c2)
{
	return c1.m_make == c2.m_make ? c1.m_model < c2.m_model : c1.m_make < c2.m_make;
}

std::ostream& operator<<(std::ostream &out, const Car &c1)
{
	out << "(" << c1.m_make << ", " << c1.m_model << ")";
	
	return out;
}

int main()
{
	std::vector<Car> v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end()); // requires an overloaded operator<

	for (auto &car : v)
		std::cout << car << '\n'; // requires an overloaded operator<<

	return 0;
}