// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#ifndef TRIE_H
#define TRIE_H
#include "head.h"
void trie();
void TriApogee(Etudiant tabEtudiants[], short nbretudiant);
void TriMoyenne(Etudiant tabEtudiants[], short nbretudiant);
void TriDateInscription(Etudiant tabEtudiants[], short nbretudiant);
// on utlise cette fonction pout transfomer la date de form jj/mm/aaaa a aaaa/mm/jj pour trie par date d'inscription
char* nouvDateFromat(char date[]);
#endif 