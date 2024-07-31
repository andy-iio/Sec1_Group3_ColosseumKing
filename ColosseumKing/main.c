//ColosseumKing
//Andy Guest | Alexa Bowman | Ceren Askin | Grae Watson

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // for srand()
#include <time.h> // to use time for srand()
//#include"test_save_load_login.h"

//all our modules, rename yours if you want to
#include "character.h"
#include "menu.h"
//#include "attack_module.h"
#include "training.h"
#include "save_load_login.h"


int main(int argc, char* argv[]) {

	
	srand(time(NULL)); //seeding the random number generator used in character module

	char filename[] = "ascii.txt";

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

	struct Player* player;

	topMainMenu(&player); 
	return 0;
}

	//temporary testing for character module, I will remove later, feel free to comment it out -andy
	/*struct Player* player1 = loadPlayer("abcde", 50, 70, 80, 90, 100, 1);
	struct Enemy* zorb = initializeEnemy(LION);
	struct Player* ko = initializePlayer("po");
	matchEnemyToCharacterStats(zorb, ko);
	printf("player health: %d\n", ko->health);
	printf("player health: %d enemy health: %d\n", player1->health, zorb->health);
	player1->health++;
	zorb->health++;
	printf("player health: %d enemy health: %d\n", player1->health, zorb->health);
	player1->health--;
	zorb->health--;
	printf("player health: %d enemy health: %d\n", player1->health, zorb->health);
	randomHealthIncrease(player1);
	printf("player health: %d enemy health: %d\n", player1->health, zorb->health);
	*/
  //end of character module temmporary testing
	//-------------------------------------------


	//struct Player* player = initializePlayer("Player1", "Password123");

	//player->level = 8; //change somthing to make sure reading is good
	//saveCharacter(player);

	//loadCharcterFromFile(player);
	////check if it read right
	//printf("\nplayer username: %s\n", player->userName);
	//printf("player level: %d\n", player->level);

//	player->stats.belt = 2;
//	player->stats.boots = 4;
//	player->stats.bracers = 6;
//	player->stats.cape = 8;
//	player->stats.coins = 10;
//	player->stats.gauntlets = 12;
//	player->stats.helmet = 14;
//	player->stats.leggings = 16;
//	player->stats.shield = 18;
//
//
//	SaveTraining(player);
//	LoadTraining(player);
//
//
//	saveLogin(player);
//	loadLogin(player);
//
//}


	//if (argc != 3) {
	//	printf("Arguments were not provided\n");
	//	return 1;  // Exit with error code
	//}
	//// Retrieve username and password from command line arguments
	//char* username = argv[1];
	//char* password = argv[2];

	//// Validate login using the function
	//if (Login(username, password)) {
	//	printf("\nLogin successful!\n");
	//	topMainMenu();
	//	//inGameLoop(player); // Start the game and run the game loop
	//}
	//else {
	//	printf("Invalid username or password.\n");
	//}