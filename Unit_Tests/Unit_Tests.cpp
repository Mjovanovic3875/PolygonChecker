#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "triangleSolver.h"
#include "SquareSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
	
		TEST_METHOD(INVALID_TRAINGLE_ALL_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(-1, -1, -1), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(0, 1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(1, 0, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_THIRD_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(1, 1, 0), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_FIRST_SECOND_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(0, 0, 1), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_THIRD_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(0, 1, 0), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_THIRD_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(1, 0, 0), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_ALL_ZERO)
		{
			Assert::AreEqual(analyzeTriangle(0, 0, 0), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(-1, 1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(1, -1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_THIRD_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(1, 1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_FIRST_SECOND_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(-1, -1, 1), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_THIRD_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(-1, 1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_THIRD_NEGITIVE)
		{
			Assert::AreEqual(analyzeTriangle(1, -1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SUM_LESS_THAN)
		{
			Assert::AreEqual(analyzeTriangle(2, 3, 1), "Not a triangle");
		}
		TEST_METHOD(VALID_TRAINGLE_SUM_GREATER_THAN)
		{
			Assert::AreEqual(analyzeTriangle(3, 4, 2), "Scalene triangle");
		}

		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_1) {
			Assert::AreEqual(analyzeTriangle('c', 1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_2) {
			Assert::AreEqual(analyzeTriangle(1, 'b', 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_3) {
			Assert::AreEqual(analyzeTriangle(1, 1, 'a'), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_all) {
			Assert::AreEqual(analyzeTriangle('c', 'b', 'a'), "Not a triangle");
		}

		TEST_METHOD(ISOSCELES_one_two) {
			Assert::AreEqual(analyzeTriangle(2, 2, 3), "Isosceles triangle");
		}
		TEST_METHOD(ISOSCELES_one_three) {
			Assert::AreEqual(analyzeTriangle(2, 3, 2), "Isosceles triangle");
		}
		TEST_METHOD(ISOSCELES_two_three) {
			Assert::AreEqual(analyzeTriangle(3, 2, 2), "Isosceles triangle");

		}
		TEST_METHOD(EQUALATERAL) {
			for (int i = 1; i < 200; i++) {
				Assert::AreEqual(analyzeTriangle(i, i, i), "Equilateral triangle");
			}
		}
		TEST_METHOD(SCALENE) {
			for (int i = 1; i < 200; i++) {
				Assert::AreEqual(analyzeTriangle(i+2, i + 3, i + 4), "Scalene triangle");
			}
		}
	};
}