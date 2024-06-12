// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Ajoute.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
void ajoutEtudiants(){
    // par defaul le tableu continet 0 eutdiant
    short nbretudiants = 0;
    Etudiant *tabEtudiants = (Etudiant *)malloc(sizeof(Etudiant)*nbretudiants);
    if (tabEtudiants == NULL){
        printf("Désolé, il y a un problème, essayez plus tard \n");
        exit(EXIT_FAILURE);
    }
    printf("--------------------------------------------\n");
    printf(ANSI_COLOR_BLUE"Combien des etudiant vous voulez ajouter ? \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf(": ");
    scanf("%hd",&nbretudiants);
    clear();
    // rallouer l'espace memoire
    tabEtudiants = realloc(tabEtudiants,nbretudiants*sizeof(Etudiant));
    if (tabEtudiants == NULL){
        printf(ANSI_COLOR_RED"Désolé, il y a un problème, essayez plus tard \n"ANSI_COLOR_RESET);
        exit(EXIT_FAILURE);
    }

    // L'ajout d'etudiant.
    for (short i = 0 ; i < nbretudiants ; ++i){
        printf("--------------------------------------------\n");
        printf(ANSI_COLOR_BLUE"Etudiant [%hd] \n"ANSI_COLOR_RESET,i+1);
        printf("--------------------------------------------\n");
        while (getchar() != '\n');
        printf("Prénom : ");
        fgets(tabEtudiants[i].prenom,sizeof(tabEtudiants[i].prenom),stdin);
        deletnewline(tabEtudiants[i].prenom);
        printf("---\n");
        printf("Nom : ");
        fgets(tabEtudiants[i].nom,sizeof(tabEtudiants[i].nom),stdin);
        deletnewline(tabEtudiants[i].nom);
        printf("---\n");
        printf("Filière :");
        fgets(tabEtudiants[i].filiere.nom,sizeof(tabEtudiants[i].filiere.nom),stdin);
        deletnewline(tabEtudiants[i].filiere.nom);
        printf("---\n");
        do {
            printf("Date d'inscription (jj/mm/aaaa): ");
            fgets(tabEtudiants[i].dateInscri,sizeof(tabEtudiants[i].dateInscri),stdin);
            deletnewline(tabEtudiants[i].dateInscri);
        } while (dateEstValid(tabEtudiants[i].dateInscri) == '0');
        printf("---\n");
        do{
            printf("Numéro apogée:");
            scanf("%d",&tabEtudiants[i].apogee);
        }while (apogeeEstValid(tabEtudiants[i].apogee) == '0');
        printf("---\n");
        printf(ANSI_COLOR_BLUE"Saisi les notes des modules : \n"ANSI_COLOR_RESET);
        printf("--------------------------------------------\n");
        float somme = 0;
        for (short j = 0 ; j<6 ; ++j){
            while (getchar() != '\n');
            printf("Saisi le nom de module %hd: ",j+1);
            fgets((tabEtudiants + i)->filiere.tabModules[j].nom,20,stdin);
            printf("---\n");
            printf("Saisi la note : ");
            scanf("%f",&((tabEtudiants + i)->filiere.tabModules[j].note));
            // verifier si la note saisi est valid .
            while ((tabEtudiants + i)->filiere.tabModules[j].note < 0  || (tabEtudiants + i)->filiere.tabModules[j].note > 20){
                printf(ANSI_COLOR_RED"La note doit entre enter 0 et 20 \n"ANSI_COLOR_RESET);
                printf("Saisi la note : ");
                scanf("%f",&((tabEtudiants + i)->filiere.tabModules[j].note));
            }
            printf("---\n");
            somme += (tabEtudiants + i)->filiere.tabModules[j].note;
        }
        (tabEtudiants + i)->moyenne = somme / 6 ;
        clear();
        printf(ANSI_COLOR_GREEN"Les informations ont été ajoutées avec succès.\n"ANSI_COLOR_GREEN);
    }
    // Ajout les inforamation dans la base de donnee
    ajoutDansFichier(tabEtudiants,nbretudiants);
    // free l'espace reserver 
    free(tabEtudiants);
}
// add the content to data base functions
void ajoutDansFichier(Etudiant tabEtudiants[],short nbretudiant){
    FILE *file = NULL;
    file = fopen("./data/Etudiants.bin","ab");
    if (file != NULL){
        for (int i = 0 ; i < nbretudiant ; ++i) fwrite(tabEtudiants + i,sizeof(Etudiant),1,file);
        fclose(file);
    }
    else {ERROR;} // si il y a un promlem dans l'overture
}