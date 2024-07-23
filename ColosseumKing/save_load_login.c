#include<stdio.h>
#include<stdbool.h>
#include"save_load_login.h"
#include"character.h"
#define MAX 100

// saving charcter 
bool saveCharacter(struct Player Player) {
    FILE* file = fopen("character_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    };

    fprintf(file,"PLAYER DATA:\n");
    fprintf(file,"Username: %s\n", Player.userName);
    fprintf(file,"Constitution: %d\n",Player.constitution);
    fprintf(file,"Coordination : %d\n", Player.coordination);
    fprintf(file,"Gear : %d\n", Player.armourLevel);
    fprintf(file,"Health : %d\n", Player.health);
    fprintf(file,"Level : %d\n", Player.level);
    fprintf(file,"Speed : %d\n", Player.speed);
    fprintf(file,"Strength : %d\n", Player.strength);
    fprintf(file,"Avatar :\n");
    
    fclose(file);
    printf("Character saved to file\n");
    return true;
}

// loading charcter 
bool loadCharcterFromFile(struct Player* player) {
    FILE* file = fopen("character_data.txt", "r");
    if (file == NULL) {
        printf("No existing file found\n");
        return false;
    }

    char buffer[MAX];
 
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strcmp(buffer, "PLAYER DATA:\n") == 0) {
            struct Player* NewPlayer = malloc(sizeof(NewPlayer));

            if (NewPlayer == NULL) {
                fprintf(stderr, "Memory Allocation failed\n");
                fclose(file);
                return false;
            }
            fscanf(buffer, "Username: %[^\n]", player->userName);
            fscanf(buffer, "Constitution : %d", player->constitution);
            fscanf(buffer, "Coordanation : %d", player->coordination);
            fscanf(buffer, "Gear : %d", player->armourLevel);
            fscanf(buffer, "Health : %d", player->health);
            fscanf(buffer, "Level : %d", player->level);
            fscanf(buffer, "Speed : %d", player->speed);
            fscanf(buffer, "Strength : %d", player->strength);
            fscanf(buffer, "Strength : %d", player->strength);
        }
        fclose(file);
        printf("Player loaded from file");
    }
}

//saving training << need file still 
bool savetraining() {
    FILE* file = fopen("training_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }

    fprintf(file, "test character");

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
    fprintf(file, "Password: %s %d\n",info->password);
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