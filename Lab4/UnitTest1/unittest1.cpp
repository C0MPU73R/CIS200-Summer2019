#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab4/VectorFun.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestNumberOfEvenSummedRows)
		{
			// AAA

			// Arange
			vector<vector<int>> numbers = { {1,2,3,4 }, {5,6,7,8}, {9,10,11,13} };
			int expectedNumberOfEvenSummedRows = 2;

			// Act
			int actualNumberOfEvenSummedRows = numberOfEvenSummedRows(numbers);

			// Assert
			Assert::AreEqual(expectedNumberOfEvenSummedRows, actualNumberOfEvenSummedRows);
		}

		TEST_METHOD(TestNumberOfOddSummedRows)
		{
			// AAA

			// Arange
			vector<vector<int>> numbers = { {1,2,3,4 }, {5,6,7,8}, {9,10,11,13} };
			int expectedNumberOfOddSummedRows = 1;

			// Act
			int actualNumberOfOddSummedRows = numberOfOddSummedRows(numbers);

			// Assert
			Assert::AreEqual(expectedNumberOfOddSummedRows, actualNumberOfOddSummedRows);
		}

		TEST_METHOD(TestStandardDeviation)
		{
			// AAA

			// Arange
			vector<int> numbers = { 1,2,3,4,5,6,7 };
			double expectedStandardDeviation = 2;

			// Act
			double actualStandardDeviation = standardDeviation(numbers);

			// Assert
			Assert::AreEqual(expectedStandardDeviation, actualStandardDeviation, .01);
		}

		TEST_METHOD(TestStandardDeviationWithDecimal)
		{
			// AAA

			// Arange
			vector<int> numbers = { 1,2,3,4,5,6 };
			double expectedStandardDeviation = 1.708;

			// Act
			double actualStandardDeviation = standardDeviation(numbers);

			// Assert
			Assert::AreEqual(expectedStandardDeviation, actualStandardDeviation, .01);
		}
	};
}