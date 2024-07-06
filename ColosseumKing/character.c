#include "character.h"
#include <string.h>
//Andy

//----INITILIZE----//
//initialize a new player
void initializePlayer(struct Player* player, char* username, int health, int attackDamage, int strength, int speed, int coordination) {
	player->health = health;
	player->attackDamage = attackDamage;
	player->strength = strength;
	player->speeed = speed;
	player->coordination = coordination;
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
};

//initalize a new enemy
void initializeEnemy(struct Enemy* enemy, char type, int health, int attackDamage) {
	enemy->health = health;
	enemy->attackDamage = attackDamage;
	enemy->type = type;
};


//----HEALTH----//
//returns the current health of a character
int getHealth(struct Character* character) {
	return character->health;
};

//increase the health value of a character by x amount
void increaseHealth(struct Character* character, int healthIncrease) {
	character->health += healthIncrease;
};

//decrease the health value of a character by x amount
void decreaseHealth(struct Character* character, int healthDecrease) {
	character->health -= healthDecrease;
};

//randomly increase the health of a character 
void randomHealthIncrease(struct Character* character) {
	character->health += (rand() % 5 + 1); // rand num b/t 1 & 5
};
void getCharacterLevel() {

};

//----ATTACK DAMAGE----//
//returns the attack damage of a character
int getAttackDamage(struct Character* character) {
	return character->attackDamage;
};

//increase the characters attack damage by x amount
void increaseAttackDamage(struct Character* character, int attackDamageIncrease) {
	character->attackDamage += attackDamageIncrease;
};

//----PRINT CHARACTER IMAGES----//
//prints the ASCII image of a character
void printCharacterImage() {

};