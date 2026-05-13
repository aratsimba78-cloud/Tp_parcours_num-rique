#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.hpp"
#include <math.h>
#include <vector>
#include<iostream>

const float pi = 3.141592;

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference() {
	return 2*radius*pi;
}

double Circle::area() {
	return pi*radius*radius;
}

void Circle::draw() {
	std::vector<Point> cercle;
	
	Point C,A;
	C.x = center.x - radius;
	C.y = center.y;
	
	cercle.push_back(C);
	
	for (double i = C.x ; i < center.x + radius ; ++i){
		double dx = i - center.x;
		A.y = center.y + sqrt(radius*radius - dx*dx);
		A.x = i;
		cercle.push_back(A);
	}
	
	for (double i = center.x + radius ; i >= center.x - radius ; --i){
		double dx = i - center.x;
		A.y = center.y - sqrt(radius*radius - dx*dx);
		A.x = i;
		cercle.push_back(A);
	}
	draw_picture(cercle);	
}

void Circle::translate(Point T) {
	center.x += T.x;
	center.y += T.y;
}

void Circle::resize(double ratio) {
	radius *= ratio;
}