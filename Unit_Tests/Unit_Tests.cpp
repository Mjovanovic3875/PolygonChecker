#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "TriangleSolver.h"
#include "SquareSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
	
		TEST_METHOD(get_Area_Valid)
		{
			
		}
		TEST_METHOD(get_Area_One_Negitive)
		{
			
		}

		TEST_METHOD(get_Area_All_Negitive)
		{
			
		}
		TEST_METHOD(get_Area_char_Input)
		{
		
		}

		TEST_METHOD(get_Perimiter_Valid)
		{

		}
		TEST_METHOD(get_Perimiter_One_Negitive)
		{

		}

		TEST_METHOD(get_Perimiter_All_Negitive)
		{
			
		}
		TEST_METHOD(get_Perimiter_char_Input)
		{
			
		}
		TEST_METHOD(is_Rectangle_Invalid)
		{
			COORDINATE SquareSides;
			SquareSides.x[0] = 3;
			SquareSides.x[1] = 1;
			SquareSides.x[2] = 0;
			SquareSides.x[3] = 1;
			SquareSides.y[0] = 1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(&SquareSides), false);
		}
		TEST_METHOD(is_Rectangle_Pass)
		{
			COORDINATE SquareSides;
			SquareSides.x[0] = 0;
			SquareSides.x[1] = 1;
			SquareSides.x[2] = 0;
			SquareSides.x[3] = 1;
			SquareSides.y[0] = 1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(&SquareSides), true);
		}

		TEST_METHOD(Is_Rectangle_char_input)
		{
			COORDINATE SquareSides;
			SquareSides.x[0] = 'a';
			SquareSides.x[1] = 2;
			SquareSides.x[2] = 1;
			SquareSides.x[3] = 2;
			SquareSides.y[0] = -1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(&SquareSides), false);
		}
		TEST_METHOD(is_Rectangle_Single_Negitive_Invalid)
		{
			COORDINATE SquareSides;
			SquareSides.x[0] = -1;
			SquareSides.x[1] = 2;
			SquareSides.x[2] = 1;
			SquareSides.x[3] = 2;
			SquareSides.y[0] = -1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(&SquareSides), false);
		}
		TEST_METHOD(is_Rectangle_All_Negitive_Valid)
		{
			COORDINATE SquareSides;
			SquareSides.x[0] = -1;
			SquareSides.x[1] = -2;
			SquareSides.x[2] = -1;
			SquareSides.x[3] = -2;
			SquareSides.y[0] = -1;
			SquareSides.y[1] = -2;
			SquareSides.y[2] = -1;
			SquareSides.y[3] = -2;
			Assert::AreEqual(isRectangle(&SquareSides), true);
		}
		TEST_METHOD(is_Rectangle_Too_Few_Points)
		{
			COORDINATE SquareSides;
			SquareSides.x[0] = 3;
			SquareSides.x[1] = 4;
			SquareSides.x[2] = 1;
			SquareSides.y[0] = 3;
			SquareSides.y[1] = 4;
			SquareSides.y[2] = 1;
		    Assert::AreEqual(isRectangle(&SquareSides),false);
		}




		TEST_METHOD(INVALID_TRAINGLE_ALL_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(-1, -1, -1), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_ZERO)
		{
			Assert::AreEqual(analyze_triangle(0, 1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_ZERO)
		{
			Assert::AreEqual(analyze_triangle(1, 0, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_THIRD_ZERO)
		{
			Assert::AreEqual(analyze_triangle(1, 1, 0), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_FIRST_SECOND_ZERO)
		{
			Assert::AreEqual(analyze_triangle(0, 0, 1), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_THIRD_ZERO)
		{
			Assert::AreEqual(analyze_triangle(0, 1, 0), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_THIRD_ZERO)
		{
			Assert::AreEqual(analyze_triangle(1, 0, 0), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_ALL_ZERO)
		{
			Assert::AreEqual(analyze_triangle(0, 0, 0), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(-1, 1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(1, -1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_THIRD_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(1, 1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_FIRST_SECOND_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(-1, -1, 1), "Not a triangle");
		}

		TEST_METHOD(INVALID_TRAINGLE_FIRST_THIRD_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(-1, 1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SECOND_THIRD_NEGITIVE)
		{
			Assert::AreEqual(analyze_triangle(1, -1, -1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRAINGLE_SUM_LESS_THAN)
		{
			Assert::AreEqual(analyze_triangle(2, 3, 1), "Not a triangle");
		}
		TEST_METHOD(VALID_TRAINGLE_SUM_GREATER_THAN)
		{
			Assert::AreEqual(analyze_triangle(3, 4, 2), "Scalene triangle");
		}

		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_1) {
			Assert::AreEqual(analyze_triangle('c', 1, 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_2) {
			Assert::AreEqual(analyze_triangle(1, 'b', 1), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_3) {
			Assert::AreEqual(analyze_triangle(1, 1, 'a'), "Not a triangle");
		}
		TEST_METHOD(INVALID_TRIANGLE_CHAR_side_all) {
			Assert::AreEqual(analyze_triangle('c', 'b', 'a'), "Not a triangle");
		}

		TEST_METHOD(ISOSCELES_one_two) {
			Assert::AreEqual(analyze_triangle(2, 2, 3), "Isosceles triangle");
		}
		TEST_METHOD(ISOSCELES_one_three) {
			Assert::AreEqual(analyze_triangle(2, 3, 2), "Isosceles triangle");
		}
		TEST_METHOD(ISOSCELES_two_three) {
			Assert::AreEqual(analyze_triangle(3, 2, 2), "Isosceles triangle");

		}
		TEST_METHOD(EQUALATERAL) {
			for (int i = 1; i < 200; i++) {
				Assert::AreEqual(analyze_triangle(i, i, i), "Equilateral triangle");
			}
		}
		TEST_METHOD(SCALENE) {
			for (int i = 1; i < 200; i++) {
				Assert::AreEqual(analyze_triangle(i+2, i + 3, i + 4), "Scalene triangle");
			}
		}
	};
}