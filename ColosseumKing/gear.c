#define _CRT_SECURE_NO_WARNINGS
#include "training.h"
#include "character.h"
#include "gear.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeCharacter(STATSWITHCOLOR* character) {
    strncpy(character->userName, "Player1", MAXSIZE); // Default name, can be changed
    character->coins = 10; // Default 10 coins
    character->helmet = 0;
    character->chestplate = 0;
    character->leggings = 0;
    character->boots = 0;
    character->gauntlets = 0;
    character->shoulderPads = 0;
    character->belt = 0;
    character->bracers = 0;
    character->cape = 0;
    character->shield = 0;
    character->isHelmetBlue = 0;
    character->isChestplateBlue = 0;
    character->isLeggingsBlue = 0;
    character->isBootsBlue = 0;
    character->isGauntletsBlue = 0;
    character->isShoulderPadsBlue = 0;
    character->isBeltBlue = 0;
    character->isBracersBlue = 0;
    character->isCapeBlue = 0;
    character->isShieldBlue = 0;
}

void buyGear(STATSWITHCOLOR* character) {
    printf("\033[32mYou have %d coins.\033[0m\n", character->coins);

    int gearCost = 10;

    if (character->coins >= gearCost) {
        printf("\033[32mYou have enough coins to buy the gear set.\033[0m\n");
        character->coins -= gearCost;

        printf("\033[32mPurchase successful! Your remaining coins: %d\033[0m\n", character->coins);

        character->helmet = 1;
        character->chestplate = 1;
        character->leggings = 1;
        character->boots = 1;
        character->gauntlets = 1;
        character->shoulderPads = 1;
        character->belt = 1;
        character->bracers = 1;
        character->cape = 1;
        character->shield = 1;

        printf("\033[32mYou have successfully bought the gear set!\033[0m\n");
    }
    else {
        printf("\033[31mYou do not have enough coins to buy the gear set.\033[0m\n");
        printf("\033[31mYou need %d more coins to buy the gear set.\033[0m\n", gearCost - character->coins);
    }
    printf("****************************\n");
}

void displayArmor(STATSWITHCOLOR* character) {
    printf("\nCurrent Armor for %s:\n", character->userName);
    printf("+-------------------+--------+\n");
    printf("| \033[32m      Armor       \033[0m| \033[32m Value\033[0m |\n");
    printf("+-------------------+--------+\n");

    if (character->isHelmetBlue) {
        printf("| \033[1;33mHelmet\033[0m            |   \033[1;36m%2d\033[0m   |\n", character->helmet);
    }
    else {
        printf("| \033[1;33mHelmet\033[0m            |   %2d   |\n", character->helmet);
    }

    if (character->isChestplateBlue) {
        printf("| \033[1;33mChestplate\033[0m        |   \033[1;36m%2d\033[0m   |\n", character->chestplate);
    }
    else {
        printf("| \033[1;33mChestplate\033[0m        |   %2d   |\n", character->chestplate);
    }

    if (character->isLeggingsBlue) {
        printf("| \033[1;33mLeggings\033[0m          |   \033[1;36m%2d\033[0m   |\n", character->leggings);
    }
    else {
        printf("| \033[1;33mLeggings\033[0m          |   %2d   |\n", character->leggings);
    }

    if (character->isBootsBlue) {
        printf("| \033[1;33mBoots\033[0m             |   \033[1;36m%2d\033[0m   |\n", character->boots);
    }
    else {
        printf("| \033[1;33mBoots\033[0m             |   %2d   |\n", character->boots);
    }

    if (character->isGauntletsBlue) {
        printf("| \033[1;33mGauntlets\033[0m         |   \033[1;36m%2d\033[0m   |\n", character->gauntlets);
    }
    else {
        printf("| \033[1;33mGauntlets\033[0m         |   %2d   |\n", character->gauntlets);
    }

    if (character->isShoulderPadsBlue) {
        printf("| \033[1;33mShoulder Pads\033[0m     |   \033[1;36m%2d\033[0m   |\n", character->shoulderPads);
    }
    else {
        printf("| \033[1;33mShoulder Pads\033[0m     |   %2d   |\n", character->shoulderPads);
    }

    if (character->isBeltBlue) {
        printf("| \033[1;33mBelt\033[0m              |   \033[1;36m%2d\033[0m   |\n", character->belt);
    }
    else {
        printf("| \033[1;33mBelt\033[0m              |   %2d   |\n", character->belt);
    }

    if (character->isBracersBlue) {
        printf("| \033[1;33mBracers\033[0m           |   \033[1;36m%2d\033[0m   |\n", character->bracers);
    }
    else {
        printf("| \033[1;33mBracers\033[0m           |   %2d   |\n", character->bracers);
    }

    if (character->isCapeBlue) {
        printf("| \033[1;33mCape\033[0m              |   \033[1;36m%2d\033[0m   |\n", character->cape);
    }
    else {
        printf("| \033[1;33mCape\033[0m              |   %2d   |\n", character->cape);
    }

    if (character->isShieldBlue) {
        printf("| \033[1;33mShield\033[0m            |   \033[1;36m%2d\033[0m   |\n", character->shield);
    }
    else {
        printf("| \033[1;33mShield\033[0m            |   %2d   |\n", character->shield);
    }

    printf("+-------------------+--------+\n");
}

void trainArmor(STATSWITHCOLOR* character) {
    int points = MAXSIZE;
    int choice;
    char operation;

    while (points > 0) {
        displayArmor(character);
        printf("\033[1;31mYou have %d points to use on armor.\n\033[0m", points);
        printf("1. Helmet\n");
        printf("2. Chestplate\n");
        printf("3. Leggings\n");
        printf("4. Boots\n");
        printf("5. Gauntlets\n");
        printf("6. Shoulder Pads\n");
        printf("7. Belt\n");
        printf("8. Bracers\n");
        printf("9. Cape\n");
        printf("10. Shield\n");
        printf("\nEnter the number of the armor part you want to modify: ");

        if (scanf("%d", &choice) != 1) {
            printf("\033[31mInvalid input. Please enter a number between 1 and 10.\n\033[0m");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("\033[1;31mHelmet selected.\n\033[0m");
            break;
        case 2:
            printf("\033[1;31mChestplate selected.\n\033[0m");
            break;
        case 3:
            printf("\033[1;31mLeggings selected.\n\033[0m");
            break;
        case 4:
            printf("\033[1;31mBoots selected.\n\033[0m");
            break;
        case 5:
            printf("\033[1;31mGauntlets selected.\n\033[0m");
            break;
        case 6:
            printf("\033[1;31mShoulder Pads selected.\n\033[0m");
            break;
        case 7:
            printf("\033[1;31mBelt selected.\n\033[0m");
            break;
        case 8:
            printf("\033[1;31mBracers selected.\n\033[0m");
            break;
        case 9:
            printf("\033[1;31mCape selected.\n\033[0m");
            break;
        case 10:
            printf("\033[1;31mShield selected.\n\033[0m");
            break;
        default:
            printf("\033[31mInvalid choice. Please enter a number between 1 and 10.\n\033[0m");
            continue;
        }

        while (1) {
            printf("\nEnter '+' to increase, '-' to decrease the armor stat or 's' to save changes: ");
            if (scanf(" %c", &operation) != 1) {
                printf("\n\033[31mInvalid input. Please enter '+', '-', or 's'.\n\033[0m");
                while (getchar() != '\n');
                continue;
            }

            if (operation == 's') {
                break;
            }
            else if (operation == '+') {
                switch (choice) {
                case 1:
                    character->helmet++;
                    character->isHelmetBlue = 1;
                    points--;
                    break;
                case 2:
                    character->chestplate++;
                    character->isChestplateBlue = 1;
                    points--;
                    break;
                case 3:
                    character->leggings++;
                    character->isLeggingsBlue = 1;
                    points--;
                    break;
                case 4:
                    character->boots++;
                    character->isBootsBlue = 1;
                    points--;
                    break;
                case 5:
                    character->gauntlets++;
                    character->isGauntletsBlue = 1;
                    points--;
                    break;
                case 6:
                    character->shoulderPads++;
                    character->isShoulderPadsBlue = 1;
                    points--;
                    break;
                case 7:
                    character->belt++;
                    character->isBeltBlue = 1;
                    points--;
                    break;
                case 8:
                    character->bracers++;
                    character->isBracersBlue = 1;
                    points--;
                    break;
                case 9:
                    character->cape++;
                    character->isCapeBlue = 1;
                    points--;
                    break;
                case 10:
                    character->shield++;
                    character->isShieldBlue = 1;
                    points--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (character->helmet > 0) {
                        character->helmet--;
                        points++;
                    }
                    else {
                        printf("\033[31mHelmet cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 2:
                    if (character->chestplate > 0) {
                        character->chestplate--;
                        points++;
                    }
                    else {
                        printf("\033[31mChestplate cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 3:
                    if (character->leggings > 0) {
                        character->leggings--;
                        points++;
                    }
                    else {
                        printf("\033[31mLeggings cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 4:
                    if (character->boots > 0) {
                        character->boots--;
                        points++;
                    }
                    else {
                        printf("\033[31mBoots cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 5:
                    if (character->gauntlets > 0) {
                        character->gauntlets--;
                        points++;
                    }
                    else {
                        printf("\033[31mGauntlets cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 6:
                    if (character->shoulderPads > 0) {
                        character->shoulderPads--;
                        points++;
                    }
                    else {
                        printf("\033[31mShoulder Pads cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 7:
                    if (character->belt > 0) {
                        character->belt--;
                        points++;
                    }
                    else {
                        printf("\033[31mBelt cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 8:
                    if (character->bracers > 0) {
                        character->bracers--;
                        points++;
                    }
                    else {
                        printf("\033[31mBracers cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 9:
                    if (character->cape > 0) {
                        character->cape--;
                        points++;
                    }
                    else {
                        printf("\033[31mCape cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 10:
                    if (character->shield > 0) {
                        character->shield--;
                        points++;
                    }
                    else {
                        printf("\033[31mShield cannot be less than 0.\n\033[0m");
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
            displayArmor(character);
            printf("\033[1;31mYou have %d points to use on armor.\n\033[0m", points);
        }
    }
    displayArmor(character);
}

void startTrainingGear() {
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

    STATSWITHCOLOR* character = (STATSWITHCOLOR*)malloc(sizeof(STATSWITHCOLOR));
    if (character == NULL) {
        printf("Failed to create character.\n");
        return;
    }
    strncpy(character->userName, name, MAXSIZE);
    initializeCharacter(character); // Initialize character attributes

    trainArmor(character);

    free(character);

    printf("\n\033[1;31mTraining session complete.\n\033[0m");
}