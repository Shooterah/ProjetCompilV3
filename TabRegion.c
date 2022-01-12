#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "TabRegion.h"

/**************************************************************************************
---------------------------------------------------------------------------------------
                            FONCTIONS TABLE DES REGIONS
---------------------------------------------------------------------------------------
 *************************************************************************************/


int NIS = 0;
int comptRegion = 0;
int pileRegion[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

/******************************************************************

Fonction initialiser la table des Régions

******************************************************************/

void initTabRegion(){
  maTableRegion.compteur;
  for(int i=0; i<20; i++){
    maTableRegion.donnee[i].taille = 0;
    maTableRegion.donnee[i].NIS = -1;
    maTableRegion.donnee[i].Arbre = NULL;
  }
}

/******************************************************************

Fonction afficher la table des Régions

******************************************************************/

void afficheTabRegion(){
  fprintf(stdout, "\n*******************************************\n");
  fprintf(stdout, "************* TABLE REGION ****************\n");
  fprintf(stdout, "*******************************************\n\n");

  fprintf(stdout, "   Taille     NIS          Arbre\n");
  for (int i = 0; i < 20; i++){
    fprintf(stdout, "   ------------------------------------\n");
    fprintf(stdout, "%d      %d      %d            X\n", i, maTableRegion.donnee[i].taille, maTableRegion.donnee[i].NIS /*, maTableRegion.donnee[i].Arbre */);
  }
  fprintf(stdout, "\n");
  fprintf(stdout, "\n*******************************************\n");
  fprintf(stdout, "***************** ARBRES ******************\n");
  fprintf(stdout, "*******************************************\n\n");
  for (int i = 0; i < 20; i++){
      fprintf(stdout, "**** ARBRE REGION [%d] ****\n\n", i);
      afficher_arbre(maTableRegion.donnee[i].Arbre);
      fprintf(stdout, "\n\n");
  }
}

/*********************************************************
Fonction qui renvois le nombre de région a l'instant t
*********************************************************/

int cptRegion(){
  return comptRegion;
}

/*********************************************************
Fonction qui incrémente le nombre de région de 1
*********************************************************/

void incrementeCptRegion(){
  comptRegion++;
}

/*********************************************************
Fonction qui incrémente le nombre NIS de 1
*********************************************************/

void incrementeNIS(){
  NIS++;
}

/*********************************************************************
Fonction qui empile le numRegion en paramètre dans la Pile des région
*********************************************************************/

void empilerRegion(int num){
  int i = 0;
  while(pileRegion[i] != -1){
    i++;
  }
  pileRegion[i] = num;
}

/***************************************
Fonction qui dépile la Pile des Region
***************************************/

void depilerRegion(){
  int i = 0;
  while(pileRegion[i] != -1){
    i++;
  }
  if(i == 0){
    return;
  }
  else{
    pileRegion[i-1] = -1;
  }
}

/***************************************
Fonction qui décrémente le numéro NIS
***************************************/

void decrementeNIS(){
  NIS--;
}

/*******************************************************
Fonction qui renvois la région actuel (Haut de la pile)
*******************************************************/

int numRegion(){
  int i=0;
  while(pileRegion[i] != -1){
    i++;
  }
  return pileRegion[i-1];
}

/*******************************************************
Fonction qui renvois le nombre de région dans la pile
*******************************************************/

int taillePile(){
  int i=0;
  while(pileRegion[i] != -1){
    i++;
  }
  return i;
}

/*******************************************************
Fonction qui copie la pile pour la parcourir
*******************************************************/

void copiePile(int *copie){
  for(int i=0; i<20; i++){
    copie[i] = pileRegion[i];
  }
}

/*******************************************************
Fonction qui renvois le NIS
*******************************************************/

int numNIS(){
  return NIS;
}