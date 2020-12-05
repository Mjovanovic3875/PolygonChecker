#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "triangleSolver.h"

typedef struct coordinate { // this is a coordinate struct it contains x and y coordinates for up to 4 points and carries 2 side lengths
	int x[4];
	int y[5];
	int side1;
	int side2;
}COORDINATE;

COORDINATE getSquareSides(COORDINATE points); //gets user input and returned them as a coordinate struct
int getPerimiter(int x, int y); // returns the perimeter of a rectangle based on two lines
int getArea(int x, int y); //returns the area of two lines
bool isRectangle(COORDINATE* points); // determines if the given set of coordinates is a rectangle or not
