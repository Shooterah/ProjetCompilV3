#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

arbre concatPereFils(arbre pere, arbre fils){

    pere->filsGauche = fils;
    return(pere);

}

arbre concatPereFrere(arbre pere, arbre frere){

    if(pere->frereDroit != NULL){
       pere->frereDroit =  concatPereFrere(pere->frereDroit, frere);
    }
    else{
        if(arbreIf){
            if(pere->nature == A_LISTE_ARG || pere->nature == A_LISTE_VAR){
                pere->filsGauche = concatPereFrere(pere->filsGauche, frere);
            }else{
                pere->frereDroit = frere;
            }
        }
        else{
            if(pere->nature == A_LISTE_INSTR || pere->nature == A_LISTE_ARG || pere->nature == A_LISTE_VAR){
                pere->filsGauche = concatPereFrere(pere->filsGauche, frere);
            }else{
                pere->frereDroit = frere;
            }
        }
    }
    return pere;
}

arbre creerNoeud(int nature, int carre1, int carre2){
	arbre a1 = (arbre) malloc(sizeof(noeud));
	a1->nature = nature;
	a1->carre1 = carre1;
    a1->carre2 = carre2;
	a1->frereDroit = NULL;
	a1->filsGauche = NULL;
    
	return(a1) ;
}

void afficher_fonction(arbre a, int profondeur){

	int i;

    /* arbre vide ? */
    if (a == NULL){
        return;
    }
  
    /* Augmente la distance entre les noeuds */
   // profondeur += 5;
    
    /* Affiche le noeuds avec avec les espaces */
    /* On compte */
    for (i = 0; i < profondeur; i++){
        printf(" ");
    }
    switch (a->nature)
    {
        case A_IDF : printf("A_IDF") ; break ;
        case A_ENTIER : printf("A_ENTIER") ; break ;
        case A_AFFECT : printf("A_AFFECT") ; break ;
        case A_PLUS : printf("A_PLUS") ; break ;
        case A_MOINS : printf("A_MOINS") ; break ;
        case A_MULT : printf("A_MULT") ; break ;
        case A_DIV : printf("A_DIV") ; break ;
        case A_CNST_ENT : printf("A_CNST_ENT") ; break ;
        case A_CNST_REE : printf("A_CNST_REE") ; break ;
        case A_CNST_CH : printf("A_CNST_CH") ; break ;
        case A_OPBIN : printf("A_OPBIN") ; break ;
        case A_AFFECTATION : printf("A_AFFECTATION") ; break ;
        case A_INSTR_COND : printf("A_INSTR_COND") ; break ;
        case A_TANT_QUE : printf("A_TANT_QUE") ; break ;
        case A_APPEL : printf("A_APPEL") ; break ;
        case A_LISTE_INSTR : printf("A_LISTE_INSTR") ; break ;
        case A_VIDE : printf("A_VIDE") ; break ;
        case A_RETURN : printf("A_RETURN") ; break ;
        case A_LIRE : printf("A_LIRE") ; break ;
        case A_ECRIRE : printf("A_ECRIRE") ; break ;
        case A_ET : printf("A_ET") ; break ;
        case A_OU : printf("A_OU") ; break ;
        case A_NON : printf("A_NON") ; break ;
        case A_INF : printf("A_INF") ; break ;
        case A_SUP : printf("A_SUP") ; break ;
        case A_INF_EGAL : printf("A_INF_EGAL") ; break ;
        case A_SUP_EGAL : printf("A_SUP_EGAL") ; break ;
        case A_EGAL : printf("A_EGAL") ; break ;
        case A_DIFF : printf("A_DIFF") ; break ;
        case A_TRUE : printf("A_TRUE") ; break ;
        case A_FALSE : printf("A_FALSE") ; break ;
        case A_APPEL_PROC : printf("A_APPEL_PROC") ; break ;
        case A_APPEL_FONC : printf("A_APPEL_FONC") ; break ;
        case A_LISTE_ARG : printf("A_LISTE_ARG") ; break ;
        case A_POINT : printf("A_POINT") ; break ;
        case A_LISTE_VAR : printf("A_LISTE_VAR") ; break ;
        case A_LISTE_FORMAT : printf("A_LISTE_FORMAT") ; break ;
        case A_FORMAT_INT : printf("A_FORMAT_INT") ; break ;
        case A_FORMAT_BOOL : printf("A_FORMAT_BOOL") ; break ;
        case A_FORMAT_FLOAT : printf("A_FORMAT_FLOAT") ; break ;
        case A_FORMAT_CHAR : printf("A_FORMAT_CHAR") ; break ;
        case A_FORMAT_STRING : printf("A_FORMAT_STRING") ; break ;
        case A_SUITE_ECRITURE : printf("A_SUITE_ECRITURE") ; break ;
        case A_TABLEAU : printf("A_TABLEAU") ; break ;
        default : printf("Je suis la et c'est pas normal"); break ;
    }
    printf("[%d][%d]                   \n",a->carre1, a->carre2);
  
    /* Affiche fils gauche*/
    afficher_fonction(a->filsGauche, profondeur+3);

    /* Affiche frere droit */
    afficher_fonction(a->frereDroit, profondeur);

}
  
/* Appelle de l'affichage */
void afficher_arbre(arbre a){
   /* On commence avec 0 espace c.a.d une profondeur de 0 */
   afficher_fonction(a, 0);
}


