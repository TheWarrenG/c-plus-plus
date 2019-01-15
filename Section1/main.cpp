#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Resource *res = new Resource;
	auto ptr1{ std::make_shared<Resource>(*res) };
	auto ptr2{ ptr1 };

	return 0;
}