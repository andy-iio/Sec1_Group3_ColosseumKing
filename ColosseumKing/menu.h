#pragma once

void clearInputBuffer();
int topMainMenu();
int mainMenu(struct Player* player);
int loadGameMenu();
void trainingMenu(struct Player* player);
char settingsMenu();
void exitGameMenu();
int inGameMenu(struct Player* player);
void inGameLoop(struct Player* player);