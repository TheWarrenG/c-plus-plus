#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "gameFlow.h"


int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	std::cout << "Enter your name: ";
	std::string playerName;
	std::getline(std::cin, playerName);

	Player player{ playerName };
	std::cout << "Welcome, " << player.getName() << "\n";

	bool gameFinished{ false };
	while (!gameFinished)
	{
		gameFinished = fightMonster(player);
	}

	if (player.hasWon())
		std::cout << "You won with " << player.getGold() << " gold!\n";
	else
	{
		std::cout << "You died at level " << player.getLevel() <<
			" and with " << player.getGold() << " gold.\n";

		std::cout << "Too bad you can't take it with you!\n";
	}

	return 0;
}
