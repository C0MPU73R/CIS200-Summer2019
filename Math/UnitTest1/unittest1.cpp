#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Math\MathFunctions.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CircleGetRadius)
		{
			// AAA

			// Arrange
			double expectedRadius = 3;
			Circle circle(expectedRadius);

			// Act
			double actualRadius = circle.getRadius();
			
			// Assert
			Assert::AreEqual(expectedRadius, actualRadius);
		}

		TEST_METHOD(CircleGetArea)
		{
			// AAA

			// Arrange
			double radius = 3;
			double expectedArea = radius * radius*3.14159;
			Circle circle(radius);

			// Act
			double actualArea = circle.getArea();

			// Assert
			Assert::AreEqual(expectedArea, actualArea);
		}

		TEST_METHOD(CircleGetCircumference)
		{
			// AAA

			// Arrange
			double radius = 3;
			double expectedCircumference = radius * 2 * 3.14159;
			Circle circle(radius);

			// Act
			double actualCircumference = circle.getCircumference();

			// Assert
			Assert::AreEqual(expectedCircumference, actualCircumference);
		}

	};
}