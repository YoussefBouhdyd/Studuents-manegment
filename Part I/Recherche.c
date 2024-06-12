// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Recherche.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rechercherEtudiant(Etudiant tabEtudiants[],short nbretudiant){
    short choix,exit = 0;
    printf("Rcherche: \n");
    printf("--------------------------------------------\n");
    printf("1| Rechercher par le nom. \n");
    printf("2| Rechercher par le prénom. \n");
    printf("3| Rechercher par le numéro apogée. \n");
    printf("--------------------------------------------\n");
    printf("Veuillez choisir un numéro parmi cette liste : \n");
    printf("--------------------------------------------\n");
    printf("Choix: ");
    scanf("%hd",&choix);
    switch (choix){
        case 1:
            char nomrecherch[20];
            // Effacer le tampon d'entrée
            while (getchar() != '\n');
            printf("Saisi le nom recherche : ");
            fgets(nomrecherch,20,stdin);
            deletnewline(nomrecherch);
            for (int i = 0 ; i < nbretudiant ; ++i ){
                if (strncmp(tabEtudiants[i].nom,nomrecherch,20) == 0){
                    afficherEtudiant(tabEtudiants[i]);
                    exit++;
                }
            }
            printf("--------------------------------------------\n");
            printf("Les resultates trouve (%d) \n",exit);
            break;
        case 2:
            char prenomrecherch[20];
            while (getchar() != '\n');
            printf("Saisi le prénom recherche : ");
            fgets(prenomrecherch,20,stdin);
            deletnewline(prenomrecherch);
            for (int i = 0 ; i < nbretudiant ; ++i ){
                if (strncmp(tabEtudiants[i].prenom,prenomrecherch,20) == 0){
                    afficherEtudiant(tabEtudiants[i]);
                    exit++;
                }
            }
            printf("--------------------------------------------\n");
            // thers is the risk in exit because the same varaibel in the two case shout fix
            printf("Les resultates trouve (%d) \n",exit);
            break;
        case 3:
            int apogeerecherch;
            while (getchar() != '\n');
            printf("Saisi l'apogée recherche : ");
            scanf("%d",&apogeerecherch);
            for (int i = 0 ; i < nbretudiant ; ++i ){
                if (tabEtudiants[i].apogee == apogeerecherch){
                    afficherEtudiant(tabEtudiants[i]);
                    exit++;
                }
            }
            printf("--------------------------------------------\n");
            // thers is the risk in exit because the same varaibel in the two case shout fix
            printf("Les resultates trouve (%d) \n",exit);
            break;            
        default:
            printf(ANSI_COLOR_RED"Votre choix n'est pas dans la liste \n"ANSI_COLOR_RESET);
            break; 
    }
}
