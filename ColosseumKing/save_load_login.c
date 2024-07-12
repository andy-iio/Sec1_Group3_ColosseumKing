#include<stdio.h>
#include<stdbool.h>
#include "save_load_login.h"

bool saveDisk() {
    //FILE* file = fopen("somefile.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return false;
    }

    fprintf(file, "test");

    fclose(file);
    printf("Data saved to file\n");
    return true;
}

bool loadDisk() {
    //FILE* file = fopen("somefile.txt", "r");
    if (file == NULL) {
        printf("No existing file found\n");
        return false;
    }
    fclose(file);
    printf("Data loaded from file \n");
    return true;
}

// Function to validate username and password
int Login(char* username, char* password) {

    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
        return 1;  // Login successful
    }
    else {
        return 0;  // Invalid username or password
    }
}