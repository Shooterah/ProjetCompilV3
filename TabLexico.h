/****************************************************************** 
                            TABLE LEXICO 
 *****************************************************************/

/*******************************************

Structure de la Table Lexicographique

*******************************************/

typedef struct{
  int Long;
  char *lexeme;
  int suivant;
}Lexico;

typedef struct{
  Lexico donnee[500];
  int compteur;
}tabLexico;

typedef int tabHashcode[32];

/* Variable Global de la Table Lexicographique et la Table de Hashage */

tabLexico maTableLexico;
tabHashcode maTabHash;

/********************

Liste des Fonctions

********************/

int hashage(char *lexeme);
void initLexico();
void initHash();
int insererLexeme(char *lexeme);
void afficheTableLexico();
void afficheTableHash();
int presentLexeme(char *lexeme);