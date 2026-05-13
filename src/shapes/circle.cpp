#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.hpp"
#include <math.h>
#include <vector>
#include<iostream>

const float pi = 3.141592;

Circle::Circle(double r, Point c) : radius(r), center(c) {};

//calcul le périmètre du cercle
double Circle::circumference() {
	return 2*radius*pi;
}

//calcul l'aire du cercle
double Circle::area() {
	return pi*radius*radius;
}

//dessine le cercle
void Circle::draw() {
	std::vector<Point> cercle;
	
	Point C,A;
	C.x = center.x - radius;
	C.y = center.y;
	
	cercle.push_back(C);
	
	//ajoute les points du demi-cercle supérieur dans le tableau cercle
	for (double i = C.x ; i < center.x + radius ; ++i){
		double dx = i - center.x;
		A.y = center.y + sqrt(radius*radius - dx*dx);
		A.x = i;
		cercle.push_back(A);
	}
	
	//ajoute les points du demi-cercle inférieur dans le tableau cercle
	for (double i = center.x + radius ; i >= center.x - radius ; --i){
		double dx = i - center.x;
		A.y = center.y - sqrt(radius*radius - dx*dx);
		A.x = i;
		cercle.push_back(A);
	}
	
	//dessine le cercle
	draw_picture(cercle);	
}

//Additionne les coordonnées d'un point à celles du centre du cercle
void Circle::translate(Point T) {
	center.x += T.x;
	center.y += T.y;
}

//modifie le rayon du cercle uniquement
void Circle::resize(double ratio) {
	radius *= ratio;
}

//vérifie si le cercle est égal à un autre cercle
bool Circle::equals(Circle circle) {
	return radius == circle.radius and center.x == circle.center.x and center.y == circle.center.y;
}