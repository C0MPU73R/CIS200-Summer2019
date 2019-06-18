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

	};
}