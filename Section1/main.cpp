#include <utility>
#include <iostream>

int main()
{
	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

	for (int endIndex = length - 1; endIndex > 0; --endIndex)
	{
		bool notSwap = true;
		for (int currentIndex = 0; currentIndex < endIndex; ++currentIndex)
		{
			if (array[currentIndex] > array[currentIndex + 1])
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);
				notSwap = false;
			}
		}
		if (notSwap)
		{
			std::cout << "Early termination on iteration " << 9 - endIndex << "\n";
			break;
		}
	}

	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

	return 0;
}