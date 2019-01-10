#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Creature.h"

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

/*Decreases the health of a creature. */
void Creature::reduceHealth(int damage)
{
	m_hitPoints -= damage;
}

/* Returns whether a creature is dead. */
bool Creature::isDead()
{
	return m_hitPoints <= 0;
}

/* Increases the amount of gold held by a creature. */
void Creature::addGold(int gold)
{
	m_gold += gold;
}
