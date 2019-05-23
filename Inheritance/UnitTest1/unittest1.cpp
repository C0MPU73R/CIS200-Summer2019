#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Inheritance\Polygon.h"
#include "..\Inheritance\Rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestPolygonPerimeter)
		{
			// AAA

			// Arrange
			double sideLength = 10;
			double expectedPerimeter = sideLength * 4;

			// Act
			Polygon square(4);
			square.setSideLength(0, sideLength);
			square.setSideLength(1, sideLength);
			square.setSideLength(2, sideLength);
			square.setSideLength(3, sideLength);
			double actualPerimeter = square.getPerimeter();

			// Assert
			Assert::AreEqual(expectedPerimeter, actualPerimeter);
		}

		TEST_METHOD(TestPolygonArea)
		{
			// AAA

			// Arrange
			double sideLength = 10;
			double expectedArea = sideLength * sideLength;

			// Act
			Polygon square(4);
			square.setSideLength(0, sideLength);
			square.setSideLength(1, sideLength);
			square.setSideLength(2, sideLength);
			square.setSideLength(3, sideLength);

			// Assert
			try
			{
				square.getArea();
				Assert::Fail();
			}
			catch (exception &e)
			{

			}
		}

		TEST_METHOD(TestRectangleArea)
		{
			// AAA

			// Arrange
			double width = 10;
			double length = 5;
			double expectedArea = width * length;

			// Act
			Rectangle rectangle(width, length);
			double actualArea = rectangle.getArea();

			// Assert
			Assert::AreEqual(expectedArea, actualArea);
		}

		// this test is sort of silly
		TEST_METHOD(TestRectanglePerimeter)
		{
			// AAA

			// Arrange
			double width = 10;
			double length = 5;
			double expectedPerimeter = width * 2 + length * 2;

			// Act
			Rectangle rectangle(width, length);
			double actualPerimeter = rectangle.getPerimeter();

			// Assert
			Assert::AreEqual(expectedPerimeter, actualPerimeter);
		}



	};
}