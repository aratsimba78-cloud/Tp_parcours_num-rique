#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
	double ab = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	double bc = sqrt((C.x - B.x)*(C.x - B.x) + (C.y - B.y)*(C.y - B.y));
	double ca = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y));
	
	return ab+bc+ca;
}

double Triangle::area(){
	double ab = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	double bc = sqrt((C.x - B.x)*(C.x - B.x) + (C.y - B.y)*(C.y - B.y));
	double ca = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y));
	double demiperim = perimeter()/2.0;
	return sqrt(demiperim * (demiperim - ab) * (demiperim - bc) * (demiperim - ca));
	
}

Point Triangle::center(){
	Point Grav(0,0);
	Grav.x = (C.x + B.x + A.x)/3;
	Grav.y = (C.y + B.y + A.y)/3;
	
	return Grav;
}