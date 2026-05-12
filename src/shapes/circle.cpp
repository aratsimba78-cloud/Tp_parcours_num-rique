#include "point.hpp"
#include "shapes/circle.hpp"

const float pi = 3.141592;

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference() {
	return 2*radius*pi;
}