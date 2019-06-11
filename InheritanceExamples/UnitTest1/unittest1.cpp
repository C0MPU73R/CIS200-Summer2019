#include "stdafx.h"
#include "CppUnitTest.h"
#include "../InheritanceExamples/Header.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodGetSuit)
		{
			// AAA

			// Arrange
			SomeBaseClass baseClass;
			Suit expectedSuit = Spades;

			// Act
			Suit actualSuit = baseClass.getSuit();

			// Assert
			Assert::IsTrue(expectedSuit == actualSuit);

		}

		TEST_METHOD(TestMethodStatus)
		{
			// AAA

			// Arrange
			SomeBaseClass baseClass;
			string expectedStatus = "My status is: Base class string";

			// Act
			string actualStatus = baseClass.status();

			// Assert
			Assert::AreEqual(expectedStatus, actualStatus);

		}

	};
}