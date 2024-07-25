#include<stdio.h>
#include<stdbool.h>
#include"save_load_login.h"
#include"character.h"
#define MAX 100

// saving charcter 
bool saveCharacter(struct Player* player, char username) {
    FILE* file = fopen("character_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    };

    initializePlayer(player, username);

    fclose(file);
    printf("Character saved to file\n");
    return true;
    
}

// loading charcter 
bool loadCharcterFromFile(struct Character* player, char username) {
    FILE* file = fopen("character_data.txt", "r");
    if (file == NULL) {
        printf("No existing file found\n");
        return false;
    }

    char buffer[MAX];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strcmp(buffer, "PLAYER DATA:\n") == 0) {
            struct Player* NewPlayer = loadPlayer(player, username, player->health, player->attackDamage, player->strength, player->speed, player->coordination, player->armourLevel, player->armourSkill, player->swordLevel, player->swordSkill, player->avatar);
            if (NewPlayer == NULL) {
                fprintf(stderr, "Memory Allocation failed\n");
                fclose(file);
                return false;
            }
            else {
                printf("Player loaded from file\n");
            }
            fclose(file);
        }
    }
        
}


//saving training << need file still 
bool savetraining(struct Player * player) {
    FILE* file = fopen("training_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }
    
    char buffer[MAX];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strcmp(buffer, "GEAR DATA:\n") == 0) {
            struct Player* NewPlayer = loadGear(player, player->stats.helmet, player->stats.chestplate, player->stats.leggings, player->stats.boots,
                player->stats.gauntlets, player->stats.shoulderPads, player->stats.belt, player->stats.bracers, player->stats.cape, player->stats.shield, player->stats.coins
            );

            if (NewPlayer == NULL) {
                fprintf(stderr, "Memory Allocation failed\n");
                fclose(file);
                return false;
            }
            else {
                printf("Player loaded from file\n");
            }
            fclose(file);
        }
    }



    fclose(file);
    printf("Data saved to file\n");
    return true;
}

// loading training << need file still  
bool loadtraining() {
    FILE* file = fopen("login_info.txt", "r");
    if (file == NULL) {
        printf("No existing file found\n");
        return false;
    }
    fclose(file);
    printf("Data loaded from file \n");
    return true;
}


// loading login info 
bool saveLogin(struct login* info) {
    FILE* file = fopen("login_info.txt", "r");
    if (file == NULL) {
        printf("No existing file found\n");
        return false;
    }
    fprintf(file, "LOGIN INFORMATION:\n");
    fprintf(file, "Username: %s\n",info->userName);
    //fprintf(file, "Password: %s %d\n",info->password);
    fclose(file);
    printf("Data loaded from file \n");
    return true;
}

// save login 
bool loadLogin(struct Player* player) {
    FILE* file = fopen("login_info.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }

    fprintf(file, "test character");

    fclose(file);
    printf("Data saved to file\n");
    return true;
}


// Function to validate username and password
bool Login(char* username, char* password) {

    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
        return true;// Login successful
    }
    else {
        return false;//Invalid username or password
    }
}