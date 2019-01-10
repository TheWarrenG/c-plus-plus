#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_hitPoints;
	int m_damage;
	int m_gold;

public:
	Creature(std::string name, char symbol,
			 int hitPoints, int damage, int gold)
		: m_name{ name }, m_symbol{ symbol },
		  m_hitPoints{ hitPoints }, m_damage{ damage },
		  m_gold{ gold }
	{
	}

	void reduceHealth(int damage)
	{
		m_hitPoints -= damage;
	}

	bool isDead()
	{
		return m_hitPoints <= 0;
	}

	void addGold(int gold)
	{
		m_gold += gold;
	}

	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_hitPoints; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

};

class Player : public Creature
{
private:
	int m_level{ 1 };

public:
	Player(std::string name)
		: Creature(name, '@', 10, 1, 0)
	{
	}

	void levelUp()
	{
		++m_level;
		++m_damage;
	}

	bool hasWon() { return (m_level == 20); }
	int getLevel() { return m_level; }
};

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

	struct MonsterData
	{
		std::string name;
		char symbol;
		int hitPoints;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type)
	: Creature(monsterData[type].name, monsterData[type].symbol,
			   monsterData[type].hitPoints, monsterData[type].damage,
			   monsterData[type].gold)
	{
	}

	static Monster getRandomMonster()
	{
		Type type{ static_cast<Monster::Type>(getRandomNumber(0, MAX_TYPES - 1)) };
		return Monster(type);
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

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

void attackPlayer(Player &player, Monster &monster)
{
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() <<
		" hit you for " << monster.getDamage() << " damage.\n";
}

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
		} while (playerAction != 'r' && playerAction !='R' &&
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
