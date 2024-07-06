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
	srand(time(NULL)); //seeding the random number generator used in character module

	//-------------------------------------------
	//temporary testing for character module, I will remove later, feel free to comment it out -andy
	struct Player player1;
	struct Enemy zorb;

	initializePlayer(&player1, "abcde", 50, 70, 80, 90, 100);
	initializeEnemy(&zorb, "a", 50, 60);
	printf("player health: %d enemy health: %d\n", getHealth(&player1), getHealth(&zorb));
	increaseHealth(&player1, 4);
	increaseHealth(&zorb, 7);
	printf("player health: %d enemy health: %d\n", getHealth(&player1), getHealth(&zorb));
	decreaseHealth(&player1, 9);
	decreaseHealth(&zorb, 2);
	printf("player health: %d enemy health: %d\n", getHealth(&player1), getHealth(&zorb));
	randomHealthIncrease(&player1);
	printf("player health: %d enemy health: %d\n", getHealth(&player1), getHealth(&zorb));
	//end of character module temmporary testing
	//-------------------------------------------


	return 0;
}