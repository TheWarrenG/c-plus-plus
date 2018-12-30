#include <string>
#include <iostream>

enum monsterType
{
	MONSTER_OGRE,
	MONSTER_DRAGON,
	MONSTER_ORC,
	MONSTER_GIANT_SPIDER,
	MONSTER_SLIME
};

struct Monster
{
	monsterType type;
	std::string name;
	int damage;
};

void printMonster(Monster monster)
{
	std::string type;
	if (monster.type == MONSTER_OGRE)
		type = "Ogre";
	else if (monster.type == MONSTER_DRAGON)
		type = "Dragon";
	else if (monster.type == MONSTER_ORC)
		type = "Orc";
	else if (monster.type == MONSTER_GIANT_SPIDER)
		type = "Giant Spider";
	else if (monster.type == MONSTER_SLIME)
		type = "Slime";
	else
		type = "Unknown";
	std::cout << "This " << type << " is named " <<
		monster.name << " and has " << monster.damage << " health.\n";
}

int main()
{
	Monster ogre = { MONSTER_OGRE, "Torg", 145 };
	Monster slime = { MONSTER_SLIME, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);
	
	return 0;
}