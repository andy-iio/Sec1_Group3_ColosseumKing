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
#define MAXSIZE 50

int topMainMenu() {
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
            //ask player for username 
            struct Player* player = initializePlayer("username here");
            startTraining();  // Start the training module
            clearInputBuffer();
            return 0;
        case 2:
            if (loadGameMenu() == 0) {
                //struct Player* player = loadCharacterFromFile();
                return 0; // Exit mainMenu after successful load
            }
            break;
        case 3:
            if (settingsMenu() == 'c') {
                clearInputBuffer();
                continue; // Return to main menu
            }
            break;
        case 4:
            exitGameMenu(); // Exit the game
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}

int mainMenu() {
    int choice = 0;
    char input[MAXSIZE];
    //delete this below
   // struct Player gear;
   // initializeGear(&gear); // Initialize gear attributes

    while (1) {
        do {
            printf("\033\n[1;31mMAIN MENU\n\033[0m");
            printf("1. New Game\n"); //call initailzePlayer(username)
            printf("2. Load Game\n"); // Load an existing game -> struct Player* player = loadCharacterFromFile();
            printf("3. Buy Armor Set\n"); // Buy armor for the player -> buyGear(&player);
            printf("4. Training\n"); // Start the training module -> startTraining();
            printf("5. Settings\n"); // Open the settings menu -> settingsMenu();
            printf("6. Exit Game\n"); // exitGameMenu();
            printf("\nEnter your choice: "); // Prompt the user to make a selection

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
            //ask player for username 
            struct Player* player = initializePlayer("username here");
            startTraining();  // Start the training module
            clearInputBuffer();
            return 0;
        case 2:
            if (loadGameMenu() == 0) {
                //struct Player* player = loadCharacterFromFile();
                return 0; // Exit mainMenu after successful load
            }
            break;
        case 3:
            buyGear(&player); // Allow player to buy gear
            clearInputBuffer();
            break;
        case 4:
            trainingMenu(); // Open the training menu
            clearInputBuffer();
            break;
        case 5:
            if (settingsMenu() == 'c') {
                clearInputBuffer();
                continue; // Return to previous menu
            }
            break;
        case 6:
            exitGameMenu(); // Exit the game
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}

int loadGameMenu() {
    char filename[MAXSIZE];
    char input[MAXSIZE];
    int choice = 0;
    int count = 0;

    FILE* fp = fopen("save_files.txt", "r");
    if (fp == NULL) {
        printf("No save files found.\n");
        return 1; // Return to main menu if no save files found
    }

    asteriskShortLine();
    printf("\033[1;31mLOAD GAME\n\033[0m");

    // Read the save files and display them as menu options
    while (fgets(filename, sizeof(filename), fp)) {
        printf("%d. %s", ++count, filename); // Display save files
    }
    fclose(fp);

    if (count == 0) {
        printf("No save files available.\n");
        return 1; // Return to main menu if no save files available
    }

    // Prompt the user to choose a file to load
    printf("\nEnter the number of the save file to load: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > count) {
        printf("\033[31mInvalid choice. Please enter a valid save file number (1-%d).\n\033[0m", count);
        return 1; // Return to main menu if invalid choice
    }

    // Reopen the file to get the chosen save file
    fp = fopen("save_files.txt", "r");
    if (fp == NULL) {
        printf("Error reopening save files.\n");
        return 1; // Return to main menu if error reopening file
    }

    count = 0;
    while (fgets(filename, sizeof(filename), fp)) {
        if (++count == choice) {
            printf("Loading save file: %s\n", filename); // Load the chosen save file
            break;
        }
    }
    fclose(fp);
    inGameLoop();
    return 0;
}

char settingsMenu() {
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
            return;  // Return to previous menu
        }
    }
}

void exitGameMenu() {
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

int inGameMenu() {
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
            // Save file function here
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
                mainMenu(); // Return to the main menu -> mainMenu();
                return 0;
            case 'n':
                asteriskShortLine();
                break;
            default:
                printf("\033[1;31mInvalid choice, please try again.\n\033[0m");
            }
            break;
        case 5:
            exitGameMenu(); // Exit the game -> exitGameMenu();
            return 0;
        default:
            printf("\033[1;31mInvalid choice, please try again.\n\033[0m");
        }
    }
}
void inGameLoop() {
    int ch;

    while (1) {
        printf("\033[1;36mGame running... Press ESC to open menu.\n\033[0m");
        ch = getch(); // Wait for a key press

        if (ch == 27) { // 27 is the ASCII value of the ESC key
            asteriskShortLine();
            inGameMenu(); // Open the in-game menu -> inGameMenu();
        }
    }
}