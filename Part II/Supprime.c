// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#include "Supprime.h"
#include "Utile.h"
#include <stdio.h>
#include <stdlib.h>
void supprimeEtudiant(){
    int deletedapogee;
    int exist = 0;
    printf("--------------------------------------------\n");
    printf(ANSI_COLOR_RED"Saisi l'apogée de l'étudiant qui voudrait supprimer \n"ANSI_COLOR_RESET);
    printf("--------------------------------------------\n");
    printf("Apogée: ");
    scanf("%d",&deletedapogee);   
    FILE *modifeidfile = NULL;
    modifeidfile = fopen("./data/modifiedfile.bin", "wb");
    if (modifeidfile != NULL) {
        FILE *file = NULL;
        file = fopen("./data/Etudiants.bin", "rb");
        if (file != NULL) {
            Etudiant etudiant;
            while (fread(&etudiant, sizeof(Etudiant), 1, file)) {
                if (etudiant.apogee == deletedapogee) {
                    exist = 1 ;
                    continue;
                }
                else {
                    fwrite(&etudiant, sizeof(Etudiant), 1, modifeidfile);
                }
            }
            fclose(file);
        } 
        else {
            printf(ANSI_COLOR_RED"Erreur lors de l'ouverture du fichier Etudiants.bin.\n"ANSI_COLOR_RESET);
        }
        fclose(modifeidfile);
    }
    else {
        printf(ANSI_COLOR_RED"Erreur lors de l'ouverture du fichier modifiedfile.bin.\n"ANSI_COLOR_RESET);
    } 
    // verifier si l'etudiant exist 
    if (exist == 0) {
        printf(ANSI_COLOR_RED"L'etudiant avec le numero d'Apogee %d n'existe pas dans la liste.\n"ANSI_COLOR_RESET, deletedapogee);
    } 
    else {
        printf(ANSI_COLOR_GREEN"l'étudiant a été supprimé avec succès \n"ANSI_COLOR_RESET);
        #ifdef _WIN32
            system("copy modifiedfile.bin Etudiants.bin");
        #else
            system("cp ./data/modifiedfile.bin ./data/Etudiants.bin");
        #endif
    } 
}