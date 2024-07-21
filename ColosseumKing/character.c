#include "character.h"

#define DEFAULT_VALUE 1
//Andy

//----INITILIZE----//
//allocate the memory for the character struct 
struct Character* _allocateMemory() {
	struct Character* character = (struct Character*)malloc(sizeof(struct Character));
	if (character == NULL) {
		printf("memory allocation failed\n");
		exit(1);
	}
	return character;
}

//this function is only to be used on this file, use initalizePlayer or initalizeEnemy instead
void _initalizeCharacter(struct Character* c) {
c->health = DEFAULT_VALUE;
c->attackDamage = DEFAULT_VALUE;
c->strength = DEFAULT_VALUE;
c->speed = DEFAULT_VALUE;
c->coordination = DEFAULT_VALUE;
}

//this function is only to be used on this file, use initalizePlayer or initalizeEnemy instead
void _loadCharacter(struct Character* c, int health, int attackDamage, int strength, int speed, int coordination) {
	c->health = health;
	c->attackDamage = attackDamage;
	c->strength = strength;
	c->speed = speed;
	c->coordination = coordination;
}

//initialize a new player
struct Player* initializePlayer(char* username) {
	struct Player* player = _allocateMemory();
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	_initalizeCharacter(player);
};

//load a player from save file 
struct Player* loadPlayer(char* username, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel) {
	struct Player* player = _allocateMemory();
	player->armourLevel = armourLevel;
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	_loadCharacter(player, health, attackDamage, strength, speed, coordination);
}


//initalize a new enemy with default values
struct Enemy* initializeEnemy(enum enemyType type) {
	struct Enemy* enemy = _allocateMemory();
	enemy->type = type;
	_initalizeCharacter(enemy);
}

//load an enemy from save file
struct Enemy* loadEnemy(enum enemyType type, int health, int attackDamage, int strength, int speed, int coordination) {
	struct Enemy* enemy = _allocateMemory();
	enemy->type = type;
	_loadCharacter(enemy, health, attackDamage, strength, speed, coordination);
};

//will match the enemy to the characters stats and randomly add or decrease each stat value by 1 or 0
void matchEnemyToCharacterStats(struct Enemy* enemy, struct Player* player) {
	enemy = loadEnemy(enemy->type, player->health, player->attackDamage, player->strength, player->speed, player->coordination);
}

//----HEALTH----//

//randomly increase the health of a character 
void randomHealthIncrease(struct Character* character) {
	character->health += (rand() % 5 + 1); // rand num b/t 1 & 5
};

//----Stats & Skills----//

//increase the level of a player by 1
void increasePlayerLevel(struct Player* player) {
	player->level++;
}

//randomly increase a skill 
void randomSkillIncrease(struct Character* character, char skill) {

}

//----PRINT CHARACTER IMAGES----//
//prints the ASCII image of a character through txt file
void printCharacterImage() {

};