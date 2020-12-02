#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "TriangleSolver.h"


#define TRIANGLE_NUMBER_OF_SIDES 3


struct triangle
{
	double sideA;
	double sideB;
	double sideC;
	char* typeOfTriangle;
	double *insideAnglesRadians;
	double *insideAngleDegrees;
};


TRIANGLE* create_triangle(double sideA, double sideB, double sideC)
{
	TRIANGLE* result = (TRIANGLE*)malloc(sizeof(TRIANGLE));

	if (result == NULL)
	{
		exit(1);
	}

	result->sideA = sideA;
	result->sideB = sideB;
	result->sideC = sideC;
	result->typeOfTriangle = analyze_triangle(result->sideA, result->sideB, result->sideC);
	result->insideAnglesRadians = inside_angles_radians(result->sideA, result->sideB, result->sideC);
	result->insideAngleDegrees = inside_angles_degrees(result->sideA, result->sideB, result->sideC);

	return result;
}


TRIANGLE* triangle_wizard()
{
	printf_s("Enter the three sides of the triangle\n");

	double sideA;
	printf("Enter the 1st side: ");
	scanf_s("%lf", &sideA);

	double sideB;
	printf("Enter the 2nd side: ");
	scanf_s("%lf", &sideB);


	double sideC;
	printf("Enter the 3rd side: ");
	scanf_s("%lf", &sideC);


	return create_triangle(sideA, sideB, sideC);
}


void free_triangle(TRIANGLE* triangle)
{
	free(triangle->insideAngleDegrees);
	free(triangle->insideAnglesRadians);
}


int get_largest_side(int sideOne, int sideTwo, int sideThree)
{
	if (sideOne > sideTwo)
	{
		if (sideOne > sideThree)
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	else
	{
		if (sideTwo > sideThree)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
}


bool is_triangle(int sideOne, int sideTwo, int sideThree)
{
	int largestSide = get_largest_side(sideOne, sideTwo, sideThree);

	if (largestSide == 1)
	{
		return (sideTwo + sideThree) > sideOne;
	}
	else if (largestSide == 2)
	{
		return (sideOne + sideThree) > sideTwo;
	}
	else
	{
		return (sideOne + sideTwo) > sideThree;
	}
}


bool is_equaliteral(int sideOne, int sideTwo, int sideThree)
{
	return (sideOne == sideTwo) && (sideOne == sideThree);
}


bool is_isosceles(int sideOne, int sideTwo, int sideThree)
{
	if (sideOne == sideTwo)
	{
		return (sideOne != sideThree);
	}
	else if (sideOne == sideThree)
	{
		// We know that sideOne != sideTwo, so triangle is isosceles
		return true;
	}
	else if (sideTwo == sideThree)
	{
		// We know that sideOne != sideTwo, so triangle is isosceles
		return true;
	}
	else
	{
		// All sides are different
		return false;
	}
}


bool is_scalene(int sideOne, int sideTwo, int sideThree)
{
	return (sideOne != sideTwo) && (sideTwo != sideThree) && (sideOne != sideThree);
}


bool is_sum_greater(int one, int two, int three) {

	int largestSide = get_largest_side(one, two, three);

	if (largestSide == 1) {
		if ((two + three) > one) {
			return true;
		}
	}
	else if (largestSide == 2) {
		if ((one + three) > two) {
			return true;
		}
	}
	else if (largestSide == 3) {
		if ((two + one) > three) {
			return true;
		}
	}
	return false;
}


// Revision history
// - Danny fixed bug
// - Emil rewrote for readability
const char* analyze_triangle(int sideOne, int sideTwo, int sideThree) {
	// Define possible returns as static constants
	// This allows us to avoid memory allocation while letting the
	// strings to persist beyond the function call
	static const char* NOT_A_TRIANGLE_RETURN = NOT_A_TRIANGLE;
	static const char* IS_EQUILATERAL_RETURN = IS_EQUILATERAL;
	static const char* IS_ISOSCELES_RETURN = IS_ISOSCELES;
	static const char* IS_SCALENE_RETURN = IS_SCALENE;


	if (!is_triangle(sideOne, sideTwo, sideThree))
	{
		return NOT_A_TRIANGLE_RETURN;
	}
	else if (is_equaliteral(sideOne, sideTwo, sideThree))
	{
		return IS_EQUILATERAL_RETURN;
	}
	else if (is_isosceles(sideOne, sideTwo, sideThree))
	{
		return IS_ISOSCELES_RETURN;
	}
	else if (is_scalene(sideOne, sideTwo, sideThree))
	{
		return IS_SCALENE_RETURN;
	}
	// The function should NOT ever go here
	// TODO: Write a nice error message
	exit(1);
}


double radians_to_degrees(double radians)
{
	return radians * ((double)180 / M_PI);
}

// Revision history
// - Emil created
double find_angle(int a, int b, int c)
{
	// b^2 + c^2 - a^2
	double numerator = pow(b, (double)2) + pow(c, (double)2) - pow(a, (double)2);
	// 2bc
	double denominator = (double)2 * (double)b * (double)c; // explicit cast upwards to avoid  overflow (hopefully)
	
	//arcos
	double angleInRadians = acos(numerator / denominator);


	return angleInRadians;
}

// Revision history
// - Emil created
double* inside_angles_radians(int sideOne, int sideTwo, int sideThree)
{
	// See https://www.calculator.net/triangle-calculator.html#:~:text=The%20interior%20angles%20of%20a,of%20interest%20from%20180%C2%B0.
	double* result = (double*)malloc(sizeof(double) * 3);

	if (result == NULL)
	{
		fprintf(stderr, "Error allocating memory for insideAngles return!\n");
		exit(1);
	}

	result[0] = find_angle(sideOne, sideTwo, sideThree);
	result[1] = find_angle(sideTwo, sideOne, sideThree);
	result[2] = find_angle(sideThree, sideOne, sideTwo);

	return result;
}


double* inside_angles_degrees(int sideOne, int sideTwo, int sideThree)
{
	double* angles_radians = inside_angles_radians(sideOne, sideTwo, sideThree);
	double* angles_degrees = (double*)malloc(sizeof(double));

	for (int i = 0; i < TRIANGLE_NUMBER_OF_SIDES; i++)
	{
		angles_degrees[i] = radians_to_degrees(angles_radians[i]);
	}
	free(angles_radians);

	return angles_degrees;
}