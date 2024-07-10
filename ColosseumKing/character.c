#include "character.h"
#include <string.h>
#define DEFAULT_VALUE 10
//Andy

//----INITILIZE----//
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
void initializePlayer(struct Player* player, char* username) {
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	_initalizeCharacter(player);
};

//load a player from save file 
void loadPlayer(struct Player* player, char* username, int health, int attackDamage, int strength, int speed, int coordination, int gearLevel) {
	player->gearLevel = gearLevel;
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	_loadCharacter(player, health, attackDamage, strength, speed, coordination);
}

//initalize a new enemy with default values
void initializeEnemy(struct Enemy* enemy, enum enemyType type) {
	enemy->type = type;
	_initalizeCharacter(enemy);
}

//load an enemy from save file
void loadEnemy(struct Enemy* enemy, enum enemyType type, int health, int attackDamage, int strength, int speed, int coordination) {
	enemy->type = type;
	_loadCharacter(enemy, health, attackDamage, strength, speed, coordination);
};


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