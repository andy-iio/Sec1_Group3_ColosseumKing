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
	int attackDamage;
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
	int avatar; //this will hold the avatar # that will be printed in attack module
}CHARACTER;

struct Player {
	struct Character character;
	struct statsWithColor stats; //gear stats, find this struct in gear.h
	char userName[50];
	char Password[50];
	int level;
	int skillPoints;
};

struct Enemy {
	struct Character character;
	enum enemyType type;
};

//----INITILIZE NEW CHARACTER----//

//load a player from save file 
struct Player* loadPlayer(char* username, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill, int avatar);
//initialize a new player with default values 
struct Player* initializePlayer(char* username);

//initalize a new enemy with default values
struct Enemy* initializeEnemy(enum enemyType type);

//load enemy from save file
struct Enemy* loadEnemy(enum enemyType type, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill, int avatar);

void matchEnemyToCharacterStats(struct Enemy* enemy, struct Player* player);

//----HEALTH----//

//randomly increase the health of a character
void randomHealthIncrease(struct Character* character);

//----GEAR----//
struct Player* loadGear(struct Player* player, int helmet, int chestPlate, int leggings, int boots, int gauntlets, int shoulderPads, int belt, int bracers, int cape, int sheild, int coins);

//----SKILLS----//

//increase the level of a player by 1
void increasePlayerLevel(struct Player* player);

//----PRINT CHARACTER IMAGES----//
//prints the ASCII image of a character through a txt file
void printCharacterImage();
