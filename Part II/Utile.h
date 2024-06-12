// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#ifndef UTILE_H
#define UTILE_H
#include "head.h"
// effacer le terminal
void clear();
// cette fonction supprime les  \n 
void deletnewline(char *string);
// cette fonction verifier si data d'inscription donnee est valid ou no
char dateEstValid(char *date);
// cette fonction verifier si l'appoge donnee est valid ou no
char apogeeEstValid(int apogee);
// affiche un etudiant
void afficherEtudiant(Etudiant etudiant);
#endif