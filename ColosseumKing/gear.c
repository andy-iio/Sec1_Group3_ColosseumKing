#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "training.h"
#include "gear.h"
#include "gear.h"
#include "buffer.h"
#include "asterisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeGear(STATSWITHCOLOR* gear) {
    gear->coins = 1; // Default 1 coins
    gear->helmet = 0;
    gear->chestplate = 0;
    gear->leggings = 0;
    gear->boots = 0;
    gear->gauntlets = 0;
    gear->shoulderPads = 0;
    gear->belt = 0;
    gear->bracers = 0;
    gear->cape = 0;
    gear->shield = 0;
    gear->isHelmetBlue = 0;
    gear->isChestplateBlue = 0;
    gear->isLeggingsBlue = 0;
    gear->isBootsBlue = 0;
    gear->isGauntletsBlue = 0;
    gear->isShoulderPadsBlue = 0;
    gear->isBeltBlue = 0;
    gear->isBracersBlue = 0;
    gear->isCapeBlue = 0;
    gear->isShieldBlue = 0;
}

void buyGear(STATSWITHCOLOR* gear) {
    printf("\033[32mYou have %d coins.\033[0m\n", gear->coins);

    int gearCost = 10;

    if (gear->coins >= gearCost) {
        printf("\033[32mYou have enough coins to buy the gear set.\033[0m\n");
        gear->coins -= gearCost;

        printf("\033[32mPurchase successful! Your remaining coins: %d\033[0m\n", gear->coins);

        gear->helmet = 1;
        gear->chestplate = 1;
        gear->leggings = 1;
        gear->boots = 1;
        gear->gauntlets = 1;
        gear->shoulderPads = 1;
        gear->belt = 1;
        gear->bracers = 1;
        gear->cape = 1;
        gear->shield = 1;

        printf("\033[32mYou have successfully bought the gear set!\033[0m\n");
    }
    else {
        printf("\033[31mYou do not have enough coins to buy the gear set.\033[0m\n");
        printf("\033[31mYou need %d more coins to buy the gear set.\033[0m\n", gearCost - gear->coins);
    }
    asteriskShortLine();
}

void displayArmor(STATSWITHCOLOR* gear) {
    //printf("\nCurrent Armor for %s:\n", gear->userName);
    printf("+-------------------+--------+\n");
    printf("| \033[32m      Armor       \033[0m| \033[32m Value\033[0m |\n");
    printf("+-------------------+--------+\n");

    if (gear->isHelmetBlue) {
        printf("| \033[1;33mHelmet\033[0m            |   \033[1;36m%2d\033[0m   |\n", gear->helmet);
    }
    else {
        printf("| \033[1;33mHelmet\033[0m            |   %2d   |\n", gear->helmet);
    }

    if (gear->isChestplateBlue) {
        printf("| \033[1;33mChestplate\033[0m        |   \033[1;36m%2d\033[0m   |\n", gear->chestplate);
    }
    else {
        printf("| \033[1;33mChestplate\033[0m        |   %2d   |\n", gear->chestplate);
    }

    if (gear->isLeggingsBlue) {
        printf("| \033[1;33mLeggings\033[0m          |   \033[1;36m%2d\033[0m   |\n", gear->leggings);
    }
    else {
        printf("| \033[1;33mLeggings\033[0m          |   %2d   |\n", gear->leggings);
    }

    if (gear->isBootsBlue) {
        printf("| \033[1;33mBoots\033[0m             |   \033[1;36m%2d\033[0m   |\n", gear->boots);
    }
    else {
        printf("| \033[1;33mBoots\033[0m             |   %2d   |\n", gear->boots);
    }

    if (gear->isGauntletsBlue) {
        printf("| \033[1;33mGauntlets\033[0m         |   \033[1;36m%2d\033[0m   |\n", gear->gauntlets);
    }
    else {
        printf("| \033[1;33mGauntlets\033[0m         |   %2d   |\n", gear->gauntlets);
    }

    if (gear->isShoulderPadsBlue) {
        printf("| \033[1;33mShoulder Pads\033[0m     |   \033[1;36m%2d\033[0m   |\n", gear->shoulderPads);
    }
    else {
        printf("| \033[1;33mShoulder Pads\033[0m     |   %2d   |\n", gear->shoulderPads);
    }

    if (gear->isBeltBlue) {
        printf("| \033[1;33mBelt\033[0m              |   \033[1;36m%2d\033[0m   |\n", gear->belt);
    }
    else {
        printf("| \033[1;33mBelt\033[0m              |   %2d   |\n", gear->belt);
    }

    if (gear->isBracersBlue) {
        printf("| \033[1;33mBracers\033[0m           |   \033[1;36m%2d\033[0m   |\n", gear->bracers);
    }
    else {
        printf("| \033[1;33mBracers\033[0m           |   %2d   |\n", gear->bracers);
    }

    if (gear->isCapeBlue) {
        printf("| \033[1;33mCape\033[0m              |   \033[1;36m%2d\033[0m   |\n", gear->cape);
    }
    else {
        printf("| \033[1;33mCape\033[0m              |   %2d   |\n", gear->cape);
    }

    if (gear->isShieldBlue) {
        printf("| \033[1;33mShield\033[0m            |   \033[1;36m%2d\033[0m   |\n", gear->shield);
    }
    else {
        printf("| \033[1;33mShield\033[0m            |   %2d   |\n", gear->shield);
    }

    printf("+-------------------+--------+\n");
}

void trainArmor(STATSWITHCOLOR* gear) {
    int points = MAXSIZE;
    int choice;
    char operation;

    while (points > 0) {
        displayArmor(gear);
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
        printf("11. Back\n");
        printf("12. \033[32mBattle!\n\033[0m");
        printf("\nEnter the number of the armor part you want to modify: ");

        if (scanf("%d", &choice) != 1) {
            printf("\033[31mInvalid input. Please enter a number between 1 and 12.\n\033[0m");
            asteriskLongLine();
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
        case 11:
            printf("\n\033[1;31mTraining session complete.\033[0m");
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            asteriskShortLine();
            return;
        case 12:
            //Attack module 
            printf("Attack module section.\n");
            inGameLoop(); //this is just a test
        default:
            printf("\033[31mInvalid choice. Please enter a number between 1 and 12.\n\033[0m");
            asteriskLongLine();
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
                    gear->helmet++;
                    gear->isHelmetBlue = 1;
                    points--;
                    break;
                case 2:
                    gear->chestplate++;
                    gear->isChestplateBlue = 1;
                    points--;
                    break;
                case 3:
                    gear->leggings++;
                    gear->isLeggingsBlue = 1;
                    points--;
                    break;
                case 4:
                    gear->boots++;
                    gear->isBootsBlue = 1;
                    points--;
                    break;
                case 5:
                    gear->gauntlets++;
                    gear->isGauntletsBlue = 1;
                    points--;
                    break;
                case 6:
                    gear->shoulderPads++;
                    gear->isShoulderPadsBlue = 1;
                    points--;
                    break;
                case 7:
                    gear->belt++;
                    gear->isBeltBlue = 1;
                    points--;
                    break;
                case 8:
                    gear->bracers++;
                    gear->isBracersBlue = 1;
                    points--;
                    break;
                case 9:
                    gear->cape++;
                    gear->isCapeBlue = 1;
                    points--;
                    break;
                case 10:
                    gear->shield++;
                    gear->isShieldBlue = 1;
                    points--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (gear->helmet > 0) {
                        gear->helmet--;
                        points++;
                    }
                    else {
                        printf("\033[31mHelmet cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 2:
                    if (gear->chestplate > 0) {
                        gear->chestplate--;
                        points++;
                    }
                    else {
                        printf("\033[31mChestplate cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 3:
                    if (gear->leggings > 0) {
                        gear->leggings--;
                        points++;
                    }
                    else {
                        printf("\033[31mLeggings cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 4:
                    if (gear->boots > 0) {
                        gear->boots--;
                        points++;
                    }
                    else {
                        printf("\033[31mBoots cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 5:
                    if (gear->gauntlets > 0) {
                        gear->gauntlets--;
                        points++;
                    }
                    else {
                        printf("\033[31mGauntlets cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 6:
                    if (gear->shoulderPads > 0) {
                        gear->shoulderPads--;
                        points++;
                    }
                    else {
                        printf("\033[31mShoulder Pads cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 7:
                    if (gear->belt > 0) {
                        gear->belt--;
                        points++;
                    }
                    else {
                        printf("\033[31mBelt cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 8:
                    if (gear->bracers > 0) {
                        gear->bracers--;
                        points++;
                    }
                    else {
                        printf("\033[31mBracers cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 9:
                    if (gear->cape > 0) {
                        gear->cape--;
                        points++;
                    }
                    else {
                        printf("\033[31mCape cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 10:
                    if (gear->shield > 0) {
                        gear->shield--;
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
            displayArmor(gear);
            printf("\033[1;31mYou have %d points to use on armor.\n\033[0m", points);
        }
    }
    displayArmor(gear);
}

void startTrainingGear() {
    char name[MAXSIZE];

    while (1) {
        printf("Enter the name of your gear: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) > 0) {
            break;
        }
        printf("\033[31mgear name cannot be empty. Please enter a valid name.\n\n\033[0m");
        asteriskShortLine();
    }

    STATSWITHCOLOR* gear = (STATSWITHCOLOR*)malloc(sizeof(STATSWITHCOLOR));
    if (gear == NULL) {
        printf("Failed to create gear.\n");
        return;
    }
    initializeGear(gear); // Initialize gear attributes

    trainArmor(gear);

    free(gear);
}