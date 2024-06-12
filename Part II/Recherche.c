// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Recherche.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rechercherEtudiant(){
    short choix,exist = 0;
    printf(ANSI_COLOR_BLUE"Rcherche: \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("1| Rechercher par le nom. \n");
    printf("2| Rechercher par le prénom. \n");
    printf("3| Rechercher par le numéro apogée. \n");
    printf(ANSI_COLOR_RED"0| Quitter.\n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("Veuillez choisir un numéro parmi cette liste : \n");
    printf("--------------------------------------------\n");
    printf("Choix: ");
    scanf("%hd",&choix);
    FILE *file = NULL;
    char nomrecherch[20];
    char prenomrecherch[20];
    int apogeerecherch;
    Etudiant etudiant;
    file = fopen("./data/Etudiants.bin","rb");
    if (file != NULL){
        switch (choix){
            case 1:
                // Effacer le tampon d'entrée
                while (getchar() != '\n');
                printf("Saisi le nom recherche : ");
                fgets(nomrecherch,20,stdin);
                deletnewline(nomrecherch);
                while (fread(&etudiant,sizeof(Etudiant),1,file)){
                    if (strncmp(etudiant.nom,nomrecherch,20) == 0){
                        afficherEtudiant(etudiant);
                        exist++;
                    }
                }
                printf("--------------------------------------------\n");
                exist != 0 ? printf(ANSI_COLOR_GREEN"Les resultates trouvee (%d)\n"ANSI_COLOR_RESET,exist):printf(ANSI_COLOR_RED"Les resultates trouvee (%d)\n"ANSI_COLOR_RESET,exist);
                rechercherEtudiant();
                break;
            case 2:
                while (getchar() != '\n');
                printf("Saisi le prénom recherche : ");
                fgets(prenomrecherch,20,stdin);
                deletnewline(prenomrecherch);
                while (fread(&etudiant,sizeof(Etudiant),1,file)){
                    if (strncmp(etudiant.prenom,prenomrecherch,20) == 0){
                        afficherEtudiant(etudiant);
                        exist++;
                    }
                }
                printf("--------------------------------------------\n");
                exist != 0 ? printf(ANSI_COLOR_GREEN"Les resultates trouvee (%d)\n"ANSI_COLOR_RESET,exist):printf(ANSI_COLOR_RED"Les resultates trouvee (%d)\n"ANSI_COLOR_RESET,exist);
                rechercherEtudiant();
                break;
            case 3:
                while (getchar() != '\n');
                printf("Saisi l'apogée recherche : ");
                scanf("%d",&apogeerecherch);
                while (fread(&etudiant,sizeof(Etudiant),1,file)){
                    if (etudiant.apogee == apogeerecherch){
                        afficherEtudiant(etudiant);
                        exist++;
                    }
                }
                exist != 0 ? printf(ANSI_COLOR_GREEN"Les resultates trouvee (%d)\n"ANSI_COLOR_RESET,exist):printf(ANSI_COLOR_RED"Les resultates trouvee (%d)\n"ANSI_COLOR_RESET,exist);
                printf("\n");
                rechercherEtudiant();
                break; 
            case 0:
                clear();
                break;           
            default:
                printf(ANSI_COLOR_RED"Votre choix n'est pas dans la liste \n"ANSI_COLOR_RESET);
                rechercherEtudiant();
                break; 
        }
        fclose(file);
    }
    else {ERROR;}

}
