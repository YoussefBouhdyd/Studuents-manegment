// Ce projet a été créé par: (AZAOUY Hassan 2130054) et (Bouhdyd Youssef 2229859)
#ifndef HEAD_H
#define HEAD_H
#pragma pack(1)
#define ERROR printf("Désolé, il y a un problème, essayez plus tard \\n");exit(EXIT_FAILURE)
#define ANSI_COLOR_RED      "\x1b[1;31m"
#define ANSI_COLOR_BLUE     "\x1b[1;34m"
#define ANSI_COLOR_GREEN    "\x1b[1;32m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_YELLOW   "\x1b[1;33m"
typedef struct Module{
    char nom[20];
    float note;
}Module;

typedef struct filiere{
    Module tabModules[6];
    char nom[10];
}Filiere;

typedef struct Etudiant{
    Filiere filiere;
    char nom[20];
    char prenom[20];
    char dateInscri[20];
    float moyenne;
    int apogee;
}Etudiant;
#endif