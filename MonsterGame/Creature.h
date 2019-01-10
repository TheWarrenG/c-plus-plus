#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include <string>

// Generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max);

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

	/*Decreases the health of a creature. */
	void reduceHealth(int damage);

	/* Returns whether a creature is dead. */
	bool isDead();

	/* Increases the amount of gold held by a creature. */
	void addGold(int gold);

	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_hitPoints; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

};
#endif
