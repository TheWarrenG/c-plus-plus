#include <iostream>

double readNumber();
char readOperation();
void answer(double x, double y, char op);



int main()
{
	double x = readNumber();
	double y = readNumber();
	char op = readOperation();
	answer(x, y, op);
	return 0;
}

double readNumber()
{
	std::cout << "Enter a double value: ";
	double input;
	std::cin >> input;
	return input;
}

char readOperation()
{
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char input;
	std::cin >> input;
	return input;
}

void answer(double x, double y, char op)
{
	double ans;
	if (op == '+')
		 ans = x + y;
	else if (op == '-')
		ans = x - y;
	else if (op == '*')
		ans = x * y;
	else if (op == '/')
		ans = x / y;
	std::cout << x << " " << op << " " << y << " is " << ans << std::endl;
}
