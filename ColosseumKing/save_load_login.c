#include<stdio.h>
#include<stdbool.h>
#include"save_load_login.h"
#include"character.h"
#define MAX 100

// saving charcter 
bool saveCharacter(struct Player player) {
    FILE* file_Character = fopen("character_data.txt", "w");
    if (file_Character == NULL) {
        printf("Error opening file for writing\n");
        return false;
    };

    fprintf(file_Character, "PLAYER DATA:\n");
    fprintf(file_Character, "Username: %s\n",player.userName);
    fprintf(file_Character, "Attack: %d\n", player.character.attackDamage);
    fprintf(file_Character, "Coordination: %d\n", player.character.coordination);
    fprintf(file_Character, "Armour: %d\n", player.character.armourLevel);
    fprintf(file_Character, "Health: %d\n", player.character.health);
    fprintf(file_Character, "Level: %d\n", player.level);
    fprintf(file_Character, "Speed: %d\n", player.character.speed);
    fprintf(file_Character, "Strength: %d\n", player.character.strength);
    fprintf(file_Character, "Avatar: %d\n", player.character.avatar);
    
    fclose(file_Character);
    printf("Character saved to file\n");
    return true;
    
}

// loading charcter 
struct Player* loadCharcterFromFile(struct Player* player) {
    FILE* file_Character = fopen("character_data.txt", "r");
    if (file_Character == NULL) {
        printf("No existing file found\n");
        return false;
    }

    char buffer[MAX];
    struct Character* NewPlayer = malloc(sizeof(struct Character));
    
    while (fgets(buffer, sizeof(buffer), file_Character) != NULL) {
        if (strcmp(buffer, "PLAYER DATA:\n") == 0) {
            if (NewPlayer == NULL) {
                fprintf(stderr, "Memory Allocation failed\n");
                fclose(file_Character);
                return false;
            }

            if (fgets(player->userName, 50, file_Character) == NULL ||
                (fscanf(NewPlayer->health, file_Character) == NULL ||
                    fscanf(NewPlayer->attackDamage, file_Character) == NULL ||
                    fscanf(NewPlayer->strength, file_Character) == NULL ||
                    fscanf(NewPlayer->speed, file_Character) == NULL ||
                    fscanf(NewPlayer->coordination, file_Character) == NULL ||
                    fscanf(NewPlayer->armourLevel, file_Character) == NULL ||
                    fscanf(NewPlayer->armourSkill, file_Character) == NULL ||
                    fscanf(NewPlayer->swordLevel, file_Character) == NULL ||
                    fscanf(NewPlayer->swordSkill, file_Character) == NULL ||
                    fscanf(NewPlayer->avatar, file_Character) == NULL)) {

                printf("Error reading player data");
                free(NewPlayer);
                return false;

            };

            NewPlayer = loadPlayer(player,NewPlayer->health, NewPlayer->attackDamage, NewPlayer->strength, NewPlayer->speed, 
                NewPlayer->coordination, NewPlayer->armourLevel, NewPlayer->armourSkill, NewPlayer->swordLevel, NewPlayer->swordSkill, NewPlayer->avatar);
            
             printf("Player loaded from file\n");
            }
            fclose(file_Character);

        }
    }
        
// save training << need file still  
bool SaveTraining(struct Player player) {
    FILE* file_Gear = fopen("training_data.txt", "w");
    if (file_Gear == NULL) {
        printf("No existing file found\n");
        return false;
    }

    fprintf(file_Gear, "GEAR DATA:\n");
    fprintf(file_Gear, "Usrename: %s\n", player.userName);
    fprintf(file_Gear, "Helment: %d\n", player.stats.helmet);
    fprintf(file_Gear, "Chesplate: %d\n", player.stats.chestplate);
    fprintf(file_Gear, "Leggings: %d\n", player.stats.leggings);
    fprintf(file_Gear, "Boots: %d\n", player.stats.boots);
    fprintf(file_Gear, "Gauntlets: %d\n", player.stats.gauntlets);
    fprintf(file_Gear, "ShoulderPads: %d\n", player.stats.shoulderPads);
    fprintf(file_Gear, "Belt: %d\n", player.stats.belt);
    fprintf(file_Gear, "Bracers: %d\n", player.stats.bracers);
    fprintf(file_Gear, "Cape: %d\n", player.stats.cape);
    fprintf(file_Gear, "Shield: %d\n", player.stats.shield);
    fprintf(file_Gear, "Coins: %d\n", player.stats.coins);

    fclose(file_Gear);
    printf("Data saved from file \n");
    return true;
}

// load training
bool LoadTraining(struct Player* player) {
    FILE* file_Gear = fopen("training_data.txt", "w");
    if (file_Gear == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }
    
    char buffer[MAX];
    while (fgets(buffer, sizeof(buffer), file_Gear) != NULL) {
        if (strcmp(buffer, "GEAR DATA:\n") == 0) {
            if (player == NULL) {
                fprintf(stderr, "Memory Allocation failed\n");
                fclose(file_Gear);
                return false;
            }

            char buffer[MAX];
            struct Player* NewPlayer = malloc(sizeof(struct Character));
            
            if (fgets(player->userName, 50, file_Gear) == NULL ||
                (fscanf(NewPlayer->stats.helmet,file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.chestplate, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.leggings, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.boots, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.gauntlets, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.shoulderPads, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.belt, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.bracers, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.cape, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.shield, file_Gear) == NULL ||
                    fscanf(NewPlayer->stats.coins, file_Gear) == NULL)) {

                printf("Error reading player data");
                free(NewPlayer);
                return false;

            };
            
                NewPlayer = loadGear(player, player->stats.helmet, player->stats.chestplate, player->stats.leggings, player->stats.boots,
                    player->stats.gauntlets, player->stats.shoulderPads, player->stats.belt, player->stats.bracers, player->stats.cape, player->stats.shield, player->stats.coins
                );
                printf("Training loaded from file\n");
            }
            fclose(file_Gear);
    }
    fclose(file_Gear);
    printf("Data loaded from file\n");
    return true;
}



// save login information
bool saveLogin(struct login* info) {
    FILE* file = fopen("login_info.txt", "r");
    if (file == NULL) {
        printf("No existing file found\n");
        return false;
    }
    fprintf(file, "LOGIN INFORMATION:\n");
    fprintf(file, "Username: %s\n",info->userName);
    fprintf(file, "Password: %s %d\n",info->password);
    
    fclose(file);
    printf("Data loaded from file \n");
    return true;
}

// load login information 
bool loadLogin(struct login* info) {
    FILE* file = fopen("login_info.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }
    fscanf(info->userName, file);
    fscanf(info->password, file);

    fclose(file);
    printf("Data saved to file\n");
    return true;
}


// Function to validate username and password
bool Login(char* username, char* password) {

    char key1 = username;
    char key2 = password;

    loadLogin(username);

    if (strcmp(username, key1) == 0 && strcmp(password, key2) == 0) {
        return true;// Login successful
    }
    else {
        return false;//Invalid username or password
    }
}