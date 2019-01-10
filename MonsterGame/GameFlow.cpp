#include <iostream>

#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "gameFlow.h"

/* PLAYER attacks MONSTER. If MONSTER is killed, PLAYER
   levels up and receivs gold from MONSTER. */
void attackMonster(Player &player, Monster &monster)
{
	monster.reduceHealth(player.getDamage());
	std::cout << "You hit the " << monster.getName() <<
		" for " << player.getDamage() << " damage.\n";
	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << ".\n";

		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << '\n';

		player.addGold(monster.getGold());
		std::cout << "You found " << monster.getGold() << " gold.\n";
	}
}

/* MONSTER attacks PLAYER.*/
void attackPlayer(Player &player, Monster &monster)
{
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() <<
		" hit you for " << monster.getDamage() << " damage.\n";
}

/* PLAYER fights a randomly generated monster until either
   PLAYER defeats the monster or monster defeats the PLAYER. */
bool fightMonster(Player &player)
{
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() <<
		" (" << monster.getSymbol() << ").\n";
	while (!monster.isDead() && !player.isDead())
	{
		char playerAction;
		do
		{
			std::cout << "(R)un or (F)ight: ";
			std::cin >> playerAction;
			std::cin.ignore(32767, '\n');
		} while (playerAction != 'r' && playerAction != 'R' &&
			playerAction != 'f' && playerAction != 'F');

		if (playerAction == 'f' || playerAction == 'F')
		{
			attackMonster(player, monster);
			if (!monster.isDead())
				attackPlayer(player, monster);
		}
		else
		{
			if (getRandomNumber(0, 1))
			{
				std::cout << "You successfully fled.\n";
				break;
			}
			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(player, monster);
			}
		}
	}

	return player.hasWon() || player.isDead();
}