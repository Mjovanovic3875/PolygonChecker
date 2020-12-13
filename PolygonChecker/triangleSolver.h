  #pragma once

#define NOT_A_TRIANGLE "Not a triangle"
#define IS_EQUILATERAL "Equilateral triangle"
#define IS_ISOSCELES  "Isosceles triangle"
#define IS_SCALENE "Scalene triangle"


typedef struct triangle TRIANGLE;

TRIANGLE* create_triangle(double sideA, double sideB, double sideC);
TRIANGLE* triangle_wizard();
void free_triangle(TRIANGLE* triangle);
void print_triangle_information(TRIANGLE* triangle);

const char* analyze_triangle(double side1, double side2, double side3);
double radians_to_degrees(double radians);
double* inside_angles_radians(double one, double two, double three);
double* inside_angles_degrees(double sideOne, double sideTwo, double sideThree);
double find_angle(double a, double b, double c);
bool is_triangle(double sideOne, double sideTwo, double sideThree);
bool is_sum_greater(int one, int two, int three);