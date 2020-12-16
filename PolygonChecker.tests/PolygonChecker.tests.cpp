#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "TriangleSolver.h"
#include "SquareSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define ANGLE_TOLERANCE 0.05

namespace PolygonCheckertests
{
	TEST_CLASS(TringleSolverTests)
	{
	public:
		TEST_METHOD(radians_to_degrees_OneDecimalZeroFourSevenTwo_Sixty)
		{
			//arrange
			double radians = 1.0472;
			double expected = 60;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_TwoDecimalZeroNineFourFour_OneHundredTwenty)
		{
			//arrange
			double radians = 2.0944;
			double expected = 120;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ZeroDecimalZeroOneSevenFour_One)
		{
			//arrange
			double radians = 0.0174;
			double expected = 1;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ThreeDecimalOneZeroSixSix_178)
		{
			//arrange
			double radians = 3.1066;
			double expected = 178;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_OneDecimalTwoTwoOneSeven_Seventy)
		{
			//arrange
			double radians = 1.2217;
			double expected = 70;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ZeroDecimalSixNineEightOne_forty)
		{
			//arrange
			double radians = 0.6981;
			double expected = 40;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_ZeroDecimalSevenEightFiveFour_fortyfive)
		{
			//arrange
			double radians = 0.7854;
			double expected = 45;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(find_angle_OneAndOneAndOne_1decimal0472)
		{
			//arrange
			double sideOne = 1;
			double sideTwo = 1;
			double sideThree = 1;

			double expected = 1.0472;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(find_angle_TweleveAndTweleveAndSixteen_0decimal8410)
		{
			//arrange
			double sideOne = 12;
			double sideTwo = 12;
			double sideThree = 16;

			double expected = 0.8410;

			//act
			double answer = find_angle(sideOne, sideTwo, sideThree);

			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

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
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

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
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

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
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

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
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(inside_angles_radians_OneOneOne_1decimal0472)
		{
			//arrange
			double sideOne = 1;
			double sideTwo = 1;
			double sideThree = 1;

			double* expected = (double*)malloc(sizeof(double) * 3);

			if (expected == NULL)
			{
				return;
			}
			expected[0] = 1.0472; //angle oppiiste to side one
			expected[1] = 1.0472; //angle oppiiste to side two
			expected[2] = 1.0472; //angle oppiiste to side three

			//act
			double* answer = inside_angles_radians(sideOne, sideTwo, sideThree);

			//assert

			Assert::AreEqual(expected[0], answer[0], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[1], answer[1], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[2], answer[2], ANGLE_TOLERANCE);
		}

		TEST_METHOD(inside_angles_radians_TwelveTwelveSixteen_0Decimal84107_0Decimal84107_1Decimal45946)
		{
			//arrange
			double sideOne = 12;
			double sideTwo = 12;
			double sideThree = 16;

			double* expected = (double*)malloc(sizeof(double) * 3);

			if (expected == NULL)
			{
				return;
			}
			expected[0] = 0.84107; //angle oppiiste to side one
			expected[1] = 0.84107; //angle oppiiste to side two
			expected[2] = 1.45946; //angle oppiiste to side three

			//act
			double* answer = inside_angles_radians(sideOne, sideTwo, sideThree);

			//assert

			Assert::AreEqual(expected[0], answer[0], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[1], answer[1], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[2], answer[2], ANGLE_TOLERANCE);
		}

		TEST_METHOD(inside_angles_radians_ThreeFourFive_0Decimal6435_0Decimal9273_1Decimal5708)
		{
			//arrange
			double sideOne = 3;
			double sideTwo = 4;
			double sideThree = 5;

			double* expected = (double*)malloc(sizeof(double) * 3);

			if (expected == NULL)
			{
				return;
			}
			expected[0] = 0.6435; //angle oppiiste to side one
			expected[1] = 0.9273; //angle oppiiste to side two
			expected[2] = 1.5708; //angle oppiiste to side three

			//act
			double* answer = inside_angles_radians(sideOne, sideTwo, sideThree);

			//assert

			Assert::AreEqual(expected[0], answer[0], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[1], answer[1], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[2], answer[2], ANGLE_TOLERANCE);
		}

		TEST_METHOD(inside_angles_radians_OneOneOne_60)
		{
			//arrange
			double sideOne = 1;
			double sideTwo = 1;
			double sideThree = 1;

			double* expected = (double*)malloc(sizeof(double) * 3);

			if (expected == NULL)
			{
				return;
			}
			expected[0] = 60; //angle oppiiste to side one
			expected[1] = 60; //angle oppiiste to side two
			expected[2] = 60; //angle oppiiste to side three

			//act
			double* answer = inside_angles_degrees(sideOne, sideTwo, sideThree);

			//assert

			Assert::AreEqual(expected[0], answer[0], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[1], answer[1], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[2], answer[2], ANGLE_TOLERANCE);
		}

		TEST_METHOD(inside_angles_radians_TwelveTwelveSixteen_48Decimal19_48Decimal19_83Decimal6)
		{
			//arrange
			double sideOne = 12;
			double sideTwo = 12;
			double sideThree = 16;

			double* expected = (double*)malloc(sizeof(double) * 3);

			if (expected == NULL)
			{
				return;
			}
			expected[0] = 48.19; //angle oppiiste to side one
			expected[1] = 48.19; //angle oppiiste to side two
			expected[2] = 83.6; //angle oppiiste to side three

			//act
			double* answer = inside_angles_degrees(sideOne, sideTwo, sideThree);

			//assert

			Assert::AreEqual(expected[0], answer[0], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[1], answer[1], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[2], answer[2], ANGLE_TOLERANCE);
		}

		TEST_METHOD(inside_angles_radians_ThreeFourFive_36Decimal87_52Decimal13_90)
		{
			//arrange
			double sideOne = 3;
			double sideTwo = 4;
			double sideThree = 5;

			double* expected = (double*)malloc(sizeof(double) * 3);

			if (expected == NULL)
			{
				return;
			}
			expected[0] = 36.87; //angle oppiiste to side one
			expected[1] = 53.13; //angle oppiiste to side two
			expected[2] = 90; //angle oppiiste to side three

			//act
			double* answer = inside_angles_degrees(sideOne, sideTwo, sideThree);

			//assert

			Assert::AreEqual(expected[0], answer[0], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[1], answer[1], ANGLE_TOLERANCE);
			Assert::AreEqual(expected[2], answer[2], ANGLE_TOLERANCE);
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
			double i = 1;

			//act
			for (double i = 1; i < 200; i++)
			{
				//assert
				Assert::AreEqual(analyze_triangle(i + 2, i + 3, i + 4), "Scalene triangle");
			}
		}
	};


	//
	TEST_CLASS(SquareSolverTests)
	{
	public:
		TEST_METHOD(get_Area_FiveFive_25)
		{
			//arrange
			double x = 5;
			double y = 5;

			double expected = 25;

			//act
			double answer = get_area(x, y);


			//assert
			Assert::AreEqual(answer, expected);

		}

		TEST_METHOD(get_Area_OneHundredOneHundred_TenThousand)
		{
			//arrange
			double x = 100;
			double y = 100;

			double expected = 10000;

			//act
			double answer = get_area(x, y);


			//assert
			Assert::AreEqual(answer, expected);

		}

		TEST_METHOD(get_Perimiter_FiveFive_Twenty)
		{
			double x = 5;
			double y = 5;

			double expected = 20;

			//act
			double answer = get_perimeter(x, y);


			//assert
			Assert::AreEqual(answer, expected);
		}

		TEST_METHOD(get_area_OneHundredOneHundred_FourHundred)
		{
			double x = 100;
			double y = 100;

			double expected = 400;

			//act
			double answer = get_perimeter(x, y);


			//assert
			Assert::AreEqual(answer, expected);
		}

		TEST_METHOD(is_rectangle_PositiveRectange_True)
		{
			//arrange
			POINT pointOne = { 0.0, 2.0 };
			POINT pointTwo = { 2.0, 2.0 };
			POINT pointThree = { 0.0, 1.0 };
			POINT pointFour = { 2.0, 1.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_NegativeRectangle_True)
		{
			//arrange
			POINT pointOne = { -2.0, -2.0 };
			POINT pointTwo = { 2.0, -2.0 };
			POINT pointThree = { -2.0, -4.0 };
			POINT pointFour = { 2.0, -4.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);

		}

		TEST_METHOD(is_rectangle_PositiveRectange_false)
		{
			//arrange
			POINT pointOne = { 0, 2.0 };
			POINT pointTwo = { 10, 2.0 };
			POINT pointThree = { 0.0, 1.0 };
			POINT pointFour = { 2.0, 1.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);

		}

		TEST_METHOD(is_rectangle_NegativeRectangle_False)
		{
			//arrange
			POINT pointOne = { -2.0, -2.0 };
			POINT pointTwo = { -10, -2.0 };
			POINT pointThree = { -2.0, -4.0 };
			POINT pointFour = { 2.0, -4.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_PositveRectangleDiagonal_True)
		{
			//arrange
			POINT pointOne = { 1, 4 };
			POINT pointTwo = { 2.5, 2.5 };
			POINT pointThree = { 0,3 };
			POINT pointFour = { 1.5, 1.5 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);

			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_NegativeRectangleDiagonal_True)
		{
			//arrange
			POINT pointOne = { -1.5, -1.5 };
			POINT pointTwo = { 0, -3 };
			POINT pointThree = { -2.5,-2.5 };
			POINT pointFour = { -1, -4 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);

			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_PositveRectangleDiagonal_False)
		{
			//arrange
			POINT pointOne = { 10, 4 };
			POINT pointTwo = { 2.5, 2.5 };
			POINT pointThree = { 0,3 };
			POINT pointFour = { 1.5, 1.5 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);

			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_NegativeRectangleDiagonal_False)
		{
			//arrange
			POINT pointOne = { 10, -1.5 };
			POINT pointTwo = { 0, -3 };
			POINT pointThree = { -2.5,-2.5 };
			POINT pointFour = { -1, -4 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);

			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_PositiveSquare_True)
		{
			//arrange
			POINT pointOne = { 1, 2 };
			POINT pointTwo = { 2, 2 };
			POINT pointThree = { 1, 1 };
			POINT pointFour = { 2, 1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_NegativeSquare_True)
		{
			//arrange
			POINT pointOne = { -1, -2 };
			POINT pointTwo = { -2, -2 };
			POINT pointThree = { -1, -1 };
			POINT pointFour = { -2, -1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_PositiveSquare_false)
		{
			//arrange
			POINT pointOne = { 10, 2 };
			POINT pointTwo = { 2, 2 };
			POINT pointThree = { 1, 1 };
			POINT pointFour = { 2, 1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_NegativeSquare_False)
		{
			//arrange
			POINT pointOne = { -10, -2 };
			POINT pointTwo = { -2, -2 };
			POINT pointThree = { -1, -1 };
			POINT pointFour = { -2, -1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_PositveSquareDiagonal_True)
		{
			POINT pointOne = { 2, 3 };
			POINT pointTwo = { 3, 2 };
			POINT pointThree = { 1, 2 };
			POINT pointFour = { 2, 1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_NegativeSquareDiagonal_True)
		{
			POINT pointOne = { -2, -3 };
			POINT pointTwo = { -3, -2 };
			POINT pointThree = { -1, -2 };
			POINT pointFour = { -2, -1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_PositveSquareDiagonal_False)
		{
			POINT pointOne = { 10, 3 };
			POINT pointTwo = { 3, 2 };
			POINT pointThree = { 1, 2 };
			POINT pointFour = { 2, 1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_NegativeSquareDiagonal_False)
		{
			POINT pointOne = { -10, -3 };
			POINT pointTwo = { -3, -2 };
			POINT pointThree = { -1, -2 };
			POINT pointFour = { -2, -1 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		
	};
}
