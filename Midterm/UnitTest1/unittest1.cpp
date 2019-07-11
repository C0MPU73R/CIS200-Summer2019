#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Midterm\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodLuckyNumberConstructorThrowsException)
		{
			// Arrange
			int invalidLuckyNumber = -1;
			string actualError = "";
			string expectedError = "luckyDivisor cannot be <= 0";

			// Act
			try
			{
				LuckyNumberChecker luckyNumberChecker(invalidLuckyNumber);
				Assert::Fail();
			}
			catch (invalid_argument &e)
			{
				actualError = e.what();
			}

			// Assert
			Assert::AreEqual(expectedError, actualError);
		}

		TEST_METHOD(TestMethodLuckyNumberCheckNumberEvenlyDivisibleByLuckyDivisor)
		{
			// Arrange
			int luckyDivisor = 3;
			int numberToCheck = 9;
			string expectedResult = "This number is lucky";
			string actualResult = "";

			// Act
			LuckyNumberChecker luckyNumberChecker(luckyDivisor);
			actualResult = luckyNumberChecker.checkNumber(numberToCheck);
			
			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodLuckyNumberCheckNumberMightBeLucky)
		{
			// Arrange
			int luckyDivisor = 4;
			int numberToCheck = 9;
			string expectedResult = "This number might be lucky";
			string actualResult = "";

			// Act
			LuckyNumberChecker luckyNumberChecker(luckyDivisor);
			actualResult = luckyNumberChecker.checkNumber(numberToCheck);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodLuckyNumberCheckNotLuckyNumber)
		{
			// Arrange
			int luckyDivisor = 4;
			int numberToCheck = 10;
			string expectedResult = "This number is not lucky";
			string actualResult = "";

			// Act
			LuckyNumberChecker luckyNumberChecker(luckyDivisor);
			actualResult = luckyNumberChecker.checkNumber(numberToCheck);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodSuperLuckyNumberCheckSuperLuckyNumber)
		{
			// Arrange
			int superLuckyDivisor = 4;
			int luckyDivisor = 3;
			int numberToCheck = 12;
			string expectedResult = "This number is super lucky";
			string actualResult = "";

			// Act
			DoublyLuckyNumberChekcer doublyLuckyNumberChecker(superLuckyDivisor, luckyDivisor);
			actualResult = doublyLuckyNumberChecker.checkNumber(numberToCheck);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodSuperLuckyNumberCheckRegularLuckyNumber)
		{
			// Arrange
			int superLuckyDivisor = 17;
			int luckyDivisor = 3;
			int numberToCheck = 12;
			string expectedResult = "This number is lucky";
			string actualResult = "";

			// Act
			DoublyLuckyNumberChekcer doublyLuckyNumberChecker(superLuckyDivisor, luckyDivisor);
			actualResult = doublyLuckyNumberChecker.checkNumber(numberToCheck);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodwhiteMinusBlackSquares)
		{
			// Arrange
			vector<vector<int>> numbers = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9,10, 11, 12 }, { 13, 14, 15, 16 } };
			int expectedResult = 0;

			// Act
			int actualResult = whiteMinusBlackSquares(numbers);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodRecursiveSumOfOddNumbers)
		{
			// Arrange
			int n = 9;
			int expectedResult = 25;

			// Act
			int actualResult = RecursiveSumOfOddNumbersUpToN(n);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodRecursiveSumOfOddNumbersStartingWithEven)
		{
			// Arrange
			int n = 10;
			int expectedResult = 25;

			// Act
			int actualResult = RecursiveSumOfOddNumbersUpToN(n);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodSumOfOddNumbers)
		{
			// Arrange
			int n = 9;
			int expectedResult = 25;

			// Act
			int actualResult = SumOfOddNumbersUpToN(n);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(TestMethodSumOfOddNumbersStartingWithEven)
		{
			// Arrange
			int n = 10;
			int expectedResult = 25;

			// Act
			int actualResult = SumOfOddNumbersUpToN(n);

			// Assert
			Assert::AreEqual(expectedResult, actualResult);
		}


	};
}