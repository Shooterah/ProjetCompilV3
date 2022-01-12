#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "TabLexico.h"
#include "TabDeclaration.h"
#include "TabRegion.h"
#include "TabType.h"

/**************************************************************************************
---------------------------------------------------------------------------------------
                            FONCTIONS TABLE DECLARATION
---------------------------------------------------------------------------------------
 *************************************************************************************/


/*****************************************************

Fonction initialisation de la table des Déclarations

*****************************************************/

void initTabDecl(){
  maTableDecl.compteur = 0;
  maTableDecl.compteurDebordement = 500;
  for(int i=0; i<5000; i++){
    maTableDecl.donnee[i].nature = -1;
    maTableDecl.donnee[i].suivant = -1;
    maTableDecl.donnee[i].region = -1;
    maTableDecl.donnee[i].description = -1;
    maTableDecl.donnee[i].execution = -1;
  }
  /* On met les types de base dans la table */
  /* INT */
  maTableDecl.donnee[0].nature = 0;
  maTableDecl.donnee[0].suivant = -1;
  maTableDecl.donnee[0].region = -1;
  maTableDecl.donnee[0].description = -1;
  maTableDecl.donnee[0].execution = 1;
  /* FLOAT */
  maTableDecl.donnee[1].nature = 0;
  maTableDecl.donnee[1].suivant = -1;
  maTableDecl.donnee[1].region = -1;
  maTableDecl.donnee[1].description = -1;
  maTableDecl.donnee[1].execution = 1;
  /* BOOL */
  maTableDecl.donnee[2].nature = 0;
  maTableDecl.donnee[2].suivant = -1;
  maTableDecl.donnee[2].region = -1;
  maTableDecl.donnee[2].description = -1;
  maTableDecl.donnee[2].execution = 1;
  /* CHAR */
  maTableDecl.donnee[3].nature = 0;
  maTableDecl.donnee[3].suivant = -1;
  maTableDecl.donnee[3].region = -1;
  maTableDecl.donnee[3].description = -1;
  maTableDecl.donnee[3].execution = 1;
  /* Compteuur = 4*/
  maTableDecl.compteur = 4;
}

/*****************************************************

Fonction affichage de la table des Déclarations

*****************************************************/

void afficheTabDecl(){
  fprintf(stdout, "\n****************************************************************************\n");
  fprintf(stdout, "************************ TABLE DECLARATIONS ********************************\n");
  fprintf(stdout, "****************************************************************************\n\n");

  fprintf(stdout, "   Nature     Suivant     Région     Description     Exécution\n");
  for (int i = 0; i < maTableDecl.compteur+1; i++){
    switch(maTableDecl.donnee[i].nature){
      case 0:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_B", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 1:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_S", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 2:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_T", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 3:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "VAR", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 4:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "PARA", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 5:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "PROC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 6:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "FONC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      default:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %d         %d          %d            %d              %d\n", i, maTableDecl.donnee[i].nature, maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
    }
  }
  for (int i = 500; i < maTableDecl.compteurDebordement+1; i++){
    switch(maTableDecl.donnee[i].nature){
      case 0:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_B", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 1:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_S", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 2:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "TYPE_T", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 3:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "VAR", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 4:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "PARA", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 5:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "PROC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      case 6:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %s         %d          %d            %d              %d\n", i, "FONC", maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;
      default:
        fprintf(stdout, "   ----------------------------------------------------------------------\n");
        fprintf(stdout, "%d    %d         %d          %d            %d              %d\n", i, maTableDecl.donnee[i].nature, maTableDecl.donnee[i].suivant, maTableDecl.donnee[i].region, maTableDecl.donnee[i].description, maTableDecl.donnee[i].execution);
        break;

    }
  }
}

/*****************************************************

Fonction présence d'un léxeme dans la table Decl ?
Si oui, renvois la dernière case suivant du lexeme
Sinon renvois -1

*****************************************************/

int presentDecl(int numeroLexico){
  int cpt = numeroLexico;
  if(maTableDecl.donnee[numeroLexico].nature == -1){
    return 0;
  }
  else{
    return 1;
  }
}

/*************************************

Fonction trouver taille d'un type

**************************************/

int tailleType(int num){
  return maTableDecl.donnee[num].execution;
}

/*****************************************************

Fonction insersion dans la table des Déclarations

*****************************************************/

int insererTabDecl(int nature, int numeroLexico, int tailleStructTab, int numeroLexicoTypeVar, int nbProcFonc){

  int present = presentDecl(numeroLexico);
  int tmp;

  /* On regarde si il est déja présent */

  if(!present){
    /* Il est pas déja présent, ont le rajoute dans le même indice que la table lexico (num) */
      switch(nature){

        case DECL_TYPE_STRUCTURE: /* Si on insère une Structure */
          maTableDecl.donnee[numeroLexico].nature = nature;
          maTableDecl.donnee[numeroLexico].region = numRegion();
          maTableDecl.donnee[numeroLexico].description = maTabType.compteur;
          maTableDecl.donnee[numeroLexico].execution = tailleStructTab;
          maTableDecl.compteur = numeroLexico+1;
          return maTableDecl.compteur - 1;

        case DECL_TYPE_TABLEAU: /* Si on insère un Tableau */
          maTableDecl.donnee[numeroLexico].nature = nature;
          maTableDecl.donnee[numeroLexico].region = numRegion();
          maTableDecl.donnee[numeroLexico].description = maTabType.compteur;
          maTableDecl.donnee[numeroLexico].execution = tailleStructTab;
          maTableDecl.compteur = numeroLexico+1;
          return maTableDecl.compteur - 1;

        case DECL_VARIABLE: /* Si on insère une Variable */
          maTableDecl.donnee[numeroLexico].nature = nature;
          maTableDecl.donnee[numeroLexico].region = numRegion();
          maTableDecl.donnee[numeroLexico].description = numeroLexicoTypeVar;
          maTableDecl.donnee[numeroLexico].execution = maTableRegion.donnee[numRegion()].taille;
          maTableDecl.compteur = numeroLexico+1;
          maTableRegion.donnee[cptRegion()].taille += maTableDecl.donnee[numeroLexicoTypeVar].execution;
          return maTableDecl.compteur - 1;

        case DECL_PARAMETRE: /* Si on insère un Paramètre */
          maTableDecl.donnee[numeroLexico].nature = nature;
          maTableDecl.donnee[numeroLexico].region = numRegion();
          maTableDecl.donnee[numeroLexico].description = numeroLexicoTypeVar;
          maTableDecl.donnee[numeroLexico].execution = tailleStructTab;
          maTableDecl.compteur = numeroLexico+1;
          maTableRegion.donnee[cptRegion()].taille += maTableDecl.donnee[numeroLexicoTypeVar].execution;
          return maTableDecl.compteur - 1;

        case DECL_PROCEDURE: /* Si on insère une Procédure */
          maTableDecl.donnee[numeroLexico].nature = nature;
          maTableDecl.donnee[numeroLexico].region = numRegion();
          maTableDecl.donnee[numeroLexico].description = maTabType.compteur;
          maTableDecl.donnee[numeroLexico].execution = nbProcFonc;
          maTableDecl.compteur = numeroLexico+1;
          return maTableDecl.compteur - 1;

        case DECL_FONCTION: /* Si on insère une Fonction */
          maTableDecl.donnee[numeroLexico].nature = nature;
          maTableDecl.donnee[numeroLexico].region = numRegion();
          maTableDecl.donnee[numeroLexico].description = maTabType.compteur;
          maTableDecl.donnee[numeroLexico].execution = nbProcFonc;
          maTableDecl.compteur = numeroLexico+1;
          return maTableDecl.compteur - 1;
      }
    }
    else{
    /* Il est déja présent, ont le rajoute dans la ligne CompteurDebordement et on met le suivant de l'indice num a CompteurDebordement */
      tmp = numeroLexico;
      while(maTableDecl.donnee[tmp].suivant != -1){
        tmp = maTableDecl.donnee[tmp].suivant;
      }
      maTableDecl.donnee[tmp].suivant = maTableDecl.compteurDebordement;

      switch(nature){

        case DECL_TYPE_STRUCTURE: /* Si on insère une Structure */
          maTableDecl.donnee[maTableDecl.compteurDebordement].nature = nature;
          maTableDecl.donnee[maTableDecl.compteurDebordement].suivant = -1;
          maTableDecl.donnee[maTableDecl.compteurDebordement].region = numRegion();
          maTableDecl.donnee[maTableDecl.compteurDebordement].description = maTabType.compteur;
          maTableDecl.donnee[maTableDecl.compteurDebordement].execution = tailleStructTab;
          maTableDecl.compteurDebordement++;
          return maTableDecl.compteurDebordement - 1;

        case DECL_TYPE_TABLEAU: /* Si on insère un Tableau */
          maTableDecl.donnee[maTableDecl.compteurDebordement].nature = nature;
          maTableDecl.donnee[maTableDecl.compteurDebordement].suivant = -1;
          maTableDecl.donnee[maTableDecl.compteurDebordement].region = numRegion();
          maTableDecl.donnee[maTableDecl.compteurDebordement].description = maTabType.compteur;
          maTableDecl.donnee[maTableDecl.compteurDebordement].execution = tailleStructTab;
          maTableDecl.compteurDebordement++;
          return maTableDecl.compteurDebordement - 1;

        case DECL_VARIABLE: /* Si on insère une Variable */
          maTableDecl.donnee[maTableDecl.compteurDebordement].nature = nature;
          maTableDecl.donnee[maTableDecl.compteurDebordement].suivant = -1;
          maTableDecl.donnee[maTableDecl.compteurDebordement].region = numRegion();
          maTableDecl.donnee[maTableDecl.compteurDebordement].description = numeroLexicoTypeVar;
          maTableDecl.donnee[maTableDecl.compteurDebordement].execution = maTableRegion.donnee[numRegion()].taille;
          maTableRegion.donnee[cptRegion()].taille += maTableDecl.donnee[numeroLexicoTypeVar].execution;
          maTableDecl.compteurDebordement++;
          return maTableDecl.compteurDebordement - 1;

        case DECL_PARAMETRE: /* Si on insère un Paramètre */
          maTableDecl.donnee[maTableDecl.compteurDebordement].nature = nature;
          maTableDecl.donnee[maTableDecl.compteurDebordement].suivant = -1;
          maTableDecl.donnee[maTableDecl.compteurDebordement].region = numRegion();
          maTableDecl.donnee[maTableDecl.compteurDebordement].description = numeroLexicoTypeVar;
          maTableDecl.donnee[maTableDecl.compteurDebordement].execution = tailleStructTab;
          maTableRegion.donnee[cptRegion()].taille += maTableDecl.donnee[numeroLexicoTypeVar].execution;
          maTableDecl.compteurDebordement++;
          return maTableDecl.compteurDebordement - 1;

        case DECL_PROCEDURE: /* Si on insère une Procédure */
          maTableDecl.donnee[maTableDecl.compteurDebordement].nature = nature;
          maTableDecl.donnee[maTableDecl.compteurDebordement].suivant = -1;
          maTableDecl.donnee[maTableDecl.compteurDebordement].region = numRegion();
          maTableDecl.donnee[maTableDecl.compteurDebordement].description = maTabType.compteur;
          maTableDecl.donnee[maTableDecl.compteurDebordement].execution = nbProcFonc;
          maTableDecl.compteurDebordement++;
          return maTableDecl.compteurDebordement - 1;

        case DECL_FONCTION: /* Si on insère une Fonction */
          maTableDecl.donnee[maTableDecl.compteurDebordement].nature = nature;
          maTableDecl.donnee[maTableDecl.compteurDebordement].suivant = -1;
          maTableDecl.donnee[maTableDecl.compteurDebordement].region = numRegion();
          maTableDecl.donnee[maTableDecl.compteurDebordement].description = maTabType.compteur;
          maTableDecl.donnee[maTableDecl.compteurDebordement].execution = nbProcFonc;
          maTableDecl.compteurDebordement++;
          return maTableDecl.compteurDebordement - 1;
      }
    }
}

/****************************************

Fonction D'association de nom pour IDF

****************************************/

int associationNom(int numLexico, int nature){
  int tmp = numLexico;
  int pileCopie[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  int taille = taillePile();
  int tailleProcFonc = 20;
  copiePile(pileCopie);
  if(numLexico == 0 || numLexico == 1 || numLexico == 2 || numLexico == 3){
    return numLexico;
  }
  else{
    switch(nature){
      case DECL_PROCEDURE :
        while(tailleProcFonc >= 0){
          while(maTableDecl.donnee[tmp].suivant != -1){
            if(maTableDecl.donnee[tmp].region == tailleProcFonc && maTableDecl.donnee[tmp].nature == nature){
              return tmp;
            }
            tmp = maTableDecl.donnee[tmp].suivant;
          }
          if(maTableDecl.donnee[tmp].region == tailleProcFonc && maTableDecl.donnee[tmp].nature == nature){
              return tmp;
          }
          tmp = numLexico;
          tailleProcFonc--;
        }
        return -1;
      case DECL_FONCTION :
        while(tailleProcFonc >= 0){
          while(maTableDecl.donnee[tmp].suivant != -1){
            if(maTableDecl.donnee[tmp].region == tailleProcFonc && maTableDecl.donnee[tmp].nature == nature){
              return tmp;
            }
            tmp = maTableDecl.donnee[tmp].suivant;
          }
          if(maTableDecl.donnee[tmp].region == tailleProcFonc && maTableDecl.donnee[tmp].nature == nature){
              return tmp;
          }
          tmp = numLexico;
          tailleProcFonc--;
        }
        return -1;
      default :
        while(taille > 0){
          while(maTableDecl.donnee[tmp].suivant != -1){
            if(maTableDecl.donnee[tmp].region == pileCopie[taille-1] && maTableDecl.donnee[tmp].nature == nature){
              return tmp;
            }
            tmp = maTableDecl.donnee[tmp].suivant;
          }
          if(maTableDecl.donnee[tmp].region == pileCopie[taille-1] && maTableDecl.donnee[tmp].nature == nature){
              return tmp;
          }
          tmp = numLexico;
          taille--;
        }
        return -1;
    }
  }
}
