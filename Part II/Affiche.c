// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include <stdio.h>
#include <string.h>
#include "Affiche.h"
#include "Utile.h"
void consulter(){
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
        ConsulterTousEtud();
        consulter();
        break;
    case 2:
        ConsulterEtudAdmis();
        consulter();
        break;
    case 3:
        char filierecherch[10];
        printf("--------------------------------------------\n");
        // Effacer le tampon d'entrée
        while (getchar() != '\n');
        printf("Saisi la filiere : ");
        fgets(filierecherch,10,stdin);
        deletnewline(filierecherch);
        ConsulterEtudFiliere(filierecherch);
        consulter();
        break;
    case 0:
        clear();
        break;
    default:
        printf(ANSI_COLOR_RED"Votre choix il n'est exit pas dans la liste ! \n"ANSI_COLOR_RESET);
        consulter();
    }
}
void ConsulterTousEtud(){
    FILE *file = NULL;
    file  = fopen("./data/Etudiants.bin","rb");
    if (file != NULL){
        printf(ANSI_COLOR_BLUE"Liste de tous les etudiants:\n"ANSI_COLOR_RESET);
        Etudiant etudiant;
        while (fread(&etudiant,sizeof(Etudiant),1,file)) afficherEtudiant(etudiant);
        fclose(file);
    }
    else printf(ANSI_COLOR_RED"Les Listes sont vide \n"ANSI_COLOR_RESET);
}
void ConsulterEtudAdmis(){
    FILE *file = NULL;
    short nbradmi = 0 ;
    file  = fopen("./data/Etudiants.bin","rb");
    printf("la liste des etudiants admis est:\n");
    if (file != NULL){
        printf(ANSI_COLOR_BLUE"Liste de tous les etudiants:\n"ANSI_COLOR_RESET);
        Etudiant etudiant;
        while (fread(&etudiant,sizeof(Etudiant),1,file)){
            if(etudiant.moyenne >= 10){
                nbradmi = 1;
                afficherEtudiant(etudiant);
                printf("\n");
            }
        }
        fclose(file);
        if (nbradmi == 0 )  printf(ANSI_COLOR_RED"Il n'y exit pas un etudiant admis ! \n"ANSI_COLOR_RESET); printf("\n");
    }
    else printf(ANSI_COLOR_RED"Les Listes sont vide \n"ANSI_COLOR_RESET);
}
void ConsulterEtudFiliere(char filiere[]){
    FILE *file = NULL;
    file  = fopen("./data/Etudiants.bin","rb");
    if (file != NULL){
        printf(ANSI_COLOR_BLUE"la liste des etudiant de la filiere %s:\n"ANSI_COLOR_RESET, filiere);
        Etudiant etudiant;
        short exist = 0 ;
        while (fread(&etudiant,sizeof(Etudiant),1,file)){
            if(strcmp(etudiant.filiere.nom, filiere) == 0){
                exist = 1;
                afficherEtudiant(etudiant);
                printf("\n");
            }
        }
        if (exist == 0) {
            printf(ANSI_COLOR_RED"Cette filière n'exist pas !! \n"ANSI_COLOR_RESET);
            printf("\n");
        }
        fclose(file);
    }
    else printf(ANSI_COLOR_RED"Les Listes sont vide \n"ANSI_COLOR_RESET);
}