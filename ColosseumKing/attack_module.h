#pragma once
// By Grae Watson - 2024/07/10 - Colosseum King

#include "character.h"

//NWIN = no wins, PWIN = player wins, EWIN enemy wins
typedef enum fightstatus { NWIN, PWIN, EWIN}FIGHTSTATUS;


CHARACTER playerToCharacter(struct Player);
//
bool attackSuccess(CHARACTER attacker, CHARACTER deffender);

int attackHitAccuracy(CHARACTER attacker);

int attackPower(CHARACTER attacker);

int defenseChance(CHARACTER deffender);

int defensePower(CHARACTER deffender);

//returns FIGHTSTATUS that decides if fight continues. NWIN it continues attack phase. PWIN or EWIN it ends attack phase
FIGHTSTATUS round(CHARACTER* player, CHARACTER* enemy);

//returns false if player dies
bool attackPhase(CHARACTER player);


void printFight(CHARACTER player, CHARACTER enemy);

char** characterAvatar(int);



