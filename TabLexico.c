#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "TabLexico.h"

/**************************************************************************************
---------------------------------------------------------------------------------------
                            FONCTIONS TABLE LEXICO
---------------------------------------------------------------------------------------
 *************************************************************************************/


/**************************

Fonction Hashage du Cours

**************************/

int hashage(char *lexeme){
  int valeur = 0;
  int taille = strlen(lexeme);
  for(int i=0; i<taille; i++){
    valeur += lexeme[i];
    valeur = (valeur * lexeme[i]) % 32;
  }
  return valeur;
}


/*******************************************

Fonction initialisation de la table lexico

*******************************************/

void initLexico(){
  maTableLexico.compteur = 0;
  for(int i=0; i<500; i++){
    maTableLexico.donnee[i].Long = 0;
    maTableLexico.donnee[i].lexeme = NULL;
    maTableLexico.donnee[i].suivant = -1;
  }
  /* On met les types de base dans la table */
  /* INT */
  maTableLexico.donnee[0].Long = 3;
  maTableLexico.donnee[0].lexeme = strdup("int");
  maTableLexico.donnee[0].suivant = -1;
  /* FLOAT */
  maTableLexico.donnee[1].Long = 5;
  maTableLexico.donnee[1].lexeme = strdup("float");
  maTableLexico.donnee[1].suivant = -1;
  /* BOOL */
  maTableLexico.donnee[2].Long = 4;
  maTableLexico.donnee[2].lexeme = strdup("bool");
  maTableLexico.donnee[2].suivant = -1;
  /* CHAR */
  maTableLexico.donnee[3].Long = 4;
  maTableLexico.donnee[3].lexeme = strdup("char");
  maTableLexico.donnee[3].suivant = -1;
  /* Compteur = 4 */
  maTableLexico.compteur = 4;
}

/*********************************

Fonction initialisé la HashTable 

*********************************/

void initHash(){
  for(int i=0; i<32; i++){
    maTabHash[i] = -1;
  }
}

/************************************

Ajouter un Lexème a la Table Lexico

************************************/

int insererLexeme(char *lexeme){

  int tempo;
  int monHash = hashage(lexeme);

  if(presentLexeme(lexeme) != -1){
    return presentLexeme(lexeme);
  }
  else{
    if(maTableLexico.compteur != 500){

      maTableLexico.donnee[maTableLexico.compteur].Long = strlen(lexeme);
      maTableLexico.donnee[maTableLexico.compteur].lexeme = strdup(lexeme);

      if(maTabHash[monHash] == -1){
        maTabHash[monHash] = maTableLexico.compteur;
      }
      else{
        tempo = maTabHash[monHash];
        while(maTableLexico.donnee[tempo].suivant != -1){
          tempo = maTableLexico.donnee[tempo].suivant;

        }
        maTableLexico.donnee[tempo].suivant = maTableLexico.compteur;
      }
      maTableLexico.compteur++;
      return maTableLexico.compteur-1;
    }
    else{
      fprintf(stderr, "Erreur : La table lexico est pleine !\n");
      return -1;
    }
  }
}

/*************************

Afficher la Table Lexico

*************************/

void AfficheTableLexico(){
  fprintf(stdout, "\n*******************************************\n");
  fprintf(stdout, "************* TABLE LEXICO ****************\n");
  fprintf(stdout, "*******************************************\n\n");

  fprintf(stdout, "   Taille     Lexeme    Suivant\n");
  for (int i = 0; i < maTableLexico.compteur+1; i++){
    fprintf(stdout, "   ------------------------------------\n");
    fprintf(stdout, "%d        %d     %s    %d\n", i, maTableLexico.donnee[i].Long, maTableLexico.donnee[i].lexeme, maTableLexico.donnee[i].suivant);
  }
}


/*************************

Afficher la Table Hash

*************************/

void AfficheTableHash(){
  fprintf(stdout, "\n*******************************************\n");
  fprintf(stdout, "************* HASH TABLE ****************\n");
  fprintf(stdout, "*******************************************\n\n");
  for (int i = 0; i < 32; i++){
    fprintf(stdout, "   ----------------------\n");
    fprintf(stdout, "%d           %d\n", i, maTabHash[i]);
  }
}

/**************************************************

Savoir si un lexeme est déja dans la Table Lexico
Si oui on retourn son numLexico

**************************************************/

int presentLexeme(char *lexeme){
  for(int i=0; i<maTableLexico.compteur; i++){
    if(maTableLexico.donnee[i].lexeme != NULL){
      if(strcmp(maTableLexico.donnee[i].lexeme, lexeme) == 0){
        return i;
      }
    }
  }
  return -1;
}

