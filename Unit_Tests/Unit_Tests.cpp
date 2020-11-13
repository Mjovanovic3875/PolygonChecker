#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "triangleSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(INVALID_TRAINGLE_ZERO_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(0,0,0),"Not a triangle");
			Assert::AreEqual(analyzeTriangle(0, 1, 0), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(1, 0, 0), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(1, 1, 0), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(1, 1, -1), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(1, -1, 1), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(-1, 1, 1), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(-1, -1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR) {
			Assert::AreEqual(analyzeTriangle(0, 0, 'a'), "Not a triangle");
			Assert::AreEqual(analyzeTriangle(0, 'b', 0), "Not a triangle");
			Assert::AreEqual(analyzeTriangle('c', 0, 0), "Not a triangle");
			Assert::AreEqual(analyzeTriangle('c', 'b', 'a'), "Not a triangle");
		}

		TEST_METHOD(ISOSCELES) {
			Assert::AreEqual(analyzeTriangle(1, 1, 2), "Isosceles triangle");
			Assert::AreEqual(analyzeTriangle(1, 2, 1), "Isosceles triangle");
			Assert::AreEqual(analyzeTriangle(2, 1, 1), "Isosceles triangle");
	
		}
		TEST_METHOD(EQUALATERAL) {
			for (int i = 1; i < 200; i++) {
				Assert::AreEqual(analyzeTriangle(i, i, i), "Equilateral triangle");
			}
		}
		TEST_METHOD(SCALENE) {
			for (int i = 1; i < 200; i++) {
				Assert::AreEqual(analyzeTriangle(i, i + 1, i + 2), "Scalene triangle");
			}
		}
	};
}