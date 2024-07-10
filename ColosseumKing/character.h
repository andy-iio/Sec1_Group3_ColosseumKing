#pragma once
#include <stdio.h>
// Andy 

//the types of enemies avaliable
//these are temporary types we can change them
enum enemyType {
	MONSTER,
	SWORDSMAN,
	ALIEN
};


struct Character {
	int health;
	int attackDamage;
	int strength;
	int speed;
	int coordination;
	//also in here will be the characters ascii image if we decide to do that
};

struct Player {
	struct Character;
	char userName[50];
	int level;
	int gearLevel;
};

struct Enemy {
	struct Character;
	enum enemyType type;
};

//----INITILIZE NEW CHARACTER----//

//load a player from save file 
void loadPlayer(struct Player* player, char* username, int health, int attackDamage, int strength, int speed, int coordination, int gearLevel);

//initialize a new player with default values 
void initializePlayer(struct Player* player, char* username);

//initalize a new enemy with default values
void initializeEnemy(struct Enemy* enemy, enum enemyType type);

//load enemy from save file
void loadEnemy(struct Enemy* enemy, enum enemyType type, int health, int attackDamage, int strength, int speed, int coordination);

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
