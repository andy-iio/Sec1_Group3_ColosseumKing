#pragma once

void clearInputBuffer();
int topMainMenu();
int mainMenu(struct Player* player);
int loadGameMenu();
int trainingMenu(struct Player* player);
int settingsMenu();
void exitGameMenu();
int inGameMenu(struct Player* player);
void inGameLoop(struct Player* player);