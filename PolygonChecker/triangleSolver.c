/*
Week 14 Program 1 Assignment : Polygon Checker Group Assignment
Danny A. Smith, Emil Harvey, Milan Jovanovic
PROG71985- Fall 2020
December 2020

Revision History

1.0	NOVEMBER	 Files Created
1.1	NOVEMBER	 Triangle solver updated
1.2	NOVEMBER	 Inside angles functions completed
1.3	DECEMBER	 Tests written and triangle solver refactored
1.4	DECEMBER	 Get points from user function completed
1.5	December	 Get sides from points function completed
1.6	DECEMBER	 Refactored rectangle Checker
1.7	DECEMBER	 Refactored function names
1.8	DECEMBER	 Tests broken down into classes

Program Description :  
	This program is designed to check shapes. It can currently take in triangle lines and determin the type of triangle and angles. It can also
	take in rectangle coordinates and decide if it is a rectangle or not. Future upgradability extends to checking other polygons.
*/



#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "TriangleSolver.h"


TRIANGLE create_triangle(double sideA, double sideB, double sideC)
{
	TRIANGLE result;

	result.sideA = sideA;
	result.sideB = sideB;
	result.sideC = sideC;
	result.isTriangle = is_triangle(result.sideA, result.sideB, result.sideC);
	result.typeOfTriangle = analyze_triangle(result.sideA, result.sideB, result.sideC);

	if (result.isTriangle)
	{
		result.angleA = find_angle(result.sideA, result.sideB, result.sideC);
		result.angleB = find_angle(result.sideB, result.sideA, result.sideC);
		result.angleC = find_angle(result.sideC, result.sideA, result.sideB);
	}

	return result;
}


TRIANGLE triangle_wizard()
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


void print_triangle_information(TRIANGLE triangle)
{
	printf_s("Type of trangle: %s\n", triangle.typeOfTriangle);

	if (triangle.isTriangle)
	{
		printf_s("The inside angles are %lf, %lf, and %lf in radians\n", triangle.angleA,
																		 triangle.angleB,
																		 triangle.angleC);
		printf("or %lf, %lf, and %lf in degrees.\n", radians_to_degrees(triangle.angleA),
													 radians_to_degrees(triangle.angleB),
													 radians_to_degrees(triangle.angleC));
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
	} // Otherwise, a triangle must have its largest side smaller than the sum of the remainig sides
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
	fprintf(stderr, "Error in conditional in analyze_triangle!\n");
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