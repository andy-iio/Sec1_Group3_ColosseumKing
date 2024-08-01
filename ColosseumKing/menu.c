// Ceren
#define _CRT_SECURE_NO_WARNINGS
#include "buffer.h"
#include "menu.h"
#include "training.h"  
#include "gear.h" 
#include "save_load_login.h"
#include "asterisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attack_module.h"
#define MAXSIZE 50

int topMainMenu(struct Player* Nplayer) {
    int choice = 0;
    char input[MAXSIZE];

    while (1) {
        do {
            printf("\033\n[1;31mMAIN MENU\n\033[0m");
            printf("1. New Game\n"); //call initailzePlayer(username)
            printf("2. Load Game\n"); // Load an existing game -> struct Player* player = loadCharacterFromFile();
            printf("3. Settings\n"); // Open the settings menu -> settingsMenu();
            printf("4. Exit Game\n"); // Call exitGameMenu() function;
            printf("\nEnter your choice: "); // Prompt the user to make a selection

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if (strlen(input) > 1 || sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 4) {
                printf("\033[31mInvalid choice. Please enter a valid option (1-4).\n\033[0m");
                asteriskShortLine();
            }
        } while (choice < 1 || choice > 4);

        switch (choice) {
        case 1:
            printf("\033[1;31mStarting New Game...\n\033[0m");
            asteriskShortLine();
            printf("\033[1;31mTRAINING\n\033[0m");
            char username[MAXSIZE];

            while (1) {
                printf("Create a Username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                if (strlen(username) > 0) {
                    break;
                }
                printf("\033[31mUsername cannot be empty. Please enter a valid usename.\n\n\033[0m");
                asteriskShortLine();
            }
            char password[MAXSIZE];
            while (1) {
                printf("Create a Password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';

                if (strlen(password) > 0) {
                    break;
                }
                printf("\033[31Password cannot be empty. Please enter a valid password.\n\n\033[0m");
                asteriskShortLine();
            }
            saveLogin(username, password);

            struct Player* player = initializePlayer(username, password);
            int result = startTraining(player); // Start the training module
            //SaveTraining(player); // save trainig stats (new game)
            if (result == 6) {
                // Return menu
                clearInputBuffer();
                continue; // Return to top menu
            }
            else if (result == 7) {
                //inGameLoop(player);
                tempAttack(player);
               // attackPhase(player->character);
                return 0;
            }
            clearInputBuffer();
            return 0;
        case 2:
            if (loadGameMenu() == 0) {
                return 0; // Exit topMainMenu after successful load
            }
            break;
        case 3:
            if (settingsMenu() == 'c') {
                clearInputBuffer();
                continue; // Return to top menu
            }
            break;
        case 4:
            exitGameMenu(Nplayer); // Exit the game
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}

int mainMenu(struct Player* currentPlayer) {
    int choice = 0;
    char input[MAXSIZE];
    int trainingResult;

    while (1) {
        do {
            printf("\033[1;31mMAIN MENU - (Player: %s)\033[0m\n", currentPlayer->userName);
            printf("1. New Game\n");
            printf("2. Load Game\n");
            printf("3. Buy Armor Set\n");
            printf("4. Training\n");
            printf("5. Settings\n");
            printf("6. Exit Game\n");
            printf("\nEnter your choice: ");

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if (strlen(input) > 1 || sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 6) {
                printf("\033[31mInvalid choice. Please enter a valid option (1-6).\n\033[0m");
                asteriskShortLine();
            }
        } while (choice < 1 || choice > 6);

        switch (choice) {
        case 1:
            printf("\033[1;31mStarting New Game...\n\033[0m");
            asteriskShortLine();
            printf("\033[1;31mTRAINING\n\033[0m");
            char username[MAXSIZE];

            while (1) {
                printf("Create a Username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\'\0';

                if (strlen(username) > 0) {
                    break;
                }
                printf("\033[31mUsername cannot be empty. Please enter a valid username.\n\033[0m");
                asteriskShortLine();
            }
            char password[MAXSIZE];
            while (1) {
                printf("Create a Password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\'\0';

                if (strlen(password) > 0) {
                    break;
                }
                printf("\033[31mPassword cannot be empty. Please enter a valid password.\n\033[0m");
                asteriskShortLine();
            }

            struct Player* newPlayer = initializePlayer(username, password);
            saveLogin(newPlayer->userName, newPlayer->Password); // saving login information 


            int result = startTraining(newPlayer);  // Start the training module
            if (result == 6) {
                // Return menu
                //printf("Returning to main menu...\n");
               // clearInputBuffer();
                continue; // Return to main menu
            }
            else if (result == 7) {
                // Battle section
                printf("\n\033[1;31mTraining session complete.\033[0m");


                printf("Entering battle mode...\n");
                tempAttack(newPlayer);
                //attackPhase(newPlayer->character);
                //inGameLoop(newPlayer); // Battle in game loop (ESC)

                return 0;
            }
            clearInputBuffer(currentPlayer);
            return 0;
        case 2:
            if (loadGameMenu() == 0) {
                loadCharcterFromFile(&newPlayer);
                LoadTraining(&newPlayer);
                return 0; // Exit mainMenu after successful load
            }
            break;
        case 3:
            buyGear(currentPlayer); // Allow player to buy gear
            clearInputBuffer();
            break;
        case 4:
            trainingResult = trainingMenu(currentPlayer); // Open the training menu
            if (trainingResult == 0) {
                // Return to menu
                //printf("Returning to main menu...\n");
                continue; // Return to main menu
            }
            else if (trainingResult == 7) {
                // Battle
                printf("\n\033[1;31mTraining session complete.\033[0m");
                printf("Entering battle mode...\n");
                tempAttack(currentPlayer);
                attackPhase(currentPlayer);
                //inGameLoop(currentPlayer); // Battle in game loop (ESC)
                return 0;
            }
            clearInputBuffer();
            break;
        case 5:
            if (settingsMenu() == 'c') {
                clearInputBuffer();
                continue; // Return to previous menu
            }
            break;
        case 6:
            exitGameMenu(currentPlayer); // Exit the game
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}


int loadGameMenu() {
    struct Player* player = initializePlayer("temp", "temp");
    loadCharcterFromFile(player);
    startTraining(player);
    //char filename[MAXSIZE];
    //char input[MAXSIZE];
    //int choice = 0;
    //int count = 0;

    //FILE* fp = fopen("character.txt", "r");
    //if (fp == NULL) {
    //    printf("No save files found.\n");
    //    return 1; // Return to main menu if no save files found
    //}

    //asteriskShortLine();
    //printf("\033[1;31mLOAD GAME\n\033[0m");

    //// Read the save files and display them as menu options
    //while (fgets(filename, sizeof(filename), fp)) {
    //    printf("%d. %s", ++count, filename); // Display save files
    //}
    //fclose(fp);

    //if (count == 0) {
    //    printf("No save files available.\n");
    //    return 1; // Return to main menu if no save files available
    //}

    //// Prompt the user to choose a file to load
    //printf("\nEnter the number of the save file to load: ");
    //fgets(input, sizeof(input), stdin);
    //if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > count) {
    //    printf("\033[31mInvalid choice. Please enter a valid save file number (1-%d).\n\033[0m", count);
    //    return 1; // Return to main menu if invalid choice
    //}

    //// Reopen the file to get the chosen save file
    //fp = fopen("save_files.txt", "r");
    //if (fp == NULL) {
    //    printf("Error reopening save files.\n");
    //    return 1; // Return to main menu if error reopening file
    //}

    //count = 0;
    //while (fgets(filename, sizeof(filename), fp)) {
    //    if (++count == choice) {
    //        printf("Loading save file: %s\n", filename); // Load the chosen save file
    //        break;
    //    }
    //}
    //fclose(fp);
    ////inGameLoop(player);
    //return 0;
}

int settingsMenu() {
    char subChoice;
    char input[MAXSIZE];

    while (1) {
        asteriskShortLine();
        printf("\n\033[1;31mSETTINGS\n\033[0m");
        printf("a) Sound\n");
        printf("b) How to Play\n");
        printf("c) Back to Menu\n"); // Return to previous menu
        printf("\nEnter your choice: "); // Prompt the user to make a selection

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) != 1 || (input[0] != 'a' && input[0] != 'b' && input[0] != 'c')) {
            printf("\033[31mInvalid choice. Please enter 'a', 'b', or 'c'.\n\033[0m");
            continue;
        }

        subChoice = input[0];
        switch (subChoice) {
        case 'a':
            printf("\nSound settings...\n");
            break;
        case 'b':
            printf("\nHow to Play...\n");
            break;
        case 'c':
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            asteriskShortLine();
            return 0;  // Return to previous menu
        }
    }
    return 0;
}

void exitGameMenu(struct Player* player) {
    char subChoice;
    char input[MAXSIZE];

    while (1) {
        printf("a. Save and Exit\n");
        printf("b. Exit Game\n"); // Exit the game without saving
        printf("c. Cancel\n"); // Return to the mainMenu();
        printf("\nEnter your choice: "); // Prompt the user to make a selection

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) != 1 || (input[0] != 'a' && input[0] != 'b' && input[0] != 'c')) {
            printf("\033[31mInvalid choice. Please enter 'a', 'b', or 'c'.\n\033[0m");
            asteriskShortLine();
            continue;
        }

        subChoice = input[0];
        switch (subChoice) {
        case 'a':
            printf("\033[1;31mSaving and exiting game...\n\033[0m");
            saveCharacter(player);
            SaveTraining(player);
            exit(0);
        case 'b':
            printf("\033[1;31mExiting game...\n\033[0m");
            exit(0);
        case 'c':
            printf("\n\033[1;34mReturning to menu...\n\033[0m");
            asteriskShortLine();
            return;
        }
    }
}

int inGameMenu(struct Player* player) {
    int choice;
    char choice1;

    while (1) {
        printf("\033[1;31mIN GAME MENU\n\033[0m");
        printf("1. Return to Game\n"); // Return to the game
        printf("2. Save Game\n");
        printf("3. Settings\n"); // Open the settings menu -> settingsMenu();
        printf("4. Return to Main Menu\n"); // Return to the main menu -> mainMenu();
        printf("5. Exit Game\n"); // Exit the game -> exitGameMenu();
        printf("\nEnter your choice: "); // Prompt the user to make a selection
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
        case 1:
            printf("Returning...\n");
            return 0;
        case 2:
            printf("\n\033[1;34mSaving game...\n\033[0m");
            asteriskShortLine();
            saveCharacter(player); // save character info 
            SaveTraining(player); // save training information 
            break;
        case 3:
            settingsMenu(); // Open the settings menu -> settingsMenu();
            break;
        case 4:
            printf("Are you sure? - (y/n): ");
            choice1 = getchar();
            clearInputBuffer();

            switch (choice1) {
            case 'y':
                printf("\n\033[1;34mExiting game and returning to main menu...\n\033[0m");
                asteriskShortLine();
                mainMenu(player); // Return to the main menu -> mainMenu();
                return 0;
            case 'n':
                asteriskShortLine();
                break;
            default:
                printf("\033[1;31mInvalid choice, please try again.\n\033[0m");
            }
            break;
        case 5:
            exitGameMenu(player); // Exit the game -> exitGameMenu();
            return 0;
        default:
            printf("\033[1;31mInvalid choice, please try again.\n\033[0m");
        }
    }
}
void inGameLoop(struct Player* player) {
    int ch;

    while (1) {
        printf("\033[1;36mGame running... Press ESC to open menu.\n\033[0m");
        ch = getch(); // Wait for a key press

        if (ch == 27) { // 27 is the ASCII value of the ESC key
            asteriskShortLine();
            inGameMenu(player); // Open the in-game menu -> inGameMenu();
        }
    }
}