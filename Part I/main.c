// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include <stdio.h>
#include <stdlib.h>
#include "Affiche.h"
#include "Ajoute.h"
#include "Modifier.h"
#include "Recherche.h"
#include "Supprime.h"
#include "Trie.h"
#include "Utile.h"

int main(){
    // par defaul le tableu continet 0 eutdiant
    short nbretudiants = 0;
    Etudiant *tabEtudiants = (Etudiant *)malloc(sizeof(Etudiant)*nbretudiants);
    if (tabEtudiants == NULL){
        printf("Désolé, il y a un problème, essayez plus tard \n");
        exit(EXIT_FAILURE);
    }
    menu(tabEtudiants,&nbretudiants);
    free(tabEtudiants);
    return 0;
}


