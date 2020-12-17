#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "TriangleSolver.h"
#include "QuadrilateralSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define ANGLE_TOLERANCE 0.05

namespace PolygonCheckertests
{
	TEST_CLASS(TringleSolverTests)
	{
	public:
		TEST_METHOD(radians_to_degrees_1Decimal0472_60)
		{
			//arrange
			double radians = 1.0472;
			double expected = 60;

			//act
			double answer = radians_to_degrees(radians);

			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);
		}

		TEST_METHOD(radians_to_degrees_2Decimal0944_120)
		{
			//arrange
			double radians = 2.0944;
			double expected = 120;

			//act
			double answer = radians_to_degrees(radians);

			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);
		}

		TEST_METHOD(radians_to_degrees_0Decimal0174_1)
		{
			//arrange
			double radians = 0.0174;
			double expected = 1;

			//act
			double answer = radians_to_degrees(radians);


			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);
		}

		TEST_METHOD(radians_to_degrees_3Decimal1066_178)
		{
			//arrange
			double radians = 3.1066;
			double expected = 178;

			//act
			double answer = radians_to_degrees(radians);


			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);
		}

		TEST_METHOD(radians_to_degrees_1Decimal2217_70)
		{
			//arrange
			double radians = 1.2217;
			double expected = 70;

			//act
			double answer = radians_to_degrees(radians);


			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);
		}

		TEST_METHOD(radians_to_degrees_0Decimal6981_40)
		{
			//arrange
			double radians = 0.6981;
			double expected = 40;

			//act
			double answer = radians_to_degrees(radians);


			//assert

			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);

		}

		TEST_METHOD(radians_to_degrees_0Decimal7854_45)
		{
			//arrange
			double radians = 0.7854;
			double expected = 45;

			//act
			double answer = radians_to_degrees(radians);


			//assert
			Assert::AreEqual(answer, expected, ANGLE_TOLERANCE);
		}

		TEST_METHOD(find_angle_1And1And1_1decimal0472)
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

		TEST_METHOD(find_angle_12And12And16_0decimal8410)
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

		TEST_METHOD(find_angle_16And12And12_1decimal459)
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

		TEST_METHOD(find_angle_7And12And15_1decimal7620)
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

		TEST_METHOD(find_angle_12And7And15_0decimal9030)
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

		TEST_METHOD(find_angle_15And7And12_1decimal7620)
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

		TEST_METHOD(analyzeTriangle_Neg1AndNeg1AndNeg1_NotATriangle)
		{
			//arrange
			double side1 = -1;
			double side2 = -1;
			double side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_0And1And1_NotATriangle)
		{
			//arrange
			double side1 = 0;
			double side2 = 1;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert

			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_1And0And1_NotATriangle)
		{
			//arrange
			double side1 = 1;
			double side2 = 0;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_1And1And0_NotATriangle)
		{
			//arrange
			double side1 = 1;
			double side2 = 1;
			double side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_0And0And1_NotATriangle)
		{
			//arrange
			double side1 = 0;
			double side2 = 0;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_0And1And0_NotATriangle)
		{
			//arrange
			double side1 = 0;
			double side2 = 1;
			double side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_1And0And0_NotATriangle)
		{
			//arrange
			double side1 = 1;
			double side2 = 0;
			double side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_0And0And0_NotATriangle)
		{
			//arrange
			double side1 = 0;
			double side2 = 0;
			double side3 = 0;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_Neg1And1And1_NotATriangle)
		{
			//arrange
			double side1 = -1;
			double side2 = 1;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_1AndNeg1And1_NotATriangle)
		{
			//arrange
			double side1 = 1;
			double side2 = -1;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_1And1AndNeg1_NotATriangle)
		{
			//arrange
			double side1 = 1;
			double side2 = 1;
			double side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_Neg1AndNeg1And1_NotATriangle)
		{
			//arrange
			double side1 = -1;
			double side2 = -1;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_Neg1And1AndNeg1_NotATriangle)
		{
			//arrange
			double side1 = -1;
			double side2 = 1;
			double side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");

		}

		TEST_METHOD(analyzeTriangle_1AndNeg1AndNeg1_NotATriangle)
		{
			//arrange
			double side1 = 1;
			double side2 = -1;
			double side3 = -1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_2And3And1_NotATriangle)
		{
			//arrange
			double side1 = 2;
			double side2 = 3;
			double side3 = 1;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Not a triangle");
		}

		TEST_METHOD(analyzeTriangle_3And4And2_ScaleneTriangle)
		{
			//arrange
			double side1 = 3;
			double side2 = 4;
			double side3 = 2;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Scalene triangle");
		}

		TEST_METHOD(analyzeTriangle_2And2And3_IsoscelesTriangle)
		{
			//arrange
			double side1 = 2;
			double side2 = 2;
			double side3 = 3;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Isosceles triangle");
		}

		TEST_METHOD(analyzeTriangle_2And3And2_IsoscelesTriangle)
		{
			//arrange
			double side1 = 2;
			double side2 = 3;
			double side3 = 2;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Isosceles triangle");
		}

		TEST_METHOD(analyzeTriangle_3And2And2_IsoscelesTriangle)
		{
			//arrange
			double side1 = 3;
			double side2 = 2;
			double side3 = 2;

			//act
			const char* answer = analyze_triangle(side1, side2, side3);

			//assert
			Assert::AreEqual(answer, "Isosceles triangle");
		}
	};


	//
	TEST_CLASS(EquilateralSolverTests)
	{
	public:
		TEST_METHOD(get_area_5And5_25)
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

		TEST_METHOD(get_area_100And100_10000)
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

		TEST_METHOD(get_perimeter_5and5and5and5_20)
		{
			double sideOne = 5;
			double sideTwo = 5;
			double sideThree = 5;
			double sideFour = 5;

			double expected = 20;

			//act
			double answer = get_perimeter(sideOne, sideTwo, sideThree, sideFour);

			//assert
			Assert::AreEqual(answer, expected);
		}

		TEST_METHOD(get_perimeter_100And100And100And100_400)
		{
			double sideOne = 100;
			double sideTwo = 100;
			double sideThree = 100;
			double sideFour = 100;

			double expected = 400;

			//act
			double answer = get_perimeter(sideOne, sideTwo,
										  sideThree, sideFour);

			//assert
			Assert::AreEqual(answer, expected);
		}

		TEST_METHOD(is_rectangle_TypicalRectangle_True)
		{
			//arrange
			POINT pointOne = { 0.0, 2.0 };
			POINT pointTwo = { 2.0, 2.0 };
			POINT pointThree = { 0.0, 1.0 };
			POINT pointFour = { 2.0, 1.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, 
														       pointThree, pointFour);
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

		TEST_METHOD(is_rectangle_NotRectangle_false)
		{
			//arrange
			POINT pointOne = { 0, 2.0 };
			POINT pointTwo = { 10, 2.0 };
			POINT pointThree = { 0.0, 1.0 };
			POINT pointFour = { 2.0, 1.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, 
															   pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_NegativeNotRectangle_False)
		{
			//arrange
			POINT pointOne = { -2.0, -2.0 };
			POINT pointTwo = { -10, -2.0 };
			POINT pointThree = { -2.0, -4.0 };
			POINT pointFour = { 2.0, -4.0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, 
															   pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, false);
		}

		TEST_METHOD(is_rectangle_RotatedRectangle_True)
		{
			//arrange
			POINT pointOne = { 1, 4 };
			POINT pointTwo = { 2.5, 2.5 };
			POINT pointThree = { 0,3 };
			POINT pointFour = { 1.5, 1.5 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, 
															   pointThree, pointFour);

			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_NegativeRotatedRectangle_True)
		{
			//arrange
			POINT pointOne = { -1.5, -1.5 };
			POINT pointTwo = { 0, -3 };
			POINT pointThree = { -2.5,-2.5 };
			POINT pointFour = { -1, -4 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, 
															   pointThree, pointFour);

			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_RotatedNonRectangle_False)
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

		TEST_METHOD(is_rectangle_NegativeRotatedRectangle_False)
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

		TEST_METHOD(is_rectangle_SkewedQuadrilateral_false)
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

		TEST_METHOD(is_rectangle_NegativeSkewedQuadrilateral_False)
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

		TEST_METHOD(is_rectangle_RotatedSquare_True)
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

		TEST_METHOD(is_rectangle_NegativeRotatedSquare_True)
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

		TEST_METHOD(is_rectangle_RotateNonSquare_False)
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

		TEST_METHOD(is_rectangle_NegativeRotatedNonSquare_False)
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

		TEST_METHOD(is_rectangle_Diamond_True)
		{
			POINT pointOne = { 0, 1 };
			POINT pointTwo = { 1, 2 };
			POINT pointThree = { 2, 1 };
			POINT pointFour = { 1, 0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointOne, pointTwo, pointThree, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_OutOfOrderPoints_True)
		{
			POINT pointOne = { 0, 1 };
			POINT pointTwo = { 1, 2 };
			POINT pointThree = { 2, 1 };
			POINT pointFour = { 1, 0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointThree, pointOne, 
															   pointTwo, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(is_rectangle_LargeValidRectangle_True)
		{
			POINT pointOne = { 0, 1000 };
			POINT pointTwo = { 2000, 1000 };
			POINT pointThree = { 0, 0 };
			POINT pointFour = { 2000, 0 };

			QUADRILATERAL quadrilateral = create_quadrilateral(pointThree, pointOne,
				pointTwo, pointFour);
			//act 
			bool answer = is_rectangle(quadrilateral);

			//assert
			Assert::AreEqual(answer, true);
		}

		TEST_METHOD(find_line_length_0p0And0p1_1)
		{
			POINT pointOne = { 0, 0 };
			POINT pointTwo = { 0, 1 };

			//act 
			double answer = find_line_length(pointOne, pointTwo);

			//assert
			Assert::AreEqual(answer, 1.0);
		}

		TEST_METHOD(find_line_length_0p1And0p0_1)
		{
			POINT pointOne = { 0, 1 };
			POINT pointTwo = { 0, 0 };

			//act 
			double answer = find_line_length(pointOne, pointTwo);

			//assert
			Assert::AreEqual(answer, 1.0);
		}

		TEST_METHOD(has_duplicates_0p0And1p0And2p0And4p3_false)
		{
			POINT pointOne = { 0, 0 };
			POINT pointTwo = { 1, 0 };
			POINT pointThree = { 2, 0 };
			POINT pointFour = { 4, 3 };
			POINT pointArray[] = { pointOne, pointTwo, pointThree, pointFour };

			//act 
			bool actual = has_duplicates(pointArray, 4);

			//assert
			Assert::AreEqual(actual, false);
		}

		TEST_METHOD(has_duplicates_0p0And1p0And2p0And0p0_true)
		{
			POINT pointOne = { 0, 0 };
			POINT pointTwo = { 1, 0 };
			POINT pointThree = { 2, 0 };
			POINT pointFour = { 0, 0 };
			POINT pointArray[] = { pointOne, pointTwo, pointThree, pointFour };

			//act 
			bool actual = has_duplicates(pointArray, 4);

			//assert
			Assert::AreEqual(actual, true);
		}

		TEST_METHOD(has_duplicates_0p0And0p0And2p25And2p3_true)
		{
			POINT pointOne = { 0, 0 };
			POINT pointTwo = { 0, 0 };
			POINT pointThree = { 2, 25 };
			POINT pointFour = { 2, 3 };
			POINT pointArray[] = { pointOne, pointTwo, pointThree, pointFour };

			//act 
			bool actual = has_duplicates(pointArray, 4);

			//assert
			Assert::AreEqual(actual, true);
		}

		TEST_METHOD(has_duplicates_0p0And1p0AndNeg2pNeg25And2p25_false)
		{
			POINT pointOne = { 0, 0 };
			POINT pointTwo = { 1, 0 };
			POINT pointThree = { -2, -25 };
			POINT pointFour = { 2, 25 };
			POINT pointArray[] = { pointOne, pointTwo, pointThree, pointFour };

			//act 
			bool actual = has_duplicates(pointArray, 4);

			//assert
			Assert::AreEqual(actual, false);
		}

		TEST_METHOD(compare_point_x_0p0And0p100_0)
		{
			POINT pointOne = { 0, 0 };
			POINT pointTwo = { 0, 100 };
			
			//act 
			int actual = compare_point_x(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, 0);
		}

		TEST_METHOD(compare_point_x_1p0And0p100_1)
		{
			POINT pointOne = { 1, 0 };
			POINT pointTwo = { 0, 100 };

			//act 
			int actual = compare_point_x(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, 1);
		}

		TEST_METHOD(compare_point_x_1p0And2p100_Neg1)
		{
			POINT pointOne = { 1, 0 };
			POINT pointTwo = { 2, 100 };

			//act 
			int actual = compare_point_x(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, -1);
		}

		TEST_METHOD(compare_point_y_2p1And1p0_Neg1)
		{
			POINT pointOne = { 2, 1 };
			POINT pointTwo = { 1, 0 };

			//act 
			int actual = compare_point_y(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, -1);
		}

		TEST_METHOD(compare_point_y_2p1And1p3_1)
		{
			POINT pointOne = { 2, 1 };
			POINT pointTwo = { 1, 3 };

			//act 
			int actual = compare_point_y(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, 1);
		}

		TEST_METHOD(compare_point_y_2p1And2p3_1)
		{
			POINT pointOne = { 2, 1 };
			POINT pointTwo = { 2, 3 };

			//act 
			int actual = compare_point_y(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, 1);
		}

		TEST_METHOD(compare_point_y_2p1And2p3_Neg1)
		{
			POINT pointOne = { 2, 1 };
			POINT pointTwo = { 2, 0 };

			//act 
			int actual = compare_point_y(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, -1);
		}

		TEST_METHOD(compare_point_y_2p1And2p1_0)
		{
			POINT pointOne = { 2, 1 };
			POINT pointTwo = { 2, 1 };

			//act 
			int actual = compare_point_y(&pointOne, &pointTwo);

			//assert
			Assert::AreEqual(actual, 0);
		}
	};
}
