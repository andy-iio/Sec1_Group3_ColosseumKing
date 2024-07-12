//ColosseumKing
//Andy Guest | Alexa Bowman | Ceren Askin | Grae Watson

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // for srand()
#include <time.h> // to use time for srand()

//all our modules, rename yours if you want to
#include "character.h"
//#include "menu.h"
//#include "attack.h"
//#include "training.h"
//#include "fileManagement.h"

int main(void) {

	/*
	 if (argc != 3) {
        printf("Arugements were not provided\n", argv[0]);
        return 1;  // Exit with error code
    }
    // Retrieve username and password from command line arguments
    char* username = argv[1];
    char* password = argv[2];

    // Validate login using the function
    if (Login(username, password)) {
        printf("Login successful!\n");
    }
    else {
        printf("Invalid username or password.\n");
    }
	*/



	srand(time(NULL)); //seeding the random number generator used in character module

	//-------------------------------------------
	//temporary testing for character module, I will remove later, feel free to comment it out -andy
	struct Player player1;
	struct Enemy zorb;

	loadPlayer(&player1, "abcde", 50, 70, 80, 90, 100, 1);
	initializeEnemy(&zorb, MONSTER);
	printf("player health: %d enemy health: %d\n", player1.health, zorb.health);
	player1.health++;
	zorb.health++;
	printf("player health: %d enemy health: %d\n", player1.health, zorb.health);
	player1.health--;
	zorb.health--;
	printf("player health: %d enemy health: %d\n", player1.health, zorb.health);
	randomHealthIncrease(&player1);
	printf("player health: %d enemy health: %d\n", player1.health, zorb.health);
	//end of character module temmporary testing
	//-------------------------------------------


	return 0;
}
