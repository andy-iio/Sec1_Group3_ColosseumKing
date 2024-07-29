// Ceren 
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

int trainingMenu(struct Player* player) {
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
            startTrainingGear(player);
            clearInputBuffer();
            break;
        case 'b':
            asteriskShortLine();
            printf("\033[1;31mSKILL STATS\n\033[0m");
            int result = startTraining(player);
            if (result == 6) {
                // Back to menu
                printf("Returning to main menu...\n");
                return 8; // return value is 8
            }
            clearInputBuffer();
            break;
        case 'c':
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            asteriskShortLine();
            return 0;
        }
    }
    return 0;
}

void displayStats(struct Player* player) {
    printf("\nCurrent Stats for %s:\n", player->userName);
    printf("+----------------+--------+\n");
    printf("| \033[32m     Stat     \033[0m | \033[32m Value\033[0m |\n");
    printf("+----------------+--------+\n");

    if (player->stats.isStrengthBlue) {
        printf("| \033[1;33mStrength\033[0m       |   \033[1;36m%2d\033[0m   |\n", player->character.strength);
    }
    else {
        printf("| \033[1;33mStrength\033[0m       |   %2d   |\n", player->character.strength);
    }

    if (player->stats.isSpeedBlue) {
        printf("| \033[1;33mSpeed\033[0m          |   \033[1;36m%2d\033[0m   |\n", player->character.speed);
    }
    else {
        printf("| \033[1;33mSpeed\033[0m          |   %2d   |\n", player->character.speed);
    }

    if (player->stats.isCoordinationBlue) {
        printf("| \033[1;33mCoordination\033[0m   |   \033[1;36m%2d\033[0m   |\n", player->character.coordination);
    }
    else {
        printf("| \033[1;33mCoordination\033[0m   |   %2d   |\n", player->character.coordination);
    }

    if (player->stats.isHealthBlue) {
        printf("| \033[1;33mHealth\033[0m         |   \033[1;36m%2d\033[0m   |\n", player->character.health);
    }
    else {
        printf("| \033[1;33mHealth\033[0m         |   %2d   |\n", player->character.health);
    }

    if (player->stats.isSwordSkillsBlue) {
        printf("| \033[1;33mSword Skills\033[0m   |   \033[1;36m%2d\033[0m   |\n", player->character.swordSkill);
    }
    else {
        printf("| \033[1;33mSword Skills\033[0m   |   %2d   |\n", player->character.swordSkill);
    }

    printf("+----------------+--------+\n");
}

int trainStats(struct Player* player) {
    //int points = player->skillPoints;
    int choice;
    char operation;

    while (1) {
        displayStats(player);
        printf("\033[1;31mYou have %d points to use on skills.\n\033[0m", player->skillPoints);
        printf("1. Strength\n");
        printf("2. Speed\n");
        printf("3. Coordination\n");
        printf("4. Constitution\n");
        printf("5. Sword Skills\n");
        printf("6. Back\n");
        printf("7. \033[1;32mBattle!\n\033[0m");
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
            return 6;
        case 7:

            printf("\n\033[1;31mTraining session complete.\033[0m");
            printf("\n\033[1;31mEntering Battle...\033[0m\n");
            attackPhase(player->character);
            inGameLoop(player); // Battle in game loop (ESC)
            
            return 7;

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
                    player->character.strength++;
                    player->stats.isStrengthBlue = 1;
                    player->skillPoints--;
                    break;
                case 2:
                    player->character.speed++;
                    player->stats.isSpeedBlue = 1;
                    player->skillPoints--;
                    break;
                case 3:
                    player->character.coordination++;
                    player->stats.isCoordinationBlue = 1;
                    player->skillPoints--;
                    break;
                case 4:
                    player->character.health++;
                    player->stats.isHealthBlue = 1;
                    player->skillPoints--;
                    break;
                case 5:
                    player->character.swordSkill++;
                    player->stats.isSwordSkillsBlue = 1;
                    player->skillPoints--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (player->character.strength > 1) {
                        player->character.strength--;
                         player->skillPoints++;
                    }
                    else {
                        printf("\033[31mStrength cannot be less than 1.\n\033[0m");
                    }
                    break;
                case 2:
                    if (player->character.speed > 1) {
                        player->character.speed--;
                         player->skillPoints++;
                    }
                    else {
                        printf("\033[31mSpeed cannot be less than 1.\n\033[0m");
                    }
                    break;
                case 3:
                    if (player->character.coordination > 1) {
                        player->character.coordination--;
                         player->skillPoints++;
                    }
                    else {
                        printf("\033[31mCoordination cannot be less than 1.\n\033[0m");
                    }
                    break;
                case 4:
                    if (player->character.health > 1) {
                        player->character.health--;
                         player->skillPoints++;
                    }
                    else {
                        printf("\033[31mHealth cannot be less than 1.\n\033[0m");
                    }
                    break;
                case 5:
                    if (player->character.swordSkill > 1) {
                        player->character.swordSkill--;
                         player->skillPoints++;
                    }
                    else {
                        printf("\033[31mSword Skills cannot be less than 1.\n\033[0m");
                    }
                    break;
                }
            }
            else {
                printf("\n\033[36mInvalid input. Please enter '+', '-', or 's (save)'.\n\033[0m");
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
            if (player->skillPoints == 0) {
                break;
            }
            displayStats(player);
            printf("\033[1;31mYou have %d points to use on skills.\n\033[0m", player->skillPoints);
        }
    }
    displayStats(player);
    return 6;
}

int startTraining(struct Player* player) {

    player->stats.isStrengthBlue = 0;
    player->stats.isSpeedBlue = 0;
    player->stats.isCoordinationBlue = 0;
    player->stats.isHealthBlue = 0;
    player->stats.isSwordSkillsBlue = 0;

    int result = trainStats(player);

    //free(player);

    return result;
}