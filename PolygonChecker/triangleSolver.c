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
	bool isTriangle;
	char* typeOfTriangle;
	double *insideAnglesRadians;
	double *insideAnglesDegrees;
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
	result->isTriangle = is_triangle(result->sideA, result->sideB, result->sideC);
	result->typeOfTriangle = analyze_triangle(result->sideA, result->sideB, result->sideC);

	if (result->isTriangle)
	{
		result->insideAnglesRadians = inside_angles_radians(result->sideA, result->sideB, result->sideC);
		result->insideAnglesDegrees = inside_angles_degrees(result->sideA, result->sideB, result->sideC);
	}
	else
	{
		result->insideAnglesRadians = NULL;
		result->insideAnglesDegrees = NULL;
	}
	

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
	free(triangle->insideAnglesDegrees);
	free(triangle->insideAnglesRadians);
	free(triangle);
}


void print_triangle_information(TRIANGLE* triangle)
{
	printf_s("Type of trangle: %s\n", triangle->typeOfTriangle);

	if (triangle->isTriangle)
	{
		printf_s("The inside angles are %lf, %lf, and %lf in radians\n", triangle->insideAnglesRadians[0],
																		 triangle->insideAnglesRadians[1],
																		 triangle->insideAnglesRadians[2]);
		printf("or %lf, %lf, and %lf in degrees.\n", triangle->insideAnglesDegrees[0],
													 triangle->insideAnglesDegrees[1],
													 triangle->insideAnglesDegrees[2]);
	}
}


int get_largest_side(double sideOne, double sideTwo, double sideThree)
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


bool is_triangle(double sideOne, double sideTwo, double sideThree)
{
	int largestSide = get_largest_side(sideOne, sideTwo, sideThree);

	// First, check if any of the sides are negative. If so, this is definitely not a triangle
	if ((sideOne < 0) || (sideTwo < 0) || (sideThree < 0))
	{
		return false;
	}
	else if (largestSide == 1)
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


bool is_equaliteral(double sideOne, double sideTwo, double sideThree)
{
	return (sideOne == sideTwo) && (sideOne == sideThree);
}


bool is_isosceles(double sideOne, double sideTwo, double sideThree)
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


bool is_scalene(double sideOne, double sideTwo, double sideThree)
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
const char* analyze_triangle(double sideOne, double sideTwo, double sideThree) {
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
double find_angle(double a, double b, double c)
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
double* inside_angles_radians(double sideOne, double sideTwo, double sideThree)
{
	// See https://www.calculator.net/triangle-calculator.html#:~:text=The%20interior%20angles%20of%20a,of%20interest%20from%20180%C2%B0.
	double* result = (double*)malloc(sizeof(double) * TRIANGLE_NUMBER_OF_SIDES);

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


double* inside_angles_degrees(double sideOne, double sideTwo, double sideThree)
{
	double* angles_radians = inside_angles_radians(sideOne, sideTwo, sideThree);
	double* angles_degrees = (double*)malloc(sizeof(double) * TRIANGLE_NUMBER_OF_SIDES);

	if (angles_degrees == NULL)
	{
		exit(1);
	}

	for (int i = 0; i < TRIANGLE_NUMBER_OF_SIDES; i++)
	{
		angles_degrees[i] = radians_to_degrees(angles_radians[i]);
	}
	free(angles_radians);

	return angles_degrees;
}