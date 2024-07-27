#pragma once
#include<stdbool.h>
#include "character.h"

struct login {
	struct Player;
	char password;
};

bool saveCharacter(struct Player Player);

struct Player* loadCharcterFromFile(struct Player* player);

bool SaveTraining(struct Player player);

bool LoadTraining(struct Player* player);

bool saveLogin(struct login* info);

// Function to validate username and password
bool Login(char* username, char* password);

bool loadLogin(struct login* info);

