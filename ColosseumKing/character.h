#pragma once
#include <stdio.h>
// Andy 
struct Character {
	int health;
	int attackDamage;
	//also in here will be the characters ascii image
};

struct Player {
	struct Character;
	char userName[50];
	int strength;
	int speeed;
	int coordination;
};

struct Enemy {
	struct Character;
	char type;
};

//----INITILIZE NEW CHARACTER----//
//initialize a new player
void initializePlayer(struct Player* player, char* username, int health, int attackDamage, int strength, int speed, int coordination);

//load a player from save file 
void loadPlayer(struct Player* player);

//initalize a new enemy
void initializeEnemy(struct Enemy* enemy, char type, int health, int attackDamage);

//----HEALTH----//
//returns the current health of a character
int getHealth(struct Character* character);

//increase the health value of a character by x amount
void increaseHealth(struct Character* character, int healthIncrease);

//decrease the health value of a character by x amount
void decreaseHealth(struct Character* character, int healthDecrease);

//randomly increase the health of a character
void randomHealthIncrease(struct Character* character);

int getStrength(struct Character* character);
int getSpeed(struct Character* character);
int getCoordination(struct Character* character);
int getGearLevel(struct Character* character);

void increaseStrength(struct Character* character, int increase);
void increaseSpeed(struct Character* character, int increase);
void increaseCoordination(struct Character* character, int increase);
void increaseGearLevel(struct Character* character, int increase);

//----ATTACK DAMAGE----//
//returns the attack damage of a character
int getAttackDamage(struct Character* character);

//increase the characters attack damage by x amount
void increaseAttackDamage(struct Character* character, int attackDamageIncrease);

union stats {
	char STAMINA;
	char HEALTH;
};

//----PRINT CHARACTER IMAGES----//
//prints the ASCII image of a character
void printCharacterImage();