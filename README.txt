
Batice KEYSSAN, Romain MARTI, Alicia RATSIMBAZAFY, Yacine SERI



--------------------------------------------------
Description du projet :
--------------------------------------------------
Le but du projet est de créer un programme qui est capable de faire des desssins en 2D à partir de différentes formes géométriques telles que le carré, le cercle et le triangle.

--------------------------------------------------
Architecture du projet :
--------------------------------------------------

Les fichiers .hpp contiennent les déclarations :
-des classes
-des fonctions
-des attributs publics

Ils décrivent la structure du programme sans contenir l'implémentation complète.

Les fichiers concernés (les énumérer et dire rapidement ce qu'ils font) :



Les fichiers .cpp contiennent l'implémentation du programme.
Ils définissent le comportement des fonctions et des classes déclarées dans les fichiers .hpp.
Les fichiers ( donner le nom des fichiers cpp et dire précisement quels fichiers .hpp sont implémentés) :




Le fichier main.cpp contient la fonction principale main().
C'est la où se fait l'éxecution du programme.
C'est également là où les tests de chaque fonction correspondant au carré, au cercle et au triangle sont effectués.

--------------------------------------------------
Compilation:
--------------------------------------------------

g++ -std=c++23 -Iinclude -o main src/*.cpp src/shapes/*.cpp main.cpp -lgdi32 -luser32


--------------------------------------------------
Consignes:
--------------------------------------------------

