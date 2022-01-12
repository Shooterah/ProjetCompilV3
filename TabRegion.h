/****************************************************************** 
                            TABLE REGION 
 *****************************************************************/

typedef struct{
  int taille;
  int NIS;
  arbre Arbre;
}Region;

typedef struct tabRegion{
  int compteur;
  Region donnee[20];
}tabRegion;

/* Variable Global de la Table des déclarations */

tabRegion maTableRegion;


/********************

Liste des Fonctions

********************/

void initTabRegion();
void afficheTabRegion();
int cptRegion();
void incrementeCptRegion();
void incrementeNIS();
void empilerRegion(int num);
void depilerRegion();
void decrementeNIS();
int numRegion();
int taillePile();
void copiePile(int *copie);
int numNIS();
