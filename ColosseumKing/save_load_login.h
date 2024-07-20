#pragma once
#include<stdbool.h>
#include "character.h"

struct login {
	struct Player;
	char password;
};

bool saveCharacter(struct Player Player);

bool loadCharcterFromFile();

// Function to validate username and password
bool Login(char* username, char* password);

