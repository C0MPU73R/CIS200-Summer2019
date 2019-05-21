#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PowerBall\PowerBallTicket.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(PowerBallJackpot)
		{
			// AAA

			// Arrange
			int expectedWinnings = 2000000000;
			PowerBallTicket winningTicket(1, 2, 3, 4, 5, 6);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 6);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);

		}

		TEST_METHOD(PowerBallFiveWhiteMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 1000000;
			PowerBallTicket winningTicket(1, 2, 3, 4, 5, 6);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 7);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);

		}

	};
}