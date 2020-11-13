#include <stdio.h>
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
	else if ((side1 == side2 && side1 != side3) || // was missing if side 2 and 3 are equal 
		(side1 == side3 && side1 != side2) || (side2 == 3 && side2 != side1))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}