#define _CRT_SECURE_NO_WARNINGS
#include "character.h"
#include "training.h"
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
c->avatar = 3; //need to hardcode this for save and load since attack doesnt set it
c->level = DEFAULT_VALUE;
c->health = DEFAULT_VALUE;
c->constitution = DEFAULT_VALUE;
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
	c->constitution = attackDamage;
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
struct Player* initializePlayer(char* username, char* password) {
	struct Player* player = _allocateMemoryPlayer();
	strcpy_s(player->userName, sizeof(player->userName) - 1, username);
	strcpy_s(player->Password, sizeof(player->Password) - 1, password);
	_initalizeCharacter(&player->character);
	initializeGear(player);
	player->skillPoints = 10;
	player->level = 1;
	return player;
};

//load a player from save file 
struct Player* loadPlayer(char* username, int health, int attackDamage, int strength, int speed, int coordination, int armourLevel, int armourSkill, int swordLevel, int swordSkill, int skillPoints, int avatar) {
	struct Player* player = _allocateMemoryPlayer();
	player->character.avatar = avatar;
	player->skillPoints = skillPoints;
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

void tempAttack(struct Player* player) {
	srand(time(NULL)); //seeding the random number generator used in character module


	char filename[] = "battleImage.txt";

	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		printf("Could not open file: %s\n", filename);
		return 1;
	}
	char ch;

	while ((ch = fgetc(file)) != EOF) {
		putchar(ch);
	}

	fclose(file);


	printf("\n\n");

	int randomNum = (rand() % 2) + 1;
	if (randomNum == 1) {
		printf("You won the battle! congrats!\n");
		increasePlayerLevel(player);
		printf("LEVEL UP! You are now level %d\n", player->level);
		player->skillPoints += 5;
	}
	else {
		printf("You were defeated... better luck next time.\n");
	}

	printf("\n\n");

	//press c to continue
	char choice;
	while (1) {
		printf("Battle session complete. Press c to continue or pres m to go to the in game menu");
		if (scanf_s(" %c", &choice) != 1) {
			printf("\n\033[31mInvalid input. Please enter c to continue or m to go to the in game menu: \n\033[0m");
			while (getchar() != '\n'); // Clear input buffer
			continue;
		}
		if (choice == 'm') {
			inGameMenu(player);
			break;
		}
		else if (choice == 'c') {
			startTraining(player);
			asteriskLongLine();
			break;
		}
		else {
			printf("\n\033[31mInvalid input. Please enter c to continue or m to go to the in game menu: \n\033[0m");

		}
	}
	}
