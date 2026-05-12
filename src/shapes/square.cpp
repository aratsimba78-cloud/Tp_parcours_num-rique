#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Square::Square(Point P, Point R) : A(P), C(R) {}; //Constructeur

//Calcul du coté ( coté=diagonale /racine 2)
double Square::side(){
double diagonale= sqrt(pow(C.x - A.x, 2)+ pow(C.y - A.y, 2));
return diagonale / sqrt(2.0);
}

//Calcul du perimètre
double Square::perimeter(){
	return 4*side ();
}

//Calcul de l'Aire 
double Square::area(){
	double s=side();
	return s*s;
}

//Centre du Carre (milieu du segment AC)
Point Square::center(){
	Point centre;
	centre.x=(A.x + C.x) / 2.0;
	centre.y=((A.y +C.y) / 2.0);
	return centre;
}

void Square::draw(){
Point centre= center();
	
//Calcul du pont B et D
	//On calcule l'écart entre le point A et le centre
	double dx=A.x - centre.x;
	double dy=A.y - centre.y;
	Point B,D;
	//Formule pour tourner de 90° autour du centre pour déterminer le point B
	B.x=centre.x-dy;
	B.y=centre.y+dx;
	//Formule pour tourner de -90° autour du centre pour déterminer le point D
	D.x=centre.x+dy;
	D.y=centre.y-dx;
	
//On crée un tableau sommets pour pouvoir l'injecter dans la fonction draw_picture du fichier draw.cpp
vector<Point> sommets;
sommets.push_back(A);
sommets.push_back(B);
sommets.push_back(C);
sommets.push_back(D);
sommets.push_back(A); //On ferme le carré

//On appelle la fonction
draw_picture(sommets);
}
// git add puis git commit a chaque fonction

void Square::translate(Point T){
	
}

	
	
	

	
	
	
	
	
