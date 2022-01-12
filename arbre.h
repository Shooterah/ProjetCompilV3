#define A_IDF 1
#define A_ENTIER 2
#define A_AFFECT 3
#define A_PLUS 4
#define A_MOINS 5
#define A_MULT 6
#define A_DIV 7
#define A_CNST_ENT 8
#define A_CNST_REE 9
#define A_CNST_CH 10
#define A_OPBIN 11
#define A_AFFECTATION 12
#define A_INSTR_COND 13
#define A_TANT_QUE 14
#define A_APPEL 15
#define A_LISTE_INSTR 16
#define A_VIDE 17
#define A_RETURN 18
#define A_LIRE 19
#define A_ECRIRE 20
#define A_ET 21
#define A_OU 22
#define A_NON 23
#define A_INF 24
#define A_SUP 25
#define A_INF_EGAL 26
#define A_SUP_EGAL 27
#define A_EGAL 28
#define A_DIFF 29
#define A_TRUE 30
#define A_FALSE 31
#define A_APPEL_PROC 32
#define A_APPEL_FONC 33
#define A_LISTE_ARG 34
#define A_POINT 35
#define A_LISTE_VAR 36
#define A_LISTE_FORMAT 37
#define A_FORMAT_INT 38
#define A_FORMAT_BOOL 39
#define A_FORMAT_FLOAT 40
#define A_FORMAT_CHAR 41
#define A_FORMAT_STRING 42
#define A_SUITE_ECRITURE 43
#define A_TABLEAU 44




typedef struct noeud{
	int nature;
	int carre1;  /* Les petit carré a coté du rond pour valeur ou numLexico ou numDeclaration */
	int carre2;
	struct noeud *frereDroit;
	struct noeud *filsGauche;
} noeud ;

typedef struct noeud * arbre;

int arbreIf;

arbre concatPereFils(arbre pere, arbre fils);
arbre concatPereFrere(arbre pere, arbre frere);
arbre creerNoeud(int nature, int carre1, int carre2);
void afficher_arbre(arbre a);
void afficher_fonction(arbre a, int profondeur);
