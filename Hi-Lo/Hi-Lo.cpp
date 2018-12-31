#include <iostream>
#include <random>
#include <ctime>

/* Generate random number between 1 and 100
 * using the Mersenne Twister algorithm and
 * system time. */
int generateNumber()
{
	// Initialize Mersenne Twister with a random seed based on system time.
	std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
	
	// Create random number generator that is uniformly distributed from 0 to 100.
	std::uniform_int_distribution<> gen(0, 100);

	return gen(mersenne);
}

/* Reads in guess number I from the user.*/
int readGuess(int i)
{
	while (true)
	{
		std::cout << "Guess #" << i << ": ";
		int x;
		std::cin >> x;

		if (std::cin.fail() || x < 0 || x > 100)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else {
			std::cin.ignore(32767, '\n');
			return x;
		}
	}
}

/* Reads user input to whether the user would like to play again.*/
char readPlayAgain()
{
	char c;
	do
	{
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> c;
	} while (c != 'y' && c != 'n');
	return c;
}

/* Plays a game of Hi-Lo.*/
void playGame()
{
	std::cout << "Let's play a game. I'm thinking of a number between 0 and 100. " <<
		"You have 7 tries to guess what it is.\n";
	int target = generateNumber();
	int i(1);
	for (; i <= 7; ++i)
	{
		int guess = readGuess(i);
		if (guess == target)
		{
			std::cout << "Correct! You win!\n";
			break;
		}
		else if (guess > target)
			std::cout << "Your guess is too high.\n";
		else
			std::cout << "Your guess is too low.\n";
	}

	if (i > 7)
		std::cout << "Sorry, you lose. The correct answer was " << target << ".\n";
}


int main()
{
	do
	{
		playGame();

		char c = readPlayAgain();
		if (c == 'n')
			break;
	} while (true);

	std::cout << "Thank you for playing.";

	return 0;
}