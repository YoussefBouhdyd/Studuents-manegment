// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Utile.h"
#include "head.h"
#include <stdio.h>
#include <stdlib.h>
void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void deletnewline(char *string){
    for (char *p = string ; *p != '\0' ; p++){
        if (*p == '\n') *p = '\0' ;
    }
}
char dateEstValid(char *date){
    // define trois varible pour l'annea et mois,jour
    short j,m,a;
    if (sscanf(date,"%hd/%hd/%hd",&j,&m,&a) == 3){
        if (j >= 1 && j <= 31 && 
            m >= 1 && m <= 12 && 
            a >= 1900 && a <= 3000) {
            return '1';
        }
        else {
            printf(ANSI_COLOR_RED"La date saisie '%s' est invalide ou ne correspond pas au format (jj/mm/aaaa)."ANSI_COLOR_RESET, date);
            printf("\n");
            return '0';
        }
    }
    else {
        printf(ANSI_COLOR_RED"La date saisie '%s' est invalide ou ne correspond pas au format (jj/mm/aaaa)."ANSI_COLOR_RESET, date);
        printf("\n");
        return '0';
    }
}
char apogeeEstValid(int apogee){
    // verifier si l'apogee contient 7 nombers
    if ((int) (apogee / 1000000) >= 1 && (int) (apogee / 1000000) < 10 ){
        FILE *file = NULL ;
        file = fopen("./data/Etudiants.bin","rb+");
        Etudiant etudiant;
        if (file != NULL){
            while(fread(&etudiant,sizeof(Etudiant),1,file))
                if (etudiant.apogee == apogee) {
                    printf(ANSI_COLOR_RED"Cet apogee est deja exist ! \n"ANSI_COLOR_RESET);
                    return '0';
                }
            fclose(file);
        }
        else return '1';
    }
    else {
        printf( ANSI_COLOR_RED"L'apogge doit contient 7 chiffre \n"ANSI_COLOR_RESET);
        return '0';
    }
    return '1';
}
void afficherEtudiant(Etudiant etudiant){
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf(ANSI_COLOR_YELLOW" Nom\t\t| Prénom\t| Filière\t| Apogée\t| Date d'inscription\t| Moyenne\t\n"ANSI_COLOR_RESET);
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf(" %-10s\t| %-10s\t| %-10s\t| %-10d\t| %-20s\t| %.2f\t\n",
           etudiant.nom, etudiant.prenom,etudiant.filiere.nom, etudiant.apogee, etudiant.dateInscri, etudiant.moyenne);
    printf("------------------------------------------------------------------------------------------------------------------\n");
}