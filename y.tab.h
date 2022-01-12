/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPAFF = 258,
    EGAL = 259,
    PLUS = 260,
    MOINS = 261,
    MULT = 262,
    DIV = 263,
    ET = 264,
    OU = 265,
    EXCLA = 266,
    PO = 267,
    PF = 268,
    IF = 269,
    WHILE = 270,
    SWITCH = 271,
    FOR = 272,
    CASE = 273,
    VOID = 274,
    MAIN = 275,
    DEBUT = 276,
    FIN = 277,
    PROCEDURE = 278,
    FONCTION = 279,
    VIDE = 280,
    THEN = 281,
    APPEL = 282,
    ENDIF = 283,
    DO = 284,
    DEFINE = 285,
    STRUCT = 286,
    TYPE = 287,
    PROG = 288,
    FSTRUCT = 289,
    TABLEAU = 290,
    VARIABLE = 291,
    ELSE = 292,
    EXIT = 293,
    RETURN = 294,
    READ = 295,
    WRITE = 296,
    FINT = 297,
    FBOOL = 298,
    FFLOAT = 299,
    FCHAR = 300,
    FSTRING = 301,
    INCLUDE = 302,
    PETIT = 303,
    GRAND = 304,
    HASH = 305,
    VIRGULE = 306,
    PETIT_EQ = 307,
    GRAND_EQ = 308,
    PV = 309,
    TRUE = 310,
    FALSE = 311,
    DIFF = 312,
    ACO = 313,
    ACF = 314,
    CROO = 315,
    CROF = 316,
    GUI = 317,
    DE = 318,
    DEUX_POINTS = 319,
    POINT = 320,
    POINT_POINT = 321,
    INT = 322,
    FLOAT = 323,
    CHAR = 324,
    BOOL = 325,
    STRING = 326,
    ENTIER = 327,
    IDF = 328
  };
#endif
/* Tokens.  */
#define OPAFF 258
#define EGAL 259
#define PLUS 260
#define MOINS 261
#define MULT 262
#define DIV 263
#define ET 264
#define OU 265
#define EXCLA 266
#define PO 267
#define PF 268
#define IF 269
#define WHILE 270
#define SWITCH 271
#define FOR 272
#define CASE 273
#define VOID 274
#define MAIN 275
#define DEBUT 276
#define FIN 277
#define PROCEDURE 278
#define FONCTION 279
#define VIDE 280
#define THEN 281
#define APPEL 282
#define ENDIF 283
#define DO 284
#define DEFINE 285
#define STRUCT 286
#define TYPE 287
#define PROG 288
#define FSTRUCT 289
#define TABLEAU 290
#define VARIABLE 291
#define ELSE 292
#define EXIT 293
#define RETURN 294
#define READ 295
#define WRITE 296
#define FINT 297
#define FBOOL 298
#define FFLOAT 299
#define FCHAR 300
#define FSTRING 301
#define INCLUDE 302
#define PETIT 303
#define GRAND 304
#define HASH 305
#define VIRGULE 306
#define PETIT_EQ 307
#define GRAND_EQ 308
#define PV 309
#define TRUE 310
#define FALSE 311
#define DIFF 312
#define ACO 313
#define ACF 314
#define CROO 315
#define CROF 316
#define GUI 317
#define DE 318
#define DEUX_POINTS 319
#define POINT 320
#define POINT_POINT 321
#define INT 322
#define FLOAT 323
#define CHAR 324
#define BOOL 325
#define STRING 326
#define ENTIER 327
#define IDF 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "exp.y"

   arbre type1;
   int type2;

#line 208 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
