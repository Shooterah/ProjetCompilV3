/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "exp.y"

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


#line 110 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 313 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

#define YYUNDEFTOK  2
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   137,   137,   137,   155,   156,   166,   167,   177,   178,
     188,   189,   201,   202,   203,   204,   214,   214,   226,   226,
     237,   237,   237,   256,   266,   266,   267,   267,   276,   276,
     276,   289,   290,   299,   299,   309,   310,   331,   335,   339,
     343,   347,   356,   376,   389,   375,   399,   407,   398,   418,
     419,   429,   430,   439,   461,   463,   465,   467,   469,   471,
     473,   475,   485,   486,   495,   517,   518,   528,   529,   538,
     547,   558,   567,   586,   595,   596,   605,   624,   625,   635,
     636,   647,   647,   649,   649,   651,   662,   662,   665,   665,
     673,   685,   686,   687,   688,   698,   699,   709,   710,   720,
     721,   733,   734,   735,   736,   737,   738,   739,   740,   750,
     760,   761,   762,   771,   781,   782,   791,   807,   827,   828,
     829,   830,   831,   832,   833,   834,   835,   836,   837
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPAFF", "EGAL", "PLUS", "MOINS", "MULT",
  "DIV", "ET", "OU", "EXCLA", "PO", "PF", "IF", "WHILE", "SWITCH", "FOR",
  "CASE", "VOID", "MAIN", "DEBUT", "FIN", "PROCEDURE", "FONCTION", "VIDE",
  "THEN", "APPEL", "ENDIF", "DO", "DEFINE", "STRUCT", "TYPE", "PROG",
  "FSTRUCT", "TABLEAU", "VARIABLE", "ELSE", "EXIT", "RETURN", "READ",
  "WRITE", "FINT", "FBOOL", "FFLOAT", "FCHAR", "FSTRING", "INCLUDE",
  "PETIT", "GRAND", "HASH", "VIRGULE", "PETIT_EQ", "GRAND_EQ", "PV",
  "TRUE", "FALSE", "DIFF", "ACO", "ACF", "CROO", "CROF", "GUI", "DE",
  "DEUX_POINTS", "POINT", "POINT_POINT", "INT", "FLOAT", "CHAR", "BOOL",
  "STRING", "ENTIER", "IDF", "$accept", "programme", "$@1", "corps",
  "liste_declarations", "liste_instructions", "suite_liste_inst",
  "declaration", "declaration_type", "$@2", "suite_declaration_type",
  "$@3", "$@4", "$@5", "dimension", "liste_dimensions", "$@6", "$@7",
  "une_dimension", "$@8", "$@9", "liste_champs", "un_champ", "$@10",
  "nom_type", "type_simple", "declaration_variable",
  "declaration_procedure", "$@11", "$@12", "declaration_fonction", "$@13",
  "$@14", "liste_parametres", "liste_param", "un_param", "instruction",
  "resultat_retourne", "appel", "liste_arguments", "liste_args", "un_arg",
  "condition", "tant_que", "affectation", "variable", "var_tab", "val_tab",
  "expression", "ea1", "$@15", "$@16", "ea2", "$@17", "$@18", "ea3", "eb1",
  "eb2", "eb3", "eb4", "lire", "liste_variables", "ecrire",
  "suite_ecriture", "format", "liste_format", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,  -147,    65,    68,  -147,    71,   -53,    -1,     1,    15,
      71,  -147,    68,  -147,    36,  -147,  -147,  -147,  -147,    87,
      96,  -147,     7,   102,   105,   112,     2,    66,  -147,  -147,
    -147,  -147,     4,  -147,  -147,  -147,  -147,  -147,  -147,    61,
      62,  -147,    82,  -147,     7,     7,   120,    -2,  -147,  -147,
    -147,  -147,  -147,   -31,  -147,    89,    49,  -147,   134,   129,
    -147,  -147,    72,    91,     7,  -147,   100,  -147,     7,    -2,
      84,   146,   146,    95,    94,  -147,  -147,   103,    22,   106,
      11,    20,    -2,    -2,    -2,    -2,    -2,    -2,   161,   162,
     163,   174,     7,     7,  -147,   -31,     8,   130,   118,   170,
     133,  -147,  -147,  -147,  -147,   -23,    76,  -147,   115,  -147,
     150,   154,  -147,  -147,  -147,  -147,   131,  -147,  -147,  -147,
     164,   165,   179,  -147,    76,    76,    76,    76,    76,    76,
      -2,    -2,    -2,    -2,   129,  -147,  -147,    72,  -147,  -147,
    -147,  -147,  -147,    85,    72,    17,  -147,     7,    -2,  -147,
     132,    -9,  -147,    68,   110,  -147,  -147,   158,   125,   -18,
     -18,  -147,    49,    49,  -147,  -147,   -31,  -147,  -147,  -147,
    -147,  -147,  -147,   -31,  -147,    72,  -147,    76,   110,  -147,
     115,  -147,  -147,   126,  -147,   139,   166,  -147,   -31,  -147,
    -147,    68,  -147,   147,  -147,   142,  -147,   -18,  -147,   140,
     -29,  -147,   143,   177,    94,  -147,  -147,   -12,     7,    94,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,     7,   141,  -147,
       7,  -147,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     3,     0,     5,     0,    12,    13,    14,    15,     0,
       0,    58,    62,     0,     0,    73,     0,     0,    57,    55,
      56,    54,     0,    75,    60,    61,    43,    46,    16,     0,
       0,     4,     0,     6,     0,     0,     0,     0,   107,   108,
      94,    59,    93,    92,    63,    79,    85,    90,    80,    96,
      98,   100,   110,     0,    65,     8,     0,    10,     0,     0,
       0,    49,    49,     0,     0,     9,     7,    81,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,   111,     0,   118,   114,     0,
      66,    67,    69,    11,    72,     0,    78,    74,     0,    44,
       0,    20,    37,    38,    40,    39,     0,    36,    42,    35,
       0,     0,     0,    91,   105,   101,   102,   103,   104,   106,
       0,     0,     0,     0,    95,    97,   109,     0,   119,   120,
     121,   122,   123,     0,     0,     0,    64,     0,     0,    76,
       0,     0,    51,     0,     0,    18,    17,     0,     0,     0,
       0,    99,    82,    84,    87,    89,   112,   124,   125,   126,
     127,   128,   117,   115,   113,     0,    68,    77,     0,    50,
       0,    45,    47,     0,    21,     0,     0,    71,   116,    53,
      52,     0,    33,     0,    31,     0,    41,     0,    48,     0,
       0,    24,     0,     0,     0,    19,    32,     0,     0,     0,
      70,    34,    26,    23,    25,    28,    22,     0,     0,    27,
       0,    29,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -144,  -147,   -10,   198,   197,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    -7,  -147,
    -147,  -147,    12,  -147,  -131,  -146,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,   144,  -147,    31,   -15,  -147,   108,  -147,
    -147,    67,  -147,  -147,  -147,    -4,  -147,  -147,   -22,   -32,
    -147,  -147,   -33,  -147,  -147,   -27,    78,   121,   122,   137,
    -147,  -147,  -147,  -147,  -147,  -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    11,    12,    13,    26,    14,    15,    73,
     156,   183,   157,   195,   202,   207,   208,   217,   214,   218,
     222,   193,   194,   199,   118,   119,    16,    17,    71,   153,
      18,    72,   191,   109,   151,   152,    27,    51,    52,    99,
     100,   101,    29,    30,    31,    53,    33,   105,   102,    55,
      88,    89,    56,    90,    91,    57,    58,    59,    60,    61,
      34,    96,    35,   145,    98,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    32,    41,     5,   179,   205,    32,    68,   182,   181,
      47,    66,    77,    77,     1,    81,    19,    20,    46,    47,
      36,   136,    32,    47,    65,    66,   -83,    21,   148,    69,
     174,    92,   189,   123,    70,   120,    32,   106,   149,   212,
      10,    22,    23,    24,   192,   180,   104,   198,    77,   213,
     124,   125,   126,   127,   128,   129,   -86,   -88,    95,   137,
      77,    77,    48,    49,    69,     4,    48,    49,   175,    70,
      50,    25,    37,   211,    38,    25,    19,    20,   216,    50,
      25,   -81,   -83,    50,    25,    19,    20,    21,    39,     5,
      43,     6,     7,    82,   -81,   -83,    21,   162,   163,    44,
       8,    22,    23,    24,     9,   164,   165,    82,    45,   -83,
      22,    23,    24,    28,    62,    92,   177,    63,    28,   121,
      67,    75,    78,    79,    64,    74,    10,   167,   168,   169,
     170,   171,    80,   166,    28,    25,    76,    83,    84,    93,
     173,    85,    86,    92,    25,    94,    87,   172,    28,   186,
     187,    83,    84,    97,   103,    85,    86,   107,   108,   111,
      87,   112,   113,   114,   115,   116,   130,   117,   131,   144,
     132,   188,   138,   139,   140,   141,   142,   112,   113,   114,
     115,   116,   133,   146,   147,   155,   215,   203,   150,   154,
     159,   158,   161,   184,   160,   215,   178,   185,   221,   192,
     196,   200,   201,   197,   204,   210,   209,   220,    40,    42,
     219,   190,   206,   134,   176,   135,   110,   122
};

static const yytype_uint8 yycheck[] =
{
      22,     5,    12,    21,    13,    34,    10,     3,   154,   153,
      12,    26,    44,    45,    33,    47,    14,    15,    11,    12,
      73,    13,    26,    12,    22,    40,     6,    25,    51,    60,
      13,     9,   178,    13,    65,    13,    40,    69,    61,    51,
      58,    39,    40,    41,    73,    54,    68,   191,    80,    61,
      82,    83,    84,    85,    86,    87,     7,     8,    62,    51,
      92,    93,    55,    56,    60,     0,    55,    56,    51,    65,
      72,    73,    73,   204,    73,    73,    14,    15,   209,    72,
      73,     5,     6,    72,    73,    14,    15,    25,    73,    21,
      54,    23,    24,     4,     5,     6,    25,   130,   131,    12,
      32,    39,    40,    41,    36,   132,   133,     4,    12,     6,
      39,    40,    41,     5,    12,     9,   148,    12,    10,    13,
      54,    59,    44,    45,    12,    64,    58,    42,    43,    44,
      45,    46,    12,   137,    26,    73,    54,    48,    49,    10,
     144,    52,    53,     9,    73,    73,    57,    62,    40,   159,
     160,    48,    49,    62,    54,    52,    53,    73,    12,    64,
      57,    67,    68,    69,    70,    71,     5,    73,     6,    51,
       7,   175,    42,    43,    44,    45,    46,    67,    68,    69,
      70,    71,     8,    13,    51,    31,   208,   197,    73,    39,
      26,    60,    13,    35,    29,   217,    64,    72,   220,    73,
      61,    54,    60,    37,    64,    28,    63,    66,    10,    12,
     217,   180,   200,    92,   147,    93,    72,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    75,    76,     0,    21,    23,    24,    32,    36,
      58,    77,    78,    79,    81,    82,   100,   101,   104,    14,
      15,    25,    39,    40,    41,    73,    80,   110,   112,   116,
     117,   118,   119,   120,   134,   136,    73,    73,    73,    73,
      80,    79,    81,    54,    12,    12,    11,    12,    55,    56,
      72,   111,   112,   119,   122,   123,   126,   129,   130,   131,
     132,   133,    12,    12,    12,    22,   110,    54,     3,    60,
      65,   102,   105,    83,    64,    59,    54,   123,   130,   130,
      12,   123,     4,    48,    49,    52,    53,    57,   124,   125,
     127,   128,     9,    10,    73,   119,   135,    62,   138,   113,
     114,   115,   122,    54,   122,   121,   123,    73,    12,   107,
     107,    64,    67,    68,    69,    70,    71,    73,    98,    99,
      13,    13,   133,    13,   123,   123,   123,   123,   123,   123,
       5,     6,     7,     8,   131,   132,    13,    51,    42,    43,
      44,    45,    46,   139,    51,   137,    13,    51,    51,    61,
      73,   108,   109,   103,    39,    31,    84,    86,    60,    26,
      29,    13,   126,   126,   129,   129,   119,    42,    43,    44,
      45,    46,    62,   119,    13,    51,   115,   123,    64,    13,
      54,    77,    99,    85,    35,    72,    79,    79,   119,    99,
     109,   106,    73,    95,    96,    87,    61,    37,    77,    97,
      54,    60,    88,    79,    64,    34,    96,    89,    90,    63,
      28,    98,    51,    61,    92,   122,    98,    91,    93,    92,
      66,   122,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    76,    75,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    83,    82,    85,    84,
      86,    87,    84,    88,    90,    89,    91,    89,    93,    94,
      92,    95,    95,    97,    96,    98,    98,    99,    99,    99,
      99,    99,   100,   102,   103,   101,   105,   106,   104,   107,
     107,   108,   108,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   113,   113,   114,   114,   115,
     116,   117,   118,   119,   119,   119,   120,   121,   121,   122,
     122,   124,   123,   125,   123,   123,   127,   126,   128,   126,
     126,   129,   129,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   133,   133,   133,   133,   133,   134,
     135,   135,   135,   136,   137,   137,   137,   138,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     2,     3,     3,     3,
       2,     3,     1,     1,     1,     1,     0,     5,     0,     5,
       0,     0,     6,     3,     0,     2,     0,     4,     0,     0,
       5,     1,     3,     0,     4,     1,     1,     1,     1,     1,
       1,     4,     4,     0,     0,     6,     0,     0,     8,     0,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     0,     1,     4,     0,     1,     1,     3,     1,
       9,     6,     3,     1,     3,     1,     4,     3,     1,     1,
       1,     0,     4,     0,     4,     1,     0,     4,     0,     4,
       1,     3,     1,     1,     1,     3,     1,     3,     1,     4,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     4,
       0,     1,     3,     5,     0,     2,     3,     3,     0,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 137 "exp.y"
                 {nbProcFonc = 0; empilerRegion(cptRegion());}
#line 1665 "y.tab.c"
    break;

  case 3:
#line 138 "exp.y"
            {
                if(verbal){
                    AfficheTableLexico(); AfficheTableHash(); afficheTabDecl(); afficheTabTypeEntete(); afficheTabRegion(); MachineVirtuel(); AffichePileExec();
                }
                else{
                    MachineVirtuel();
                }
            }
#line 1678 "y.tab.c"
    break;

  case 4:
#line 155 "exp.y"
                                                        {maTableRegion.donnee[numRegion()].Arbre = (yyvsp[0].type1); maTableRegion.donnee[numRegion()].NIS = numNIS();}
#line 1684 "y.tab.c"
    break;

  case 5:
#line 156 "exp.y"
                                                        {maTableRegion.donnee[numRegion()].Arbre = (yyvsp[0].type1); maTableRegion.donnee[numRegion()].NIS = numNIS();}
#line 1690 "y.tab.c"
    break;

  case 8:
#line 177 "exp.y"
                                                        {(yyval.type1) = (yyvsp[-1].type1);}
#line 1696 "y.tab.c"
    break;

  case 9:
#line 178 "exp.y"
                                                        {(yyval.type1) = (yyvsp[-1].type1);}
#line 1702 "y.tab.c"
    break;

  case 10:
#line 188 "exp.y"
                                                                                {(yyval.type1) = (yyvsp[-1].type1);}
#line 1708 "y.tab.c"
    break;

  case 11:
#line 189 "exp.y"
                                                                                {(yyval.type1) = concatPereFrere((yyvsp[-2].type1), (yyvsp[-1].type1));}
#line 1714 "y.tab.c"
    break;

  case 16:
#line 214 "exp.y"
                            {numLexico = (yyvsp[0].type2);}
#line 1720 "y.tab.c"
    break;

  case 18:
#line 226 "exp.y"
                                {tailleStructTab = 0; nbChamps = 0;}
#line 1726 "y.tab.c"
    break;

  case 19:
#line 227 "exp.y"
                        {  
                            if(associationNom(numLexico, DECL_TYPE_STRUCTURE) != -1){
                                yyerror();
                                printf("Une structure utilisant ce nom [%s] est déja déclaré et accessible\n", maTableLexico.donnee[numLexico].lexeme);
                                exit(-1);     
                            }
                            insererTabDecl(1, numLexico, tailleStructTab, 0, nbProcFonc); 
                            insererStructTabTypesEntete(nbChamps, listeChamps);
                       }
#line 1740 "y.tab.c"
    break;

  case 20:
#line 237 "exp.y"
                         {tailleStructTab = 0;}
#line 1746 "y.tab.c"
    break;

  case 21:
#line 237 "exp.y"
                                                        {tailleDimension = 1; nbDim = 0; tmpBorne = 0;}
#line 1752 "y.tab.c"
    break;

  case 22:
#line 238 "exp.y"
                       {
                            if(associationNom(numLexico, DECL_TYPE_TABLEAU) != -1){
                                yyerror();
                                printf("Un tableau utilisant ce nom [%s] est déja déclaré et accessible\n", maTableLexico.donnee[numLexico].lexeme);
                                exit(-1);     
                            }
                            tailleStructTab = tailleStructTab * tailleDimension; 
                            (yyval.type1) = insererTabDecl(2, numLexico, tailleStructTab, 0, nbProcFonc);
                            insererTableauTabTypesEntete(tmpTypeTab, nbDim, tabBorne);
                       }
#line 1767 "y.tab.c"
    break;

  case 24:
#line 266 "exp.y"
                   {valExpression = 0;}
#line 1773 "y.tab.c"
    break;

  case 25:
#line 266 "exp.y"
                                                      {nbDim++;}
#line 1779 "y.tab.c"
    break;

  case 26:
#line 267 "exp.y"
                                            {valExpression = 0;}
#line 1785 "y.tab.c"
    break;

  case 27:
#line 267 "exp.y"
                                                                                {nbDim++;}
#line 1791 "y.tab.c"
    break;

  case 28:
#line 276 "exp.y"
                           {tabBorne[tmpBorne] = valExpression; tmpBorne++;}
#line 1797 "y.tab.c"
    break;

  case 29:
#line 276 "exp.y"
                                                                                                    {tabBorne[tmpBorne] = valExpression; tmpBorne++;}
#line 1803 "y.tab.c"
    break;

  case 30:
#line 277 "exp.y"
                                                                                                                                {
                                                                                                                                    tailleDimension *= (tabBorne[tmpBorne-1] - tabBorne[tmpBorne-2] + 1);
                                                                                                                                }
#line 1811 "y.tab.c"
    break;

  case 33:
#line 299 "exp.y"
               {listeChamps[nbChamps] = (yyvsp[0].type2); nbChamps++;}
#line 1817 "y.tab.c"
    break;

  case 36:
#line 311 "exp.y"
           {
                if(associationNom((yyvsp[0].type2), DECL_TYPE_TABLEAU) == -1 && associationNom((yyvsp[0].type2), DECL_TYPE_STRUCTURE) == -1){
                    yyerror();
                    printf("Le type donné [%s] a la variable n'éxiste pas !\n", maTableLexico.donnee[(yyvsp[0].type2)].lexeme);
                    exit(-1);     
                }
                tailleStructTab += tailleType((yyvsp[0].type2)); tmpTypeVar = (yyvsp[0].type2); listeChamps[nbChamps] = (yyvsp[0].type2); nbChamps++; tmpTypeTab = (yyvsp[0].type2);
           }
#line 1830 "y.tab.c"
    break;

  case 37:
#line 331 "exp.y"
                                                {tailleStructTab += 1; tmpTypeVar = 0; listeChamps[nbChamps] = 0; nbChamps++;
                                                 tmpTypeTab = 0;
                                                 listeParam[nbParam] = 0; 
                                                 tmpRetour = 0; nbParam++;}
#line 1839 "y.tab.c"
    break;

  case 38:
#line 335 "exp.y"
                                                {tailleStructTab += 1; tmpTypeVar = 1; listeChamps[nbChamps] = 1; nbChamps++;
                                                 tmpTypeTab = 1; 
                                                 tmpRetour = 1;
                                                 listeParam[nbParam] = 1; nbParam++;}
#line 1848 "y.tab.c"
    break;

  case 39:
#line 339 "exp.y"
                                                {tailleStructTab += 1; tmpTypeVar = 2; listeChamps[nbChamps] = 2; nbChamps++;
                                                 tmpTypeTab = 2; 
                                                 tmpRetour = 2;
                                                 listeParam[nbParam] = 2; nbParam++;}
#line 1857 "y.tab.c"
    break;

  case 40:
#line 343 "exp.y"
                                                {tailleStructTab += 1; tmpTypeVar = 3; listeChamps[nbChamps] = 3; nbChamps++;
                                                 tmpTypeTab = 3; 
                                                 tmpRetour = 3;
                                                 listeParam[nbParam] = 3; nbParam++;}
#line 1866 "y.tab.c"
    break;

  case 41:
#line 347 "exp.y"
                                                {tailleStructTab += (yyvsp[-1].type2);}
#line 1872 "y.tab.c"
    break;

  case 42:
#line 357 "exp.y"
                    {
                        if(associationNom((yyvsp[-2].type2), DECL_VARIABLE) != -1){
                            if(maTableDecl.donnee[associationNom((yyvsp[-2].type2), DECL_VARIABLE)].region == numRegion()){
                                yyerror();
                                printf("Une variable du même nom [%s] est déja déclaré dans la région actuel\n", maTableLexico.donnee[(yyvsp[-2].type2)].lexeme);
                                exit(-1); 
                            }
                        }
                        insererTabDecl(3, (yyvsp[-2].type2), tailleStructTab, tmpTypeVar, nbProcFonc);
                    }
#line 1887 "y.tab.c"
    break;

  case 43:
#line 376 "exp.y"
                        {
                            if(associationNom((yyvsp[0].type2), DECL_PROCEDURE) != -1){
                                yyerror();
                                printf("Une procédure du même nom [%s] est déja déclaré !\n", maTableLexico.donnee[(yyvsp[0].type2)].lexeme);
                                exit(-1); 
                            }
                            incrementeCptRegion(); 
                            incrementeNIS();  
                            nbParam = 0; 
                            nbProcFonc++; 
                            insererTabDecl(5, (yyvsp[0].type2), tailleStructTab, 0, nbProcFonc); 
                            empilerRegion(cptRegion());
                        }
#line 1905 "y.tab.c"
    break;

  case 44:
#line 389 "exp.y"
                                         {insererProcTabTypesEntete(nbParam, listeParam);}
#line 1911 "y.tab.c"
    break;

  case 45:
#line 389 "exp.y"
                                                                                                 {decrementeNIS(); depilerRegion();}
#line 1917 "y.tab.c"
    break;

  case 46:
#line 399 "exp.y"
                       {
                            if(associationNom((yyvsp[0].type2), DECL_FONCTION) != -1){
                                yyerror();
                                printf("Une Fonction du même nom [%s] est déja déclaré !\n", maTableLexico.donnee[(yyvsp[0].type2)].lexeme);
                                exit(-1); 
                            }
                            incrementeCptRegion(); incrementeNIS(); empilerRegion(cptRegion()); nbParam = 0; nbChamps = 0; nbProcFonc++; insererTabDecl(6, (yyvsp[0].type2), tailleStructTab, 0, nbProcFonc);
                       }
#line 1930 "y.tab.c"
    break;

  case 47:
#line 407 "exp.y"
                                                           {insererFoncTabTypesEntete(tmpRetour, nbParam, listeParam);}
#line 1936 "y.tab.c"
    break;

  case 48:
#line 408 "exp.y"
                             {decrementeNIS(); depilerRegion();}
#line 1942 "y.tab.c"
    break;

  case 53:
#line 440 "exp.y"
           {
                if(associationNom((yyvsp[-2].type2), DECL_PARAMETRE) != -1){
                    yyerror();
                    printf("Le nom de ce paramètre [%s] est déja utilisé !\n", maTableLexico.donnee[(yyvsp[-2].type2)].lexeme);
                    exit(-1); 
                }
                insererTabDecl(DECL_PARAMETRE, (yyvsp[-2].type2), tailleStructTab, 0, nbProcFonc); listeParam[nbParam] = associationNom((yyvsp[-2].type2), DECL_PARAMETRE); nbParam++;
           }
#line 1955 "y.tab.c"
    break;

  case 54:
#line 461 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), (yyvsp[0].type1));}
#line 1961 "y.tab.c"
    break;

  case 55:
#line 463 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), (yyvsp[0].type1));}
#line 1967 "y.tab.c"
    break;

  case 56:
#line 465 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), (yyvsp[0].type1));}
#line 1973 "y.tab.c"
    break;

  case 57:
#line 467 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), (yyvsp[0].type1));}
#line 1979 "y.tab.c"
    break;

  case 58:
#line 469 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), creerNoeud(A_VIDE, -1, -1));}
#line 1985 "y.tab.c"
    break;

  case 59:
#line 471 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), concatPereFrere(creerNoeud(A_RETURN, -1, -1), (yyvsp[0].type2)));}
#line 1991 "y.tab.c"
    break;

  case 60:
#line 473 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), (yyvsp[0].type1));}
#line 1997 "y.tab.c"
    break;

  case 61:
#line 475 "exp.y"
                                            {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_INSTR, -1, -1), (yyvsp[0].type1));}
#line 2003 "y.tab.c"
    break;

  case 63:
#line 486 "exp.y"
                                    {(yyval.type2) = (yyvsp[0].type1);}
#line 2009 "y.tab.c"
    break;

  case 64:
#line 495 "exp.y"
                                              {   
                                            if(associationNom((yyvsp[-3].type2), DECL_PROCEDURE) != -1){
                                                (yyval.type1) = concatPereFils(creerNoeud(A_APPEL_PROC, (yyvsp[-3].type2), associationNom((yyvsp[-3].type2), DECL_PROCEDURE)), (yyvsp[-1].type1));
                                            }else if(associationNom((yyvsp[-3].type2), DECL_FONCTION) != -1){
                                                (yyval.type1) = concatPereFils(creerNoeud(A_APPEL_FONC, (yyvsp[-3].type2), associationNom((yyvsp[-3].type2), DECL_FONCTION)), (yyvsp[-1].type1));
                                            }
                                            else{
                                                yyerror();
                                                AfficheTableLexico(); afficheTabDecl();
                                                printf("\nAppel impossible, fonction ou procédure pas déclaré : %d\n", (yyvsp[-3].type2));
                                                exit(-1);
                                            }
                                        }
#line 2027 "y.tab.c"
    break;

  case 65:
#line 517 "exp.y"
                                  {(yyval.type1) = creerNoeud(A_VIDE, -1, -1);}
#line 2033 "y.tab.c"
    break;

  case 66:
#line 518 "exp.y"
                                  {(yyval.type1) = (yyvsp[0].type1);}
#line 2039 "y.tab.c"
    break;

  case 67:
#line 528 "exp.y"
                                               {(yyval.type1) = (yyvsp[0].type1);}
#line 2045 "y.tab.c"
    break;

  case 68:
#line 529 "exp.y"
                                               {(yyval.type1) = concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1));}
#line 2051 "y.tab.c"
    break;

  case 69:
#line 538 "exp.y"
                                {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_ARG, -1, -1), (yyvsp[0].type1));}
#line 2057 "y.tab.c"
    break;

  case 70:
#line 549 "exp.y"
                                             {arbreIf = 1; (yyval.type1) = concatPereFils(creerNoeud(A_INSTR_COND, -1, -1), concatPereFrere(concatPereFrere((yyvsp[-6].type1), (yyvsp[-3].type1)), (yyvsp[-1].type1))); arbreIf = 0;}
#line 2063 "y.tab.c"
    break;

  case 71:
#line 558 "exp.y"
                                                        {(yyval.type1) = concatPereFils(creerNoeud(A_TANT_QUE, -1, -1), concatPereFrere((yyvsp[-3].type1), (yyvsp[0].type1)));}
#line 2069 "y.tab.c"
    break;

  case 72:
#line 567 "exp.y"
                                        {
                                            if(struc){
                                                (yyval.type1) = concatPereFils(creerNoeud(A_AFFECT, -1, -1), concatPereFrere(concatPereFils(creerNoeud(A_POINT, -1, -1), (yyvsp[-2].type1)), (yyvsp[0].type1)));
                                                struc = 0;
                                            }
                                            else{
                                                (yyval.type1) = concatPereFils(creerNoeud(A_AFFECT, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));
                                            }
                                        }
#line 2083 "y.tab.c"
    break;

  case 73:
#line 587 "exp.y"
            {
                if(associationNom((yyvsp[0].type2), DECL_VARIABLE) == -1){
                    yyerror();
                    printf("La variable [%s] n'est pas déclaré !\n", maTableLexico.donnee[(yyvsp[0].type2)].lexeme);
                    exit(-1); 
                }
                (yyval.type1) = creerNoeud(A_IDF, (yyvsp[0].type2), associationNom((yyvsp[0].type2), DECL_VARIABLE));
            }
#line 2096 "y.tab.c"
    break;

  case 74:
#line 595 "exp.y"
                                         {struc = 1; (yyval.type1) = concatPereFrere((yyvsp[-2].type1), creerNoeud(A_IDF, (yyvsp[0].type2), associationNom((yyvsp[0].type2), DECL_VARIABLE)));}
#line 2102 "y.tab.c"
    break;

  case 76:
#line 605 "exp.y"
                                        {
                                            if(struc){
                                                tmp = concatPereFils(creerNoeud(A_TABLEAU, -1, -1), concatPereFils((yyvsp[-3].type1)->frereDroit, (yyvsp[-1].type1)));
                                                (yyvsp[-3].type1)->frereDroit = NULL;
                                                (yyval.type1) = concatPereFrere((yyvsp[-3].type1), tmp);
                                            }
                                            else{
                                                (yyval.type1) = concatPereFils(creerNoeud(A_TABLEAU, -1, -1), concatPereFils((yyvsp[-3].type1), (yyvsp[-1].type1)));
                                            }      
                                        }
#line 2117 "y.tab.c"
    break;

  case 77:
#line 624 "exp.y"
                                       {(yyval.type1) = concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1));}
#line 2123 "y.tab.c"
    break;

  case 78:
#line 625 "exp.y"
                                       {(yyval.type1) = (yyvsp[0].type1);}
#line 2129 "y.tab.c"
    break;

  case 79:
#line 635 "exp.y"
                            {(yyval.type1) = (yyvsp[0].type1);}
#line 2135 "y.tab.c"
    break;

  case 80:
#line 636 "exp.y"
                            {(yyval.type1) = (yyvsp[0].type1);}
#line 2141 "y.tab.c"
    break;

  case 81:
#line 647 "exp.y"
          {valGauche = valExpression;}
#line 2147 "y.tab.c"
    break;

  case 82:
#line 647 "exp.y"
                                                     {(yyval.type1) = concatPereFils(creerNoeud(A_PLUS, -1, -1), concatPereFrere((yyvsp[-3].type1), (yyvsp[0].type1))); valExpression = (valGauche + valExpression);}
#line 2153 "y.tab.c"
    break;

  case 83:
#line 649 "exp.y"
          {valGauche = valExpression;}
#line 2159 "y.tab.c"
    break;

  case 84:
#line 649 "exp.y"
                                                     {(yyval.type1) = concatPereFils(creerNoeud(A_MOINS, -1, -1), concatPereFrere((yyvsp[-3].type1), (yyvsp[0].type1))); valExpression = (valGauche - valExpression);}
#line 2165 "y.tab.c"
    break;

  case 85:
#line 651 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2171 "y.tab.c"
    break;

  case 86:
#line 662 "exp.y"
          {valGauche = valExpression;}
#line 2177 "y.tab.c"
    break;

  case 87:
#line 662 "exp.y"
                                                     {(yyval.type1) = concatPereFils(creerNoeud(A_MULT, -1, -1), concatPereFrere((yyvsp[-3].type1), (yyvsp[0].type1))); 
                                                      valExpression = (valGauche * valExpression);}
#line 2184 "y.tab.c"
    break;

  case 88:
#line 665 "exp.y"
          {valGauche = valExpression;}
#line 2190 "y.tab.c"
    break;

  case 89:
#line 665 "exp.y"
                                                     {(yyval.type1) = concatPereFils(creerNoeud(A_DIV, -1, -1), concatPereFrere((yyvsp[-3].type1), (yyvsp[0].type1))); 
                                                      if(valExpression == 0){
                                                        yyerror();
                                                        printf("\nErreur division par 0 ! Danger !\n");
                                                        exit(-1);
                                                      }
                                                      valExpression = (valGauche / valExpression);}
#line 2202 "y.tab.c"
    break;

  case 90:
#line 673 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2208 "y.tab.c"
    break;

  case 91:
#line 685 "exp.y"
                        {(yyval.type1) = (yyvsp[-1].type1);}
#line 2214 "y.tab.c"
    break;

  case 92:
#line 686 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2220 "y.tab.c"
    break;

  case 93:
#line 687 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2226 "y.tab.c"
    break;

  case 94:
#line 688 "exp.y"
                        {(yyval.type1) = creerNoeud(A_ENTIER, (yyvsp[0].type2), -1); valExpression = (yyvsp[0].type2);}
#line 2232 "y.tab.c"
    break;

  case 95:
#line 698 "exp.y"
                        {(yyval.type1) = concatPereFils(creerNoeud(A_ET, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2238 "y.tab.c"
    break;

  case 96:
#line 699 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2244 "y.tab.c"
    break;

  case 97:
#line 709 "exp.y"
                        {(yyval.type1) = concatPereFils(creerNoeud(A_OU, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2250 "y.tab.c"
    break;

  case 98:
#line 710 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2256 "y.tab.c"
    break;

  case 99:
#line 720 "exp.y"
                        {(yyval.type1) = concatPereFils(creerNoeud(A_NON, -1, -1), (yyvsp[-1].type1));}
#line 2262 "y.tab.c"
    break;

  case 100:
#line 721 "exp.y"
                        {(yyval.type1) = (yyvsp[0].type1);}
#line 2268 "y.tab.c"
    break;

  case 101:
#line 733 "exp.y"
                            {(yyval.type1) = concatPereFils(creerNoeud(A_INF, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2274 "y.tab.c"
    break;

  case 102:
#line 734 "exp.y"
                            {(yyval.type1) = concatPereFils(creerNoeud(A_SUP, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2280 "y.tab.c"
    break;

  case 103:
#line 735 "exp.y"
                            {(yyval.type1) = concatPereFils(creerNoeud(A_INF_EGAL, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2286 "y.tab.c"
    break;

  case 104:
#line 736 "exp.y"
                            {(yyval.type1) = concatPereFils(creerNoeud(A_SUP_EGAL, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2292 "y.tab.c"
    break;

  case 105:
#line 737 "exp.y"
                            {(yyval.type1) = concatPereFils(creerNoeud(A_EGAL, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2298 "y.tab.c"
    break;

  case 106:
#line 738 "exp.y"
                            {(yyval.type1) = concatPereFils(creerNoeud(A_DIFF, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2304 "y.tab.c"
    break;

  case 107:
#line 739 "exp.y"
                            {(yyval.type1) = creerNoeud(A_TRUE, 1, -1);}
#line 2310 "y.tab.c"
    break;

  case 108:
#line 740 "exp.y"
                            {(yyval.type1) = creerNoeud(A_FALSE, 0, -1);}
#line 2316 "y.tab.c"
    break;

  case 109:
#line 750 "exp.y"
                                        {(yyval.type1) = concatPereFils(creerNoeud(A_LIRE, -1, -1), (yyvsp[-1].type1));}
#line 2322 "y.tab.c"
    break;

  case 111:
#line 761 "exp.y"
                                                        {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_VAR, -1, -1), (yyvsp[0].type1));}
#line 2328 "y.tab.c"
    break;

  case 112:
#line 762 "exp.y"
                                                        {(yyval.type1) = concatPereFils(creerNoeud(A_LISTE_VAR, -1, -1), concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1)));}
#line 2334 "y.tab.c"
    break;

  case 113:
#line 772 "exp.y"
        {(yyval.type1) = concatPereFils(creerNoeud(A_ECRIRE, -1, -1), concatPereFrere(concatPereFils(creerNoeud(A_LISTE_FORMAT, -1, -1), (yyvsp[-2].type1)), concatPereFils(creerNoeud(A_SUITE_ECRITURE, -1, -1), (yyvsp[-1].type1))));}
#line 2340 "y.tab.c"
    break;

  case 114:
#line 781 "exp.y"
                                                    {(yyval.type1) = creerNoeud(A_VIDE, -1, -1);}
#line 2346 "y.tab.c"
    break;

  case 115:
#line 782 "exp.y"
                                                    {
                                                        if(struc){
                                                            (yyval.type1) = concatPereFils(creerNoeud(A_POINT, -1, -1), (yyvsp[0].type1));
                                                            struc = 0;
                                                        }
                                                        else{
                                                            (yyval.type1) = (yyvsp[0].type1);
                                                        } 
                                                    }
#line 2360 "y.tab.c"
    break;

  case 116:
#line 791 "exp.y"
                                                    {
                                                        if(struc){
                                                            (yyval.type1) = concatPereFrere((yyvsp[-2].type1), concatPereFils(creerNoeud(A_POINT, -1, -1), (yyvsp[0].type1)));
                                                            struc = 0;
                                                        }
                                                        else{
                                                            (yyval.type1) = concatPereFrere((yyvsp[-2].type1), (yyvsp[0].type1));
                                                        } 
                                                    }
#line 2374 "y.tab.c"
    break;

  case 117:
#line 807 "exp.y"
                                    {(yyval.type1) = (yyvsp[-1].type1);}
#line 2380 "y.tab.c"
    break;

  case 118:
#line 827 "exp.y"
                                            {(yyval.type1) = creerNoeud(A_VIDE, -1, -1);}
#line 2386 "y.tab.c"
    break;

  case 119:
#line 828 "exp.y"
                                            {(yyval.type1) = creerNoeud(A_FORMAT_INT, -1, -1);}
#line 2392 "y.tab.c"
    break;

  case 120:
#line 829 "exp.y"
                                            {(yyval.type1) = creerNoeud(A_FORMAT_BOOL, -1, -1);}
#line 2398 "y.tab.c"
    break;

  case 121:
#line 830 "exp.y"
                                            {(yyval.type1) = creerNoeud(A_FORMAT_FLOAT, -1, -1);}
#line 2404 "y.tab.c"
    break;

  case 122:
#line 831 "exp.y"
                                            {(yyval.type1) = creerNoeud(A_FORMAT_CHAR, -1, -1);}
#line 2410 "y.tab.c"
    break;

  case 123:
#line 832 "exp.y"
                                            {(yyval.type1) = creerNoeud(A_FORMAT_STRING, -1, -1);}
#line 2416 "y.tab.c"
    break;

  case 124:
#line 833 "exp.y"
                                            {(yyval.type1) = concatPereFrere((yyvsp[-1].type1), creerNoeud(A_FORMAT_INT, -1, -1));}
#line 2422 "y.tab.c"
    break;

  case 125:
#line 834 "exp.y"
                                            {(yyval.type1) = concatPereFrere((yyvsp[-1].type1), creerNoeud(A_FORMAT_BOOL, -1, -1));}
#line 2428 "y.tab.c"
    break;

  case 126:
#line 835 "exp.y"
                                            {(yyval.type1) = concatPereFrere((yyvsp[-1].type1), creerNoeud(A_FORMAT_FLOAT, -1, -1));}
#line 2434 "y.tab.c"
    break;

  case 127:
#line 836 "exp.y"
                                            {(yyval.type1) = concatPereFrere((yyvsp[-1].type1), creerNoeud(A_FORMAT_CHAR, -1, -1));}
#line 2440 "y.tab.c"
    break;

  case 128:
#line 837 "exp.y"
                                            {(yyval.type1) = concatPereFrere((yyvsp[-1].type1), creerNoeud(A_FORMAT_STRING, -1, -1));}
#line 2446 "y.tab.c"
    break;


#line 2450 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 841 "exp.y"


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

