/************************************************************************************************** 
                                          TABLE TYPE ET ENTETE 
 *************************************************************************************************/

typedef struct tabTypesEntete{
  int donnee[71];
  int compteur;
}tabTypesEntete;

/* Variable Global de la Table des déclarations */

tabTypesEntete maTabType;

/********************

Liste des Fonctions

********************/

void initTabType();
void afficheTabTypeEntete();
void insererStructTabTypesEntete(int nbChamps, int *tabChamps);
void insererTableauTabTypesEntete(int type, int nbDim, int *tabBorne);
void insererFoncTabTypesEntete(int typeRetour, int nbParam, int *tabParam);
void insererProcTabTypesEntete(int nbParam, int *tabParam);

