#pragma once

void clearInputBuffer();
int topMainMenu(struct Player* Nplayer);
int mainMenu(struct Player* player);
int loadGameMenu();
int trainingMenu(struct Player* player);
int settingsMenu();
void exitGameMenu(struct Player* player);
int inGameMenu(struct Player* player);
void inGameLoop(struct Player* player);