#pragma once
#include <stdio.h>

struct character {
	int level;
};

struct enemy {
	struct character;

};

struct player {
	struct character;
};

union stats {
	char STAMINA;
	char HEALTH;
};

void increaseCharacterLevel();
void increaseCharacterStats(union stats stat);
void getCharacterStats();
void getCharacterLevel();
void increaseCharacterArmour();