#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MidtermReview/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodEmployee)
		{
			// Arrange
			int expectedIDNumber = 42;
			string expectedName = "Eric";
			double expectedAnnualSalary = 10000;
			double expectedWeeklySalary = expectedAnnualSalary / 52;
			double expectedMonthlySalary = expectedAnnualSalary / 12;

			// Act
			Employee eric(expectedIDNumber, expectedName, expectedAnnualSalary);
			int actualIDNumber = eric.getIDNumber();
			string actualName = eric.getName();
			double actualAnnualSalary = eric.getAnnualSalary();
			double actualMonthlySalary = eric.getMonthlySalary();
			double actualWeeklySalary = eric.getWeeklySalary();

			// Assert
			Assert::AreEqual(expectedIDNumber, actualIDNumber);
			Assert::AreEqual(expectedName, actualName);
			Assert::AreEqual(expectedAnnualSalary, actualAnnualSalary);
			Assert::AreEqual(expectedMonthlySalary, actualMonthlySalary);
			Assert::AreEqual(expectedWeeklySalary, actualWeeklySalary);

		}

		TEST_METHOD(TestMethodEmployeeInvalidSalary)
		{
			// Arrange
			int expectedIDNumber = 42;
			string expectedName = "Eric";
			double expectedAnnualSalary = -1;
			string expectedErrorMessage = "Salary can't be 0 or less";
			string actualErrorMessage = "";
			// Act
			try
			{
				Employee eric(expectedIDNumber, expectedName, expectedAnnualSalary);
				Assert::Fail();
			}
			catch (invalid_argument &e)
			{
				actualErrorMessage = e.what();
			}

			Assert::AreEqual(expectedErrorMessage, actualErrorMessage);
			
			

			// Assert


		}

	};
}