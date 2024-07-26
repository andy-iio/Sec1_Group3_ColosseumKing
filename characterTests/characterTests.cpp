#include "pch.h"
#include "C:\Users\andyg\source\repos\Sec1_Group3_ColosseumKing\ColosseumKing\character.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" struct Player Player;
extern "C" struct Player* initializePlayer(char*);

namespace characterTests
{
	TEST_CLASS(characterTests)
	{
	public:
		//testing the initalize player function 
		TEST_METHOD(initalize_player)
		{
			//username
			char* expectedUsername = "testUsername";
			//default values for stats
			int expectedDefaultValue = 1;
			//call initalize player function
			struct Player* p = initializePlayer(expectedUsername);

			//check values
			Assert::AreEqual(0, strcmp(expectedUsername, p->userName));
			Assert::AreEqual(expectedDefaultValue, p->character.health);
			Assert::AreEqual(expectedDefaultValue, p->character.attackDamage);
			Assert::AreEqual(expectedDefaultValue, p->character.strength);
			Assert::AreEqual(expectedDefaultValue, p->character.speed);
			Assert::AreEqual(expectedDefaultValue, p->character.coordination);
			Assert::AreEqual(expectedDefaultValue, p->character.armourLevel);
			Assert::AreEqual(expectedDefaultValue, p->character.armourSkill);
			Assert::AreEqual(expectedDefaultValue, p->character.swordLevel);
			Assert::AreEqual(expectedDefaultValue, p->character.swordSkill);
		}

		//testing the initalize enemy function 
		TEST_METHOD(initialize_enemy)
		{
			
			//default values for stats
			int expectedDefaultValue = 1;
			//call initalize enemy function
			struct Enemy* e = initializeEnemy(LION);

			//check values
			Assert::AreEqual(static_cast<int>(LION), static_cast<int>(e->type));
			Assert::AreEqual(expectedDefaultValue,e->character.health);
			Assert::AreEqual(expectedDefaultValue,e->character.attackDamage);
			Assert::AreEqual(expectedDefaultValue,e->character.strength);
			Assert::AreEqual(expectedDefaultValue,e->character.speed);
			Assert::AreEqual(expectedDefaultValue,e->character.coordination);
			Assert::AreEqual(expectedDefaultValue,e->character.armourLevel);
			Assert::AreEqual(expectedDefaultValue,e->character.armourSkill);
			Assert::AreEqual(expectedDefaultValue,e->character.swordLevel);
			Assert::AreEqual(expectedDefaultValue,e->character.swordSkill);
		}

		//testing the load player function 
		TEST_METHOD(load_player)
		{
			//expected stats
			char* expectedUsername = "testUsername";
			int expectedHealth = 5;
			int expectedAttackDamage = 7;
			int expectedStrength = 6;
			int expectedSpeed = 12;
			int expectedCoordination = 9;
			int expectedArmourLevel = 2;
			int expectedArmourSkill = 13;
			int expectedSwordLevel = 11;
			int expectedSwordSkill = 80;
			int expectedAvatar = 3;

			struct Player* p = loadPlayer(expectedUsername, expectedHealth, expectedAttackDamage, expectedStrength, expectedSpeed, expectedCoordination, expectedArmourLevel, expectedArmourSkill, expectedSwordLevel, expectedSwordSkill, expectedAvatar);

			//check values
			Assert::AreEqual(0, strcmp(expectedUsername, p->userName));
			Assert::AreEqual(expectedHealth, p->character.health);
			Assert::AreEqual(expectedAttackDamage, p->character.attackDamage);
			Assert::AreEqual(expectedStrength, p->character.strength);
			Assert::AreEqual(expectedSpeed, p->character.speed);
			Assert::AreEqual(expectedCoordination, p->character.coordination);
			Assert::AreEqual(expectedArmourLevel, p->character.armourLevel);
			Assert::AreEqual(expectedArmourSkill, p->character.armourSkill);
			Assert::AreEqual(expectedSwordLevel, p->character.swordLevel);
			Assert::AreEqual(expectedSwordSkill, p->character.swordSkill);
		}

		//testing the load enemy function 
		TEST_METHOD(load_enemy)
		{
			//expected stats
			int expectedHealth = 5;
			int expectedAttackDamage = 7;
			int expectedStrength = 6;
			int expectedSpeed = 12;
			int expectedCoordination = 9;
			int expectedArmourLevel = 2;
			int expectedArmourSkill = 13;
			int expectedSwordLevel = 11;
			int expectedSwordSkill = 80;
			int expectedAvatar = 3;

			struct Enemy* e = loadEnemy(LION, expectedHealth, expectedAttackDamage, expectedStrength, expectedSpeed, expectedCoordination, expectedArmourLevel, expectedArmourSkill, expectedSwordLevel, expectedSwordSkill, expectedAvatar);

			//check values
			Assert::AreEqual(static_cast<int>(LION), static_cast<int>(e->type));
			Assert::AreEqual(expectedHealth,e->character.health);
			Assert::AreEqual(expectedAttackDamage,e->character.attackDamage);
			Assert::AreEqual(expectedStrength,e->character.strength);
			Assert::AreEqual(expectedSpeed,e->character.speed);
			Assert::AreEqual(expectedCoordination,e->character.coordination);
			Assert::AreEqual(expectedArmourLevel,e->character.armourLevel);
			Assert::AreEqual(expectedArmourSkill,e->character.armourSkill);
			Assert::AreEqual(expectedSwordLevel,e->character.swordLevel);
			Assert::AreEqual(expectedSwordSkill,e->character.swordSkill);
		}


		//random health increase test
		TEST_METHOD(random_health_increase)
		{
			struct Player* p = initializePlayer("user");
			int startHealthVal = p->character.health;

			randomHealthIncrease(&p->character);
			int endHealthVal = p->character.health;

			Assert::AreNotEqual(startHealthVal, endHealthVal);
			Assert::IsTrue(endHealthVal > startHealthVal);
			Assert::IsTrue(endHealthVal < startHealthVal + 6);

		}

		//load gear test
		TEST_METHOD(load_gear)
		{
			struct Player* p = initializePlayer("user");
			int startHealthVal = p->character.health;

			loadGear(p, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
			
			Assert::AreEqual(1, p->stats.helmet);
			Assert::AreEqual(2, p->stats.chestplate);
			Assert::AreEqual(3, p->stats.leggings);
			Assert::AreEqual(4, p->stats.boots);
			Assert::AreEqual(5, p->stats.gauntlets);
			Assert::AreEqual(6, p->stats.shoulderPads);
			Assert::AreEqual(7, p->stats.belt);
			Assert::AreEqual(8, p->stats.bracers);
			Assert::AreEqual(9, p->stats.cape);
			Assert::AreEqual(10, p->stats.shield);
			Assert::AreEqual(11, p->stats.coins);
		}

		//void matchEnemyToCharacterStats(struct Enemy* enemy, struct Player* player) {
		//testing the matchcharactertoenemy function
		TEST_METHOD(match_enemy_to_character)
		{
			struct Player* p = initializePlayer("test");
			// an initialized player has a total of 9 skill points
			int playerSkillPoints = 9;
			struct Enemy* e = initializeEnemy(LION);

			int enemySkillPoints = (e->character.health + e->character.attackDamage + e->character.strength + e->character.speed + e->character.coordination + e->character.armourLevel + e->character.armourSkill + e->character.swordLevel + e->character.swordSkill);
			matchEnemyToCharacterStats(e, p);

			//check values
			Assert::AreEqual(playerSkillPoints, enemySkillPoints);
		}
	};
}
