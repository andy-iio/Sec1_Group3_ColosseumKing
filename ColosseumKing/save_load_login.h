#pragma once
#include<stdbool.h>
#include "character.h"

bool saveCharacter(struct Player* Player);

struct Player* loadCharcterFromFile(struct Player* player);

bool SaveTraining(struct Player* player);

bool LoadTraining(struct Player* player);

bool saveLogin(char* username, char* password);

// Function to validate username and password
bool Login(char* username, char* password);

bool loadLogin(char* username, char* password);

