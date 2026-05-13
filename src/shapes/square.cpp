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

//Translation (on rajoute les coordonnes d'un point de translation)
void Square::translate(Point T){
    A.x += T.x;
    A.y += T.y;
    C.x += T.x;
    C.y += T.y;
}

//Fonction resize
void Square::resize(double ratio) {
//Trouver le centre (il ne doit pas bouger)
Point centre = center();

//Déplacer le point A par rapport au centre
A.x = centre.x + (A.x - centre.x) * ratio;
A.y = centre.y + (A.y - centre.y) * ratio;

//Déplacer le point 'C' par rapport au centre
C.x = centre.x + (C.x - centre.x) * ratio;
C.y = centre.y + (C.y - centre.y) * ratio;
}
	
void Square::rotate(double angle) {
Point centre =center();

// On pré-calcule le cosinus et le sinus de l'angle pour gagner du temps
double cosA =cos(angle);
double sinA =sin(angle);

// On calcule l'écart par rapport au centre
double dx_a = A.x - centre.x;
double dy_a = A.y - centre.y;

// Formule mathématique de la rotation 2D
A.x = centre.x + (dx_a * cosA - dy_a * sinA);
A.y = centre.y + (dx_a * sinA + dy_a * cosA);

double dx_c = C.x - centre.x;
double dy_c = C.y - centre.y;

C.x = centre.x + (dx_c * cosA - dy_c * sinA);
C.y = centre.y + (dx_c * sinA + dy_c * cosA);
}


	
bool Square::equals(Square square) {
double epsilon = 0.0001; // Marge d'erreur pour les doubles

// Comparaison des aires (Taille)
// On utilise std::abs pour gérer les petites imprécisions de calcul
bool memeAire = std::abs(area() - square.area()) < epsilon;

// Comparaison des centres (Position)
Point c1 = center();
Point c2 = square.center();
    
bool memePosition = (abs(c1.x - c2.x) < epsilon) && (abs(c1.y - c2.y) < epsilon);
//Le résultat est vrai seulement si les deux conditions sont réunies
return memeAire && memePosition;
}

Circle Square::inscribedCircle() {
    return Circle( side() / 2.0,center());
}

//Cercle circonscrit (Rayon = demi-diagonale)
Circle Square::circumscribedCircle() {
    double diag = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
    return Circle( diag / 2.0, center());
}
	
	
	
