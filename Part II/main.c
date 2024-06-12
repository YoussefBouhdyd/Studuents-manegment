// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include <stdio.h>
#include "Affiche.h"
#include "Ajoute.h"
#include "Modifier.h"
#include "Recherche.h"
#include "Supprime.h"
#include "Trie.h"
#include "Utile.h"


int main(){
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
        ajoutEtudiants();
        break;
    case 2:
        clear();
        modifierEtudiant();
        break;
    case 3:
        clear();
        consulter();       
        break;
    case 4:
        clear();
        trie();
        break;
    case 5:
        clear();
        rechercherEtudiant();
        break;
    case 6:
        clear();
        supprimeEtudiant();
        break;
    case 0:
        clear();
        printf("*****************\n");
        printf("*");
        printf("\033[1;34m   Au revoir   \033[0m");
        printf("*\n");
        printf("*****************\n");
        return 0;
    default:
        clear();
        printf(ANSI_COLOR_RED"Votre choix n'est pas dans la liste \n"ANSI_COLOR_RESET);
    }
    main();
}


