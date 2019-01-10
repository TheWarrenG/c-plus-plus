#include <iostream>
#include <string>

#include "Monster.h"

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

/* Return a randomly generated Monster according to MONSTERDATA. */
Monster Monster::getRandomMonster()
{
	Monster::Type type{ static_cast<Monster::Type>(getRandomNumber(0, MAX_TYPES - 1)) };
	return Monster(type);
}
