#pragma once
# include <stdbool.h>



typedef struct coordinate {
	int x[5];
	int y[5];
}COORDINATE;

COORDINATE getSquareSides(COORDINATE);
int getPerimiter(COORDINATE);
int getArea(COORDINATE);
bool isRectangle(COORDINATE);
