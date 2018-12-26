#include <iostream>
#include "constants.h"

double readHeight();
double calculateHeight(int time, double initialHeight);

void printHeight(int time, double height);
void calculateAndPrintHeight(int time, double height);

int main()
{
	double initialHeight = readHeight();
	calculateAndPrintHeight(0, initialHeight);
	calculateAndPrintHeight(1, initialHeight);
	calculateAndPrintHeight(2, initialHeight);
	calculateAndPrintHeight(3, initialHeight);
	calculateAndPrintHeight(4, initialHeight);
	calculateAndPrintHeight(5, initialHeight);
	return 0;
}

double readHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double input;
	std::cin >> input;
	return input;
}

double calculateHeight(int time, double initialHeight)
{
	double heightChange = 0.5 * myConstants::gravity * time * time;
	double finalHeight = initialHeight - heightChange;
	return finalHeight;
}

void printHeight(int time, double height)
{
	if (height > 0)
	{
		std::cout << "At " << time << " seconds, the ball is at height: " <<
			height << " meters" << std::endl;
	}
	else
		std::cout << "At " << time << " seconds, the ball is on the ground.";
}

void calculateAndPrintHeight(int time, double height)
{
	double finalHeight = calculateHeight(time, height);
	printHeight(time, finalHeight);
}
