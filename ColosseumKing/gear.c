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
    player->coins = 1; // Default 1 coins
    player->helmet = 0;
    player->chestplate = 0;
    player->leggings = 0;
    player->boots = 0;
    player->gauntlets = 0;
    player->shoulderPads = 0;
    player->belt = 0;
    player->bracers = 0;
    player->cape = 0;
    player->shield = 0;
    player->isHelmetBlue = 0;
    player->isChestplateBlue = 0;
    player->isLeggingsBlue = 0;
    player->isBootsBlue = 0;
    player->isGauntletsBlue = 0;
    player->isShoulderPadsBlue = 0;
    player->isBeltBlue = 0;
    player->isBracersBlue = 0;
    player->isCapeBlue = 0;
    player->isShieldBlue = 0;
}

void buyGear(struct Player* player) {
    printf("\033[32mYou have %d coins.\033[0m\n", player->coins);

    int playerCost = 10;

    if (player->coins >= playerCost) {
        printf("\033[32mYou have enough coins to buy the player set.\033[0m\n");
        player->coins -= playerCost;

        printf("\033[32mPurchase successful! Your remaining coins: %d\033[0m\n", player->coins);

        player->helmet = 1;
        player->chestplate = 1;
        player->leggings = 1;
        player->boots = 1;
        player->gauntlets = 1;
        player->shoulderPads = 1;
        player->belt = 1;
        player->bracers = 1;
        player->cape = 1;
        player->shield = 1;

        printf("\033[32mYou have successfully bought the player set!\033[0m\n");
    }
    else {
        printf("\033[31mYou do not have enough coins to buy the player set.\033[0m\n");
        printf("\033[31mYou need %d more coins to buy the player set.\033[0m\n", playerCost - player->coins);
    }
    asteriskShortLine();
}

void displayArmor(struct Player* player) {
    //printf("\nCurrent Armor for %s:\n", player->userName);
    printf("+-------------------+--------+\n");
    printf("| \033[32m      Armor       \033[0m| \033[32m Value\033[0m |\n");
    printf("+-------------------+--------+\n");

    if (player->isHelmetBlue) {
        printf("| \033[1;33mHelmet\033[0m            |   \033[1;36m%2d\033[0m   |\n", player->helmet);
    }
    else {
        printf("| \033[1;33mHelmet\033[0m            |   %2d   |\n", player->helmet);
    }

    if (player->isChestplateBlue) {
        printf("| \033[1;33mChestplate\033[0m        |   \033[1;36m%2d\033[0m   |\n", player->chestplate);
    }
    else {
        printf("| \033[1;33mChestplate\033[0m        |   %2d   |\n", player->chestplate);
    }

    if (player->isLeggingsBlue) {
        printf("| \033[1;33mLeggings\033[0m          |   \033[1;36m%2d\033[0m   |\n", player->leggings);
    }
    else {
        printf("| \033[1;33mLeggings\033[0m          |   %2d   |\n", player->leggings);
    }

    if (player->isBootsBlue) {
        printf("| \033[1;33mBoots\033[0m             |   \033[1;36m%2d\033[0m   |\n", player->boots);
    }
    else {
        printf("| \033[1;33mBoots\033[0m             |   %2d   |\n", player->boots);
    }

    if (player->isGauntletsBlue) {
        printf("| \033[1;33mGauntlets\033[0m         |   \033[1;36m%2d\033[0m   |\n", player->gauntlets);
    }
    else {
        printf("| \033[1;33mGauntlets\033[0m         |   %2d   |\n", player->gauntlets);
    }

    if (player->isShoulderPadsBlue) {
        printf("| \033[1;33mShoulder Pads\033[0m     |   \033[1;36m%2d\033[0m   |\n", player->shoulderPads);
    }
    else {
        printf("| \033[1;33mShoulder Pads\033[0m     |   %2d   |\n", player->shoulderPads);
    }

    if (player->isBeltBlue) {
        printf("| \033[1;33mBelt\033[0m              |   \033[1;36m%2d\033[0m   |\n", player->belt);
    }
    else {
        printf("| \033[1;33mBelt\033[0m              |   %2d   |\n", player->belt);
    }

    if (player->isBracersBlue) {
        printf("| \033[1;33mBracers\033[0m           |   \033[1;36m%2d\033[0m   |\n", player->bracers);
    }
    else {
        printf("| \033[1;33mBracers\033[0m           |   %2d   |\n", player->bracers);
    }

    if (player->isCapeBlue) {
        printf("| \033[1;33mCape\033[0m              |   \033[1;36m%2d\033[0m   |\n", player->cape);
    }
    else {
        printf("| \033[1;33mCape\033[0m              |   %2d   |\n", player->cape);
    }

    if (player->isShieldBlue) {
        printf("| \033[1;33mShield\033[0m            |   \033[1;36m%2d\033[0m   |\n", player->shield);
    }
    else {
        printf("| \033[1;33mShield\033[0m            |   %2d   |\n", player->shield);
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
                    player->helmet++;
                    player->isHelmetBlue = 1;
                    points--;
                    break;
                case 2:
                    player->chestplate++;
                    player->isChestplateBlue = 1;
                    points--;
                    break;
                case 3:
                    player->leggings++;
                    player->isLeggingsBlue = 1;
                    points--;
                    break;
                case 4:
                    player->boots++;
                    player->isBootsBlue = 1;
                    points--;
                    break;
                case 5:
                    player->gauntlets++;
                    player->isGauntletsBlue = 1;
                    points--;
                    break;
                case 6:
                    player->shoulderPads++;
                    player->isShoulderPadsBlue = 1;
                    points--;
                    break;
                case 7:
                    player->belt++;
                    player->isBeltBlue = 1;
                    points--;
                    break;
                case 8:
                    player->bracers++;
                    player->isBracersBlue = 1;
                    points--;
                    break;
                case 9:
                    player->cape++;
                    player->isCapeBlue = 1;
                    points--;
                    break;
                case 10:
                    player->shield++;
                    player->isShieldBlue = 1;
                    points--;
                    break;
                }
            }
            else if (operation == '-') {
                switch (choice) {
                case 1:
                    if (player->helmet > 0) {
                        player->helmet--;
                        points++;
                    }
                    else {
                        printf("\033[31mHelmet cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 2:
                    if (player->chestplate > 0) {
                        player->chestplate--;
                        points++;
                    }
                    else {
                        printf("\033[31mChestplate cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 3:
                    if (player->leggings > 0) {
                        player->leggings--;
                        points++;
                    }
                    else {
                        printf("\033[31mLeggings cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 4:
                    if (player->boots > 0) {
                        player->boots--;
                        points++;
                    }
                    else {
                        printf("\033[31mBoots cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 5:
                    if (player->gauntlets > 0) {
                        player->gauntlets--;
                        points++;
                    }
                    else {
                        printf("\033[31mGauntlets cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 6:
                    if (player->shoulderPads > 0) {
                        player->shoulderPads--;
                        points++;
                    }
                    else {
                        printf("\033[31mShoulder Pads cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 7:
                    if (player->belt > 0) {
                        player->belt--;
                        points++;
                    }
                    else {
                        printf("\033[31mBelt cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 8:
                    if (player->bracers > 0) {
                        player->bracers--;
                        points++;
                    }
                    else {
                        printf("\033[31mBracers cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 9:
                    if (player->cape > 0) {
                        player->cape--;
                        points++;
                    }
                    else {
                        printf("\033[31mCape cannot be less than 0.\n\033[0m");
                    }
                    break;
                case 10:
                    if (player->shield > 0) {
                        player->shield--;
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

void startTrainingGear() {
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
    initializeGear(player); // Initialize player attributes

    trainArmor(player);

    free(player);
}