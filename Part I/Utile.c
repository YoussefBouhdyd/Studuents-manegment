// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Utile.h"
#include "head.h"
#include "Affiche.h"
#include "Ajoute.h"
#include "Modifier.h"
#include "Recherche.h"
#include "Supprime.h"
#include "Trie.h"
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
char apogeeEstValid(int apogee,Etudiant tabEtudiants[] , short nbretudiant){
    // verifier si l'apogee contient 7 nombers
    if ((int) (apogee / 1000000) >= 1 && (int) (apogee / 1000000) < 10 ){
        // verifier si est deja exist
        for (short i = 0 ; i < nbretudiant ; ++i)
            if (tabEtudiants[i].apogee == apogee){
                printf(ANSI_COLOR_RED"Cet apogee est deja exist ! \n"ANSI_COLOR_RESET);
                return '0';
            }
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
void menu(Etudiant *tabEtudiants,short *nbretudiant){
    int choix;
    // affiche les taches principale de programme.
    printf("--------------------------------------------\n");
    printf(ANSI_COLOR_BLUE"Center De Gestion \n" ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("1| Ajouter un ou plusieurs étudiants.\n");
    printf("2| Modifier les informations sur l'étudiant.\n");
    printf("3| Consulter.\n");
    printf("4| Trier les étudiants.\n");
    printf("5| Rechercher.\n");
    printf("6| Supprimer.\n");
    printf(ANSI_COLOR_RED "0| Quitter.\n" ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("Veuillez choisir un numéro parmi cette liste : \n");
    printf("--------------------------------------------\n");
    printf("Choix: ");
    scanf("%d",&choix);
    switch (choix){
    case 1:
        clear();
        ajoutEtudiants(tabEtudiants,nbretudiant);
        break;
    case 2:
        clear();
        modifierEtudiant(tabEtudiants , *nbretudiant);
        break;
    case 3:
        clear();
        consulter(tabEtudiants,*nbretudiant);       
        break;
    case 4:
        clear();
        trie(tabEtudiants,*nbretudiant);
        break;
    case 5:
        clear();
        rechercherEtudiant(tabEtudiants,*nbretudiant);
        break;
    case 6:
        clear();
        supprimeEtudiant(tabEtudiants,nbretudiant);
        break;
    case 0:
        clear();
        printf("*****************\n");
        printf("*");
        printf("\033[1;34m   Au revoir   \033[0m");
        printf("*\n");
        printf("*****************\n");
        exit(0);
        break;
    default:
        clear();
        printf(ANSI_COLOR_RED"Votre choix n'est pas dans la liste \n"ANSI_COLOR_RESET);
        break;
    }
    menu(tabEtudiants,nbretudiant);
}