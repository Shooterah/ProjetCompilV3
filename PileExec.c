#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "PileExec.h"
#include "TabRegion.h"
#include "TabDeclaration.h"
#include "TabLexico.h"
#include "TabType.h"
#include "y.tab.h"

/**************************************************************************************
---------------------------------------------------------------------------------------
                            FONCTIONS PILE A L'EXECUTION
---------------------------------------------------------------------------------------
 *************************************************************************************/

/*********************************************************
Fonction qui initialise la pile a l'éxécution
*********************************************************/

void initPile(){
    maPile.BC = 0;
}

/*******************************************************************************************
Fonction qui démarre la Machine Virtuel avec comme arbre de départ l'arbre de la région 0
*******************************************************************************************/

void MachineVirtuel(){
    ExecuteArbre(maTableRegion.donnee[0].Arbre);
}

/*******************************
Fonction qui affiche la pile
*******************************/

void AffichePileExec(){
    fprintf(stdout, "\n*************************************************\n");
    fprintf(stdout, "************* PILE A L'EXECUTION ****************\n");
    fprintf(stdout, "***********************************************\n\n");
    for(int i=500; i>=0; i--){
        fprintf(stdout, "%d\t[%d]\n", i, maPile.donnee[i]);
    }
    printf("\n\n");
}

/**************************************************************************************
Fonction qui retourne le déplacement a l'indice d'un tableau
**************************************************************************************/

int indiceTableau(arbre a, int tmp){
    int indice = 0;
    int tmpTabType;
    int deplTab = 0;
    int dim;
    arbre aTmp;

    aTmp = a->filsGauche;
    tmpTabType = maPile.BC + maTableDecl.donnee[maTabType.donnee[tmp]].description; /* Début def du tableau dans tabType */
    aTmp = aTmp->filsGauche;
    tmpTabType += 2; /* Debut définition des bornes */
    dim = maTabType.donnee[tmpTabType-1];
    if(dim > 1){ /* Si plusieurs dimentions */
        deplTab = 1;
        for(int i = 1; i < dim; i++){
            if(EvalueArbreInt(aTmp) < maTabType.donnee[tmpTabType] || EvalueArbreInt(aTmp) > maTabType.donnee[tmpTabType + 1]){
                yyerror();
                printf("Array out of bound ! : [%d..%d] avec [%d]. Indice TabType : %d\n", maTabType.donnee[tmpTabType], maTabType.donnee[tmpTabType + 1], EvalueArbreInt(aTmp), tmpTabType);
                exit(-1);
            }
            deplTab *= (EvalueArbreInt(aTmp) - maTabType.donnee[tmpTabType]) * (maTabType.donnee[tmpTabType+1] - maTabType.donnee[tmpTabType] + 1);
            tmpTabType += 2;
            aTmp = aTmp->frereDroit;
        }
        if(EvalueArbreInt(aTmp) < maTabType.donnee[tmpTabType] || EvalueArbreInt(aTmp) > maTabType.donnee[tmpTabType + 1]){
            yyerror();
            printf("Array out of bound ! : [%d..%d] avec [%d]. Indice TabType : %d\n", maTabType.donnee[tmpTabType], maTabType.donnee[tmpTabType + 1], EvalueArbreInt(aTmp), tmpTabType);
            exit(-1);
        }
        if(maTabType.donnee[tmpTabType] == EvalueArbreInt(aTmp)){
            deplTab += 0;
        }
        else{
            deplTab += (EvalueArbreInt(aTmp) - maTabType.donnee[tmpTabType]);
        }
    }
    else{ /* Une dimention */
        if(EvalueArbreInt(aTmp) < maTabType.donnee[tmpTabType] || EvalueArbreInt(aTmp) > maTabType.donnee[tmpTabType + 1]){
            yyerror();
            printf("Array out of bound ! : [%d..%d] avec [%d]. Indice TabType : %d\n", maTabType.donnee[tmpTabType], maTabType.donnee[tmpTabType + 1], EvalueArbreInt(aTmp), tmpTabType);
            exit(-1);
        }
        if(maTabType.donnee[tmpTabType] == EvalueArbreInt(aTmp)){
            deplTab += 0;
        }
        else{
            deplTab += (EvalueArbreInt(aTmp) - maTabType.donnee[tmpTabType]);
        }
    }
    return indice+deplTab;
}

/**************************************************************************************
Fonction qui retourne l'indice de la variable dans la pile
**************************************************************************************/

int IndicePile(arbre a){
    int indice = 0;
    int tmpTabType;
    int deplTab = 0;
    int dim;
    arbre aTmp;
    switch(a->nature){
        case A_POINT: /* STRUCTURE */
            aTmp = a->filsGauche;
            /* On se positione au début de la mémoire de la structure dans la pile */
            if(aTmp->nature == A_TABLEAU){
                indice = maPile.BC + maTableDecl.donnee[aTmp->filsGauche->carre2].execution;
                tmpTabType = maTableDecl.donnee[maTableDecl.donnee[aTmp->filsGauche->carre2].description].description + 1; /* Début def struct dans tabType */
            }
            else{
                indice = maPile.BC + maTableDecl.donnee[aTmp->carre2].execution;
                tmpTabType = maTableDecl.donnee[maTableDecl.donnee[aTmp->carre2].description].description + 1; /* Début def struct dans tabType */
            }
        
            while(aTmp->frereDroit != NULL){ /* Tant que on est dans une structure imbriqué (a.ch1.ch2...) */
                if(aTmp->frereDroit->nature == A_TABLEAU){ /* Si tableau */
                    while(maTabType.donnee[tmpTabType] != aTmp->frereDroit->filsGauche->carre1){ /* On cherche le bon champ de structure */
                        tmpTabType += 3;
                    }
                }
                else{
                    while(maTabType.donnee[tmpTabType] != aTmp->frereDroit->carre1){ /* On cherche le bon champ de structure */
                        tmpTabType += 3;
                    }
                }
                if(aTmp->frereDroit->nature == A_TABLEAU){ /* Si tableau */
                    indice += maTabType.donnee[tmpTabType+2];
                    indice += indiceTableau(aTmp->frereDroit, tmpTabType+1);
                }
                else{
                    indice += maTabType.donnee[tmpTabType+2];
                }
                tmpTabType = maTableDecl.donnee[maTabType.donnee[tmpTabType+1]].description + 1; /* Début def struct dans tabType */
                aTmp = aTmp->frereDroit;
            }
            return indice;
            break;
        case A_TABLEAU: /* TABLEAU */
            aTmp = a->filsGauche;
            indice = maPile.BC + maTableDecl.donnee[aTmp->carre2].execution; /* On se positione au début de la mémoire de la structure dans la pile */
            tmpTabType = maTableDecl.donnee[maTableDecl.donnee[aTmp->carre2].description].description; /* Début def du tableau dans tabType */
            aTmp = aTmp->filsGauche;
            tmpTabType += 2; /* Debut définition des bornes */
            dim = maTabType.donnee[tmpTabType-1];
            if(dim > 1){ /* Si plusieurs dimentions */
                deplTab = 1;
                for(int i = 1; i < dim; i++){
                    if(EvalueArbreInt(aTmp) < maTabType.donnee[tmpTabType] || EvalueArbreInt(aTmp) > maTabType.donnee[tmpTabType + 1]){
                        yyerror();
                        printf("Array out of bound ! : [%d..%d] avec [%d]. Indice TabType : %d\n", maTabType.donnee[tmpTabType], maTabType.donnee[tmpTabType + 1], EvalueArbreInt(aTmp), tmpTabType);
                        exit(-1);
                    }
                    deplTab *= (EvalueArbreInt(aTmp) - maTabType.donnee[tmpTabType]) * (maTabType.donnee[tmpTabType+1] - maTabType.donnee[tmpTabType] + 1);
                    tmpTabType += 2;
                    aTmp = aTmp->frereDroit;
                }
                if(EvalueArbreInt(aTmp) < maTabType.donnee[tmpTabType] || EvalueArbreInt(aTmp) > maTabType.donnee[tmpTabType + 1]){
                    yyerror();
                    printf("Array out of bound ! : [%d..%d] avec [%d]. Indice TabType : %d\n", maTabType.donnee[tmpTabType], maTabType.donnee[tmpTabType + 1], EvalueArbreInt(aTmp), tmpTabType);
                    exit(-1);
                }
                if(maTabType.donnee[tmpTabType] == EvalueArbreInt(aTmp)){
                    deplTab += 0;
                }
                else{
                    deplTab += (EvalueArbreInt(aTmp) - maTabType.donnee[tmpTabType]);
                }
            }
            else{ /* Une dimention */
                if(EvalueArbreInt(aTmp) < maTabType.donnee[tmpTabType] || EvalueArbreInt(aTmp) > maTabType.donnee[tmpTabType + 1]){
                    yyerror();
                    printf("Array out of bound ! : [%d..%d] avec [%d]. Indice TabType : %d\n", maTabType.donnee[tmpTabType], maTabType.donnee[tmpTabType + 1], EvalueArbreInt(aTmp), tmpTabType);
                    exit(-1);
                }
                if(maTabType.donnee[tmpTabType] == EvalueArbreInt(aTmp)){
                    deplTab += 0;
                }
                else{
                    deplTab += (EvalueArbreInt(aTmp) - maTabType.donnee[tmpTabType]);
                }
            }
            return indice+deplTab;
            break;
        default:
            return maPile.BC + maTableDecl.donnee[a->carre2].execution;
            break;
    }
}

/************************************************
Fonction qui retourne le résultat d'une fonction
************************************************/

int EvalueArbreFonc(arbre a){
    return 1;
}

/*****************************
Vide le buffer pour les scanf
*****************************/

void viderBuffer(){
  int c;
  while((c=getchar()) != EOF && c != '\n');
 
}

/*****************************************************************
Fonction qui calcule le résultat d'une expression et la retourne
*****************************************************************/

int EvalueArbreInt(arbre a){
    int value;
    switch(a->nature){
        case A_PLUS:
            return EvalueArbreInt(a->filsGauche) + EvalueArbreInt(a->filsGauche->frereDroit);
            break;
        case A_MOINS:
            return EvalueArbreInt(a->filsGauche) - EvalueArbreInt(a->filsGauche->frereDroit);
            break;
        case A_MULT:
            return EvalueArbreInt(a->filsGauche) * EvalueArbreInt(a->filsGauche->frereDroit);
            break;
        case A_DIV:
            if(EvalueArbreInt(a->filsGauche->frereDroit) != 0){
                return EvalueArbreInt(a->filsGauche) / EvalueArbreInt(a->filsGauche->frereDroit);
            }
            else{
                yyerror();
                printf("\nDivision par 0 ! DANGER !\n");
                exit(-1);
            }
            break;
        case A_ENTIER:
            return a->carre1;
            break;
        case A_IDF:
            return maPile.donnee[IndicePile(a)];
            break;
        case A_POINT: /* STRUCTURE */
            return maPile.donnee[IndicePile(a)];
            break;
        case A_TABLEAU: /* TABLEAU */
            return maPile.donnee[IndicePile(a)];
            break;
        case A_APPEL_FONC:
            value = EvalueArbreFonc(a);
            break;
    }
}

/*****************************************************************
Fonction qui calcule le résultat d'une opération booléenne
*****************************************************************/

int EvalueArbreBool(arbre a){
    switch(a->nature){
        case A_ET:
            if(EvalueArbreBool(a->filsGauche) != 0 && EvalueArbreBool(a->filsGauche->frereDroit) != 0){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_OU:
            if(EvalueArbreBool(a->filsGauche) != 0 || EvalueArbreBool(a->filsGauche->frereDroit) != 0){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_NON:
            if(EvalueArbreInt(a->filsGauche) != 0){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case A_INF:
            if(EvalueArbreInt(a->filsGauche) < EvalueArbreInt(a->filsGauche->frereDroit)){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_SUP:
            if(EvalueArbreInt(a->filsGauche) > EvalueArbreInt(a->filsGauche->frereDroit)){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_INF_EGAL:
            if(EvalueArbreInt(a->filsGauche) <= EvalueArbreInt(a->filsGauche->frereDroit)){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_SUP_EGAL:
            if(EvalueArbreInt(a->filsGauche) >= EvalueArbreInt(a->filsGauche->frereDroit)){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_EGAL:
            if(EvalueArbreInt(a->filsGauche) == EvalueArbreInt(a->filsGauche->frereDroit)){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_DIFF:
            if(EvalueArbreInt(a->filsGauche) != EvalueArbreInt(a->filsGauche->frereDroit)){
                return 1;
            }
            else{
                return 0;
            }
            break;
        case A_TRUE:
            return 1;
            break;
        case A_FALSE:
            return 0;
            break;
    }
}

/**************************************************************************
Fonction qui remplit la pile avec une valeur donné a un emplacement donné
**************************************************************************/

void RemplirPile(int pos, int valeur){
    maPile.donnee[pos] = valeur;
}

/**************************************************
Fonction qui lit l'abre en fonction de sa nature
**************************************************/

void ExecuteArbre(arbre a){
    int pos; 
    int valeur;
    int compteurEcrire = 0;
    arbre Acompteur;
    switch(a->nature){
        case A_AFFECT:     /* a := b */
            pos = IndicePile(a->filsGauche);
            valeur = EvalueArbreInt(a->filsGauche->frereDroit);
            RemplirPile(pos, valeur);
            break;
        case A_LISTE_INSTR:
            if(a->filsGauche != NULL){
                ExecuteArbre(a->filsGauche);
            }
            if(a->filsGauche->frereDroit != NULL){
                ExecuteArbre(a->filsGauche->frereDroit);
            }
            break;
        case A_INSTR_COND:  /* IF THEN ELSE */
            if(EvalueArbreBool(a->filsGauche)){
                ExecuteArbre(a->filsGauche->frereDroit);
            }
            else{
                ExecuteArbre(a->filsGauche->frereDroit->frereDroit);
            }
            break;
        case A_TANT_QUE:  /* WHILE */
            while(EvalueArbreBool(a->filsGauche) != 0){
                ExecuteArbre(a->filsGauche->frereDroit);
            }
            break;
        case A_APPEL_PROC:
            RemplirPile(maPile.BC + maTableRegion.donnee[maTableDecl.donnee[a->carre2].region].taille, maPile.BC);
            maPile.BC += maTableRegion.donnee[maTableDecl.donnee[a->carre2].region].taille;
            ExecuteArbre(maTableRegion.donnee[maTableDecl.donnee[a->carre2].execution].Arbre);
            break;
        case A_LIRE:      /* SCANF */
            switch(maTableDecl.donnee[a->filsGauche->filsGauche->carre2].description){
                case 0: /* INT */
                    printf("\n\n ***** Inserez un INT ***** \n\n");  
                    if(scanf("%d", &maPile.donnee[IndicePile(a->filsGauche->filsGauche)]) != 1){
                        printf("\n Erreur scanf \n");
                    }
                    break;
                case 1: /* FLOAT */
                    printf("\n\n ***** Inserez un FLOAT ***** \n\n");  
                    if(scanf("%f", &maPile.donnee[IndicePile(a->filsGauche->filsGauche)]) != 1){
                        printf("\n Erreur scanf \n");
                    }
                    break;
                case 2: /* BOOL */
                    printf("\n\n ***** Inserez un BOOL (1 ou 0) ***** \n\n");  
                    if(scanf("%d", &maPile.donnee[IndicePile(a->filsGauche->filsGauche)]) != 1){
                        printf("\n Erreur scanf \n");
                    }
                    break;
                case 3: /* CHAR */
                    printf("\n\n ***** Inserez un CHAR ***** \n\n");  
                    if(scanf("%c", &maPile.donnee[IndicePile(a->filsGauche->filsGauche)]) != 1){
                        printf("\n Erreur scanf \n");
                    }
                    break;
            }
            break;
        case A_ECRIRE:    /* PRINTF */
            Acompteur = a->filsGauche;
            if(Acompteur->filsGauche != NULL){
                Acompteur = Acompteur->filsGauche;
                compteurEcrire++;
                while(Acompteur->frereDroit != NULL){
                    compteurEcrire++;
                    Acompteur = Acompteur->frereDroit;
                }
                printf("\n\n");
                printf("****** FONCTION WRITE ******\n\n");
                Acompteur = a->filsGauche->frereDroit->filsGauche;
                for(int i=0; i<compteurEcrire; i++){
                    fprintf(stdout, "|| Valeur[%d] : %d ||\n", i+1, maPile.donnee[IndicePile(Acompteur)]);
                    Acompteur = Acompteur->frereDroit;    
                }
                printf("\n\n");
            }
            break;
    }
}


void afficher_fonction_fichier(arbre a, int profondeur,FILE * save ){

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
        fprintf(save," ");
    }
    switch (a->nature)
    {
        case A_IDF : fprintf(save,"A_IDF") ; break ;
        case A_ENTIER : fprintf(save,"A_ENTIER") ; break ;
        case A_AFFECT : fprintf(save,"A_AFFECT") ; break ;
        case A_PLUS : fprintf(save,"A_PLUS") ; break ;
        case A_MOINS : fprintf(save,"A_MOINS") ; break ;
        case A_MULT : fprintf(save,"A_MULT") ; break ;
        case A_DIV : fprintf(save,"A_DIV") ; break ;
        case A_CNST_ENT : fprintf(save,"A_CNST_ENT") ; break ;
        case A_CNST_REE : fprintf(save,"A_CNST_REE") ; break ;
        case A_CNST_CH : fprintf(save,"A_CNST_CH") ; break ;
        case A_OPBIN : fprintf(save,"A_OPBIN") ; break ;
        case A_AFFECTATION : fprintf(save,"A_AFFECTATION") ; break ;
        case A_INSTR_COND : fprintf(save,"A_INSTR_COND") ; break ;
        case A_TANT_QUE : fprintf(save,"A_TANT_QUE") ; break ;
        case A_APPEL : fprintf(save,"A_APPEL") ; break ;
        case A_LISTE_INSTR : fprintf(save,"A_LISTE_INSTR") ; break ;
        case A_VIDE : fprintf(save,"A_VIDE") ; break ;
        case A_RETURN : fprintf(save,"A_RETURN") ; break ;
        case A_LIRE : fprintf(save,"A_LIRE") ; break ;
        case A_ECRIRE : fprintf(save,"A_ECRIRE") ; break ;
        case A_ET : fprintf(save,"A_ET") ; break ;
        case A_OU : fprintf(save,"A_OU") ; break ;
        case A_NON : fprintf(save,"A_NON") ; break ;
        case A_INF : fprintf(save,"A_INF") ; break ;
        case A_SUP : fprintf(save,"A_SUP") ; break ;
        case A_INF_EGAL : fprintf(save,"A_INF_EGAL") ; break ;
        case A_SUP_EGAL : fprintf(save,"A_SUP_EGAL") ; break ;
        case A_EGAL : fprintf(save,"A_EGAL") ; break ;
        case A_DIFF : fprintf(save,"A_DIFF") ; break ;
        case A_TRUE : fprintf(save,"A_TRUE") ; break ;
        case A_FALSE : fprintf(save,"A_FALSE") ; break ;
        case A_APPEL_PROC : fprintf(save,"A_APPEL_PROC") ; break ;
        case A_APPEL_FONC : fprintf(save,"A_APPEL_FONC") ; break ;
        case A_LISTE_ARG : fprintf(save,"A_LISTE_ARG") ; break ;
        case A_POINT : fprintf(save,"A_POINT") ; break ;
        case A_LISTE_VAR : fprintf(save,"A_LISTE_VAR") ; break ;
        case A_LISTE_FORMAT : fprintf(save,"A_LISTE_FORMAT") ; break ;
        case A_FORMAT_INT : fprintf(save,"A_FORMAT_INT") ; break ;
        case A_FORMAT_BOOL : fprintf(save,"A_FORMAT_BOOL") ; break ;
        case A_FORMAT_FLOAT : fprintf(save,"A_FORMAT_FLOAT") ; break ;
        case A_FORMAT_CHAR : fprintf(save,"A_FORMAT_CHAR") ; break ;
        case A_FORMAT_STRING : fprintf(save,"A_FORMAT_STRING") ; break ;
        case A_SUITE_ECRITURE : fprintf(save,"A_SUITE_ECRITURE") ; break ;
        case A_TABLEAU : fprintf(save,"A_TABLEAU") ; break ;
        default : fprintf(save,"Je suis la et c'est pas normal"); break ;
    }
    fprintf(save,"[%d][%d]                   \n",a->carre1, a->carre2);
  
    /* Affiche fils gauche*/
    afficher_fonction_fichier(a->filsGauche, profondeur+3, save);

    /* Affiche frere droit */
    afficher_fonction_fichier(a->frereDroit, profondeur, save);

}



void Enregistrer_fichier(){

    FILE * save = fopen("save.txt", "w");
    if( save == NULL){
        printf(" erreur ouverture du fichier \n");
        exit(EXIT_FAILURE);
    }

    fprintf(save, "\n*******************************************\n");
    fprintf(save, "************* TABLE LEXICO ****************\n");
    fprintf(save, "*******************************************\n\n");

    fprintf(save, "   Taille     Lexeme    Suivant\n");
    for (int i = 0; i < maTableLexico.compteur+1; i++){
        fprintf(save, "   ------------------------------------\n");
        fprintf(save, "%d        %d     %s    %d\n", i, maTableLexico.donnee[i].Long, maTableLexico.donnee[i].lexeme, maTableLexico.donnee[i].suivant);
    }

    fprintf(save, "\n*******************************************\n");
    fprintf(save, "************* HASH TABLE ****************\n");
    fprintf(save, "*******************************************\n\n");
    for (int i = 0; i < 32; i++){
        fprintf(save, "   ----------------------\n");
        fprintf(save, "%d           %d\n", i, maTabHash[i]);
    }
    fprintf(save, "\n****************************************************************************\n");
  fprintf(save, "************************ TABLE DECLARATIONS ********************************\n");
  fprintf(save, "****************************************************************************\n\n");

  fprintf(save, "   Nature     Suivant     Région     Description     Exécution\n");
  for (int i = 0; i < maTableDecl.compteur+1; i++){
    switch(maTableDecl.donnee[i].nature){
      case 0:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_B", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 1:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_S", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 2:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_T", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 3:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "VAR", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 4:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "PARA", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 5:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "PROC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 6:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "FONC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      default:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %d         %d          %d            %d              %d\n", i, maTableDecl.donnee[i].nature, maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
    }
  }
  for (int i = 500; i < maTableDecl.compteurDebordement+1; i++){
    switch(maTableDecl.donnee[i].nature){
      case 0:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_B", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 1:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_S", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 2:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_T", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 3:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "VAR", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 4:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "PARA", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 5:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "PROC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 6:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %s         %d          %d            %d              %d\n", i, "FONC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      default:
        fprintf(save, "   ----------------------------------------------------------------------\n");
        fprintf(save, "%d    %d         %d          %d            %d              %d\n", i, maTableDecl.donnee[i].nature, maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;

    }
  }

  fprintf(save, "\n*********************************************************************************\n");
  fprintf(save, "**************************** TABLE TYPE ET ENTETE ********************************\n");
  fprintf(save, "**********************************************************************************\n\n");

  for(int i = 0; i < 70; i++){
    fprintf(save, "[%d]", maTabType.donnee[i]);
  }
  fprintf(save, "\n");

  fprintf(save, "\n*******************************************\n");
  fprintf(save, "************* TABLE REGION ****************\n");
  fprintf(save, "*******************************************\n\n");

  fprintf(save, "   Taille     NIS          Arbre\n");
  for (int i = 0; i < 20; i++){
    fprintf(save, "   ------------------------------------\n");
    fprintf(save, "%d      %d      %d            X\n", i, maTableRegion.donnee[i].taille, maTableRegion.donnee[i].NIS /*, maTableRegion.donnee[i].Arbre */);
  }
  fprintf(save, "\n");
  fprintf(save, "\n*******************************************\n");
  fprintf(save, "***************** ARBRES ******************\n");
  fprintf(save, "*******************************************\n\n");
  for (int i = 0; i < 20; i++){
      fprintf(save, "**** ARBRE REGION [%d] ****\n\n", i);
      afficher_fonction_fichier( maTableRegion.donnee[i].Arbre, 0,save );
      fprintf(save, "\n\n");
  }


  fprintf(save, "\n*************************************************\n");
    fprintf(save, "************* PILE A L'EXECUTION ****************\n");
    fprintf(save, "***********************************************\n\n");
    for(int i=500; i>=0; i--){
        fprintf(save, "%d\t[%d]\n", i, maPile.donnee[i]);
    }
    printf("\n\n");

    fclose(save);



}