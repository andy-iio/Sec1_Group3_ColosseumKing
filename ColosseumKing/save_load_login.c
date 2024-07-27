#include<stdio.h>
#include<stdbool.h>
#include"save_load_login.h"
#include"character.h"
#define MAX 100

// saving charcter 
bool saveCharacter(struct Player* player) {
    FILE* file_Character = fopen("character.txt", "w");
    if (file_Character == NULL) {
        printf("Error opening file for writing\n");
        return false;
    };

    
        fprintf(file_Character, "%s,%d,%d,%d,%d,%d,%d,%d,%d\n",
            player->userName,
            player->character.attackDamage,
            player->character.coordination,
            player->character.armourLevel,
            player->character.health,
            player->level,
            player->character.speed,
            player->character.strength,
            player->character.avatar);

        fclose(file_Character);
        printf("Character saved to CSV file\n");
        return true;
    }


// loading charcter 
struct Player* loadCharcterFromFile(struct Player* player) {
    FILE* file_Character = fopen("character.txt", "r");
    if (file_Character == NULL) {
        printf("No existing file found\n");
        return false;
    }
    
    if (fscanf(file_Character,
        "%49[^,],%d,%d,%d,%d,%d,%d,%d,%d\n",
        player->userName,
        &player->character.attackDamage,
        &player->character.coordination,
        &player->character.armourLevel,
        &player->character.health,
        &player->level,
        &player->character.speed,
        &player->character.strength,
        &player->character.avatar) != 9) {
        printf("error\n");
        free(player);
        fclose(file_Character);
        return NULL;
    }
    printf("character read from fiile");
    fclose(file_Character);
    return player;
}
  

// Save Training  
bool SaveTraining(struct Player* player) {
    FILE* file_Gear = fopen("trainfile.txt", "w");
    if (file_Gear == NULL) {
        printf("No existing file found\n");
        return false;
    }


    fprintf(file_Gear, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        player->userName,
        player->stats.belt,
        player->stats.boots,
        player->stats.bracers,
        player->stats.cape,
        player->stats.coins,
        player->stats.gauntlets,
        player->stats.helmet,
        player->stats.leggings,
        player->stats.shield);

    fclose(file_Gear);
    printf("training saved to CSV file\n");
    return true;
}


// load training
bool LoadTraining(struct Player* player) {
    FILE* file_Gear = fopen("trainfile.txt", "r");
    if (file_Gear == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }

    if (fscanf(file_Gear,
        "%49[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        player->userName,
        &player->stats.belt,
        &player->stats.boots,
        &player->stats.bracers,
        &player->stats.cape,
        &player->stats.coins,
        &player->stats.gauntlets,
        &player->stats.helmet,
        &player->stats.leggings,
        &player->stats.shield) != 10) {
        printf("error (training)\n");
        free(player);
        fclose(file_Gear);
        return NULL;
    }
    printf("training read from fiile\n");
    fclose(file_Gear);
    return player;
}
    
// save login information
bool saveLogin(struct login* info) {
    FILE* file_login = fopen("login.txt", "w");
    if (file_login == NULL) {
        printf("No existing file found\n");
        return false;
    }
    fprintf(file_login,"%s,%s,\n",
        info->userName,
        info->password);
    
    fclose(file_login);
    printf("Info saved to file \n");
    return true;
}

// load login information 
bool loadLogin(struct login* info) {
    FILE* file_login = fopen("login.txt", "w");
    if (file_login == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }
    if (fscanf(file_login,
        "%s, %s\n",
        info->userName,
        info->password) != 2)
    
    fclose(file_login);
    printf("Info loaded from file\n");
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