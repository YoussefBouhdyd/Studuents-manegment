// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include <stdio.h>
#include <string.h>
#include "Affiche.h"
#include "Utile.h"
void consulter(Etudiant tabEtudiants[],short nbretudiant){
    short choix;
    printf(ANSI_COLOR_BLUE"Consultation \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("1| La liste de tous les étudiants. \n");
    printf("2| La liste des étudiants admis seulement. \n");
    printf("3| La liste des étudiants d'une filière spécifiée. \n");
    printf(ANSI_COLOR_RED"0| Quitter. \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("Choix : ");
    scanf("%hd",&choix);
    switch (choix){
    case 1:
        ConsulterTousEtud(tabEtudiants,nbretudiant);
        consulter(tabEtudiants,nbretudiant);
        break;
    case 2:
        ConsulterEtudAdmis(tabEtudiants,nbretudiant);
        consulter(tabEtudiants,nbretudiant);
        break;
    case 3:
        char filierecherch[10];
        printf("--------------------------------------------\n");
        // Effacer le tampon d'entrée
        while (getchar() != '\n');
        printf("Saisi la filiere : ");
        fgets(filierecherch,10,stdin);
        deletnewline(filierecherch);
        ConsulterEtudFiliere(tabEtudiants,nbretudiant,filierecherch);
        consulter(tabEtudiants,nbretudiant);
        break;
    case 0:
        clear();
        menu(tabEtudiants,&nbretudiant);
    default:
        printf(ANSI_COLOR_RED"Vorte choixn'est exist pas \n"ANSI_COLOR_RESET);
    }
}
void ConsulterTousEtud(Etudiant tabEtudiants[], short n){
    printf("Liste de tous les etudiants:\n");
    for(int i = 0; i < n; i++){
        afficherEtudiant(tabEtudiants[i]);
        printf("\n");
    }
}
void ConsulterEtudAdmis(Etudiant tabEtudiants[], short n){
    printf("la liste des etudiants admis est:\n");
    for(int i = 0; i < n; i++){
        if(tabEtudiants[i].moyenne >= 10){
            afficherEtudiant(tabEtudiants[i]);
            printf("\n");
        }
    }
}
void ConsulterEtudFiliere(Etudiant tabEtudiants[], short n, char filiere[]){
    short exist = 0 ;
    printf("la liste des etudiant de la filiere %s:\n", filiere);
    for(int i = 0; i < n; i++){
        if(strcmp(tabEtudiants[i].filiere.nom, filiere) == 0){
            exist++;
            afficherEtudiant(tabEtudiants[i]);
            printf("\n");
        }
        if (exist == 0) printf(ANSI_COLOR_RED"Cette filière n'exist pas !! \n"ANSI_COLOR_RESET);
    }
}