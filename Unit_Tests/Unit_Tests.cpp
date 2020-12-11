#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "TriangleSolver.h"
#include "SquareSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define ANGLETOLERANCE 0.05

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
			EQUILATERAL SquareSides;
			SquareSides.x[0] = 3;
			SquareSides.x[1] = 1;
			SquareSides.x[2] = 0;
			SquareSides.x[3] = 1;
			SquareSides.y[0] = 1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(SquareSides), false);
		}
		TEST_METHOD(is_Rectangle_Pass)
		{
			EQUILATERAL SquareSides;
			SquareSides.x[0] = 0;
			SquareSides.x[1] = 1;
			SquareSides.x[2] = 0;
			SquareSides.x[3] = 1;
			SquareSides.y[0] = 1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(SquareSides), true);
		}

		TEST_METHOD(Is_Rectangle_char_input)
		{
			EQUILATERAL SquareSides;
			SquareSides.x[0] = 'a';
			SquareSides.x[1] = 2;
			SquareSides.x[2] = 1;
			SquareSides.x[3] = 2;
			SquareSides.y[0] = -1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(SquareSides), false);
		}
		TEST_METHOD(is_Rectangle_Single_Negitive_Invalid)
		{
			EQUILATERAL SquareSides;
			SquareSides.x[0] = -1;
			SquareSides.x[1] = 2;
			SquareSides.x[2] = 1;
			SquareSides.x[3] = 2;
			SquareSides.y[0] = -1;
			SquareSides.y[1] = 2;
			SquareSides.y[2] = 1;
			SquareSides.y[3] = 2;
			Assert::AreEqual(isRectangle(SquareSides), false);
		}
		TEST_METHOD(is_Rectangle_All_Negitive_Valid)
		{
			EQUILATERAL SquareSides;
			SquareSides.x[0] = -1;
			SquareSides.x[1] = -2;
			SquareSides.x[2] = -1;
			SquareSides.x[3] = -2;
			SquareSides.y[0] = -1;
			SquareSides.y[1] = -2;
			SquareSides.y[2] = -1;
			SquareSides.y[3] = -2;
			Assert::AreEqual(isRectangle(SquareSides), true);
		}
		TEST_METHOD(is_Rectangle_Too_Few_Points)
		{
			EQUILATERAL SquareSides;
			SquareSides.x[0] = 3;
			SquareSides.x[1] = 4;
			SquareSides.x[2] = 1;
			SquareSides.y[0] = 3;
			SquareSides.y[1] = 4;
			SquareSides.y[2] = 1;
		    Assert::AreEqual(isRectangle(SquareSides),false);
		}

		TEST_METHOD(radians_to_degrees_OneDecimalZeroFourSevenTwo_Sixty)
		{
			//arrange
			double radians = 1.0472;
			double expected = 60;
			
			//act
			double answer = radians_to_degrees(radians);
		

			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_TwoDecimalZeroNineFourFour_OneHundredTwenty)
		{
			//arrange
			double radians = 2.0944;
			double expected = 120;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ZeroDecimalZeroOneSevenFour_One)
		{
			//arrange
			double radians = 0.0174;
			double expected = 1;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ThreeDecimalOneZeroSixSix_178)
		{
			//arrange
			double radians = 3.1066;
			double expected = 178;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}


		TEST_METHOD(radians_to_degrees_OneDecimalTwoTwoOneSeven_Seventy)
		{
			//arrange
			double radians = 1.2217;
			double expected = 70;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ZeroDecimalSixNineEightOne_forty)
		{
			//arrange
			double radians = 0.6981;
			double expected = 40;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ZeroDecimalSevenEightFiveFour_fortyfive)
		{
			//arrange
			double radians = 0.7854;
			double expected = 45;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(find_angle_OneOneOne_1decimal0472)
		{
			//arrange
			double sideOne = 1;
			double sideTwo = 1;
			double sideThree = 1;

			double expected = 1.0472;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);
			
			//assert
			Assert::AreEqual(answer,expected, ANGLETOLERANCE );

		}

		TEST_METHOD(find_angle_TweleveTweleveSixteen_0decimal8410)
		{
			//arrange
			double sideOne = 12;
			double sideTwo = 12;
			double sideThree = 16;

			double expected = 0.8410;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(find_angle_SixteenTweleveTweleve_1decimal459)
		{
			//arrange
			double sideOne = 16;
			double sideTwo = 12;
			double sideThree = 12;

			double expected = 1.459;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(find_angle_SevenTwelveFifteen_1decimal7620)
		{
			//arrange
			double sideOne = 7;
			double sideTwo = 12;
			double sideThree = 15;

			double expected = 0.4760;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(find_angle_TwelveSevenFifteen_0decimal9030)
		{
			//arrange
			double sideOne = 12;
			double sideTwo = 7;
			double sideThree = 15;

			double expected = 0.9030;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}

		TEST_METHOD(find_angle_FifteenSevenTwelve_1decimal7620)
		{
			//arrange
			double sideOne = 15;
			double sideTwo = 7;
			double sideThree = 12;

			double expected = 1.7620;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLETOLERANCE);

		}



		TEST_METHOD(analyzeTriangle_negOneallsides_NotATriangle)
		{
			//arrange
			int side1 = -1;
			int side2 = -1;
			int side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert

			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_zeroOneOne_NotATriangle)
		{
			//arrange
			int side1 = 0;
			int side2 = 1;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert

			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneZeroOne_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = 0;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneOneZero_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = 1;
			int side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_ZeroZeroOne_NotATriangle)
		{
			//arrange
			int side1 = 0;
			int side2 = 0;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_ZeroOneZero_NotATriangle)
		{
			//arrange
			int side1 = 0;
			int side2 = 1;
			int side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneZeroZero_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = 0;
			int side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_ZeroZeroZero_NotATriangle)
		{
			//arrange
			int side1 = 0;
			int side2 = 0;
			int side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_negOneOneOne_NotATriangle)
		{
			//arrange
			int side1 = -1;
			int side2 = 1;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneNegOneOne_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = -1;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneOneNegOne_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = 1;
			int side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_NegOneNegOneOne_NotATriangle)
		{
			//arrange
			int side1 = -1;
			int side2 = -1;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_NegOneOneNegOne_NotATriangle)
		{
			//arrange
			int side1 = -1;
			int side2 = 1;
			int side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
			
		}
		TEST_METHOD(analyzeTriangle_OneNegOneNegOne_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = -1;
			int side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_TwoThreeOne_NotATriangle)
		{
			//arrange
			int side1 = 2;
			int side2 = 3;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_TwoThreeOne_ScaleneTriangle)
		{
			//arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 2;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Scalene triangle");
		}

		TEST_METHOD(analyzeTriangle_CharThreeOne_NotATriangle) 
		{
			//arrange
			char side1 = 'c';
			int side2 = 1;
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert

			Assert::AreEqual(answer, "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneCharOne_NotATriangle) 
		{
			//arrange
			int side1 = 1;
			char side2 = 'c';
			int side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(analyze_triangle(1, 'b', 1), "Not a triangle");
		}
		TEST_METHOD(analyzeTriangle_OneOneChar_NotATriangle)
		{
			//arrange
			int side1 = 1;
			int side2 = 1;
			char side3 = 'c';

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}
		
		TEST_METHOD(analyzeTriangle_TwoTwoThree_IsoscelesTriangle) 
		{
			//arrange
			char side1 = 2;
			char side2 = 2;
			char side3 = 3;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Isosceles triangle");
		}
		TEST_METHOD(analyzeTriangle_TwoThreeTwo_IsoscelesTriangle) 
		{
			//arrange
			char side1 = 2;
			char side2 = 3;
			char side3 = 2;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Isosceles triangle");
		}
		TEST_METHOD(analyzeTriangle_ThreeTwoTwo_IsoscelesTriangle)
		{
			//arrange
			char side1 = 3;
			char side2 = 2;
			char side3 = 2;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Isosceles triangle");

		}
		TEST_METHOD(analyzeTriangle_OnetoTwoHundred_EquilateralTriangle)
		{
			//arrange 
			int i = 1;

			// act
			for (int i = 1; i < 200; i++)
			{
				//assert
				Assert::AreEqual(analyze_triangle(i, i, i), "Equilateral triangle");
			}
		}
		TEST_METHOD(analyzeTriangle_OnetoTwoHundred_ScaleneTriangle) {
			
			//arrange
			int i = 1;

			//act
			for (int i = 1; i < 200; i++)
			{
				//assert
				Assert::AreEqual(analyze_triangle(i+2, i + 3, i + 4), "Scalene triangle");
			}
		}
	};
}