#include<stdio.h>
#include "character.h"
#include "save_load_login.h"

// FILE CREATION FUNCTIONS FOR TRAINING, CHARACTER, AND LOGIN \\

// Training Test File 
void create_file_t() {
	FILE* file_t = fopen("train.txt", "w");
	if (file_t == NULL) {
		printf("error making file (training)\n");
			return;
	}
	fprintf(file_t,"GEAR DATA:\n");
	fprintf(file_t, "Player1\n");
	fprintf(file_t, "helmet1\nchestplate1\nleggings1\nboots1\ngauntlets1\nshoulderPads1\nbelt1\nbracers1\ncape1\nshield1\n10\n");
	fclose(file_t);
}

// Character Test File
void create_file_c() {
	FILE* file_c = fopen("c.txt", "w");
	if (file_c == NULL) {
		printf("error making file (charcter)\n");
		return;
	}
	fprintf(file_c, "CHARACTER DATA:\n");
	fprintf(file_c, "Player1\n");
	fprintf(file_c, "2\n4\n6\n8\n10\n12\n14\n16\n"); // numbers are stats

	fclose(file_c);
}

// Login Test File 
void create_file_l() {
	FILE* file_l = fopen("l.txt", "w");
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
			strcmp(Player1.stats.coins,"10") == 0) {

			printf("Test Passed (training)\n");
		}
		else {
			printf("Test failed (training)\n");

		}
	}
}

// character load test
void test_load_c() {
	struct Player Player1; // test struct 

	memset(&Player1, 0, sizeof(Player1)); // initalization of test struct 

	create_file_c(); // creating test file data


	if (loadCharcterFromFile(&Player1)) { // reading data 
		if (strcmp(Player1.userName, "Player1") == 0 &&
			strcmp(Player1.character.attackDamage, 2) == 0 &&
			strcmp(Player1.character.coordination, 4) == 0 &&
			strcmp(Player1.character.armourLevel, 6) == 0 &&
			strcmp(Player1.character.health, 8) == 0 &&
			strcmp(Player1.level, 10) == 0 &&
			strcmp(Player1.character.speed, 12) == 0 &&
			strcmp(Player1.character.strength, 14) == 0 &&
			strcmp(Player1.character.avatar, 16) == 0) {

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


	if (loadCharcterFromFile(&info)) { // reading data 
		if (strcmp(info.userName, "Player1") == 0 &&
			strcmp(info.password, "Password1") == 0) {

			printf("Test Passed (login)\n");
		}
		else {
			printf("Test failed (login)\n");

		}
	}
}














