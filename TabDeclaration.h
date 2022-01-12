/************************************************************************************************** 
                                        TABLE DECLARATION 
 *************************************************************************************************/

#define DECL_TYPE_STRUCTURE 1
#define DECL_TYPE_TABLEAU 2
#define DECL_VARIABLE 3
#define DECL_PARAMETRE 4
#define DECL_PROCEDURE 5
#define DECL_FONCTION 6


typedef struct{
  int nature;
  int suivant;
  int region;
  int description;
  int execution;
}Declaration;

typedef struct tabDeclaration{
  int compteur;
  int compteurDebordement;
  Declaration donnee[5000];
}tabDeclaration;

/* Variable Global de la Table des déclarations */

tabDeclaration maTableDecl;

/********************

Liste des Fonctions

********************/

void initTabDecl();
void afficheTabDecl();
int insererTabDecl(int nature, int numeroLexico, int tailleStructTab, int numeroLexicoTypeVar, int nbProcFonc);
int associationNom(int numLexico, int nature);
int presentDecl(int numLexico);
int tailleType(int num);