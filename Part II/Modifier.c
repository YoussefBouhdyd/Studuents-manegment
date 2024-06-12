// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Modifier.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
void modifierEtudiant() {
    // Declaration
    short exist = 0; // verifier si l'appoge saisi correspand a un etudiant
    int code; // le numero d'apogee saisie par l'utlisateur
    int i, j; // les dimension
    int choix; // la une suite des nombre reel
    printf(ANSI_COLOR_BLUE"Veuillez saisir le numero d'apogee de l'etudiant a modifier: "ANSI_COLOR_RESET);
    scanf("%d", &code);
    printf("\n");
    
    FILE *modifeidfile = NULL;
    modifeidfile = fopen("./data/modifiedfile.bin", "wb");
    if (modifeidfile != NULL) {
        FILE *file = NULL;
        file = fopen("./data/Etudiants.bin", "rb");
        if (file != NULL) {
            Etudiant etudiant;
            while (fread(&etudiant, sizeof(Etudiant), 1, file)) {
                if (etudiant.apogee == code) {
                    exist = 1;
                    printf("Voici les informations de l'etudiant avant modification:\n");
                    afficherEtudiant(etudiant);
                    printf("\nQue voulez-vous modifier?\n");
                    printf("--------------------------------------------\n");
                    printf("1| Nom\n");
                    printf("2| Prenom\n");
                    printf("3| Date d'inscription\n");
                    printf("4| Numero d'Apogee\n");
                    printf("5| Note d'un module\n");
                    printf(ANSI_COLOR_RED"0| Quitter\n"ANSI_COLOR_RESET);
                    printf("--------------------------------------------\n");
                    printf("Choix: ");
                    scanf("%d", &choix);
                    
                    switch (choix) {
                        case 1:
                            printf("Nouveau Nom: ");
                            scanf("%s", etudiant.nom);
                            break;
                        case 2:
                            printf("Nouveau Prenom: ");
                            scanf("%s", etudiant.prenom);
                            break;
                        case 3:
                            while (getchar()!= '\n');
                            do {
                                printf("Date d'inscription (jj/mm/aaaa): ");
                                fgets(etudiant.dateInscri,sizeof(etudiant.dateInscri),stdin);
                                deletnewline(etudiant.dateInscri);
                            } while (dateEstValid(etudiant.dateInscri) == '0');
                            break;
                        case 4:
                            do {
                                printf("Nouveau Numero d'Apogee: ");
                                scanf("%d", &etudiant.apogee);
                            } while (apogeeEstValid(etudiant.apogee));
                            break;
                        case 5:
                            do {
                                printf("Veuillez saisir le numero du module a modifier (1-6): ");
                                scanf("%d", &j);
                            } while ( j < 1 || j > 6);
                            printf("Nouvelle Note du module %d: ", j);
                            scanf("%f", &etudiant.filiere.tabModules[j - 1].note);
                            while (etudiant.filiere.tabModules[j - 1].note < 0  || etudiant.filiere.tabModules[j - 1].note > 20){
                                printf(ANSI_COLOR_RED"La note doit entre enter 0 et 20 \n"ANSI_COLOR_RESET);
                                printf("Nouvelle Note du module %d: ", j);
                                scanf("%f", &etudiant.filiere.tabModules[j - 1].note);
                            }
                            // Recalcul de la moyenne de la filiere
                            float somme = 0;
                            for (int k = 0; k < 6; k++) {
                                somme += etudiant.filiere.tabModules[k].note; // calculer la somme des note
                            }
                            etudiant.moyenne = somme / 6; // la mise a jour de la moyenne
                            printf("--------------------------------------------\n");
                            printf(ANSI_COLOR_GREEN"La moyenne de l'etudiant a ete mise a jour automatiquement.\n"ANSI_COLOR_RESET);
                            break;
                        case 0:
                            fwrite(&etudiant, sizeof(Etudiant), 1, modifeidfile);
                            clear();
                            break;
                        default:
                            printf(ANSI_COLOR_RED"Choix incorrect, veuillez ressayer.\n"ANSI_COLOR_RESET);
                    }
                    if (choix >= 1 && choix <= 5){
                        printf(ANSI_COLOR_GREEN"L'information d'etudianat apret la modification \n"ANSI_COLOR_RESET);
                        afficherEtudiant(etudiant);
                        fwrite(&etudiant, sizeof(Etudiant), 1, modifeidfile);
                    }
                } 
                else {
                    fwrite(&etudiant, sizeof(Etudiant), 1, modifeidfile);
                }
            }
            // Si l'etudiant n'existe pas
            fclose(file);
        } 
        else {
            printf(ANSI_COLOR_RED"Erreur lors de l'ouverture du fichier Etudiants.bin."ANSI_COLOR_RESET);
            printf("\n");
            modifierEtudiant();
        }
        fclose(modifeidfile);
    }
    else {
        printf(ANSI_COLOR_RED"Erreur lors de l'ouverture du fichier modifiedfile.bin.\n"ANSI_COLOR_RESET);
    } 
    if (exist == 0) {
        printf(ANSI_COLOR_RED"L'etudiant avec le numero d'Apogee %d n'existe pas dans la liste.\n"ANSI_COLOR_RED, code);
    } 
    else {
        #ifdef _WIN32
            system("copy modifiedfile.bin Etudiants.bin");
        #else
            system("cp ./data/modifiedfile.bin ./data/Etudiants.bin");
        #endif
    }
}