#include "SquareSolver.h"


#include <math.h>

EQUILATERAL getSquareSides(EQUILATERAL points) { // retrieve user input for the 4 coordinate points
	
		printf_s("Enter the first coordinate of the square: \n");

			printf_s("\nEnter the x coordinate of the top left coordinate of the rectangle: ");
			scanf_s("%lf", &points.x[0]); 
			printf_s("Enter the y coordinate of the top left coordinate of the rectangle: ");
			scanf_s("%lf", &points.y[0]);

			printf_s("\nEnter the x coordinate of the top right coordinate of the rectangle: "); // 01 form a line
			scanf_s("%lf", &points.x[1]);
			printf_s("Enter the y coordinate of the top right coordinate of the rectangle: " );
			scanf_s("%lf", &points.y[1]);

			printf_s("\nEnter the x coordinate of the bottom left coordinate of the rectangle: "); // 0,2 form a line
			scanf_s("%lf", &points.x[2]);
			printf_s("Enter the y coordinate of the bottom left coordinate of the rectangle: ");
			scanf_s("%lf", &points.y[2]);

			printf_s("\nEnter the x coordinate of the bottom right coordinate of the rectangle: ");//1,3 forms a line
			scanf_s("%lf", &points.x[3]);
			printf_s("Enter the y coordinate of bottom right coordinate of the rectangle: "); // 2,3 form a line
			scanf_s("%lf", &points.y[3]);
		
		return points;
	
}
int getPerimiter(int x, int y) { // return the total of 4 ints
	return  (2*x + 2*y);
}
int getArea(int x, int y) { // returns the area of two lines
	return x*y;
}
bool isRectangle(EQUILATERAL* points) { // says i need to generate 4 lines but 2 lines are identical for x and y axis so shouldnt I only need 2?
	points->top_line = sqrt(pow((points->x[1] - points->x[0]),2)+pow((points->y[1] - points->y[0]),2)); // (x2 - x1) + (y2 -y1)
	points->bottom_Line = sqrt(pow((points->x[3] - points->x[2]), 2) + pow((points->y[3] - points->y[2]), 2));

	points->left_Line = sqrt(pow((points->x[2] - points->x[0]), 2) + pow((points->y[2] - points->y[0]), 2));
	points->right_line = sqrt(pow((points->x[3] - points->x[1]), 2) + pow((points->y[3] - points->y[1]), 2));

	double c;
	c = sqrt(pow((points->x[1] - points->x[2]), 2) + pow((points->y[1] - points->y[2]), 2));
	
	TRIANGLE* triangle = create_triangle((double)points->top_line,(double) points->left_Line, c);


	if (round(triangle->insideAnglesDegrees[0]) == 90 || round(triangle->insideAnglesDegrees[1]) == 90 || round(triangle->insideAnglesDegrees[2]) == 90) {
		c = sqrt(pow((points->x[0] - points->x[3]), 2) + pow((points->y[0] - points->y[3]), 2));
		triangle = create_triangle(points->left_Line, points->bottom_Line, c);

		if (round(triangle->insideAnglesDegrees[0]) == 90 || round(triangle->insideAnglesDegrees[1]) == 90 || round(triangle->insideAnglesDegrees[2]) ==90 ) {
			c = sqrt(pow((points->x[0] - points->x[3]), 2) + pow((points->y[0] - points->y[3]), 2));
			triangle = create_triangle(points->top_line, points->right_line, c);

			if (round(triangle->insideAnglesDegrees[0]) == 90 || round(triangle->insideAnglesDegrees[1]) == 90 || round(triangle->insideAnglesDegrees[2]) == 90) {
				return true;
			}
		}
	}

	return false;
}