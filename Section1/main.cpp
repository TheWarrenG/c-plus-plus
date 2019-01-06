#include <iostream>
#include <string>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:

	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoints;

public:

	Monster(MonsterType type, std::string name, std::string roar, int hitPoints)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
	{

	}

	std::string getTypeString(MonsterType type) const
	{
		switch (type)
		{
		case Monster::DRAGON:		return "dragon";
		case Monster::GOBLIN:		return "goblin";
		case Monster::OGRE:			return "ogre";
		case Monster::ORC:			return "orc";
		case Monster::SKELETON:		return "skeleton";
		case Monster::TROLL:		return "troll";
		case Monster::VAMPIRE:		return "vampire";
		case Monster::ZOMBIE:		return "zombie";
		default:					return "???";
		}
	}

	void print() const
	{
		std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints
			<< " hitpoints and says " << m_roar << "\n";
	}
};

class MonsterGenerator
{
public:
	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		Monster::MonsterType type{ static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)) };
		int hitPoints { getRandomNumber(1, 100) };

		static std::string s_names[6]{ "Deathwing", "Millhouse Manastorm", "Flowey", "Shrek", "Sans", "Papyrus" };
		static std::string s_roar[6]{ "*rawr*", "*rattle*", "*jajaja*", "*kuku*", "*meow*", "*agh*" };

		return Monster(type, s_names[getRandomNumber(0, 5)], s_roar[getRandomNumber(0, 5)], hitPoints);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}