#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) { // any sides less then or equal to zero and not a triangle | seems correct
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) { // all three are equal its an equilateral | seems correct
		result = "Equilateral triangle";
	}
	else if (!is_Sum_Greater(side1, side2, side3)) { // must be placed after equilateral check
		result = "Not a triangle";
	}
	else if ((side1 == side2 && side1 != side3) || // was missing if side 2 and 3 are equal 
		(side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}


double findAngle(int a, int b, int c)
{
	double numerator = pow(b, (double)2) + pow(c, (double)2) - pow(a, (double)2);
	double denominator = (double)2 * (double)b * (double)c; // explicit cast upwards to avoid  overflow (hopefully)
	return acos(numerator / denominator);
}
bool is_Sum_Greater(int one, int two, int three) {

	int largest_Index = -1;
	if (one > two && one > three) {
		largest_Index = 1;
	}
	else if (two > one && two > three) {
		largest_Index = 2;
	}
	else if (three > one && three > two) {
		largest_Index = 3;
	}
	
	if (largest_Index == 1) {
		if ((two + three) > one) {
			return true;
		}
	}
	else if (largest_Index == 2) {
		if ((one + three) > two) {
			return true;
		}
	}
	else if (largest_Index == 3) {
		if ((two + one) > three) {
			return true;
		}
	}
	return false;
}

double* insideAngles(int side1, int side2, int side3)
{
	// See https://www.calculator.net/triangle-calculator.html#:~:text=The%20interior%20angles%20of%20a,of%20interest%20from%20180%C2%B0.
	double* result = (double*)malloc(sizeof(double) * 3);

	if (result == NULL)
	{
		fprintf(stderr, "Error allocating memory for insideAngles return!\n");
		exit(1);
	}

	result[0] = findAngle(side1, side2, side3);
	result[1] = findAngle(side2, side1, side3);
	result[2] = findAngle(side3, side1, side2);

	return result;
}