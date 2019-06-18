#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Project2\TrekWars.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodShipStatus)
		{
			// Arrange
			string name = "Enterprise";
			int expectedXLoc = 4;
			int expectedYLoc = 2;
			string expectedType = "Ship";
			int expectedCurrentHealth = 42;
			Alignment expectedAlign = us;
			int attackPower = 0;
			int range = 0;
			int xMove = 0;
			int yMove = 0;

			string expectedStatus = "Name: " + name + "\n"
				+ "Type: " + expectedType + "\n"
				+ "Health: " + to_string(expectedCurrentHealth) + "\n"
				+ "Location: (" + to_string(expectedXLoc) + ", " + to_string(expectedYLoc) + ")" + "\n";

			// Act
			Ship enterprise(name, expectedXLoc, expectedYLoc, expectedAlign, expectedCurrentHealth, range, attackPower, xMove, yMove);
			string actualStatus = enterprise.status();

			// Assert
			Assert::AreEqual(expectedStatus, actualStatus);
			Assert::IsTrue(expectedAlign == us);
		}

		TEST_METHOD(TestMethodShipAssessDamage)
		{
			// Arrange
			string name = "Enterprise";
			int expectedXLoc = 4;
			int expectedYLoc = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment expectedAlign = us;
			int attackPower = 0;
			int range = 0;
			int xMove = 0;
			int yMove = 0;
			int damage = 5;
			Ship enterprise(name, expectedXLoc, expectedYLoc, expectedAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.assessDamage(damage);
			int actualHealth = enterprise.getCurrentHealth();

			// Assert
			Assert::AreEqual(maxHealth - damage, actualHealth);
		}


		TEST_METHOD(TestMethodShipChangeAlignThemToUs)
		{
			// Arrange
			string name = "Enterprise";
			int expectedXLoc = 4;
			int expectedYLoc = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment startingAlign = them;
			Alignment expectedAlign = us;
			int attackPower = 0;
			int range = 0;
			int xMove = 0;
			int yMove = 0;
			int damage = 5;
			Ship enterprise(name, expectedXLoc, expectedYLoc, startingAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.changeAlign();
			Alignment actualAlign = enterprise.getAlign();

			// Assert
			Assert::IsTrue(expectedAlign == actualAlign);
		}

		TEST_METHOD(TestMethodShipChangeAlignUsToThem)
		{
			// Arrange
			string name = "Enterprise";
			int expectedXLoc = 4;
			int expectedYLoc = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment startingAlign = us;
			Alignment expectedAlign = them;
			int attackPower = 0;
			int range = 0;
			int xMove = 0;
			int yMove = 0;
			int damage = 5;
			Ship enterprise(name, expectedXLoc, expectedYLoc, startingAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.changeAlign();
			Alignment actualAlign = enterprise.getAlign();

			// Assert
			Assert::IsTrue(expectedAlign == actualAlign);
		}

		TEST_METHOD(TestMethodShipChangeAlignChaoticDoesNotChange)
		{
			// Arrange
			string name = "Enterprise";
			int expectedXLoc = 4;
			int expectedYLoc = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment startingAlign = chaotic;
			Alignment expectedAlign = chaotic;
			int attackPower = 0;
			int range = 0;
			int xMove = 0;
			int yMove = 0;
			int damage = 5;
			Ship enterprise(name, expectedXLoc, expectedYLoc, startingAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.changeAlign();
			Alignment actualAlign = enterprise.getAlign();

			// Assert
			Assert::IsTrue(expectedAlign == actualAlign);
		}

		TEST_METHOD(TestMethodShipMoveHealthDoesntGoOverMax)
		{
			// Arrange
			string name = "Enterprise";
			int startingX = 4;
			int startingY = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment startingAlign = us;
			Alignment expectedAlign = them;
			int attackPower = 0;
			int range = 0;
			int xMove = -5;
			int yMove = 5;
			int damage = 5;
			Ship enterprise(name, startingX, startingY, startingAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.move();
			int actualX = enterprise.getX();
			int actualY = enterprise.getY();
			int actualHeatlh = enterprise.getCurrentHealth();

			// Assert
			Assert::AreEqual(startingX + xMove, actualX);
			Assert::AreEqual(startingY + yMove, actualY);
			Assert::AreEqual(maxHealth, actualHeatlh);
		}

		TEST_METHOD(TestMethodShipMoveAtZeroHealthThrowsException)
		{
			// Arrange
			string name = "Enterprise";
			int startingX = 4;
			int startingY = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment startingAlign = us;
			Alignment expectedAlign = them;
			int attackPower = 0;
			int range = 0;
			int xMove = -5;
			int yMove = 5;
			int damage = 5;
			Ship enterprise(name, startingX, startingY, startingAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.assessDamage(maxHealth);
			string errorMessage = "";
			try
			{
				enterprise.move();
				Assert::Fail();
			}
			catch (invalid_argument &e)
			{
				errorMessage = e.what();
			}

			// Assert
			Assert::IsTrue(errorMessage == "Cannot move a ship at 0 health");
			
		}

		TEST_METHOD(TestMethodShipMoveHealthDoesntGoesUpOne)
		{
			// Arrange
			string name = "Enterprise";
			int startingX = 4;
			int startingY = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment startingAlign = us;
			Alignment expectedAlign = them;
			int attackPower = 0;
			int range = 0;
			int xMove = -5;
			int yMove = 5;
			int damage = 5;
			int healthIncreasedForMoving = 1;
			int expectedHealth = maxHealth - damage + healthIncreasedForMoving;
			Ship enterprise(name, startingX, startingY, startingAlign, maxHealth, range, attackPower, xMove, yMove);

			// Act
			enterprise.assessDamage(damage);
			enterprise.move();
			int actualX = enterprise.getX();
			int actualY = enterprise.getY();
			int actualHeatlh = enterprise.getCurrentHealth();

			// Assert
			Assert::AreEqual(expectedHealth, actualHeatlh);
		}

		TEST_METHOD(TestMethodShipAttackOutOfRangeDoesNothing)
		{
			// Arrange
			string name = "Enterprise";
			int startingX = 4;
			int startingY = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment align = us;
			Alignment otherAlign = them;
			int attackPower = 10;
			int range = 10;
			int xMove = -5;
			int yMove = 5;
			int expectedHealth = maxHealth;
			Ship enterprise(name, startingX, startingY, align, maxHealth, range, attackPower, xMove, yMove);
			Ship *target = new Ship(name, startingX + 10, startingY + 10, otherAlign, maxHealth, range, attackPower, xMove, yMove);
			// Act
			enterprise.attack(target);
			int actualHeatlh = target->getCurrentHealth();

			// Assert
			Assert::AreEqual(expectedHealth, actualHeatlh);
		}

		TEST_METHOD(TestMethodShipAttackInRangeSameAlignmentDoesNothing)
		{
			// Arrange
			string name = "Enterprise";
			int startingX = 4;
			int startingY = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment align = us;
			Alignment otherAlign = us;
			int attackPower = 10;
			int range = 10;
			int xMove = -5;
			int yMove = 5;
			int expectedHealth = maxHealth;
			Ship enterprise(name, startingX, startingY, align, maxHealth, range, attackPower, xMove, yMove);
			Ship *target = new Ship(name, startingX, startingY, otherAlign, maxHealth, range, attackPower, xMove, yMove);
			// Act
			enterprise.attack(target);
			int actualHeatlh = target->getCurrentHealth();

			// Assert
			Assert::AreEqual(expectedHealth, actualHeatlh);
		}

		TEST_METHOD(TestMethodShipAttackInRangeOtherAlignmentAttacks)
		{
			// Arrange
			string name = "Enterprise";
			int startingX = 4;
			int startingY = 2;
			string expectedType = "Ship";
			int maxHealth = 42;
			Alignment align = us;
			Alignment otherAlign = them;
			int attackPower = 10;
			int range = 10;
			int xMove = -5;
			int yMove = 5;
			int expectedHealth = maxHealth - attackPower;
			Ship enterprise(name, startingX, startingY, align, maxHealth, range, attackPower, xMove, yMove);
			Ship *target = new Ship(name, startingX, startingY, otherAlign, maxHealth, range, attackPower, xMove, yMove);
			// Act
			enterprise.attack(target);
			int actualHeatlh = target->getCurrentHealth();

			// Assert
			Assert::AreEqual(expectedHealth, actualHeatlh);
		}

	};
}