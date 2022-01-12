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

