#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gear.h"

// Andy 

//the types of enemies avaliable to fight against
enum enemyType {
	LION,
	TIGER,
	BEAR,
	SWORDSMAN,
};

typedef struct Character {
	int level;
	int avatar;
	int health;
	int constitution;
	int strength;
	int speed;
	int coordination;
	int armourLevel;
	int armourSkill;
	int swordLevel;
	int swordSkill;
	int tempHealth;
} CHARACTER;

struct Player {
	struct Character;
	struct statsWithColor; //gear stats, find this struct in gear.h
	char userName[50];
	//int level;
	int avatar; //this will hold the avatar # that will be printed in attack module
};

struct Enemy {
	struct Character;
	enum enemyType type;
};

//----INITILIZE NEW CHARACTER----//

//load a player from save file 
struct Player* loadPlayer(char* username, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel);

//initialize a new player with default values 
struct Player* initializePlayer(char* username);

//initalize a new enemy with default values
struct Enemy* initializeEnemy(enum enemyType type);

//load enemy from save file
struct Enemy* loadEnemy(enum enemyType type, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill);

void matchEnemyToCharacterStats(struct Enemy* enemy, struct Player* player);

//----HEALTH----//

//randomly increase the health of a character
void randomHealthIncrease(struct Character* character);

//----SKILLS----//

//randomly increase a skill 
void randomSkillIncrease(struct Character* character, char skill);

//increase the level of a player by 1
void increasePlayerLevel(struct Player* player);

//----PRINT CHARACTER IMAGES----//
//prints the ASCII image of a character through a txt file
void printCharacterImage();
