#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "training.h"
#include "gear.h"
#include "buffer.h"
#include "asterisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeGear(struct Player* player) {
    player->stats.coins = 1; // Default 1 coins
    player->stats.helmet = 0;
    player->stats.chestplate = 0;
    player->stats.leggings = 0;
    player->stats.boots = 0;
    player->stats.gauntlets = 0;
    player->stats.shoulderPads = 0;
    player->stats.belt = 0;
    player->stats.bracers = 0;
    player->stats.cape = 0;
    player->stats.shield = 0;
    player->stats.isHelmetBlue = 0;
    player->stats.isChestplateBlue = 0;
    player->stats.isLeggingsBlue = 0;
    player->stats.isBootsBlue = 0;
    player->stats.isGauntletsBlue = 0;
    player->stats.isShoulderPadsBlue = 0;
    player->stats.isBeltBlue = 0;
    player->stats.isBracersBlue = 0;
    player->stats.isCapeBlue = 0;
    player->stats.isShieldBlue = 0;
}

void buyGear(struct Player* player) {
    printf("\033[32mYou have %d coins.\033[0m\n", player->stats.coins);

    int playerCost = 10;

    if (player->stats.coins >= playerCost) {
        printf("\033[32mYou have enough coins to buy the player set.\033[0m\n");
        player->stats.coins -= playerCost;

        printf("\033[32mPurchase successful! Your remaining coins: %d\033[0m\n", player->stats.coins);

        player->stats.helmet = 1;
        player->stats.chestplate = 1;
        player->stats.leggings = 1;
        player->stats.boots = 1;
        player->stats.gauntlets = 1;
        player->stats.shoulderPads = 1;
        player->stats.belt = 1;
        player->stats.bracers = 1;
        player->stats.cape = 1;
        player->stats.shield = 1;

        printf("\033[32mYou have successfully bought the player set!\033[0m\n");
    }
    else {
        printf("\033[31mYou do not have enough coins to buy the player set.\033[0m\n");
        printf("\033[31mYou need %d more coins to buy the player set.\033[0m\n", playerCost - player->stats.coins);
    }
    asteriskShortLine();
}

void displayArmor(struct Player* player) {
    //printf("\nCurrent Armor for %s:\n", player->stats.userName);
    printf("+-------------------+--------+\n");
    printf("| \033[32m      Armor       \033[0m| \033[32m Value\033[0m |\n");
    printf("+-------------------+--------+\n");

    if (player->stats.isHelmetBlue) {
        printf("| \033[1;33mHelmet\033[0m            |   \033[1;36m%2d\033[0m   |\n", player->stats.helmet);
    }
    else {
        printf("| \033[1;33mHelmet\033[0m            |   %2d   |\n", player->stats.helmet);
    }

    if (player->stats.isChestplateBlue) {
        printf("| \033[1;33mChestplate\033[0m        |   \033[1;36m%2d\033[0m   |\n", player->stats.chestplate);
    }
    else {
        printf("| \033[1;33mChestplate\033[0m        |   %2d   |\n", player->stats.chestplate);
    }

    if (player->stats.isLeggingsBlue) {
        printf("| \033[1;33mLeggings\033[0m          |   \033[1;36m%2d\033[0m   |\n", player->stats.leggings);
    }
    else {
        printf("| \033[1;33mLeggings\033[0m          |   %2d   |\n", player->stats.leggings);
    }

    if (player->stats.isBootsBlue) {
        printf("| \033[1;33mBoots\033[0m             |   \033[1;36m%2d\033[0m   |\n", player->stats.boots);
    }
    else {
        printf("| \033[1;33mBoots\033[0m             |   %2d   |\n", player->stats.boots);
    }

    if (player->stats.isGauntletsBlue) {
        printf("| \033[1;33mGauntlets\033[0m         |   \033[1;36m%2d\033[0m   |\n", player->stats.gauntlets);
    }
    else {
        printf("| \033[1;33mGauntlets\033[0m         |   %2d   |\n", player->stats.gauntlets);
    }

    if (player->stats.isShoulderPadsBlue) {
        printf("| \033[1;33mShoulder Pads\033[0m     |   \033[1;36m%2d\033[0m   |\n", player->stats.shoulderPads);
    }
    else {
        printf("| \033[1;33mShoulder Pads\033[0m     |   %2d   |\n", player->stats.shoulderPads);
    }

    if (player->stats.isBeltBlue) {
        printf("| \033[1;33mBelt\033[0m              |   \033[1;36m%2d\033[0m   |\n", player->stats.belt);
    }
    else {
        printf("| \033[1;33mBelt\033[0m              |   %2d   |\n", player->stats.belt);
    }

    if (player->stats.isBracersBlue) {
        printf("| \033[1;33mBracers\033[0m           |   \033[1;36m%2d\033[0m   |\n", player->stats.bracers);
    }
    else {
        printf("| \033[1;33mBracers\033[0m           |   %2d   |\n", player->stats.bracers);
    }

    if (player->stats.isCapeBlue) {
        printf("| \033[1;33mCape\033[0m              |   \033[1;36m%2d\033[0m   |\n", player->stats.cape);
    }
    else {
        printf("| \033[1;33mCape\033[0m              |   %2d   |\n", player->stats.cape);
    }

    if (player->stats.isShieldBlue) {
        printf("| \033[1;33mShield\033[0m            |   \033[1;36m%2d\033[0m   |\n", player->stats.shield);
    }
    else {
        printf("| \033[1;33mShield\033[0m            |   %2d   |\n", player->stats.shield);
    }

    printf("+-------------------+--------+\n");
}

void trainArmor(struct Player* player) {
    int points = MAXSIZE;
    int choice;
    char operation;

    while (points > 0) {
        displayArmor(player);
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
            inGameLoop(player); //this is just a test
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
                    player->stats.helmet++;
                    player->stats.isHelmetBlue = 1;
                    points--;
                    break;
                case 2:
                    player->stats.chestplate++;
                    player->stats.isChestplateBlue = 1;
                    points--;
                    break;
                case 3:
                    player->stats.leggings++;
                    player->stats.isLeggingsBlue = 1;
                    points--;
                    break;
                case 4:
                    player->stats.boots++;
                    player->stats.isBootsBlue = 1;
                    points--;
                    break;
                case 5:
                    player->stats.gauntlets++;
                    player->stats.isGauntletsBlue = 1;
                    points--;
                    break;
                case 6:
                    player->stats.shoulderPads++;
                    player->stats.isShoulderPadsBlue = 1;
                    points--;
                    break;
                case 7:
                    player->stats.belt++;
                    player->stats.isBeltBlue = 1;
                    points--;
                    break;
                case 8:
                    player->stats.bracers++;
                    player->stats.isBracersBlue = 1;
                    points--;
                    break;
                case 9:
                    player->stats.cape++;
                    player->stats.isCapeBlue = 1;
                    points--;
                    break;
                case 10:
                    player->stats.shield++;
                    player->stats.isShieldBlue = 1;
                    points--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (player->stats.helmet > 0) {
                        player->stats.helmet--;
                        points++;
                    }
                    else {
                        printf("\033[31mHelmet cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 2:
                    if (player->stats.chestplate > 0) {
                        player->stats.chestplate--;
                        points++;
                    }
                    else {
                        printf("\033[31mChestplate cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 3:
                    if (player->stats.leggings > 0) {
                        player->stats.leggings--;
                        points++;
                    }
                    else {
                        printf("\033[31mLeggings cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 4:
                    if (player->stats.boots > 0) {
                        player->stats.boots--;
                        points++;
                    }
                    else {
                        printf("\033[31mBoots cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 5:
                    if (player->stats.gauntlets > 0) {
                        player->stats.gauntlets--;
                        points++;
                    }
                    else {
                        printf("\033[31mGauntlets cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 6:
                    if (player->stats.shoulderPads > 0) {
                        player->stats.shoulderPads--;
                        points++;
                    }
                    else {
                        printf("\033[31mShoulder Pads cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 7:
                    if (player->stats.belt > 0) {
                        player->stats.belt--;
                        points++;
                    }
                    else {
                        printf("\033[31mBelt cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 8:
                    if (player->stats.bracers > 0) {
                        player->stats.bracers--;
                        points++;
                    }
                    else {
                        printf("\033[31mBracers cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 9:
                    if (player->stats.cape > 0) {
                        player->stats.cape--;
                        points++;
                    }
                    else {
                        printf("\033[31mCape cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 10:
                    if (player->stats.shield > 0) {
                        player->stats.shield--;
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
            displayArmor(player);
            printf("\033[1;31mYou have %d points to use on armor.\n\033[0m", points);
        }
    }
    displayArmor(player);
}

void startTrainingGear(struct Player* player) {

    initializeGear(player); // Initialize player attributes

    trainArmor(player);

    free(player);
}