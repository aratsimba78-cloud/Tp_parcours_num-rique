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

void Triangle::rotate(double angle){
	Point G = center();
	double cosA = cos(angle);
	double sinA = sin(angle);
	std::vector<Point> points = {A,B,C};
	for (int i = 0; i < points.size(); i++){
		double x = points.at(i).x - G.x;
		double y = points.at(i).y - G.y;
		// Calcul de la rotation relative
		double X = x * cosA - y * sinA;
		double Y = x * sinA + y * cosA;
		// Mise à jour des coordonnées dans le vecteur
		points.at(i).x = G.x + X;
		points.at(i).y = G.y + Y;
	}
	A = points.at(0);
	B = points.at(1);
	C = points.at(2);
}

bool Triangle::equals(Triangle triangle){
	return A.x == triangle.A.x && A.y == triangle.A.y &&
		B.x == triangle.B.x && B.y == triangle.B.y &&
		C.x == triangle.C.x && C.y == triangle.C.y;
}
