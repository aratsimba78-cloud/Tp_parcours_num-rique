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

void Triangle::draw(){
	std::vector<Point> points = {A,B,C,A};

    draw_picture(points);
}

void Triangle::translate(Point T){
	A.x += T.x;
	A.y += T.y;
	
	B.x += T.x;
	B.y += T.y;
	
	C.x += T.x;
	C.y += T.y;
}

void Triangle::resize(double ratio){
	Point G = center();
	A.x = G.x + ratio*(A.x - G.x);
	A.y = G.y + ratio*(A.y - G.y);
	B.x = G.x + ratio*(B.x - G.x);
	B.y = G.y + ratio*(B.y - G.y);
	C.x = G.x + ratio*(C.x - G.x);
	C.y = G.y + ratio*(C.y - G.y);
}