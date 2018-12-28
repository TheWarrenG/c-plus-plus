#include <string>
#include <iostream>

int main()
{
	std::cout << "Enter your full name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "Enter your age: ";
	int age;
	std::cin >> age;

	std::cout << "You've lived " << static_cast<float>(age) / name.length() << " years for each letter in your name.";
	return 0;
}