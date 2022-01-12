%{
	#include "arbre.h"
	#include "y.tab.h"
	#include "TabLexico.h"
	#define ERREUR -99
	int Num_Ligne = 0;
%}

C1 [^"]
C2 [^"*]
C3 [^"*/]

%%

prog			{return(PROG);}
procedure		{return(PROCEDURE);}
begin			{return(DEBUT);}
end				{return(FIN);}
call			{return(APPEL);}
function		{return(FONCTION);}
tab				{return(TABLEAU);}
if 				{return(IF);}
then			{return(THEN);}
endif			{return(ENDIF);}
var 			{return(VARIABLE);}
for				{return(FOR);}
return			{return(RETURN);}
else			{return(ELSE);}
switch			{return(SWITCH);}
case			{return(CASE);}
main			{return(MAIN);}
while			{return(WHILE);}
do				{return(DO);}
void			{return(VOID);}
vide			{return(VIDE);}
of 				{return(DE);}
include			{return(INCLUDE);}
define			{return(DEFINE);}
struct			{return(STRUCT);}
fstruct			{return(FSTRUCT);}
type			{return(TYPE);}
int				{return(INT);}
float			{return(FLOAT);}
char			{return(CHAR);}
string			{return(STRING);}
bool			{return(BOOL);}
true			{return(TRUE);}
false			{return(FALSE);}
read			{return(READ);}
write			{return(WRITE);}
\. 				{return(POINT);}
==				{return(EGAL);}
\<				{return(PETIT);}
\>				{return(GRAND);}
\&\&			{return(ET);}
\|\|			{return(OU);}
\#				{return(HASH);}
\,				{return(VIRGULE);}
\.\.			{return(POINT_POINT);}
\!				{return(EXCLA);}
\<=				{return(PETIT_EQ);}
\>=				{return(GRAND_EQ);}
exit			{return(EXIT);}
\;				{return(PV);}
\:				{return(DEUX_POINTS);}
!=				{return(DIFF);}
\"				{return(GUI);}
\{				{return(ACO);}
\}				{return(ACF);}
\[				{return(CROO);}
\]				{return(CROF);}
\+				{return(PLUS);}
-				{return(MOINS);}
\*				{return(MULT);}
\/				{return(DIV);}
\( 				{return(PO);}
\)				{return(PF);}
\%d				{return(FINT);}
\%b				{return(FBOOL);}
\%f				{return(FFLOAT);}
\%c				{return(FCHAR);}
\%s				{return(FSTRING);}
\t 				{ }
:=  			{return(OPAFF);}
0|[1-9][0-9]*	{yylval.type2 = atoi(yytext); return(ENTIER);}
[a-zA-Z][a-zA-Z0-9]*	{yylval.type2 = insererLexeme(yytext) ; return(IDF) ;}
\n  			{Num_Ligne++;}
" "				;
.				{printf("Erreur Lexico\n"); return(ERREUR);}
\/\*({C2}|"{C1}*"|\*\**{C3}|\*\**"{C1}*")*\*\**\/		{ }
%%
