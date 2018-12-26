#include <iostream>
bool isPrime(int x);
int readNumber();

/* Reads in a single digit and determines
 * whether the digit is prime.
*/
int main()
{
	int input = readNumber();
	if (isPrime(input))
		std::cout << "The digit is prime";
	else
		std::cout << "The digis is not prime";
	return 0;
}

bool isPrime(int x)
{
	if (x == 2)
		return true;
	else if (x == 3)
		return true;
	else if (x == 5)
		return true;
	else if (x == 7)
		return true;
	else
		return false;
}

int readNumber()
{
	std::cout << "Enter a single-digit integer: ";
	int input;
	std::cin >> input;
	return input;
}