// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Trie.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trie(){
    short choix;
    printf(ANSI_COLOR_BLUE"Veuiller choisir le cas de tri:"ANSI_COLOR_RESET);
    printf("\n");
    printf("--------------------------------------------\n");
    printf("1| Numero d'apogee.\n");
    printf("2| Moyenne.\n");
    printf("3| Date d'inscription.\n");
    printf(ANSI_COLOR_RED"0| Quitter. \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("Choix :");
    scanf("%hd", &choix);
    printf("--------------------------------------------\n");
    FILE *file = NULL;
    file = fopen("./data/Etudiants.bin","rb");
    if (file != NULL){
        // calcluer le nomber d'etudiants dans fichier
        fseek(file,0,SEEK_END) ;
        short nbretudiants = ftell(file) / sizeof(Etudiant);
        // remplir le tableau par l'etudiants
        Etudiant tabEtudiants[nbretudiants];
        // retourner la cursur a la debut;
        rewind(file);
        short i = 0;
        while (i < nbretudiants && fread(tabEtudiants + i,sizeof(Etudiant),1,file)) i++;
        fclose(file);
        switch (choix){
            case 1:
                TriApogee(tabEtudiants, nbretudiants);
                trie();
                break;
            case 2:
                TriMoyenne(tabEtudiants, nbretudiants);
                trie();
                break;
            case 3:
                TriDateInscription(tabEtudiants, nbretudiants);
                trie();
                break;
            case 0:
                clear();
                break;
            default:
                printf(ANSI_COLOR_RED"votre choix est incorrect.\n"ANSI_COLOR_RESET);
                trie();
                break;
        }
    }
    else {ERROR;}
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
    printf(ANSI_COLOR_BLUE"La liste des etudiant trie par numero d'apogee:\n"ANSI_COLOR_RESET);
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
    printf(ANSI_COLOR_BLUE"La liste des etudiants trie par la moyenne:\n"ANSI_COLOR_RESET);
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
            if(strcmp(nouvDateFromat(tabEtudiants[j].dateInscri), nouvDateFromat(tabEtudiants[j + 1].dateInscri)) > 0){
                AIDE = tabEtudiants[j];
                tabEtudiants[j] = tabEtudiants[j + 1];
                tabEtudiants[j + 1] = AIDE;
            }
        }
    }
    printf(ANSI_COLOR_BLUE"La liste des etudiant trie par la date d'inscription:\n"ANSI_COLOR_RESET);        
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