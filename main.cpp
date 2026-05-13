#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>

int main() {
	
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
	
	
	// Initialisation des points
	Point A(0,0);
	Point B(7,7);
	Point C(-2,-2);
	Point D(4,-1);
	Point E(-1,4);
	


	std::cout << "Test du Carré" << std::endl;

	// Initialisation des carrés
	Square no1(A,B);
	Square no2(A,C);
	Square no3(D,E);
	Square no4(E,D);
	Square no5(B,A);

	//Tests des fonctions du carré
	assert((no1.side()>6.99)&&(no1.side()<7.01));
	assert((no5.side()>6.99)&&(no5.side()<7.01));
	assert((no3.side()>4.99)&&(no3.side()<5.01));
	assert(no3.side()==no4.side());
	assert(no1.side()==no5.side());
	assert((no2.side()>1.99)&&(no2.side()<2.01));
	std::cout << "La fonction side() est OK" << std::endl;

	assert((no1.perimeter()>27.99)&&(no1.perimeter()<28.01));
	assert(no5.perimeter()==no1.perimeter());
	assert((no3.perimeter()>19.99)&&(no3.perimeter()<20.01));
	assert(no4.perimeter()==no3.perimeter());
	assert((no2.perimeter()>7.99)&&(no2.perimeter()<8.01));
	std::cout << "La fonction perimeter() est OK" << std::endl;

	assert((no1.area()>48.99)&&(no1.area()<49.01));
	assert(no5.area()==no1.area());
	assert((no3.area()>24.99)&&(no3.area()<25.01));
	assert(no4.area()==no3.area());
	assert((no2.area()>3.99)&&(no2.area()<4.01));
	std::cout << "La fonction area() est OK" << std::endl;


	Point c1 = no1.center();
	Point c5 = no5.center();
	assert((c1.x> 3.49)&&(c1.x<3.51));
	assert((c1.y>3.49)&&(c1.y<3.51));
	assert((c5.x > 3.49) && (c5.x < 3.51));
	assert((c5.y > 3.49) && (c5.y < 3.51));
	std::cout<< "La fonction center() est OK"<< std::endl;	


	assert(no1.equals(no5));   // même carré, points inversés
	assert(no3.equals(no4));   // idem

	assert(!no1.equals(no2));  // carrés différents
	assert(!no1.equals(no3));
	std::cout << "La fonction equals() est OK" << std::endl;


	// Initialisation de points supp
	Point F(4,0);
	Point G(0,3);
	Point H(10,10);
	Point I(14,14);
	Point J(10,13);
	Point K(2,4);
	Point L(-3,1);
	Point M(1,-1);
	Point N(-3,2);
	Point O(1,1);
	Point P(2,2);
	Point Q(1,0);
	Point R(0,1);
	Point S(1,2);
	Point T(5,3);
	Point U(2,7);


	std::cout<<"Test du Triangle" << std::endl ;
	// Initialisation des triangles

	Triangle nt1(A,F,G);
	Triangle nt2(H,I,J);
	Triangle nt3(A,K,F);
	Triangle nt4(L,M,N);
	Triangle nt5(A,O,P);
	Triangle nt6(A,Q,R);
	Triangle nt7(S,T,U);


	assert((nt1.perimeter()>11.99)&&(nt1.perimeter()<12.01));
	assert((nt2.perimeter()>11.99)&&(nt2.perimeter()<12.01));
	assert((nt3.perimeter()>12.93)&&(nt3.perimeter()<12.95));
	assert((nt4.perimeter()>11.99)&&(nt4.perimeter()<12.01));
	assert((nt5.perimeter()>5.63)&&(nt5.perimeter()<5.65));
	assert((nt6.perimeter()>3.40)&&(nt6.perimeter()<3.42));
	assert((nt7.perimeter()>14.21)&&(nt7.perimeter()<14.23));
	std::cout<<"La fonction perimeter() est OK" << std::endl;

	

	assert((nt1.area()>5.99)&&(nt1.area()<6.01));
	assert((nt2.area()>5.99)&&(nt2.area()<6.01));
	assert((nt3.area()>7.99)&&(nt3.area()<8.01));
	assert((nt4.area()>5.99)&&(nt4.area()<6.01));
	assert((nt5.area()>=0)&&(nt5.area()<0.01));
	assert((nt6.area()>0.49)&&(nt6.area()<0.51));
	assert((nt7.area()>9.49)&&(nt7.area()<9.51));
	std::cout<<"La fonction area() est OK" << std::endl;




	// TEST SIMPLE DES FONCTIONS VOID DE SQUARE
	Square sq(A, B);

	std::cout << "- Etat initial -" << std::endl;
	std::cout << "A: (" << sq.A.x << "," << sq.A.y << "), " << "C: (" << sq.C.x << "," << sq.C.y << ")" << std::endl;

	//Translate
	sq.translate(Point(2,3));
	std::cout << "Après translate(2,3) : " << "A: (" << sq.A.x << "," << sq.A.y << "), " << "C: (" << sq.C.x << "," << sq.C.y << ")" << std::endl;

	// Resize
	sq.resize(2.0);
	std::cout << "Après resize(2.0) : "<< "A: (" << sq.A.x << "," << sq.A.y << "), " << "C: (" << sq.C.x << "," << sq.C.y << ")" << std::endl;

	// Rotate
	sq.rotate(90); // rotation 90° autour du centre
	std::cout << "Après rotate(90°) : " << "A: (" << sq.A.x << "," << sq.A.y << "), "<< "C: (" << sq.C.x << "," << sq.C.y << ")" << std::endl;

	//Draw
	std::cout << "Appel de draw() :" << std::endl;
	sq.draw();





	// Tests center() Triangle

	Point ct1 = nt1.center();
	assert((ct1.x > 1.32) && (ct1.x < 1.34));
	assert((ct1.y > 0.99) && (ct1.y < 1.01));

	Point ct2 = nt2.center();
	assert((ct2.x > 11.32) && (ct2.x < 11.34));
	assert((ct2.y > 12.32) && (ct2.y < 12.34));

	Point ct3 = nt3.center();
	assert((ct3.x > 1.99) && (ct3.x < 2.01));
	assert((ct3.y > 1.32) && (ct3.y < 1.34));

	Point ct4 = nt4.center();
	assert((ct4.x > -1.68) && (ct4.x < -1.65));
	assert((ct4.y > 0.65) && (ct4.y < 0.68));

	Point ct5 = nt5.center();
	assert((ct5.x > 0.99) && (ct5.x < 1.01));
	assert((ct5.y > 0.99) && (ct5.y < 1.01));

	Point ct6 = nt6.center();
	assert((ct6.x > 0.32) && (ct6.x < 0.34));
	assert((ct6.y > 0.32) && (ct6.y < 0.34));

	Point ct7 = nt7.center();
	assert((ct7.x > 2.65) && (ct7.x < 2.68));
	assert((ct7.y > 3.98) && (ct7.y < 4.01));

	std::cout << "La fonction center() est OK" << std::endl;




	std::cout << "Test des booléens Triangle" << std::endl;

	// equals()

	Triangle nt1_copy(A,F,G);
	Triangle nt1_reverse(F,G,A);

	assert(nt1.equals(nt1_copy));
	assert(nt1.equals(nt1_reverse));

	assert(!nt1.equals(nt2));
	assert(!nt3.equals(nt4));

	std::cout << "La fonction equals() est OK" << std::endl;


	// isRightAngled()

	// nt1 : triangle 3-4-5 rectangle
	assert(nt1.isRightAngled());

	// nt6 : triangle rectangle isocèle
	assert(nt6.isRightAngled());

	// les autres ne le sont normalement pas
	assert(!nt2.isRightAngled());
	assert(!nt3.isRightAngled());
	assert(!nt4.isRightAngled());
	assert(!nt5.isRightAngled());
	assert(!nt7.isRightAngled());

	std::cout << "La fonction isRightAngled() est OK" << std::endl;


	// isEquilateral()
	
	// aucun de tes triangles existants n'est équilatéral
	assert(!nt1.isEquilateral());
	assert(!nt2.isEquilateral());
	assert(!nt3.isEquilateral());
	assert(!nt4.isEquilateral());
	assert(!nt5.isEquilateral());
	assert(!nt6.isEquilateral());
	assert(!nt7.isEquilateral());

	std::cout << "La fonction isEquilateral() est OK" << std::endl;


	// isIsoceles()

	// nt2 : HI = HJ
	assert(nt2.isIsoceles());

	// nt6 : triangle rectangle isocèle
	assert(nt6.isIsoceles());

	// nt5 : points alignés mais deux côtés égaux
	assert(nt5.isIsoceles());

	// les autres normalement non
	assert(!nt1.isIsoceles());
	assert(!nt3.isIsoceles());
	assert(!nt4.isIsoceles());
	assert(!nt7.isIsoceles());

	std::cout << "La fonction isIsoceles() est OK" << std::endl;






	std::cout << "Test du Circle" << std::endl;

	//Points de test

	Point V(0,0);
	Point W(1,0);
	Point X(0,1);
	Point Y(2,2);
	Point Z(-1,3);

	//Cercles
	Circle c1(1, V);   // rayon 1, centre origine
	Circle c2(2, V);   // même centre, rayon différent
	Circle c3(1, W);   // même rayon, centre différent
	Circle c4(1, V);   // identique à c1

	//area()
	assert(c1.area() > 3.13 && c1.area() < 3.15);
	assert(c2.area() > 12.56 && c2.area() < 12.58);

	std::cout << "area() OK" << std::endl;


	// circumference()

	assert(c1.circumference() > 6.27 && c1.circumference() < 6.29);
	assert(c2.circumference() > 12.56 && c2.circumference() < 12.58);

	std::cout << "circumference() OK" << std::endl;

	// equals()
	assert(c1.equals(c4));   // mêmes paramètres
	assert(!c1.equals(c2));  // rayon différent
	assert(!c1.equals(c3));  // centre différent

	std::cout << "equals() OK" << std::endl;


	//translate()

	c1.translate(Point(2,3));

	assert(c1.center.x > 1.99 && c1.center.x < 2.01);
	assert(c1.center.y > 2.99 && c1.center.y < 3.01);

	std::cout << "translate() OK" << std::endl;

	//resize()

	double old_r = c2.radius;

	c2.resize(0.5);

	assert(c2.radius > old_r * 0.49 && c2.radius < old_r * 0.51);

	std::cout << "resize() OK" << std::endl;





	return 0;
}

