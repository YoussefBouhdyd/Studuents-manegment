// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Supprime.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
void supprimeEtudiant(Etudiant *tabEtudiants,short *nbretudiant){
    int deletedapogee;
    int exist = 0;
    printf("--------------------------------------------\n");
    printf(ANSI_COLOR_RED"Saisi l'apogée de l'étudiant qui voudrait supprimer \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("Apogée: ");

    scanf("%d",&deletedapogee);
    for (int i = 0 ; i < *nbretudiant ; ++i){
        if (tabEtudiants[i].apogee == deletedapogee){
            exist++;
            (*nbretudiant)--;
            for (int j = i ; j < *nbretudiant - 1 ;++j){
                tabEtudiants[j] = tabEtudiants[j+1];
            }
        }
    }
    tabEtudiants = realloc(tabEtudiants,*nbretudiant * sizeof(Etudiant));
    if (tabEtudiants == NULL && *nbretudiant!=0) {
        printf("Désolé, il y a un problème, essayez plus tard \n");
        exit(EXIT_FAILURE);
    }
    if (exist == 0) printf(ANSI_COLOR_RED"L'etudiant avec le numero d'Apogee %d n'existe pas dans la liste.\n"ANSI_COLOR_RESET, deletedapogee);
    else printf(ANSI_COLOR_GREEN"l'étudiant a été supprimé avec succès \n"ANSI_COLOR_RESET);
    menu(tabEtudiants,nbretudiant);
}