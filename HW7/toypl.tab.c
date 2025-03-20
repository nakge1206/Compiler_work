/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "toypl.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "gencode.h"
Node * rootNode;

void yyerror(const char *s);
int yylex(void);

#line 83 "toypl.tab.c"

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

#include "toypl.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TPROGRAM = 3,                   /* TPROGRAM  */
  YYSYMBOL_TMAIN = 4,                      /* TMAIN  */
  YYSYMBOL_TPROC = 5,                      /* TPROC  */
  YYSYMBOL_TFUNC = 6,                      /* TFUNC  */
  YYSYMBOL_TRETURNS = 7,                   /* TRETURNS  */
  YYSYMBOL_TVAR = 8,                       /* TVAR  */
  YYSYMBOL_TINT = 9,                       /* TINT  */
  YYSYMBOL_TLONG = 10,                     /* TLONG  */
  YYSYMBOL_TIF = 11,                       /* TIF  */
  YYSYMBOL_TTHEN = 12,                     /* TTHEN  */
  YYSYMBOL_TELSE = 13,                     /* TELSE  */
  YYSYMBOL_TWHILE = 14,                    /* TWHILE  */
  YYSYMBOL_TFOR = 15,                      /* TFOR  */
  YYSYMBOL_TTO = 16,                       /* TTO  */
  YYSYMBOL_TCALL = 17,                     /* TCALL  */
  YYSYMBOL_TRETURN = 18,                   /* TRETURN  */
  YYSYMBOL_TBEGIN = 19,                    /* TBEGIN  */
  YYSYMBOL_TEND = 20,                      /* TEND  */
  YYSYMBOL_TNUMBER = 21,                   /* TNUMBER  */
  YYSYMBOL_TNAME = 22,                     /* TNAME  */
  YYSYMBOL_TEQUAL = 23,                    /* TEQUAL  */
  YYSYMBOL_TAND = 24,                      /* TAND  */
  YYSYMBOL_TOR = 25,                       /* TOR  */
  YYSYMBOL_TNOT = 26,                      /* TNOT  */
  YYSYMBOL_TLESS = 27,                     /* TLESS  */
  YYSYMBOL_TLESSEQ = 28,                   /* TLESSEQ  */
  YYSYMBOL_TGREATER = 29,                  /* TGREATER  */
  YYSYMBOL_TGREATEREQ = 30,                /* TGREATEREQ  */
  YYSYMBOL_TNOTEQ = 31,                    /* TNOTEQ  */
  YYSYMBOL_TPLUS = 32,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 33,                    /* TMINUS  */
  YYSYMBOL_TMULT = 34,                     /* TMULT  */
  YYSYMBOL_TDIV = 35,                      /* TDIV  */
  YYSYMBOL_TSEMI = 36,                     /* TSEMI  */
  YYSYMBOL_TCOLON = 37,                    /* TCOLON  */
  YYSYMBOL_TCOMMA = 38,                    /* TCOMMA  */
  YYSYMBOL_TDOT = 39,                      /* TDOT  */
  YYSYMBOL_TLPAREN = 40,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 41,                   /* TRPAREN  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_VarDecl = 44,                   /* VarDecl  */
  YYSYMBOL_DclList = 45,                   /* DclList  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_VarList = 47,                   /* VarList  */
  YYSYMBOL_Type = 48,                      /* Type  */
  YYSYMBOL_Var = 49,                       /* Var  */
  YYSYMBOL_SubPgmList = 50,                /* SubPgmList  */
  YYSYMBOL_SubPgm = 51,                    /* SubPgm  */
  YYSYMBOL_ProcDecl = 52,                  /* ProcDecl  */
  YYSYMBOL_FunDecl = 53,                   /* FunDecl  */
  YYSYMBOL_FormParam = 54,                 /* FormParam  */
  YYSYMBOL_Cond = 55,                      /* Cond  */
  YYSYMBOL_Rel = 56,                       /* Rel  */
  YYSYMBOL_Expr = 57,                      /* Expr  */
  YYSYMBOL_Term = 58,                      /* Term  */
  YYSYMBOL_Fact = 59,                      /* Fact  */
  YYSYMBOL_FuncCall = 60,                  /* FuncCall  */
  YYSYMBOL_ParamList = 61,                 /* ParamList  */
  YYSYMBOL_ExprList = 62,                  /* ExprList  */
  YYSYMBOL_Stmt = 63,                      /* Stmt  */
  YYSYMBOL_AsgnStmt = 64,                  /* AsgnStmt  */
  YYSYMBOL_IfStmt = 65,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 66,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 67,                   /* ForStmt  */
  YYSYMBOL_CallStmt = 68,                  /* CallStmt  */
  YYSYMBOL_RtrnStmt = 69,                  /* RtrnStmt  */
  YYSYMBOL_CompStmt = 70,                  /* CompStmt  */
  YYSYMBOL_StmtList = 71                   /* StmtList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    38,    41,    45,    51,    55,    64,    70,
      74,    77,    83,    90,   100,   104,   105,   109,   120,   132,
     133,   137,   141,   145,   148,   152,   156,   160,   164,   168,
     172,   179,   183,   187,   191,   195,   199,   203,   204,   208,
     209,   212,   216,   223,   224,   228,   234,   238,   239,   240,
     241,   242,   243,   244,   248,   255,   259,   267,   274,   283,
     290,   296,   302,   308
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TPROGRAM", "TMAIN",
  "TPROC", "TFUNC", "TRETURNS", "TVAR", "TINT", "TLONG", "TIF", "TTHEN",
  "TELSE", "TWHILE", "TFOR", "TTO", "TCALL", "TRETURN", "TBEGIN", "TEND",
  "TNUMBER", "TNAME", "TEQUAL", "TAND", "TOR", "TNOT", "TLESS", "TLESSEQ",
  "TGREATER", "TGREATEREQ", "TNOTEQ", "TPLUS", "TMINUS", "TMULT", "TDIV",
  "TSEMI", "TCOLON", "TCOMMA", "TDOT", "TLPAREN", "TRPAREN", "$accept",
  "Program", "VarDecl", "DclList", "Decl", "VarList", "Type", "Var",
  "SubPgmList", "SubPgm", "ProcDecl", "FunDecl", "FormParam", "Cond",
  "Rel", "Expr", "Term", "Fact", "FuncCall", "ParamList", "ExprList",
  "Stmt", "AsgnStmt", "IfStmt", "WhileStmt", "ForStmt", "CallStmt",
  "RtrnStmt", "CompStmt", "StmtList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    -7,    42,    20,   -60,   -60,    17,    41,    38,    38,
     -60,   -60,   -60,    38,    49,   -60,    33,    51,    35,   -60,
     -25,   -60,    64,    61,    38,    38,    38,    80,    38,    63,
      65,    73,    38,    76,    94,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,    31,   -60,    82,    78,    81,   -60,   -60,
     -60,   -60,   -60,     4,     4,    38,    84,    37,    37,   -60,
      64,    38,    41,   113,   -60,    37,    37,    37,    86,   -14,
     -60,    79,    60,   -60,   -60,     9,    98,    37,    13,    66,
     -60,    49,    87,   -60,   -60,    52,    37,    37,    37,   116,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      64,    37,    66,    89,    93,   -60,   -60,    80,   -60,    91,
     -60,   -60,    64,    66,    66,    66,    66,    66,    66,    60,
      60,   -60,   -60,   -60,     3,   -60,    37,    92,   -60,   121,
      37,    66,    41,    64,    55,    49,   -60,    64,   -60,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,    14,     0,     4,     0,     0,
      13,    15,    16,     0,     0,    12,     0,     0,     0,     6,
       0,     9,     0,     0,    20,    20,     3,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    47,    48,    49,    50,
      51,    52,    53,     0,     2,    19,     0,     0,     5,    10,
      11,     7,     8,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     4,     0,    38,     0,     0,     0,    37,     0,
      24,     0,    33,    36,    39,     0,     0,    44,     0,    54,
      62,     0,     0,    23,    40,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    43,    60,    17,     0,    41,     0,
      21,    22,     0,    29,    25,    26,    27,    28,    30,    31,
      32,    34,    35,    57,     0,    59,     0,     0,    42,    55,
       0,    45,     4,     0,     0,     0,    56,     0,    18,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -58,   122,   -20,   -60,    29,    -8,   -60,   -60,
     -60,   -60,   112,    85,   -56,   -29,    18,   -59,   -60,    54,
     -60,   -57,   -60,   -60,   -60,   -60,   -60,   -60,   -12,   -60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    14,    45,    19,    20,    51,    68,     6,    10,
      11,    12,    46,    69,    70,    71,    72,    73,    74,   103,
     104,    35,    36,    37,    38,    39,    40,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    17,    23,    80,    81,    21,    48,    84,     1,    83,
      87,    88,    27,    28,    34,     3,    21,    21,    21,   130,
      52,     7,     8,     9,    56,    64,    15,    89,    78,    79,
      65,   110,   111,    87,    88,    96,    97,    66,    85,   121,
     122,    48,     4,   123,    67,    96,    97,    76,   102,    13,
     100,    59,    34,    21,   105,   129,     5,   102,    64,    15,
      15,   113,   114,   115,   116,   117,   118,    60,    22,   106,
      66,    26,   124,    24,   135,    29,   136,    67,    30,    31,
     139,    32,    33,    22,    96,    97,    15,    96,    97,    49,
      50,    25,    34,   108,    98,    99,   137,   131,    96,    97,
      44,   134,    90,    53,    34,    54,    91,    92,    93,    94,
      95,    96,    97,    55,   119,   120,    57,    58,    61,    62,
      82,   101,    63,   138,    77,    34,    86,   107,   112,    34,
     125,   126,   128,   132,   133,    18,   127,    47,     0,    75,
     109
};

static const yytype_int16 yycheck[] =
{
       8,     9,    14,    60,    62,    13,    26,    66,     3,    65,
      24,    25,    37,    38,    22,    22,    24,    25,    26,    16,
      28,     4,     5,     6,    32,    21,    22,    41,    57,    58,
      26,    87,    88,    24,    25,    32,    33,    33,    67,    98,
      99,    61,     0,   100,    40,    32,    33,    55,    77,     8,
      41,    20,    60,    61,    41,   112,    36,    86,    21,    22,
      22,    90,    91,    92,    93,    94,    95,    36,    19,    81,
      33,    36,   101,    40,   132,    11,   133,    40,    14,    15,
     137,    17,    18,    19,    32,    33,    22,    32,    33,     9,
      10,    40,   100,    41,    34,    35,    41,   126,    32,    33,
      39,   130,    23,    40,   112,    40,    27,    28,    29,    30,
      31,    32,    33,    40,    96,    97,    40,    23,    36,    41,
       7,    23,    41,   135,    40,   133,    40,    40,    12,   137,
      41,    38,    41,    41,    13,    13,   107,    25,    -1,    54,
      86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    22,     0,    36,    50,     4,     5,     6,
      51,    52,    53,     8,    44,    22,    49,    49,    45,    46,
      47,    49,    19,    70,    40,    40,    36,    37,    38,    11,
      14,    15,    17,    18,    49,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    39,    45,    54,    54,    46,     9,
      10,    48,    49,    40,    40,    40,    49,    40,    23,    20,
      36,    36,    41,    41,    21,    26,    33,    40,    49,    55,
      56,    57,    58,    59,    60,    55,    49,    40,    57,    57,
      63,    44,     7,    56,    59,    57,    40,    24,    25,    41,
      23,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      41,    23,    57,    61,    62,    41,    70,    40,    41,    61,
      56,    56,    12,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    63,    57,    41,    38,    48,    41,    63,
      16,    57,    41,    13,    57,    44,    63,    41,    70,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      54,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    64,    65,    65,    66,    67,    68,
      69,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     3,     0,     3,     1,     3,     3,     1,
       1,     1,     1,     2,     0,     1,     1,     7,    11,     1,
       0,     3,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       2,     3,     4,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     8,     5,     9,     5,
       4,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: TPROGRAM TNAME TSEMI SubPgmList TMAIN VarDecl CompStmt TDOT  */
#line 31 "toypl.y"
                                                                    {
		rootNode = makeNode("PROGRAM", (yyvsp[-4].nodeP), (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[-1].nodeP);
	}
#line 1232 "toypl.tab.c"
    break;

  case 3: /* VarDecl: TVAR DclList TSEMI  */
#line 38 "toypl.y"
                                {
		(yyval.nodeP) = makeNode("VARDECL", NULL, (yyvsp[-1].nodeP));
	}
#line 1240 "toypl.tab.c"
    break;

  case 4: /* VarDecl: %empty  */
#line 41 "toypl.y"
                {	(yyval.nodeP)=NULL;	}
#line 1246 "toypl.tab.c"
    break;

  case 5: /* DclList: DclList TSEMI Decl  */
#line 45 "toypl.y"
                           {
		(yyval.nodeP) = (yyvsp[0].nodeP);
		Node* temp = (yyvsp[0].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[-2].nodeP);
	}
#line 1257 "toypl.tab.c"
    break;

  case 6: /* DclList: Decl  */
#line 51 "toypl.y"
                {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1263 "toypl.tab.c"
    break;

  case 7: /* Decl: VarList TCOLON Type  */
#line 55 "toypl.y"
                            {
		(yyval.nodeP) = makeNode("DECL", NULL, (yyvsp[-2].nodeP));
		Node* temp = (yyvsp[-2].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[0].nodeP);
	}
#line 1274 "toypl.tab.c"
    break;

  case 8: /* VarList: VarList TCOMMA Var  */
#line 64 "toypl.y"
                          {
		(yyval.nodeP) = (yyvsp[-2].nodeP);
		Node* temp = (yyvsp[-2].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[0].nodeP);
	}
#line 1285 "toypl.tab.c"
    break;

  case 9: /* VarList: Var  */
#line 70 "toypl.y"
              { (yyval.nodeP)=(yyvsp[0].nodeP); }
#line 1291 "toypl.tab.c"
    break;

  case 10: /* Type: TINT  */
#line 74 "toypl.y"
             {
		(yyval.nodeP) = makeNode("TINT", NULL, NULL);
	}
#line 1299 "toypl.tab.c"
    break;

  case 11: /* Type: TLONG  */
#line 77 "toypl.y"
                {
		(yyval.nodeP) = makeNode("TLONG", NULL, NULL);
	}
#line 1307 "toypl.tab.c"
    break;

  case 12: /* Var: TNAME  */
#line 83 "toypl.y"
              {
		(yyval.nodeP)=makeNode("NAME", NULL, NULL);
		(yyval.nodeP)->value.sv = (yyvsp[0].sval);
	}
#line 1316 "toypl.tab.c"
    break;

  case 13: /* SubPgmList: SubPgmList SubPgm  */
#line 90 "toypl.y"
                          {
		if((yyvsp[-1].nodeP)==NULL){
			(yyval.nodeP) = (yyvsp[0].nodeP);
		} else{
			(yyval.nodeP) = (yyvsp[-1].nodeP);
			Node* temp = (yyvsp[-1].nodeP);
			while(temp->bro != NULL) { temp=temp->bro; }
			temp->bro = (yyvsp[0].nodeP);
		}
	}
#line 1331 "toypl.tab.c"
    break;

  case 14: /* SubPgmList: %empty  */
#line 100 "toypl.y"
                {	(yyval.nodeP)=NULL;	}
#line 1337 "toypl.tab.c"
    break;

  case 15: /* SubPgm: ProcDecl  */
#line 104 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1343 "toypl.tab.c"
    break;

  case 16: /* SubPgm: FunDecl  */
#line 105 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1349 "toypl.tab.c"
    break;

  case 17: /* ProcDecl: TPROC Var TLPAREN FormParam TRPAREN VarDecl CompStmt  */
#line 109 "toypl.y"
                                                             {
		(yyval.nodeP) = makeNode("PROC", NULL, (yyvsp[-5].nodeP));
		(yyvsp[-5].nodeP)->bro = (yyvsp[-3].nodeP);
		Node* temp = (yyvsp[-3].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[-1].nodeP);
		(yyvsp[-1].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1362 "toypl.tab.c"
    break;

  case 18: /* FunDecl: TFUNC Var TLPAREN FormParam TRPAREN TRETURNS TLPAREN Type TRPAREN VarDecl CompStmt  */
#line 120 "toypl.y"
                                                                                           {
		(yyval.nodeP) = makeNode("FUNC", NULL, (yyvsp[-9].nodeP));
		(yyvsp[-9].nodeP)->bro = (yyvsp[-3].nodeP);
		(yyvsp[-3].nodeP)->bro = (yyvsp[-7].nodeP);
		Node* temp = (yyvsp[-7].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[-1].nodeP);
		(yyvsp[-1].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1376 "toypl.tab.c"
    break;

  case 19: /* FormParam: DclList  */
#line 132 "toypl.y"
                { (yyval.nodeP)=(yyvsp[0].nodeP); }
#line 1382 "toypl.tab.c"
    break;

  case 20: /* FormParam: %empty  */
#line 133 "toypl.y"
          { (yyval.nodeP)=NULL; }
#line 1388 "toypl.tab.c"
    break;

  case 21: /* Cond: Cond TAND Rel  */
#line 137 "toypl.y"
                      {
		(yyval.nodeP) = makeNode("AND", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1397 "toypl.tab.c"
    break;

  case 22: /* Cond: Cond TOR Rel  */
#line 141 "toypl.y"
                       {
		(yyval.nodeP) = makeNode("OR", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1406 "toypl.tab.c"
    break;

  case 23: /* Cond: TNOT Rel  */
#line 145 "toypl.y"
                   {
		(yyval.nodeP) = makeNode("NOT", NULL, (yyvsp[0].nodeP));
	}
#line 1414 "toypl.tab.c"
    break;

  case 24: /* Cond: Rel  */
#line 148 "toypl.y"
              { (yyval.nodeP) = (yyvsp[0].nodeP); }
#line 1420 "toypl.tab.c"
    break;

  case 25: /* Rel: Expr TLESS Expr  */
#line 152 "toypl.y"
                       {
		(yyval.nodeP) = makeNode("LT", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1429 "toypl.tab.c"
    break;

  case 26: /* Rel: Expr TLESSEQ Expr  */
#line 156 "toypl.y"
                            {
		(yyval.nodeP) = makeNode("LE", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1438 "toypl.tab.c"
    break;

  case 27: /* Rel: Expr TGREATER Expr  */
#line 160 "toypl.y"
                             {
		(yyval.nodeP) = makeNode("GT", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1447 "toypl.tab.c"
    break;

  case 28: /* Rel: Expr TGREATEREQ Expr  */
#line 164 "toypl.y"
                               {
		(yyval.nodeP) = makeNode("GE", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1456 "toypl.tab.c"
    break;

  case 29: /* Rel: Expr TEQUAL Expr  */
#line 168 "toypl.y"
                           {
		(yyval.nodeP) = makeNode("EQ", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1465 "toypl.tab.c"
    break;

  case 30: /* Rel: Expr TNOTEQ Expr  */
#line 172 "toypl.y"
                           {
		(yyval.nodeP) = makeNode("NE", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1474 "toypl.tab.c"
    break;

  case 31: /* Expr: Expr TPLUS Term  */
#line 179 "toypl.y"
                        {
		(yyval.nodeP)=makeNode("PLUS", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1483 "toypl.tab.c"
    break;

  case 32: /* Expr: Expr TMINUS Term  */
#line 183 "toypl.y"
                          {
		(yyval.nodeP)=makeNode("MINUS", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1492 "toypl.tab.c"
    break;

  case 33: /* Expr: Term  */
#line 187 "toypl.y"
                {	(yyval.nodeP) = (yyvsp[0].nodeP);	}
#line 1498 "toypl.tab.c"
    break;

  case 34: /* Term: Term TMULT Fact  */
#line 191 "toypl.y"
                        {
		(yyval.nodeP)=makeNode("TIMES", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1507 "toypl.tab.c"
    break;

  case 35: /* Term: Term TDIV Fact  */
#line 195 "toypl.y"
                         {
		(yyval.nodeP)=makeNode("DIVIDE", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1516 "toypl.tab.c"
    break;

  case 36: /* Term: Fact  */
#line 199 "toypl.y"
                {	(yyval.nodeP) = (yyvsp[0].nodeP);	}
#line 1522 "toypl.tab.c"
    break;

  case 37: /* Fact: Var  */
#line 203 "toypl.y"
            {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1528 "toypl.tab.c"
    break;

  case 38: /* Fact: TNUMBER  */
#line 204 "toypl.y"
                  {
		(yyval.nodeP)=makeNode("NUMBER", NULL, NULL);
		(yyval.nodeP)->value.dv = (yyvsp[0].dval);
	}
#line 1537 "toypl.tab.c"
    break;

  case 39: /* Fact: FuncCall  */
#line 208 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1543 "toypl.tab.c"
    break;

  case 40: /* Fact: TMINUS Fact  */
#line 209 "toypl.y"
                      {
		(yyval.nodeP)=makeNode("NEG", NULL, (yyvsp[0].nodeP));
	}
#line 1551 "toypl.tab.c"
    break;

  case 41: /* Fact: TLPAREN Expr TRPAREN  */
#line 212 "toypl.y"
                               {	(yyval.nodeP)=(yyvsp[-1].nodeP);	}
#line 1557 "toypl.tab.c"
    break;

  case 42: /* FuncCall: Var TLPAREN ParamList TRPAREN  */
#line 216 "toypl.y"
                                      {
		(yyval.nodeP) = makeNode("FCALL", NULL, (yyvsp[-3].nodeP));
		(yyvsp[-3].nodeP)->bro = (yyvsp[-1].nodeP);
	}
#line 1566 "toypl.tab.c"
    break;

  case 43: /* ParamList: ExprList  */
#line 223 "toypl.y"
                        { (yyval.nodeP)=(yyvsp[0].nodeP); }
#line 1572 "toypl.tab.c"
    break;

  case 44: /* ParamList: %empty  */
#line 224 "toypl.y"
          { (yyval.nodeP)=NULL; }
#line 1578 "toypl.tab.c"
    break;

  case 45: /* ExprList: ExprList TCOMMA Expr  */
#line 228 "toypl.y"
                             {
		(yyval.nodeP) = (yyvsp[-2].nodeP);
		Node* temp = (yyvsp[-2].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[0].nodeP);
	}
#line 1589 "toypl.tab.c"
    break;

  case 46: /* ExprList: Expr  */
#line 234 "toypl.y"
                { (yyval.nodeP)=(yyvsp[0].nodeP); }
#line 1595 "toypl.tab.c"
    break;

  case 47: /* Stmt: AsgnStmt  */
#line 238 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1601 "toypl.tab.c"
    break;

  case 48: /* Stmt: IfStmt  */
#line 239 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1607 "toypl.tab.c"
    break;

  case 49: /* Stmt: WhileStmt  */
#line 240 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1613 "toypl.tab.c"
    break;

  case 50: /* Stmt: ForStmt  */
#line 241 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1619 "toypl.tab.c"
    break;

  case 51: /* Stmt: CallStmt  */
#line 242 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1625 "toypl.tab.c"
    break;

  case 52: /* Stmt: RtrnStmt  */
#line 243 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1631 "toypl.tab.c"
    break;

  case 53: /* Stmt: CompStmt  */
#line 244 "toypl.y"
                        {	(yyval.nodeP)=(yyvsp[0].nodeP);	}
#line 1637 "toypl.tab.c"
    break;

  case 54: /* AsgnStmt: Var TEQUAL Expr  */
#line 248 "toypl.y"
                        {
		(yyval.nodeP) = makeNode("ASSIGN", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1646 "toypl.tab.c"
    break;

  case 55: /* IfStmt: TIF TLPAREN Cond TRPAREN TTHEN Stmt  */
#line 255 "toypl.y"
                                            {
		(yyval.nodeP) = makeNode("IF", NULL, (yyvsp[-3].nodeP));
		(yyvsp[-3].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1655 "toypl.tab.c"
    break;

  case 56: /* IfStmt: TIF TLPAREN Cond TRPAREN TTHEN Stmt TELSE Stmt  */
#line 259 "toypl.y"
                                                         {
		(yyval.nodeP) = makeNode("IF", NULL, (yyvsp[-5].nodeP));
		(yyvsp[-5].nodeP)->bro = (yyvsp[-2].nodeP);
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1665 "toypl.tab.c"
    break;

  case 57: /* WhileStmt: TWHILE TLPAREN Cond TRPAREN Stmt  */
#line 267 "toypl.y"
                                         {
		(yyval.nodeP) = makeNode("WHILE", NULL, (yyvsp[-2].nodeP));
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1674 "toypl.tab.c"
    break;

  case 58: /* ForStmt: TFOR TLPAREN Var TEQUAL Expr TTO Expr TRPAREN Stmt  */
#line 274 "toypl.y"
                                                           {
		(yyval.nodeP) = makeNode("FOR", NULL, (yyvsp[-6].nodeP));
		(yyvsp[-6].nodeP)->bro = (yyvsp[-4].nodeP);
		(yyvsp[-4].nodeP)->bro = (yyvsp[-2].nodeP);
		(yyvsp[-2].nodeP)->bro = (yyvsp[0].nodeP);
	}
#line 1685 "toypl.tab.c"
    break;

  case 59: /* CallStmt: TCALL Var TLPAREN ParamList TRPAREN  */
#line 283 "toypl.y"
                                            {
		(yyval.nodeP) = makeNode("PCALL", NULL, (yyvsp[-3].nodeP));
		(yyvsp[-3].nodeP)->bro = (yyvsp[-1].nodeP);
	}
#line 1694 "toypl.tab.c"
    break;

  case 60: /* RtrnStmt: TRETURN TLPAREN Expr TRPAREN  */
#line 290 "toypl.y"
                                     {
		(yyval.nodeP) = makeNode("RETURN", NULL, (yyvsp[-1].nodeP));
	}
#line 1702 "toypl.tab.c"
    break;

  case 61: /* CompStmt: TBEGIN StmtList TEND  */
#line 296 "toypl.y"
                             {
		(yyval.nodeP) = makeNode("COMP", NULL, (yyvsp[-1].nodeP));
	}
#line 1710 "toypl.tab.c"
    break;

  case 62: /* StmtList: StmtList TSEMI Stmt  */
#line 302 "toypl.y"
                            {
		(yyval.nodeP) = (yyvsp[-2].nodeP);
		Node* temp = (yyvsp[-2].nodeP);
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = (yyvsp[0].nodeP);
	}
#line 1721 "toypl.tab.c"
    break;

  case 63: /* StmtList: Stmt  */
#line 308 "toypl.y"
               { (yyval.nodeP) = (yyvsp[0].nodeP); }
#line 1727 "toypl.tab.c"
    break;


#line 1731 "toypl.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 311 "toypl.y"


void yyerror(const char *s) {
    fprintf(stderr, "syntax error\n");
}

void traverse(Node *nodeP, int depth) {
    if (nodeP == NULL) {
        return;
    }
    
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    
    printf("%s", nodeP->kind);

	// value 출력
    if (strcmp(nodeP->kind, "NUMBER") == 0) {
        // NUMBER 노드의 경우 double 값 출력
        printf(" : %.2lf", nodeP->value.dv);
    } else if (strcmp(nodeP->kind, "NAME") == 0) {
        // NAME 노드의 경우 문자열 값 출력
        printf(" : %s", nodeP->value.sv);
    }

	printf("\n");
    
    // 자식 노드를 방문
    traverse(nodeP->son, depth + 1);
    // 형제 노드를 방문
    traverse(nodeP->bro, depth);
}

// 메인 함수
int main() {
    if (yyparse() != 0) {
        fprintf(stderr, "Parsing failed\n");
        return 1; // 오류 발생 시 종료
    }
    
    if (rootNode == NULL) {
        fprintf(stderr, "Error: rootNode is NULL\n");
        return 1; // rootNode가 NULL인 경우 오류 처리
    }
    
	//traverse -> 입력 : 추상구문트리 root, 출력 : 추상구문트리
    traverse(rootNode, 0);
	printf("\n");

	//gencode 실행
	//code(rootNode);
    return 0;
}

