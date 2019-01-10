#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Creature.h"

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

	/* Contains values necessary to initialize Creature. */
	struct MonsterData
	{
		std::string name;
		char symbol;
		int hitPoints;
		int damage;
		int gold;
	};

	/* Array that contains all possible MONSTERDATA structs. */
	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type)
		: Creature(monsterData[type].name, monsterData[type].symbol,
			monsterData[type].hitPoints, monsterData[type].damage,
			monsterData[type].gold)
	{
	}

	/* Return a randomly generated Monster according to MONSTERDATA. */
	static Monster getRandomMonster();
};

#endif
