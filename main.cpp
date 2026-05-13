#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include "shapes/circle.hpp"
#include <vector>

#include<iostream>

int main() {
	
	Circle C1 {
		10,
		Point(0,0),
	};
	
	Point X {
		1, 1,
	};
	
	/*
	std::cout<<C1.circumference()<<std::endl;
	std::cout<<C1.area();*/
	//C1.draw();
	
	/*
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
	*/
	return 0;
}
