#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\MazeSolver\MazeSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodMazeSolver)
		{
			// Arrange
			vector<vector<char>> maze = {
				{'S','W','W','W','O','W','W','W','W','W'},
				{'O','O','O','O','O','W','O','O','O','W'},
				{'O','W','O','W','O','W','O','W','O','W'},
				{'O','W','O','W','O','O','O','W','O','W'},
				{'O','O','O','W','O','W','W','O','O','W'},
				{'W','W','O','W','O','O','W','O','W','W'},
				{'W','O','O','O','W','O','W','O','O','O'},
				{'W','O','W','O','O','O','W','O','W','O'},
				{'W','O','W','W','O','W','W','O','W','O'},
				{'W','O','O','O','O','W','W','O','W','E'}
			};

			MazeSolver mazeSolver(maze);
			int expectedShortestPath = 24;

			// Act
			int actualShortestPath = mazeSolver.solve();

			// Assert
			Assert::AreEqual(expectedShortestPath, actualShortestPath);
		}

	};
}