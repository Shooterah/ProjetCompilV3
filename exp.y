

/*******************************************************************************************
                                        DECLARATIONS
*******************************************************************************************/


%{
#include <stdio.h>
#include <string.h>
#include "arbre.h"
#include "TabLexico.h"
#include "TabDeclaration.h"
#include "TabRegion.h"
#include "TabType.h"
#include "PileExec.h"

int yylex();
int yyerror();

extern FILE *yyin;
extern int Num_Ligne;

int verbal;
int tmpTypeVar;
int struc = 0;
int tabStruc = 0;
int tailleStructTab;
int tailleDimension;
int valExpression;
int valInt;
int valGauche;
int nbProcFonc;
int listeChamps[50];
int tabBorne[50];
int nbChamps;
int tmpTypeTab;
int nbDim;
int tmpBorne;
int nbParam;
int listeParam[50];
int tmpRetour;
int numLexico;
arbre tmp;

%}


/*******************************************************************************************
                                        UNION DES TYPES
*******************************************************************************************/


%union{
   arbre type1;
   int type2;
}


/*******************************************************************************************
                                        TOKEN CALCULS
*******************************************************************************************/


%token OPAFF EGAL

/* Opérateurs définis par ordrede priorité */

%left PLUS MOINS
%left MULT DIV
%left ET OU EXCLA
%right PO PF


/*******************************************************************************************
                                        TOKEN INSTRUCTION
*******************************************************************************************/


%token IF WHILE SWITCH FOR CASE VOID MAIN DEBUT FIN PROCEDURE FONCTION VIDE THEN APPEL ENDIF DO DEFINE STRUCT TYPE PROG FSTRUCT TABLEAU VARIABLE ELSE EXIT RETURN READ WRITE


/*******************************************************************************************
                                        TOKEN FORMAT
*******************************************************************************************/


%token FINT FBOOL FFLOAT FCHAR FSTRING


/*******************************************************************************************
                                        TOKEN PONCTUATION
*******************************************************************************************/


%token INCLUDE PETIT GRAND HASH VIRGULE PETIT_EQ GRAND_EQ PV TRUE FALSE DIFF ACO ACF CROO CROF GUI DE PO PF DEUX_POINTS POINT POINT_POINT


/*******************************************************************************************
                                        TOKEN TYPE SIMPLE
*******************************************************************************************/

%token INT FLOAT CHAR BOOL STRING


/*******************************************************************************************
                                TOKEN ET TYPE INTEGER ET ARBRE
*******************************************************************************************/


%token <type2> ENTIER IDF

%type <type1> programme corps liste_declarations liste_instructions suite_liste_inst declaration declaration_type suite_declaration_type dimension liste_dimensions une_dimension liste_champs un_champ nom_type type_simple declaration_variable declaration_procedure declaration_fonction liste_parametres liste_param un_param instruction appel liste_arguments liste_args un_arg condition tant_que affectation variable var_tab val_tab expression ea1 ea2 ea3 eb1 eb2 eb3 eb4 lire liste_variables ecrire format liste_format suite_ecriture

%type <type2> resultat_retourne


/*******************************************************************************************
********************************************************************************************
                                            GRAMMAIRE
********************************************************************************************
*******************************************************************************************/



%%


/*******************************************************************************************
Le programme cpyrr : débute par "PROG"
                     suivis d'un "corps"

A la fin : Affiche les tables
*******************************************************************************************/


programme : PROG {nbProcFonc = 0; empilerRegion(cptRegion());} corps 
            {
                if(verbal){
                    AfficheTableLexico(); AfficheTableHash(); afficheTabDecl(); afficheTabTypeEntete(); afficheTabRegion(); MachineVirtuel(); AffichePileExec();Enregistrer_fichier();
                }
                else{
                    MachineVirtuel();
                    Enregistrer_fichier();
                }
            }
          ;


/*******************************************************************************************
Le corps  est constitué de : Une liste de déclaration suivis d'une liste d'instruction
                             Ou une liste d'instruction seule
*******************************************************************************************/


corps : liste_declarations liste_instructions           {maTableRegion.donnee[numRegion()].Arbre = $2; maTableRegion.donnee[numRegion()].NIS = numNIS();} 
      | liste_instructions                              {maTableRegion.donnee[numRegion()].Arbre = $1; maTableRegion.donnee[numRegion()].NIS = numNIS();} 
      ;


/*******************************************************************************************
Une liste de déclaration : Contient une déclaration suivie d'un point virgule
                           Ou contient plusieur déclarations suivies de points virgule
*******************************************************************************************/


liste_declarations : declaration PV
                   | liste_declarations declaration PV
                   ;


/*******************************************************************************************
Liste d'instruction : Commence par "DEBUT" suivi d'une suite d'instruction et fini par "FIN"
                      Ou commence par "{" suivi d'une suite d'instruction et fini par "}"
*******************************************************************************************/


liste_instructions : DEBUT suite_liste_inst FIN         {$$ = $2;}     
                   | ACO suite_liste_inst ACF           {$$ = $2;}
                   ;


/*******************************************************************************************
Suite liste d'instruction : Commence par une "instruction" suivie d'un point virgule
                            Ou comme au dessus mais précédé d'une "suite liste d'instruction"
*******************************************************************************************/


suite_liste_inst : instruction PV                                               {$$ = $1;}
                 | suite_liste_inst instruction PV                              {$$ = concatPereFrere($1, $2);}
                 ;


/*******************************************************************************************
Une déclaration est : Soit une déclaration de type
                      Soit une déclaration de variable
                      Soit une déclaration de procedure
                      Soit une déclaration de fonction
*******************************************************************************************/


declaration : declaration_type
            | declaration_variable
            | declaration_procedure
            | declaration_fonction
            ;


/*******************************************************************************************
Délaration de type : Commence par "TYPE" suivie d'un "IDF", de ":", et d'une 
                     "suite_declaration_type"
*******************************************************************************************/


declaration_type : TYPE IDF {numLexico = $2;} DEUX_POINTS suite_declaration_type
                 ;


/*******************************************************************************************
Suite déclaration type : -Déclaration d'une structure : 
                            Commence par "STRUCT" suivie "liste_champs" suivie "FSTRUCT"
                         -Déclaration d'un tableau :
                            Commence par "TABLEAU" suivie "dimension" suivie "DE" suivie nom_type
*******************************************************************************************/


suite_declaration_type : STRUCT {tailleStructTab = 0; nbChamps = 0;} liste_champs PV FSTRUCT 
                        {  
                            if(associationNom(numLexico, DECL_TYPE_STRUCTURE) != -1){
                                yyerror();
                                printf("Une structure utilisant ce nom [%s] est déja déclaré et accessible\n", maTableLexico.donnee[numLexico].lexeme);
                                exit(-1);     
                            }
                            insererTabDecl(1, numLexico, tailleStructTab, 0, nbProcFonc); 
                            insererStructTabTypesEntete(nbChamps, listeChamps);
                       }

                       | {tailleStructTab = 0;} TABLEAU {tailleDimension = 1; nbDim = 0; tmpBorne = 0;} dimension DE nom_type                     
                       {
                            if(associationNom(numLexico, DECL_TYPE_TABLEAU) != -1){
                                yyerror();
                                printf("Un tableau utilisant ce nom [%s] est déja déclaré et accessible\n", maTableLexico.donnee[numLexico].lexeme);
                                exit(-1);     
                            }
                            tailleStructTab = tailleStructTab * tailleDimension; 
                            $$ = insererTabDecl(2, numLexico, tailleStructTab, 0, nbProcFonc);
                            insererTableauTabTypesEntete(tmpTypeTab, nbDim, tabBorne);
                       }
                       ;


/*******************************************************************************************
Dimension : "[" suivie de "liste_dimension" suivie de "]"
*******************************************************************************************/


dimension : CROO liste_dimensions CROF
          ;


/*******************************************************************************************
Liste dimension : "une_dimension"
                  Ou "liste_dimension" suivie de "VIRGULE" suivie de "dimension"
*******************************************************************************************/


liste_dimensions : {valExpression = 0;} une_dimension {nbDim++;}                                     
                 | liste_dimensions VIRGULE {valExpression = 0;} une_dimension  {nbDim++;}             
                 ;


/*******************************************************************************************
Une_dimension : "expression" suivie de ".." suivie d'une "expression"
*******************************************************************************************/


une_dimension : expression {tabBorne[tmpBorne] = valExpression; tmpBorne++;} POINT_POINT expression {tabBorne[tmpBorne] = valExpression; tmpBorne++;}         
                                                                                                                                {
                                                                                                                                    tailleDimension *= (tabBorne[tmpBorne-1] - tabBorne[tmpBorne-2] + 1);
                                                                                                                                }
              ;


/*******************************************************************************************
Liste champ : Soit "un_champ"
              Soit "liste_champs" suivis d'un ";" suivis de "un_champs"
*******************************************************************************************/


liste_champs : un_champ
             | liste_champs PV un_champ                               
             ;


/*******************************************************************************************
Un champs : Commence par un "IDF" suivis de ":" suivis de "nom_type"
*******************************************************************************************/


un_champ : IDF {listeChamps[nbChamps] = $1; nbChamps++;} DEUX_POINTS nom_type
         ;
 

/*******************************************************************************************
Nom_type : "type_simple"
           Ou un "IDF"
*******************************************************************************************/


nom_type : type_simple
         | IDF  
           {
                if(associationNom($1, DECL_TYPE_TABLEAU) == -1 && associationNom($1, DECL_TYPE_STRUCTURE) == -1){
                    yyerror();
                    printf("Le type donné [%s] a la variable n'éxiste pas !\n", maTableLexico.donnee[$1].lexeme);
                    exit(-1);     
                }
                tailleStructTab += tailleType($1); tmpTypeVar = $1; listeChamps[nbChamps] = $1; nbChamps++; tmpTypeTab = $1;
           }
         ;


/*******************************************************************************************
Type_simple : Soit "INT"
              Soit "FLOAT"
              Soit "BOOL"
              Soit "CHAR"
              Soit "STRING" suivis de "[" suivis de "ENTIER" suivis de "]"
*******************************************************************************************/


type_simple : INT                               {tailleStructTab += 1; tmpTypeVar = 0; listeChamps[nbChamps] = 0; nbChamps++;
                                                 tmpTypeTab = 0;
                                                 listeParam[nbParam] = 0; 
                                                 tmpRetour = 0; nbParam++;}                                                              
            | FLOAT                             {tailleStructTab += 1; tmpTypeVar = 1; listeChamps[nbChamps] = 1; nbChamps++;
                                                 tmpTypeTab = 1; 
                                                 tmpRetour = 1;
                                                 listeParam[nbParam] = 1; nbParam++;}                                 
            | BOOL                              {tailleStructTab += 1; tmpTypeVar = 2; listeChamps[nbChamps] = 2; nbChamps++;
                                                 tmpTypeTab = 2; 
                                                 tmpRetour = 2;
                                                 listeParam[nbParam] = 2; nbParam++;}                                 
            | CHAR                              {tailleStructTab += 1; tmpTypeVar = 3; listeChamps[nbChamps] = 3; nbChamps++;
                                                 tmpTypeTab = 3; 
                                                 tmpRetour = 3;
                                                 listeParam[nbParam] = 3; nbParam++;}                                 
            | STRING CROO ENTIER CROF           {tailleStructTab += $3;}                                 
            ;


/*******************************************************************************************
Declaration variable : "VAR" suivie de "IDF" suivie de ":" suivie de "nom_type"
*******************************************************************************************/


declaration_variable : VARIABLE IDF DEUX_POINTS nom_type 
                    {
                        if(associationNom($2, DECL_VARIABLE) != -1){
                            if(maTableDecl.donnee[associationNom($2, DECL_VARIABLE)].region == numRegion()){
                                yyerror();
                                printf("Une variable du même nom [%s] est déja déclaré dans la région actuel\n", maTableLexico.donnee[$2].lexeme);
                                exit(-1); 
                            }
                        }
                        insererTabDecl(3, $2, tailleStructTab, tmpTypeVar, nbProcFonc);
                    }
                     ;


/*******************************************************************************************
Declaration procédure : "PROCEDURE" suivis de "IDF" suivis de "liste_parametre" suivis de "corps"
*******************************************************************************************/


declaration_procedure : PROCEDURE IDF 
                        {
                            if(associationNom($2, DECL_PROCEDURE) != -1){
                                yyerror();
                                printf("Une procédure du même nom [%s] est déja déclaré !\n", maTableLexico.donnee[$2].lexeme);
                                exit(-1); 
                            }
                            incrementeCptRegion(); 
                            incrementeNIS();  
                            nbParam = 0; 
                            nbProcFonc++; 
                            insererTabDecl(5, $2, tailleStructTab, 0, nbProcFonc); 
                            empilerRegion(cptRegion());
                        }                
                        liste_parametres {insererProcTabTypesEntete(nbParam, listeParam);} corps {decrementeNIS(); depilerRegion();}
                      ;


/*******************************************************************************************
Déclaration fonction : "FONCTION" suivis de "IDF" suivis de "liste_parametres" suivis de "RETURN" suivis de "type_simple" suivis de "corps" 
*******************************************************************************************/


declaration_fonction : FONCTION IDF 
                       {
                            if(associationNom($2, DECL_FONCTION) != -1){
                                yyerror();
                                printf("Une Fonction du même nom [%s] est déja déclaré !\n", maTableLexico.donnee[$2].lexeme);
                                exit(-1); 
                            }
                            incrementeCptRegion(); incrementeNIS(); empilerRegion(cptRegion()); nbParam = 0; nbChamps = 0; nbProcFonc++; insererTabDecl(6, $2, tailleStructTab, 0, nbProcFonc);
                       }
                       liste_parametres RETURN type_simple {insererFoncTabTypesEntete(tmpRetour, nbParam, listeParam);}
                       corps {decrementeNIS(); depilerRegion();}
                     ;


/*******************************************************************************************
Liste paramètre : "(" suivis de "liste_param" suivis de ")"
                  Ou rien
*******************************************************************************************/


liste_parametres : 
                 | PO liste_param PF
                 ;


/*******************************************************************************************
Liste param : "un_param"
              Ou "liste_param" suivis de ";" suivis de "un_param"
*******************************************************************************************/


liste_param : un_param
            | liste_param PV un_param
            ;


/*******************************************************************************************
Un param : "IDF" suivis de ":" suivis de "type_simple"
*******************************************************************************************/


un_param : IDF DEUX_POINTS type_simple 
           {
                if(associationNom($1, DECL_PARAMETRE) != -1){
                    yyerror();
                    printf("Le nom de ce paramètre [%s] est déja utilisé !\n", maTableLexico.donnee[$1].lexeme);
                    exit(-1); 
                }
                insererTabDecl(DECL_PARAMETRE, $1, tailleStructTab, 0, nbProcFonc); listeParam[nbParam] = associationNom($1, DECL_PARAMETRE); nbParam++;
           }
         ;


/*******************************************************************************************
Instruction : "affectation"
              Ou "condition"
              Ou "tant_que"
              Ou "appel"
              Ou "VIDE"
              Ou "RETURN" suivis de "resultat_retourne"
*******************************************************************************************/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

instruction : affectation                   {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), $1);}

            | condition                     {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), $1);}

            | tant_que                      {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), $1);}

            | appel                         {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), $1);}

            | VIDE                          {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), creerNoeud(A_VIDE, -1, -1));}

            | RETURN resultat_retourne      {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), concatPereFrere(creerNoeud(A_RETURN, -1, -1), $2));}

            | lire                          {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), $1);}

            | ecrire                        {$$ = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), $1);}
            ;


/*******************************************************************************************
Resultat retourne : Rien
                    Ou "expression"
*******************************************************************************************/


resultat_retourne : 
                  | expression      {$$ = $1;}
                  ;


/*******************************************************************************************
Appel : "IDF" suivis de "liste_arguments"
*******************************************************************************************/


appel : IDF PO liste_arguments PF             {   
                                            if(associationNom($1, DECL_PROCEDURE) != -1){
                                                $$ = concatPereFils(creerNoeud(A_APPEL_PROC, $1, associationNom($1, DECL_PROCEDURE)), $3);
                                            }else if(associationNom($1, DECL_FONCTION) != -1){
                                                $$ = concatPereFils(creerNoeud(A_APPEL_FONC, $1, associationNom($1, DECL_FONCTION)), $3);
                                            }
                                            else{
                                                yyerror();
                                                AfficheTableLexico(); afficheTabDecl();
                                                printf("\nAppel impossible, fonction ou procédure pas déclaré : %d\n", $1);
                                                exit(-1);
                                            }
                                        }                             
      ;


/*******************************************************************************************
Liste arguments : "(" suivis de "liste_args" ")"
                  Ou rien
*******************************************************************************************/


liste_arguments :                 {$$ = creerNoeud(A_VIDE, -1, -1);}
                | liste_args      {$$ = $1;}
                ;


/*******************************************************************************************
Liste args : "un_arg"
             Ou "liste_args" suivis de "," suivis de "un_arg"
*******************************************************************************************/


liste_args : un_arg                            {$$ = $1;}      
           | liste_args VIRGULE un_arg         {$$ = concatPereFrere($1, $3);}
           ;


/*******************************************************************************************
Un arg : "expression"
*******************************************************************************************/


un_arg : expression             {$$ = concatPereFils(creerNoeud(A_LISTE_ARG, -1, -1), $1);}
       ;


/*******************************************************************************************
Condition : "IF" suivis de "expression_booleene" suivis de "THEN" suivis de "liste_instruction" suivis de "ELSE" suivis de "liste_instruction"
*******************************************************************************************/


condition : IF PO eb1 PF                    
            THEN liste_instructions 
            ELSE liste_instructions ENDIF    {arbreIf = 1; $$ = concatPereFils(creerNoeud(A_INSTR_COND, -1, -1), concatPereFrere(concatPereFrere($3, $6), $8)); arbreIf = 0;}
          ; 


/*******************************************************************************************
Tant que : "WHILE" suivis de "expression_booleenne" suivis de "DO" suivis de "liste_instruction"
*******************************************************************************************/


tant_que : WHILE PO eb1 PF DO liste_instructions        {$$ = concatPereFils(creerNoeud(A_TANT_QUE, -1, -1), concatPereFrere($3, $6));}
         ;


/*******************************************************************************************
Affectation : "variable" suivis de "OPAFF" suivis de "expression"
*******************************************************************************************/


affectation : variable OPAFF expression {
                                            if(struc){
                                                $$ = concatPereFils(creerNoeud(A_AFFECT, -1, -1), concatPereFrere(concatPereFils(creerNoeud(A_POINT, -1, -1), $1), $3));
                                                struc = 0;
                                            }
                                            else{
                                                $$ = concatPereFils(creerNoeud(A_AFFECT, -1, -1), concatPereFrere($1, $3));
                                            }
                                        }
            ;


/*******************************************************************************************
Variable : IDF
           Ou "variable" suivis de "." suivis de "IDF"
           Ou "var_tab"
*******************************************************************************************/


variable : IDF 
            {
                if(associationNom($1, DECL_VARIABLE) == -1){
                    yyerror();
                    printf("La variable [%s] n'est pas déclaré !\n", maTableLexico.donnee[$1].lexeme);
                    exit(-1); 
                }
                $$ = creerNoeud(A_IDF, $1, associationNom($1, DECL_VARIABLE));
            }
         | variable POINT IDF            {struc = 1; $$ = concatPereFrere($1, creerNoeud(A_IDF, $3, associationNom($3, DECL_VARIABLE)));}
         | var_tab                       
         ;


/*******************************************************************************************
Var tab : "variable" suivis de "[" suivis de "val_tab" suivis de "]"
*******************************************************************************************/


var_tab : variable CROO val_tab CROF    {
                                            if(struc){
                                                tmp = concatPereFils(creerNoeud(A_TABLEAU, -1, -1), concatPereFils($1->frereDroit, $3));
                                                $1->frereDroit = NULL;
                                                $$ = concatPereFrere($1, tmp);
                                            }
                                            else{
                                                $$ = concatPereFils(creerNoeud(A_TABLEAU, -1, -1), concatPereFils($1, $3));
                                            }      
                                        }
        ;


/*******************************************************************************************
Val tab : "val_tab" suivis de "," suivis de "ea1"
          Ou "ea1"
*******************************************************************************************/


val_tab : val_tab VIRGULE ea1          {$$ = concatPereFrere($1, $3);}
        | ea1                          {$$ = $1;}
        ;


/*******************************************************************************************
Expression : "ea1" (Expression arithmétique 1)
             Ou "eb1" (Expression booléenne 1)
*******************************************************************************************/


expression : ea1            {$$ = $1;}
           | eb1            {$$ = $1;}
           ;


/*******************************************************************************************
Ea1 : "ea1" suivis de "PLUS" suivis de "ea2"
      Ou "ea1" suivis de "MOINS" suivis de "ea2"
      Ou "ea2"
*******************************************************************************************/


ea1 : ea1 {valGauche = valExpression;} PLUS ea2      {$$ = concatPereFils(creerNoeud(A_PLUS, -1, -1), concatPereFrere($1, $4)); valExpression = (valGauche + valExpression);}

    | ea1 {valGauche = valExpression;} MOINS ea2     {$$ = concatPereFils(creerNoeud(A_MOINS, -1, -1), concatPereFrere($1, $4)); valExpression = (valGauche - valExpression);}

    | ea2               {$$ = $1;}
    ;


/*******************************************************************************************
Ea2 : "ea2" suivis de "MULT" suivis de "ea3"
      Ou "ea2" suivis de "DIV" suivis de "ea3"
      Ou "ea3"
*******************************************************************************************/


ea2 : ea2 {valGauche = valExpression;} MULT ea3      {$$ = concatPereFils(creerNoeud(A_MULT, -1, -1), concatPereFrere($1, $4)); 
                                                      valExpression = (valGauche * valExpression);}

    | ea2 {valGauche = valExpression;} DIV ea3       {$$ = concatPereFils(creerNoeud(A_DIV, -1, -1), concatPereFrere($1, $4)); 
                                                      if(valExpression == 0){
                                                        yyerror();
                                                        printf("\nErreur division par 0 ! Danger !\n");
                                                        exit(-1);
                                                      }
                                                      valExpression = (valGauche / valExpression);}

    | ea3               {$$ = $1;}
    ;


/*******************************************************************************************
Ea3 : "(" suivis de "ea1" suivis de ")"
      Ou "variable"
      Ou "appel"
      Ou "ENTIER"
*******************************************************************************************/


ea3 : PO ea1 PF         {$$ = $2;}
    | variable          {$$ = $1;}
    | appel             {$$ = $1;}
    | ENTIER            {$$ = creerNoeud(A_ENTIER, $1, -1); valExpression = $1;}
    ;


/*******************************************************************************************
Eb1 : "eb1" suivis de "ET" suivis de "eb2"
      Ou "eb2"
*******************************************************************************************/


eb1 : eb1 ET eb2        {$$ = concatPereFils(creerNoeud(A_ET, -1, -1), concatPereFrere($1, $3));}
    | eb2               {$$ = $1;}
    ;


/*******************************************************************************************
Eb2 : "eb2" suivis de "OU" suivis de "eb3"
      Ou "eb3"
*******************************************************************************************/


eb2 : eb2 OU eb3        {$$ = concatPereFils(creerNoeud(A_OU, -1, -1), concatPereFrere($1, $3));}
    | eb3               {$$ = $1;}
    ;


/*******************************************************************************************
Eb3 : "EXCLA" suivis de "eb4"
      Ou "eb4"
*******************************************************************************************/


eb3 : EXCLA PO eb4 PF   {$$ = concatPereFils(creerNoeud(A_NON, -1, -1), $3);}
    | eb4               {$$ = $1;}
    ;


/*******************************************************************************************
Eb4 : "(" suivis de "eb1" suivis de ")"
      Ou "ea1" suivis de "comparaison" suivis de "ea1"
      Ou "TRUE"
      Ou "FALSE"
*******************************************************************************************/


eb4 : ea1 PETIT ea1         {$$ = concatPereFils(creerNoeud(A_INF, -1, -1), concatPereFrere($1, $3));}
    | ea1 GRAND ea1         {$$ = concatPereFils(creerNoeud(A_SUP, -1, -1), concatPereFrere($1, $3));}
    | ea1 PETIT_EQ ea1      {$$ = concatPereFils(creerNoeud(A_INF_EGAL, -1, -1), concatPereFrere($1, $3));}
    | ea1 GRAND_EQ ea1      {$$ = concatPereFils(creerNoeud(A_SUP_EGAL, -1, -1), concatPereFrere($1, $3));}
    | ea1 EGAL ea1          {$$ = concatPereFils(creerNoeud(A_EGAL, -1, -1), concatPereFrere($1, $3));}
    | ea1 DIFF ea1          {$$ = concatPereFils(creerNoeud(A_DIFF, -1, -1), concatPereFrere($1, $3));}
    | TRUE                  {$$ = creerNoeud(A_TRUE, 1, -1);}
    | FALSE                 {$$ = creerNoeud(A_FALSE, 0, -1);}
    ;    


/*******************************************************************************************
lire : Affiche les valeurs d'une suite de variable sur le terminal
       "READ" suivis de "(" suivis de "liste_variables" suivis de ")"
*******************************************************************************************/


lire : READ PO liste_variables PF       {$$ = concatPereFils(creerNoeud(A_LIRE, -1, -1), $3);}
     ;


/*******************************************************************************************
Liste variable : Rien
                 Ou "variable"
                 Ou "liste_variable" suivis de "," suivis de "varibale"
*******************************************************************************************/

liste_variables : 
               | variable                               {$$ = concatPereFils(creerNoeud(A_LISTE_VAR, -1, -1), $1);}
               | liste_variables VIRGULE variable       {$$ = concatPereFils(creerNoeud(A_LISTE_VAR, -1, -1), concatPereFrere($1, $3));}
               ;


/*******************************************************************************************
Ecrire : Affiche des valeurs de variables formaté "%quelqueChose"
         "WRITE" suivis de "(" suivis de "format" suivis de "suite_ecriture" suivis de ")"
*******************************************************************************************/

ecrire : WRITE PO format suite_ecriture PF      
        {$$ = concatPereFils(creerNoeud(A_ECRIRE, -1, -1), concatPereFrere(concatPereFils(creerNoeud(A_LISTE_FORMAT, -1, -1), $3), concatPereFils(creerNoeud(A_SUITE_ECRITURE, -1, -1), $4)));}
       ;


/*******************************************************************************************
Suite ecriture : Rien
                 Ou "VIRGULE" suivis de "variable" suivis de "suite_ecriture"
*******************************************************************************************/

suite_ecriture :                                    {$$ = creerNoeud(A_VIDE, -1, -1);}
               | VIRGULE variable                   {
                                                        if(struc){
                                                            $$ = concatPereFils(creerNoeud(A_POINT, -1, -1), $2);
                                                            struc = 0;
                                                        }
                                                        else{
                                                            $$ = $2;
                                                        } 
                                                    }
               | suite_ecriture VIRGULE variable    {
                                                        if(struc){
                                                            $$ = concatPereFrere($1, concatPereFils(creerNoeud(A_POINT, -1, -1), $3));
                                                            struc = 0;
                                                        }
                                                        else{
                                                            $$ = concatPereFrere($1, $3);
                                                        } 
                                                    }
               ;


/*******************************************************************************************
Format : "GUI" suivis de "liste_format" suivis de "GUI"
*******************************************************************************************/

format : GUI liste_format GUI       {$$ = $2;}
       ;


/*******************************************************************************************
liste_format : Suite des formats des variable, exemple : "%d %s %b %d"
             Rien
             Ou "FINT"
             Ou "FBOOL"
             Ou "FFLOAT"
             Ou "FCHAR"
             Ou "FSTRING"
             Ou "format" suivis de "FINT"
             Ou "format" suivis de "FBOOL"
             Ou "format" suivis de "FFLOAT"
             Ou "format" suivis de "FCHAR"
             Ou "format" suivis de "FSTRING"
*******************************************************************************************/


liste_format :                              {$$ = creerNoeud(A_VIDE, -1, -1);}
             | FINT                         {$$ = creerNoeud(A_FORMAT_INT, -1, -1);}
             | FBOOL                        {$$ = creerNoeud(A_FORMAT_BOOL, -1, -1);}
             | FFLOAT                       {$$ = creerNoeud(A_FORMAT_FLOAT, -1, -1);}
             | FCHAR                        {$$ = creerNoeud(A_FORMAT_CHAR, -1, -1);}
             | FSTRING                      {$$ = creerNoeud(A_FORMAT_STRING, -1, -1);}
             | liste_format FINT            {$$ = concatPereFrere($1, creerNoeud(A_FORMAT_INT, -1, -1));}
             | liste_format FBOOL           {$$ = concatPereFrere($1, creerNoeud(A_FORMAT_BOOL, -1, -1));}
             | liste_format FFLOAT          {$$ = concatPereFrere($1, creerNoeud(A_FORMAT_FLOAT, -1, -1));}
             | liste_format FCHAR           {$$ = concatPereFrere($1, creerNoeud(A_FORMAT_CHAR, -1, -1));}
             | liste_format FSTRING         {$$ = concatPereFrere($1, creerNoeud(A_FORMAT_STRING, -1, -1));}
             ;


%%

int yyerror(){
	printf("Erreur en ligne %d\n", Num_Ligne);
}

int main(int argc, char *argv[]){

    initLexico(); 
    initHash(); 
    initTabDecl(); 
    initTabType(); 
    initTabRegion(); 
    initPile();
    arbreIf = 0;

    yyin=fopen(argv[1],"r");

    if(!yyin)
    {
        printf("\n\n Erreur fichier n'éxiste pas !\n\n");
        exit(0);    
    }

    if(argc == 3){
        verbal = 1;
    }
    else{
        verbal = 0;
    }

	yyparse();
}

