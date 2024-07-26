#define _CRT_SECURE_NO_WARNINGS
#include "training.h"
#include "gear.h"
#include "character.h"
#include "buffer.h"
#include "menu.h"
#include "asterisk.h"
#include "attack_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

void trainingMenu() {
    char subChoice;
    char input[MAXSIZE];

    while (1) {
        printf("\033[1;31mTRAINING MENU\n\033[0m");
        printf("a. Gear Stats\n");
        printf("b. Skill Stats\n");
        printf("c. Back\n");
        printf("\nEnter your choice: ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) != 1 || (input[0] != 'a' && input[0] != 'b' && input[0] != 'c')) {
            printf("\033[31mInvalid choice. Please enter 'a', 'b', or 'c'.\n\033[0m");
            continue;
        }

        subChoice = input[0];
        switch (subChoice) {
        case 'a':
            asteriskShortLine();
            printf("\033[1;31mGEAR STATS\n\033[0m");
            startTrainingGear();
            clearInputBuffer();
            break;
        case 'b':
            asteriskShortLine();
            printf("\033[1;31mSKILL STATS\n\033[0m");
            startTraining();
            clearInputBuffer();
            break;
        case 'c':
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            asteriskShortLine();
            mainMenu();
            return;
        }
    }
}

void displayStats(struct Player* player) {
    printf("\nCurrent Stats for %s:\n", player->userName);
    printf("+----------------+--------+\n");
    printf("| \033[32m     Stat     \033[0m | \033[32m Value\033[0m |\n");
    printf("+----------------+--------+\n");

    if (player->isStrengthBlue) {
        printf("| \033[1;33mStrength\033[0m       |   \033[1;36m%2d\033[0m   |\n", player->strength);
    }
    else {
        printf("| \033[1;33mStrength\033[0m       |   %2d   |\n", player->strength);
    }

    if (player->isSpeedBlue) {
        printf("| \033[1;33mSpeed\033[0m          |   \033[1;36m%2d\033[0m   |\n", player->speed);
    }
    else {
        printf("| \033[1;33mSpeed\033[0m          |   %2d   |\n", player->speed);
    }

    if (player->isCoordinationBlue) {
        printf("| \033[1;33mCoordination\033[0m   |   \033[1;36m%2d\033[0m   |\n", player->coordination);
    }
    else {
        printf("| \033[1;33mCoordination\033[0m   |   %2d   |\n", player->coordination);
    }

    if (player->isHealthBlue) {
        printf("| \033[1;33mHealth\033[0m         |   \033[1;36m%2d\033[0m   |\n", player->health);
    }
    else {
        printf("| \033[1;33mHealth\033[0m         |   %2d   |\n", player->health);
    }

    if (player->isSwordSkillsBlue) {
        printf("| \033[1;33mSword Skills\033[0m   |   \033[1;36m%2d\033[0m   |\n", player->swordSkills);
    }
    else {
        printf("| \033[1;33mSword Skills\033[0m   |   %2d   |\n", player->swordSkills);
    }

    printf("+----------------+--------+\n");
}

void trainStats(struct Player* player) {
    int points = MAXSIZE;
    int choice;
    char operation;

    while (points > 0) {
        displayStats(player);
        printf("\033[1;31mYou have %d points to use on skills.\n\033[0m", points);
        printf("1. Strength\n");
        printf("2. Speed\n");
        printf("3. Coordination\n");
        printf("4. Constitution\n");
        printf("5. Sword Skills\n");
        printf("6. Back\n");
        printf("7. \033[32mBattle!\n\033[0m");
        printf("\nEnter the number of the stat you want to modify: ");

        if (scanf("%d", &choice) != 1) {
            printf("\033[31mInvalid input. Please enter a number between 1 and 7.\n\033[0m");
            asteriskLongLine();
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("\033[1;31mStrength selected.\n\033[0m");
            break;
        case 2:
            printf("\033[1;31mSpeed selected.\n\033[0m");
            break;
        case 3:
            printf("\033[1;31mCoordination selected.\n\033[0m");
            break;
        case 4:
            printf("\033[1;31mConstitution selected.\n\033[0m");
            break;
        case 5:
            printf("\033[1;31mSword Skills selected.\n\033[0m");
            break;
        case 6:
            printf("\n\033[1;31mTraining session complete.\033[0m");
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            asteriskShortLine();
            return;
        case 7:
            //Attack module 
            printf("Attack module section.\n");
            attackPhase(playerToCharacter(player));
            //inGameLoop(); //this is just a test
        default:
            printf("\033[31mInvalid choice. Please enter a number between 1 and 7.\n\033[0m");
            asteriskLongLine();
            while (getchar() != '\n');
            continue;
        }

        while (1) {
            printf("\nEnter '+' to increase, '-' to decrease the stat or 's' to save changes: ");
            if (scanf(" %c", &operation) != 1) {
                printf("\n\033[31mInvalid input. Please enter '+', '-', or 's'.\n\033[0m");
                while (getchar() != '\n');
                continue;
            }

            if (operation == 's') {
                asteriskLongLine();
                break;
            }
            else if (operation == '+') {
                switch (choice) {
                case 1:
                    player->strength++;
                    player->isStrengthBlue = 1;
                    points--;
                    break;
                case 2:
                    player->speed++;
                    player->isSpeedBlue = 1;
                    points--;
                    break;
                case 3:
                    player->coordination++;
                    player->isCoordinationBlue = 1;
                    points--;
                    break;
                case 4:
                    player->health++;
                    player->isHealthBlue = 1;
                    points--;
                    break;
                case 5:
                    player->swordSkills++;
                    player->isSwordSkillsBlue = 1;
                    points--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (player->strength > 0) {
                        player->strength--;
                        points++;
                    }
                    else {
                        printf("\033[31mStrength cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 2:
                    if (player->speed > 0) {
                        player->speed--;
                        points++;
                    }
                    else {
                        printf("\033[31mSpeed cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 3:
                    if (player->coordination > 0) {
                        player->coordination--;
                        points++;
                    }
                    else {
                        printf("\033[31mCoordination cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 4:
                    if (player->health > 0) {
                        player->health--;
                        points++;
                    }
                    else {
                        printf("\033[31mHealth cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 5:
                    if (player->swordSkills > 0) {
                        player->swordSkills--;
                        points++;
                    }
                    else {
                        printf("\033[31mSword Skills cannot be less than 0.\n\033[0m");
                    }
                    break;
                }
            }
            else {
                printf("\n\033[36mInvalid input. Please enter '+', '-', or 's (save)'.\n\033[0m");
            }

            if (points == 0) {
                break;
            }
            asteriskLongLine();
            switch (choice) {
            case 1:
                printf("\033[1;31mSTRENGTH\033[0m");
                break;
            case 2:
                printf("\033[1;31mSPEED\033[0m");
                break;
            case 3:
                printf("\033[1;31mCOORDINATION\033[0m");
                break;
            case 4:
                printf("\033[1;31mHEALTH\033[0m");
                break;
            case 5:
                printf("\033[1;31mSWORD SKILLS\033[0m");
                break;
            }

            displayStats(player);
            printf("\033[1;31mYou have %d points to use on skills.\n\033[0m", points);
        }
    }
    displayStats(player);
}

void startTraining() {
    char name[MAXSIZE];

    while (1) {
        printf("Enter the name of your player: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) > 0) {
            break;
        }
        printf("\033[31mplayer name cannot be empty. Please enter a valid name.\n\n\033[0m");
        asteriskShortLine();
    }

    struct Player* player = (struct Player*)malloc(sizeof(struct Player));
    if (player == NULL) {
        printf("Failed to create player.\n");
        return;
    }
    strncpy(player->userName, name, MAXSIZE);
    player->strength = 0;
    player->speed = 0;
    player->coordination = 0;
    player->health = 0;
    player->swordSkills = 0;
    player->isStrengthBlue = 0;
    player->isSpeedBlue = 0;
    player->isCoordinationBlue = 0;
    player->isHealthBlue = 0;
    player->isSwordSkillsBlue = 0;

    trainStats(player);

    free(player);
}