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

		TEST_METHOD(PowerBallFourWhiteAndRedMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 50000;
			PowerBallTicket winningTicket(1, 2, 3, 4, 7, 6);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 6);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallFourWhiteMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 100;
			PowerBallTicket winningTicket(1, 2, 3, 4, 7, 7);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 6);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallThreeWhiteAndRedMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 100;
			PowerBallTicket winningTicket(1, 2, 3, 6, 7, 7);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 7);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallThreeWhiteMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 7;
			PowerBallTicket winningTicket(1, 2, 3, 6, 7, 8);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 7);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallTwoWhiteAndRedMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 7;
			PowerBallTicket winningTicket(1, 2, 9, 6, 7, 8);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 8);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallRedMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 4;
			PowerBallTicket winningTicket(10, 8, 9, 6, 7, 8);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 8);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallNoMatch)
		{
			// AAA

			// Arrange
			int expectedWinnings = 0;
			PowerBallTicket winningTicket(10, 8, 9, 6, 7, 9);
			PowerBallTicket myTicket(5, 4, 3, 2, 1, 8);

			// Act
			int actualWinnings = myTicket.getWinnings(winningTicket);

			// Assert
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(PowerBallDuplicateWhiteNumbers)
		{
			// AAA

			// Arrange

			// Act
			try 
			{
				PowerBallTicket myTicket(1, 4, 3, 2, 1, 7);
				Assert::Fail();
			}
			catch (invalid_argument &e)
			{

			}
		}

	};
}