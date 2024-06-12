// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Trie.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trie(Etudiant tabEtudiants[],short nbretudiant){
    short choix;
    printf("veuiller choisir le cas de tri:\n");
    printf("1| Numero d'apogee\n");
    printf("2| Moyenne\n");
    printf("3| Date d'inscription\n");
    printf("--------------------------------------------\n");
    printf("Choix :");
    scanf("%hd", &choix);
    printf("--------------------------------------------\n");

    switch (choix)
    {
    case 1:
        TriApogee(tabEtudiants, nbretudiant);
        break;
    case 2:
        TriMoyenne(tabEtudiants, nbretudiant);
        break;
    case 3:
        TriDateInscription(tabEtudiants, nbretudiant);
        break;
    default:
        printf("votre choix est incorrect.\n");
        break;
    }
}
void TriApogee(Etudiant tabEtudiants[], short nbretudiant){
    //declaration
    int i, j; // des indice pour parcourir le tableau de structure
    Etudiant AIDE; // pour nous aider a la permutation
    for(i = 0; i < nbretudiant - 1; i++){
        for(j = 0; j < nbretudiant - i - 1; j++){
            if(tabEtudiants[j].apogee > tabEtudiants[j + 1].apogee){
                AIDE = tabEtudiants[j];
                tabEtudiants[j] = tabEtudiants[j + 1];
                tabEtudiants[j + 1] = AIDE;
            }
        }
    }
    printf("la liste des etudiant trie par numero d'apogee:\n");
    for(int i = 0; i < nbretudiant; i++){
        afficherEtudiant(tabEtudiants[i]);
        printf("\n");
    }
}
void TriMoyenne(Etudiant tabEtudiants[], short nbretudiant){
    int i, j; // des indice pour parcourir le tableau de structure
    Etudiant AIDE; // pour nous aider a la permutation

    for(i = 0; i < nbretudiant - 1; i++){
        for(j = 0; j < nbretudiant - i - 1; j++){
            if(tabEtudiants[j].moyenne > tabEtudiants[j + 1].moyenne){
                AIDE = tabEtudiants[j];
                tabEtudiants[j] = tabEtudiants[j + 1];
                tabEtudiants[j + 1] = AIDE;
            }
        }
    }
    printf("la liste des etudiants trie par la moyenne:\n");
    for(int i = 0; i < nbretudiant; i++){
        afficherEtudiant(tabEtudiants[i]);
        printf("\n");
    }
}
void TriDateInscription(Etudiant tabEtudiants[], short nbretudiant){

    int i, j; // des indice pour parcourir le tableau de structure
    Etudiant AIDE; // pour nous aider a la permutation
    for(i = 0; i < nbretudiant - 1; i++){
        for(j = 0; j < nbretudiant - i - 1; j++){
            if(strcmp(nouvDateFromat(tabEtudiants[j].dateInscri),nouvDateFromat( tabEtudiants[j + 1].dateInscri)) > 0){
                AIDE = tabEtudiants[j];
                tabEtudiants[j] = tabEtudiants[j + 1];
                tabEtudiants[j + 1] = AIDE;
            }
        }
    }
    printf("la liste des etudiant trie par la date d'inscription:\n");        
    for(int i = 0; i < nbretudiant; i++){
        afficherEtudiant(tabEtudiants[i]);
        printf("\n");
    }
}
char* nouvDateFromat(char date[]){
    int jour,mois,annee;
    sscanf(date,"%d/%d/%d",&jour,&mois,&annee);
    char* nouveauForma = (char*)malloc(11);
    sprintf(nouveauForma, "%d/%02d/%02d", annee, mois, jour);
    return nouveauForma;
}