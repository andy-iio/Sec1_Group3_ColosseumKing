//ColosseumKing
//Andy Guest | Alexa Bowman | Ceren Askin | Grae Watson

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // for srand()
#include <time.h> // to use time for srand()

//all our modules, rename yours if you want to
#include "character.h"
#include "menu.h"
#include "attack_module.h"
#include "training.h"
#include "save_load_login.h"


int main(int argc, char* argv[]) {
	srand(time(NULL)); //seeding the random number generator used in character module

	CHARACTER player1 = { 1, 1, 100, 10, 10, 10, 10 };
	attackPhase(player1);
	//char filename[] = "ascii.txt";

	//FILE* file = fopen(filename, "r");

	//if (file == NULL) {
	//	printf("Could not open file: %s\n", filename);
	//	return 1;
	//}
	//char ch;

	//while ((ch = fgetc(file)) != EOF) {
	//	putchar(ch);
	//}

	//fclose(file);


	if (argc != 3) {
		printf("Arguments were not provided\n");
		return 1;  // Exit with error code
	}
	// Retrieve username and password from command line arguments
	char* username = argv[1];
	char* password = argv[2];

	// Validate login using the function
	//if (Login(username, password)) {
	//	printf("\nLogin successful!\n");
	//	topMainMenu();
	//	//inGameLoop(player); // Start the game and run the game loop
	//}
	//else {
	//	printf("Invalid username or password.\n");
	//}

	topMainMenu(); //remove this line once the save & load stuff is fixed above^^
	return 0;
}


 //   // Validate login using the function
 //   if (Login(username, password)) {
 //       printf("\nLogin successful!\n");
	//	mainMenu();
	//	inGameLoop(); // Start the game and run the game loop
 //   }
 //   else {
 //       printf("Invalid username or password.\n");
 //   }
	//



//-------------------------------------------
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
	*///end of character module temmporary testing
	//-------------------------------------------
