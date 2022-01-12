#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "TabLexico.h"
#include "TabDeclaration.h"
#include "TabType.h"

/**************************************************************************************
---------------------------------------------------------------------------------------
                         FONCTIONS TABLE TYPE ET ENTETE
---------------------------------------------------------------------------------------
 *************************************************************************************/


/************************************************************

Fonction initialisation de la table des Types et des Entêtes

************************************************************/

void initTabType(){
  maTabType.compteur = 0;
  for(int i=0; i<71; i++){
    maTabType.donnee[i] = -1;
  }
}

/************************************************************

Fonction affichage de la table des Types et des Entêtes

************************************************************/

void afficheTabTypeEntete(){

  fprintf(stdout, "\n*********************************************************************************\n");
  fprintf(stdout, "**************************** TABLE TYPE ET ENTETE ********************************\n");
  fprintf(stdout, "**********************************************************************************\n\n");

  for(int i = 0; i < 70; i++){
    fprintf(stdout, "[%d]", maTabType.donnee[i]);
  }
  fprintf(stdout, "\n");

}

/******************************************************************

Fonction inserer Structure dans la table des Types et des Entêtes

******************************************************************/

void insererStructTabTypesEntete(int nbChamps, int *tabChamps){

    /**********************************************************************
     *                          A SAVOIR
     * tabChamps contient le num lexico du champ suivi du type des champ !
    ***********************************************************************/

  int depl = 0;

  /* Nombre de champs de la structure */

  maTabType.donnee[maTabType.compteur] = nbChamps/2;
  maTabType.compteur++;

  /* Pour chaque champs : [Son num Lexico] [Son Type] [Le déplacement, à l'exécution, pour atteindre l'emplacement du champ à l'intérieur de la structure] */

  for(int i=0; i<nbChamps; i+=2){
    /* Le type */
    maTabType.donnee[maTabType.compteur] = tabChamps[i];
    maTabType.compteur++;
    /* Le num lexico du champ */
    maTabType.donnee[maTabType.compteur] = tabChamps[i+1];
    maTabType.compteur++;
    /* Le deplacement */
    maTabType.donnee[maTabType.compteur] = depl;
    depl += maTableDecl.donnee[tabChamps[i+1]].execution;
    maTabType.compteur++;
  }

}

/******************************************************************

Fonction inserer Structure dans la table des Types et des Entêtes

******************************************************************/

void insererTableauTabTypesEntete(int type, int nbDim, int *tabBorne){

    /******************************************************************************************
     *                                      A SAVOIR
     * tabBornes contient borne inférieur suivit de la borne supérieur pour chaque dimension
    ******************************************************************************************/

  /* Le Type du Tableau */

  maTabType.donnee[maTabType.compteur] = type;
  maTabType.compteur++;

  /* Nombre de Dimention du Tableau */

  maTabType.donnee[maTabType.compteur] = nbDim;
  maTabType.compteur++;

  for(int i=0; i<nbDim*2; i+=2){
    /* Borne inférieur de la Dimension i */
    maTabType.donnee[maTabType.compteur] = tabBorne[i];
    maTabType.compteur++;
    /* Borne supérieur de la Dimension i */
    maTabType.donnee[maTabType.compteur] = tabBorne[i+1];
    maTabType.compteur++;
  }
}

/******************************************************************

Fonction inserer Fonction dans la table des Types et des Entêtes

******************************************************************/

void insererFoncTabTypesEntete(int typeRetour, int nbParam, int *tabParam){

  /* Le Type de Retour */

  maTabType.donnee[maTabType.compteur] = typeRetour;
  maTabType.compteur++;

  /* Le Nombre de Paramètre */

  maTabType.donnee[maTabType.compteur] = nbParam;
  maTabType.compteur++;

  for(int i=0; i<nbParam*2; i+=2){
    /* Num Lexico du Paramètre */
    maTabType.donnee[maTabType.compteur] = tabParam[i];
    maTabType.compteur++;
    /* Type du Paramètre */
    maTabType.donnee[maTabType.compteur] = tabParam[i+1];
    maTabType.compteur++;
  }
}

/******************************************************************

Fonction inserer Procedure dans la table des Types et des Entêtes

******************************************************************/

void insererProcTabTypesEntete(int nbParam, int *tabParam){

  /* Le Nombre de Paramètre */

  maTabType.donnee[maTabType.compteur] = nbParam;
  maTabType.compteur++;

  for(int i=0; i<nbParam*2; i+=2){
    /* Num Lexico du Paramètre */
    maTabType.donnee[maTabType.compteur] = tabParam[i];
    maTabType.compteur++;
    /* Type du Paramètre */
    maTabType.donnee[maTabType.compteur] = maTableDecl.donnee[tabParam[i+1]].nature;
    maTabType.compteur++;
  }
}