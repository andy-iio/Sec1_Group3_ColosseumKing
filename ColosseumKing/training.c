#define _CRT_SECURE_NO_WARNINGS
#include "training.h"
#include "gear.h"
#include "character.h"
#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5

void trainingMenu() {
    char subChoice;
    char input[MAXSIZE];

    while (1) {
        printf("****************************\n");
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
            printf("****************************\n");
            printf("\033[1;31mGEAR STATS\n\033[0m");
            startTrainingGear();
            clearInputBuffer();
            break;
        case 'b':
            printf("****************************\n");
            printf("\033[1;31mSKILL STATS\n\033[0m");
            startTraining();
            clearInputBuffer();
            break;
        case 'c':
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            printf("****************************\n");
            return;
        }
    }
}

void displayStats(STATSWITHCOLOR* character) {
    printf("\nCurrent Stats for %s:\n", character->userName);
    printf("+----------------+--------+\n");
    printf("| \033[32m     Stat     \033[0m | \033[32m Value\033[0m |\n");
    printf("+----------------+--------+\n");

    if (character->isStrengthBlue) {
        printf("| \033[1;33mStrength\033[0m       |   \033[1;36m%2d\033[0m   |\n", character->strength);
    }
    else {
        printf("| \033[1;33mStrength\033[0m       |   %2d   |\n", character->strength);
    }

    if (character->isSpeedBlue) {
        printf("| \033[1;33mSpeed\033[0m          |   \033[1;36m%2d\033[0m   |\n", character->speed);
    }
    else {
        printf("| \033[1;33mSpeed\033[0m          |   %2d   |\n", character->speed);
    }

    if (character->isCoordinationBlue) {
        printf("| \033[1;33mCoordination\033[0m   |   \033[1;36m%2d\033[0m   |\n", character->coordination);
    }
    else {
        printf("| \033[1;33mCoordination\033[0m   |   %2d   |\n", character->coordination);
    }

    if (character->isHealthBlue) {
        printf("| \033[1;33mHealth\033[0m         |   \033[1;36m%2d\033[0m   |\n", character->health);
    }
    else {
        printf("| \033[1;33mHealth\033[0m         |   %2d   |\n", character->health);
    }

    if (character->isSwordSkillsBlue) {
        printf("| \033[1;33mSword Skills\033[0m   |   \033[1;36m%2d\033[0m   |\n", character->swordSkills);
    }
    else {
        printf("| \033[1;33mSword Skills\033[0m   |   %2d   |\n", character->swordSkills);
    }

    printf("+----------------+--------+\n");
}

void trainStats(STATSWITHCOLOR* character) {
    int points = MAXSIZE;
    int choice;
    char operation;

    while (points > 0) {
        displayStats(character);
        printf("\033[1;31mYou have %d points to use on skills.\n\033[0m", points);
        printf("1. Strength\n");
        printf("2. Speed\n");
        printf("3. Coordination\n");
        printf("4. Health\n");
        printf("5. Sword Skills\n");
        printf("\nEnter the number of the stat you want to modify: ");

        if (scanf("%d", &choice) != 1) {
            printf("\033[31mInvalid input. Please enter a number between 1 and 5.\n\033[0m");
            printf("*************************************************************************");
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
            printf("\033[1;31mHealth selected.\n\033[0m");
            break;
        case 5:
            printf("\033[1;31mSword Skills selected.\n\033[0m");
            break;
        default:
            printf("\033[31mInvalid choice. Please enter a number between 1 and 5.\n\033[0m");
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
                printf("*************************************************************************");
                break;
            }
            else if (operation == '+') {
                switch (choice) {
                case 1:
                    character->strength++;
                    character->isStrengthBlue = 1;
                    points--;
                    break;
                case 2:
                    character->speed++;
                    character->isSpeedBlue = 1;
                    points--;
                    break;
                case 3:
                    character->coordination++;
                    character->isCoordinationBlue = 1;
                    points--;
                    break;
                case 4:
                    character->health++;
                    character->isHealthBlue = 1;
                    points--;
                    break;
                case 5:
                    character->swordSkills++;
                    character->isSwordSkillsBlue = 1;
                    points--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (character->strength > 0) {
                        character->strength--;
                        points++;
                    }
                    else {
                        printf("\033[31mStrength cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 2:
                    if (character->speed > 0) {
                        character->speed--;
                        points++;
                    }
                    else {
                        printf("\033[31mSpeed cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 3:
                    if (character->coordination > 0) {
                        character->coordination--;
                        points++;
                    }
                    else {
                        printf("\033[31mCoordination cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 4:
                    if (character->health > 0) {
                        character->health--;
                        points++;
                    }
                    else {
                        printf("\033[31mHealth cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 5:
                    if (character->swordSkills > 0) {
                        character->swordSkills--;
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
            printf("*************************************************************************\n");
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

            displayStats(character);
            printf("\033[1;31mYou have %d points to use on skills.\n\033[0m", points);
        }
    }
    displayStats(character);
}

void startTraining() {
    char name[MAXSIZE];

    while (1) {
        printf("Enter the name of your character: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) > 0) {
            break;
        }
        printf("\033[31mCharacter name cannot be empty. Please enter a valid name.\n\n\033[0m");
        printf("****************************\n");
    }

    STATSWITHCOLOR* player = (STATSWITHCOLOR*)malloc(sizeof(STATSWITHCOLOR));
    if (player == NULL) {
        printf("Failed to create character.\n");
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

    printf("\n\033[1;31mTraining session complete.\n\033[0m");
}