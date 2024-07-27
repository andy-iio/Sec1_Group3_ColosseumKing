#include<stdio.h>
#include "character.h"
#include "save_load_login.h"
#define MAX 10

// FILE CREATION FUNCTIONS FOR TRAINING, CHARACTER, AND LOGIN \\



// Login Test File 
void create_file_l() {
	FILE* file_l = fopen("log.txt", "w");
	if (file_l == NULL) {
		printf("error making file (login)\n");
		return;
	}
	fprintf(file_l, "LOGIN INFORMATION:\n");
	fprintf(file_l, " Player1\n");
	fprintf(file_l, "Password1\n"); 

	fclose(file_l);
}


// FILE LOAD FUNCTION TESTS FOR LOADING TRAINING, CHARACTER, AND LOGIN INFORMATION \\

void create_file_t() {
FILE* file_t = fopen("training2.txt", "w");
if (file_t == NULL) {
	printf("error making file (training)\n");
	return;
}
fprintf(file_t, "GEAR DATA:\n");
fprintf(file_t, "Player1\n");
fprintf(file_t, "helmet1\nchestplate1\nleggings1\nboots1\ngauntlets1\nshoulderPads1\nbelt1\nbracers1\ncape1\nshield1\n10\n");
fclose(file_t);
}

// training load test 
void test_load_t() {

	struct Player Player1; // test struct 

	memset(&Player1, 0, sizeof(Player1)); // initalization of test struct 

	create_file_t(); // creating test file data

	if (LoadTraining(&Player1)) { // reading data 
		if (strcmp(Player1.userName, "Player1") == 0 &&
			strcmp(Player1.stats.helmet, "helmet1") == 0 &&
			strcmp(Player1.stats.chestplate, "chestplate1") == 0 &&
			strcmp(Player1.stats.leggings, "leggings1") == 0 &&
			strcmp(Player1.stats.boots, "boots1") == 0 &&
			strcmp(Player1.stats.gauntlets, "gauntlets1") == 0 &&
			strcmp(Player1.stats.shoulderPads, "shoulderPads1") == 0 &&
			strcmp(Player1.stats.belt, "belt1") == 0 &&
			strcmp(Player1.stats.bracers, "bracers1") == 0 &&
			strcmp(Player1.stats.cape, "cape1") == 0 &&
			strcmp(Player1.stats.shield, "shield1") == 0 &&
			strcmp(Player1.stats.coins, "10") == 0) {

			printf("Test Passed (training)\n");
		}
		else {
			printf("Test failed (training)\n");

		}
	}
}


// character load test
void test_load_c() {

	FILE* file_c = fopen("character.txt", "w");
	if (file_c == NULL) {
		printf("error making file (charcter)\n");
		return;
	}
	
	char username = "a";
	fprintf(file_c, "PLAYER DATA:\n");
	fprintf(file_c, "Username: %c\nAttack: %d\nCoordination: %d\nArmour: %d\nHealth: %d\nLevel: %d\nSpeed: %d\nStrength: %d\nAvatar: %d\n",username, 2, 4, 6, 8, 10, 12, 14, 0); // numbers are stats
	fclose(file_c);
	
	struct Player Player1; // test struct 

	memset(&Player1, 0, sizeof(Player1)); // initalization of test struct 

	if (loadCharcterFromFile(&Player1)) { // reading data 
		if (fgets(Player1.userName, "Username: %c\n", file_c) == NULL ||
			strcmp(Player1.character.attackDamage, "Attack: %d\n", file_c) != 0 ||
			strcmp(Player1.character.coordination, "Coordination: %d\n", file_c) != 0 ||
			strcmp(Player1.character.armourLevel, "Armour: %d\n", file_c) != 0 ||
			strcmp(Player1.character.health, "Health: %d\n", file_c) != 0 ||
			strcmp(Player1.level, "Level %d\n", file_c) != 0 ||
			strcmp(Player1.character.speed, "Speed: %d\n", file_c) != 0 ||
			strcmp(Player1.character.strength, "Strength: %d\n", file_c) != 0 ||
			strcmp(Player1.character.avatar, "Avatar: %d\n", file_c) != 0) {

			printf("Test Passed (character)\n");
		}
		else {
			printf("Test failed (character)\n");

		}
	}
}

// login load test
void test_load_l() {
	struct login info; // test struct 

	memset(&info, 0, sizeof(info)); // initalization of test struct 

	create_file_l(); // creating test file data

	if (loadLogin(&info)) { // reading data 
		if (strcmp(info.userName, "Player1") == 0 &&
			strcmp(info.password, "Password1") == 0) {

			printf("Test Passed (login)\n");
		}
		else {
			printf("Test failed (login)\n");

		}
	}
}














