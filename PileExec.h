/****************************************************************** 
                      PILE A L'EXECUTION
 *****************************************************************/

union cellule{
  int entier;
  float reel;
  char boleen;
  char caractere;
};

typedef struct{
  /*union cellule donnee[5000];*/
  int donnee[5000];
  int BC;
}pile;
  
pile maPile;


/********************

Liste des Fonctions

********************/

void initPile();
void MachineVirtuel();
void ExecuteArbre(arbre a);
void AffichePileExec();
int IndicePile(arbre a);
int EvalueArbreInt(arbre a);
void RemplirPile(int pos, int valeur);
int EvalueArbreBool(arbre a);
int EvalueArbreFonc(arbre a);
void viderBuffer();
void Enregistrer_fichier();
