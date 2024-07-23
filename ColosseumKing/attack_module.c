// By Grae Watson - 2024/07/10 - Colosseum King


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "attack_module.h"


CHARACTER playerToCharacter(struct Player p)
{
	CHARACTER c;

	c.avatar = p.avatar;
	c.level = p.level;
	c.health = p.health;
	c.constitution = p.constitution;
	c.strength = p.strength;
	c.speed = p.speed;
	c.coordination = p.coordination;
	c.armourLevel = p.armourLevel;
	c.armourSkill = p.armourSkill;
	c.swordLevel = p.swordLevel;
	c.swordSkill = p.swordSkill;
}


bool attackSuccess(CHARACTER attacker, CHARACTER deffender)
{
	if (attackHitAccuracy(attacker) > defenseChance(deffender))
		return true;
	else
		return false;

}

int attackHitAccuracy(CHARACTER attacker)
{
	return attacker.coordination + attacker.swordSkill + (rand() % (attacker.level - 0 + 1) - 0);
}

int attackPower(CHARACTER attacker)
{
	return  attacker.strength + attacker.swordLevel + (rand() % (attacker.level - 0 + 1) - 0);
}

int defenseChance(CHARACTER deffender)
{
	return deffender.speed + deffender.armourSkill + (rand() % (deffender.level - 0 + 1) - 0);
}

int defensePower(CHARACTER deffender)
{
	return deffender.constitution + deffender.armourLevel + (rand() % (deffender.level - 0 + 1) - 0);
}

FIGHTSTATUS round(CHARACTER *player, CHARACTER *enemy)
{
	if (player->speed > enemy->speed)
	{
		if (attackSuccess(*player, *enemy))
			enemy->tempHealth = enemy->tempHealth - attackPower(*player);

		if (0 >= enemy->tempHealth)
			return PWIN;

		if (attackSuccess(*enemy, *player))
			player->tempHealth = player->tempHealth - attackPower(*enemy);
	}
	else if (player->speed < enemy->speed)
	{
		if (attackSuccess(*enemy, *player))
			player->tempHealth = player->tempHealth - attackPower(*enemy);

		if (0 >= player->tempHealth)
			return EWIN;

		if (attackSuccess(*player, *enemy))
			enemy->tempHealth = enemy->tempHealth - attackPower(*player);
	} 
	else if (1 == ( rand() % (1 - 0 + 1) - 0 ) )
	{
		if (attackSuccess(*player, *enemy))
			enemy->tempHealth = enemy->tempHealth - attackPower(*player);

		if (0 >= enemy->tempHealth)
			return PWIN;

		if (attackSuccess(*enemy, *player))
			player->tempHealth = player->tempHealth - attackPower(*enemy);
	}
	else
	{
		if (attackSuccess(*enemy, *player))
			player->tempHealth = player->tempHealth - attackPower(*enemy);

		if (0 >= player->tempHealth)
			return EWIN;

		if (attackSuccess(*player, *enemy))
			enemy->tempHealth = enemy->tempHealth - attackPower(*player);
	}

	if (0 >= player->tempHealth)
		return EWIN;

	if (0 >= enemy->tempHealth)
		return PWIN;

	return NWIN;

}

bool attackPhase(CHARACTER player)
{
	CHARACTER enemy; 
	
	matchEnemyToCharacterStats(&enemy, &player);

	FIGHTSTATUS current = NWIN;

	while (NWIN == current)
	{
		current = round(&player, &enemy);
	}

	if (EWIN == current)
		return false;
	
	return true;
}

void printFight(CHARACTER player, CHARACTER enemy)
{

}

char** characterAvatar(int i)
{
	char avatars[6][30][40] = {(
		(".-----------------------------------."),
		("|.---------------------------------.|"),
		("||                 _.._            ||"),
		("||               .'  ..=`_         ||"),
		("||              / _ ='. )`,        ||"),
		("||             | .--:'./`\ \       ||"),
		("||            .'    .-'   | )      ||"),
		("||           / /:';' _   _( |      ||"),
		("||          /.' | | '' |''| |      ||"),
		("||         (  .|  |   __  ' /      ||"),
		("||         |  |/ / \  `- /( |      ||"),
		("||         )_.:./)   `--'._\       ||"),
		("||        .'    `,    +  :\)       ||"),
		("||       /       :`;_    : |       ||"),
		("||      |        :'::`-..',|       ||"),
		("||     .'   .-   \::\::::::`,      ||"),
		("||     |    /`,   |::`:::::::\     ||"),
		("||    /    /   \  |,:::::\::/      ||"),
		("||   /    /     \  |::::::::|      ||"),
		("||  |   -----.o......_:::::.'      ||"),
		("||  .         B    `-':::.':|      ||"),
		("||  `-.-----==B-,   `.::::::|      ||"),
		("||            /:`, `.\\:::::|      ||"),
		("||            /:::\\\\::::::|      ||"),
		("||      MJP  '::::::::::'          ||"),
		("||          (::::'                 ||"),
		("||                                 ||"),
		("|`---------------------------------'|"),
		("`-----------------------------------'"))};
}
