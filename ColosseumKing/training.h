#pragma once
#include "character.h"
#define MAXSIZE 10

typedef struct statsWithColor {
    char userName[MAXSIZE];
    int strength;
    int speed;
    int coordination;
    int health;
    int swordSkills;
    int isStrengthBlue;
    int isSpeedBlue;
    int isCoordinationBlue;
    int isHealthBlue;
    int isSwordSkillsBlue;
    int helmet;
    int chestplate;
    int leggings;
    int boots;
    int gauntlets;
    int shoulderPads;
    int belt;
    int bracers;
    int cape;
    int shield;
    int isHelmetBlue;
    int isChestplateBlue;
    int isLeggingsBlue;
    int isBootsBlue;
    int isGauntletsBlue;
    int isShoulderPadsBlue;
    int isBeltBlue;
    int isBracersBlue;
    int isCapeBlue;
    int isShieldBlue;
    int coins;
} STATSWITHCOLOR;

void startTraining();
void displayStats(STATSWITHCOLOR* character);
void trainStats(STATSWITHCOLOR* character);