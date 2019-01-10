#pragma once
#ifndef GAMEFLOW_H
#define GAMEFLOW_H
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

/* PLAYER attacks MONSTER. If MONSTER is killed, PLAYER
   levels up and receivs gold from MONSTER. */
void attackMonster(Player &player, Monster &monster);

/* MONSTER attacks PLAYER.*/
void attackPlayer(Player &player, Monster &monster);

/* PLAYER fights a randomly generated monster until either
   PLAYER defeats the monster or monster defeats the PLAYER. */
bool fightMonster(Player &player);

#endif
