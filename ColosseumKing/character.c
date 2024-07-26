#include "character.h"
#define DEFAULT_VALUE 1

//Andy

//----INITILIZE----//
//allocate the memory for the character struct 
struct Enemy* _allocateMemoryEnemy() {
	struct Enemy* enemy = (struct Enemy*)malloc(sizeof(struct Enemy));
	if (enemy == NULL) {
		printf("memory allocation failed\n");
		free(enemy);
		exit(1);
	}
	return enemy;
}

struct Player* _allocateMemoryPlayer() {
	struct Player* player = (struct Player*)malloc(sizeof(struct Player));
	if (player == NULL) {
		printf("memory allocation failed\n");
		free(player);
		exit(1);
	}
	return player;
}

//this function is only to be used on this file, use initalizePlayer or initalizeEnemy instead
void _initalizeCharacter(struct Character* c) {
c->health = DEFAULT_VALUE;
c->attackDamage = DEFAULT_VALUE;
c->strength = DEFAULT_VALUE;
c->speed = DEFAULT_VALUE;
c->coordination = DEFAULT_VALUE;
c->armourLevel = DEFAULT_VALUE;
c->armourSkill = DEFAULT_VALUE;
c->swordLevel = DEFAULT_VALUE;
c->swordSkill = DEFAULT_VALUE;
}

//this function is only to be used on this file, use initalizePlayer or initalizeEnemy instead
void _loadCharacter(struct Character* c, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill, int avatar) {
	c->health = health;
	c->attackDamage = attackDamage;
	c->strength = strength;
	c->speed = speed;
	c->coordination = coordination;
	c->armourLevel = armourLevel;
	c->armourSkill = armourSkill;
	c->swordLevel = swordLevel;
	c->swordSkill = swordSkill;
	c->avatar = avatar;
}

//initialize a new player
struct Player* initializePlayer(char* username) {
	struct Player* player = _allocateMemoryPlayer();
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	_initalizeCharacter(&player->character);
	initializeGear(player);
	return player;
};

//load a player from save file 
struct Player* loadPlayer(char* username, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill, int avatar) {
	struct Player* player = _allocateMemoryPlayer();
	player->character.avatar = avatar;
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	_loadCharacter(&player->character, health, attackDamage, strength, speed, coordination, armourLevel, armourSkill, swordLevel, swordSkill, avatar);
	return player;
}

//initalize a new enemy with default values
struct Enemy* initializeEnemy(enum enemyType type) {
	struct Enemy* enemy = _allocateMemoryEnemy();
	enemy->type = type;
	_initalizeCharacter(&enemy->character);
	return enemy;
}

//load an enemy from save file --we dont need this?? 
struct Enemy* loadEnemy(enum enemyType type, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill, int avatar) {
	struct Enemy* enemy = _allocateMemoryEnemy();
	enemy->type = type;
	_loadCharacter(&enemy->character, health, attackDamage, strength, speed, coordination, armourLevel, armourSkill, swordLevel, swordSkill, avatar);
	return enemy;
};

//will match the enemy to the characters stats and randomly add or decrease each stat value by 1 or 0
//same # of stats as character total but split up differently added random on top 
void matchEnemyToCharacterStats(struct Enemy* enemy, struct Player* player) {
	int characterStatsTotalPoints = (player->character.health + player->character.attackDamage + player->character.speed + player->character.strength + player->character.coordination + player->character.armourLevel + player->character.armourSkill + player->character.swordSkill + player->character.swordLevel);

	int remainingPoints = characterStatsTotalPoints + (rand() % 5 + 1);
	while (remainingPoints != 0) {
		int randomStat = (rand() % 9 + 1); //random num between 1 and 9 (9 stats)

		switch (randomStat) {
		case 1:
			enemy->character.health++;
			remainingPoints--;
			break;
		case 2:
			enemy->character.attackDamage++;
			remainingPoints--;
			break;
		case 3:
			enemy->character.speed++;
			remainingPoints--;
			break;
		case 4:
			enemy->character.strength++;
			remainingPoints--;
			break;
		case 5:
			enemy->character.coordination++;
			remainingPoints--;
			break;
		case 6:
			enemy->character.armourLevel++;
			remainingPoints--;
			break;
		case 7:
			enemy->character.armourSkill++;
			remainingPoints--;
			break;
		case 8:
			enemy->character.swordLevel++;
			remainingPoints--;
			break;
		case 9:
			enemy->character.swordSkill++;
			remainingPoints--;
			break;
		
		}
	}
}

//-----GEAR-----//
//loads the gear for the player from a save file
struct Player* loadGear(struct Player* player, int helmet, int chestPlate, int leggings, int boots, int gauntlets, int shoulderPads, int belt, int bracers, int cape, int sheild, int coins) {
	player->stats.helmet = helmet;
	player->stats.chestplate = chestPlate;
	player->stats.leggings = leggings;
	player->stats.boots = boots;
	player->stats.gauntlets = gauntlets;
	player->stats.shoulderPads = shoulderPads;
	player->stats.belt = belt;
	player->stats.bracers = bracers;
	player->stats.cape = cape;
	player->stats.shield = sheild;
	player->stats.coins = coins;
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

//----PRINT CHARACTER IMAGES----//
//prints the ASCII image of a character through txt file
void printCharacterImage() {

};