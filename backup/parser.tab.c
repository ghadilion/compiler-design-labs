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
#line 1 "parser.y"

	#include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int yylex (void);
    void yyerror (char const *);
	
    extern FILE *yyin;
	extern FILE *yyout;
    extern int yylineno;
    extern char* yytext;
    extern int line;
    extern int col;

    struct indirectTriple {
        int index;
        char *op;
        char *arg1;
        char *arg2;
    } instructions[128];

    struct symbol {
        char *name;
        char *type;
        int line;
        int col;
    } symbolTable[128];
    
    void insertNewSymbol(char*, char*);
    int findSymbolPostion(char *);
    char* newTemp();
    void gen(char*, char*, char*);
    void displaySymbolTable();
    void displayTriples();
    int isSameType(char*, char*);
    int isUndeclared(char*); 
    int tripleNumber = -1;
    int symbolNumber = -1;

#line 112 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_DATATYPE = 8,                   /* DATATYPE  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_LPAREN = 10,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 11,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 12,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 13,                    /* RBRACE  */
  YYSYMBOL_LBOX = 14,                      /* LBOX  */
  YYSYMBOL_RBOX = 15,                      /* RBOX  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 17,                     /* COLON  */
  YYSYMBOL_DOT = 18,                       /* DOT  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_DOLLAR = 20,                    /* DOLLAR  */
  YYSYMBOL_HASH = 21,                      /* HASH  */
  YYSYMBOL_TILDE = 22,                     /* TILDE  */
  YYSYMBOL_ARROW = 23,                     /* ARROW  */
  YYSYMBOL_WITH = 24,                      /* WITH  */
  YYSYMBOL_LOOP = 25,                      /* LOOP  */
  YYSYMBOL_UNTIL = 26,                     /* UNTIL  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_UPDATE = 28,                    /* UPDATE  */
  YYSYMBOL_EXIT = 29,                      /* EXIT  */
  YYSYMBOL_SKIP = 30,                      /* SKIP  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_ID = 34,                        /* ID  */
  YYSYMBOL_ALLOC = 35,                     /* ALLOC  */
  YYSYMBOL__NULL = 36,                     /* _NULL  */
  YYSYMBOL_TRUE = 37,                      /* TRUE  */
  YYSYMBOL_FALSE = 38,                     /* FALSE  */
  YYSYMBOL_INTLIT = 39,                    /* INTLIT  */
  YYSYMBOL_FLOATLIT = 40,                  /* FLOATLIT  */
  YYSYMBOL_CHARLIT = 41,                   /* CHARLIT  */
  YYSYMBOL_STRINGLIT = 42,                 /* STRINGLIT  */
  YYSYMBOL_ASSIGN = 43,                    /* ASSIGN  */
  YYSYMBOL_EQUALS = 44,                    /* EQUALS  */
  YYSYMBOL_NEQUALS = 45,                   /* NEQUALS  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LTE = 48,                       /* LTE  */
  YYSYMBOL_GTE = 49,                       /* GTE  */
  YYSYMBOL_PLUS = 50,                      /* PLUS  */
  YYSYMBOL_MINUS = 51,                     /* MINUS  */
  YYSYMBOL_MUL = 52,                       /* MUL  */
  YYSYMBOL_DIV = 53,                       /* DIV  */
  YYSYMBOL_MOD = 54,                       /* MOD  */
  YYSYMBOL_AND = 55,                       /* AND  */
  YYSYMBOL_OR = 56,                        /* OR  */
  YYSYMBOL_PLUSEQUALS = 57,                /* PLUSEQUALS  */
  YYSYMBOL_MINUSEQUALS = 58,               /* MINUSEQUALS  */
  YYSYMBOL_MULEQUALS = 59,                 /* MULEQUALS  */
  YYSYMBOL_DIVEQUALS = 60,                 /* DIVEQUALS  */
  YYSYMBOL_MODEQUALS = 61,                 /* MODEQUALS  */
  YYSYMBOL_NOT = 62,                       /* NOT  */
  YYSYMBOL_INCR = 63,                      /* INCR  */
  YYSYMBOL_DECR = 64,                      /* DECR  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_datatype = 67,                  /* datatype  */
  YYSYMBOL_body = 68,                      /* body  */
  YYSYMBOL_with = 69,                      /* with  */
  YYSYMBOL_until = 70,                     /* until  */
  YYSYMBOL_update = 71,                    /* update  */
  YYSYMBOL_else = 72,                      /* else  */
  YYSYMBOL_condition = 73,                 /* condition  */
  YYSYMBOL_m = 74,                         /* m  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_id = 76,                        /* id  */
  YYSYMBOL_unary = 77,                     /* unary  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_relop = 79,                     /* relop  */
  YYSYMBOL_value = 80                      /* value  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    74,    75,    76,    77,    78,    79,
      80,    83,    84,    85,    86,    89,    90,    93,    94,    95,
      98,    99,   102,   103,   106,   107,   108,   109,   110,   113,
     116,   125,   128,   135,   140,   146,   157,   158,   161,   167,
     167,   173,   173,   179,   179,   185,   185,   191,   197,   200,
     201,   204,   205,   206,   207,   208,   209,   212,   213,   214,
     215,   216,   223,   224
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOL", "INT", "FLOAT",
  "CHAR", "STRING", "DATATYPE", "VOID", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBOX", "RBOX", "SEMICOLON", "COLON", "DOT", "COMMA", "DOLLAR",
  "HASH", "TILDE", "ARROW", "WITH", "LOOP", "UNTIL", "WHILE", "UPDATE",
  "EXIT", "SKIP", "IF", "ELSE", "RETURN", "ID", "ALLOC", "_NULL", "TRUE",
  "FALSE", "INTLIT", "FLOATLIT", "CHARLIT", "STRINGLIT", "ASSIGN",
  "EQUALS", "NEQUALS", "LT", "GT", "LTE", "GTE", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "AND", "OR", "PLUSEQUALS", "MINUSEQUALS", "MULEQUALS",
  "DIVEQUALS", "MODEQUALS", "NOT", "INCR", "DECR", "$accept", "program",
  "datatype", "body", "with", "until", "update", "else", "condition", "m",
  "statement", "id", "unary", "expression", "relop", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -48,     2,   -48,     5,     9,   -48,   -48,   -48,    60,    -2,
      11,     0,    -5,   -24,    18,    60,    -9,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,    79,   -13,   -48,   -48,    21,
      79,    94,   -48,   -48,   -48,   -48,   -48,   -48,    79,    79,
      24,    81,   -48,    27,    32,    16,   -48,    56,    79,   -48,
      51,   -48,   -48,   -48,   -48,   -48,   -48,    12,   -48,    56,
      33,    79,    79,    79,    79,    79,   -48,   -48,    18,    18,
      43,    42,    56,   -48,   -48,    60,   -40,   -40,   -48,   -48,
     -48,    79,    79,    65,    66,   -24,    60,     7,    56,    56,
     -48,   -48,    67,    48,    49,   -48,   -48,    71,   -48,    60,
      62,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    16,     1,     0,     0,    35,    36,    37,     2,     0,
       0,     0,     0,     0,    39,    14,    19,    13,     8,     4,
       5,     6,     9,    10,     7,    39,    31,    33,    34,     0,
      39,    61,    62,    63,    57,    58,    59,    60,    39,    39,
       0,    28,    49,     0,     0,    21,    61,    32,    39,    15,
       0,    55,    56,    51,    52,    53,    54,     0,    47,    27,
       0,    39,    39,    39,    39,    39,    29,    29,    39,    39,
       0,     0,    30,    48,    24,    16,    38,    40,    42,    44,
      46,    39,    39,     0,     0,     0,    16,    16,    25,    26,
      17,    18,     0,    16,    23,    20,    11,     0,    12,    16,
      16,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,    -1,   -48,   -48,   -48,   -48,   -47,    20,
     -12,    76,    84,   -14,   -48,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    26,    15,     9,    45,    71,    98,    40,    81,
      10,    11,    12,    41,    57,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    29,     2,    18,    19,    20,    21,    22,    23,    24,
       5,    47,    63,    64,    65,    13,    50,    43,    44,    14,
      94,    83,    84,    16,    58,    59,     3,    17,    30,     5,
      48,     3,    49,     4,    72,    60,     5,    68,     4,     6,
       7,     5,    69,    25,    70,    75,    74,    76,    77,    78,
      79,    80,    31,    85,    86,    32,    33,    34,    35,    36,
      37,    96,    73,     6,     7,     6,     7,    88,    89,    38,
       6,     7,     3,    92,    87,   101,    90,    91,    95,     4,
      39,    97,     5,    99,     3,    93,     3,    82,    28,    30,
       0,     4,     0,     4,     5,    27,     5,     0,   100,     0,
       0,    61,    62,    63,    64,    65,    61,    62,    63,    64,
      65,     6,     7,    46,     0,     0,    32,    33,    34,    35,
      36,    37,     0,     6,     7,     6,     7,     0,     0,     0,
      38,    61,    62,    63,    64,    65,    66,    67,    51,    52,
      53,    54,    55,    56
};

static const yytype_int8 yycheck[] =
{
       1,    13,     0,     3,     4,     5,     6,     7,     8,     9,
      34,    25,    52,    53,    54,    10,    30,    26,    27,    10,
      13,    68,    69,    25,    38,    39,    24,    16,    10,    34,
      43,    24,    11,    31,    48,    11,    34,    10,    31,    63,
      64,    34,    10,    43,    28,    12,    34,    61,    62,    63,
      64,    65,    34,    10,    12,    37,    38,    39,    40,    41,
      42,    13,    11,    63,    64,    63,    64,    81,    82,    51,
      63,    64,    24,    85,    75,    13,    11,    11,    11,    31,
      62,    32,    34,    12,    24,    86,    24,    67,    12,    10,
      -1,    31,    -1,    31,    34,    11,    34,    -1,    99,    -1,
      -1,    50,    51,    52,    53,    54,    50,    51,    52,    53,
      54,    63,    64,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    -1,    63,    64,    63,    64,    -1,    -1,    -1,
      51,    50,    51,    52,    53,    54,    55,    56,    44,    45,
      46,    47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,     0,    24,    31,    34,    63,    64,    68,    69,
      75,    76,    77,    10,    10,    68,    25,    16,     3,     4,
       5,     6,     7,     8,     9,    43,    67,    77,    76,    75,
      10,    34,    37,    38,    39,    40,    41,    42,    51,    62,
      73,    78,    80,    26,    27,    70,    34,    78,    43,    11,
      78,    44,    45,    46,    47,    48,    49,    79,    78,    78,
      11,    50,    51,    52,    53,    54,    55,    56,    10,    10,
      28,    71,    78,    11,    34,    12,    78,    78,    78,    78,
      78,    74,    74,    73,    73,    10,    12,    68,    78,    78,
      11,    11,    75,    68,    13,    11,    13,    32,    72,    12,
      68,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    74,
      75,    75,    75,    75,    75,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     7,     8,     2,     2,     4,     0,     4,     4,     0,
       4,     0,     4,     0,     3,     4,     4,     2,     1,     0,
       4,     2,     3,     2,     2,     1,     1,     1,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     2,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  case 4: /* datatype: INT  */
#line 74 "parser.y"
                { (yyval.attributes).mode = "INT";                                            }
#line 1258 "parser.tab.c"
    break;

  case 5: /* datatype: FLOAT  */
#line 75 "parser.y"
                { (yyval.attributes).mode = "FLOAT";                                          }
#line 1264 "parser.tab.c"
    break;

  case 6: /* datatype: CHAR  */
#line 76 "parser.y"
                { (yyval.attributes).mode = "CHAR";                                           }
#line 1270 "parser.tab.c"
    break;

  case 7: /* datatype: VOID  */
#line 77 "parser.y"
                { (yyval.attributes).mode = "VOID";                                           }
#line 1276 "parser.tab.c"
    break;

  case 8: /* datatype: BOOL  */
#line 78 "parser.y"
                { (yyval.attributes).mode = "BOOL";                                           }
#line 1282 "parser.tab.c"
    break;

  case 9: /* datatype: STRING  */
#line 79 "parser.y"
                { (yyval.attributes).mode = "STRING";                                         }
#line 1288 "parser.tab.c"
    break;

  case 10: /* datatype: DATATYPE  */
#line 80 "parser.y"
                { (yyval.attributes).mode = "DATATYPE";                                       }
#line 1294 "parser.tab.c"
    break;

  case 30: /* statement: id datatype ASSIGN expression  */
#line 117 "parser.y"
                { if(isSameType((yyvsp[-2].attributes).mode, (yyvsp[0].attributes).mode)) {
                    (yyvsp[-3].attributes).mode = (yyvsp[-2].attributes).mode;
                    insertNewSymbol((yyvsp[-3].attributes).place, (yyvsp[-3].attributes).mode);
                    tripleNumber++;
                    gen("=", (yyvsp[-3].attributes).place, (yyvsp[0].attributes).place);
                  }
                }
#line 1306 "parser.tab.c"
    break;

  case 31: /* statement: id datatype  */
#line 126 "parser.y"
                { (yyvsp[-1].attributes).mode = (yyvsp[0].attributes).mode; insertNewSymbol((yyvsp[-1].attributes).place, (yyvsp[-1].attributes).mode);      }
#line 1312 "parser.tab.c"
    break;

  case 32: /* statement: id ASSIGN expression  */
#line 129 "parser.y"
                { if(!isUndeclared((yyvsp[-2].attributes).place) && isSameType((yyvsp[-2].attributes).mode, (yyvsp[0].attributes).mode) ) {
                    tripleNumber++;
                    gen("=", (yyvsp[-2].attributes).place, (yyvsp[0].attributes).place);
                  }
                }
#line 1322 "parser.tab.c"
    break;

  case 33: /* statement: id unary  */
#line 135 "parser.y"
                { char* t = newTemp(); insertNewSymbol(t, (yyvsp[-1].attributes).mode); 
                  char op[2] = {(yyvsp[0].attributes).place[0], '\0'};
                  gen(op, (yyvsp[-1].attributes).place, "1"); gen("=", (yyvsp[-1].attributes).place, t);
                }
#line 1331 "parser.tab.c"
    break;

  case 34: /* statement: unary id  */
#line 140 "parser.y"
                { char* t = newTemp(); insertNewSymbol(t, (yyvsp[0].attributes).mode);
                  char op[2] = {(yyvsp[-1].attributes).place[0], '\0'};
                  gen(op, (yyvsp[0].attributes).place, "1"); gen("=", (yyvsp[0].attributes).place, t);
                }
#line 1340 "parser.tab.c"
    break;

  case 35: /* id: ID  */
#line 146 "parser.y"
                { /* printf("****%s\n", yytext); */
                  (yyval.attributes).place = strdup(yytext); 
                  int symbolPosition = findSymbolPostion(yytext);
                  if(symbolPosition != -1)
                    (yyval.attributes).mode = symbolTable[symbolPosition].type;
                  else
                    (yyval.attributes).mode = "";
                }
#line 1353 "parser.tab.c"
    break;

  case 36: /* unary: INCR  */
#line 157 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "UNARY";               }
#line 1359 "parser.tab.c"
    break;

  case 37: /* unary: DECR  */
#line 158 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "UNARY";               }
#line 1365 "parser.tab.c"
    break;

  case 38: /* expression: expression PLUS expression  */
#line 162 "parser.y"
                { (yyval.attributes).place = newTemp(); (yyval.attributes).mode = strdup((yyvsp[-2].attributes).mode);
                  insertNewSymbol((yyval.attributes).place, (yyval.attributes).mode);
                  gen("+", (yyvsp[-2].attributes).place, (yyvsp[0].attributes).place);                          
                }
#line 1374 "parser.tab.c"
    break;

  case 40: /* expression: expression MINUS expression  */
#line 168 "parser.y"
                { (yyval.attributes).place = newTemp(); (yyval.attributes).mode = strdup((yyvsp[-2].attributes).mode);
                  insertNewSymbol((yyval.attributes).place, (yyval.attributes).mode);
                  gen("-", (yyvsp[-2].attributes).place, (yyvsp[0].attributes).place);                          
                }
#line 1383 "parser.tab.c"
    break;

  case 42: /* expression: expression MUL expression  */
#line 174 "parser.y"
                { (yyval.attributes).place = newTemp(); (yyval.attributes).mode = strdup((yyvsp[-2].attributes).mode);
                  insertNewSymbol((yyval.attributes).place, (yyval.attributes).mode);
                  gen("*", (yyvsp[-2].attributes).place, (yyvsp[0].attributes).place);                          
                }
#line 1392 "parser.tab.c"
    break;

  case 44: /* expression: expression DIV expression  */
#line 180 "parser.y"
                { (yyval.attributes).place = newTemp(); (yyval.attributes).mode = strdup((yyvsp[-2].attributes).mode);
                  insertNewSymbol((yyval.attributes).place, (yyval.attributes).mode);
                  gen("/", (yyvsp[-2].attributes).place, (yyvsp[0].attributes).place);                          
                }
#line 1401 "parser.tab.c"
    break;

  case 46: /* expression: expression MOD expression  */
#line 186 "parser.y"
                { (yyval.attributes).place = newTemp(); (yyval.attributes).mode = strdup((yyvsp[-2].attributes).mode);
                  insertNewSymbol((yyval.attributes).place, (yyval.attributes).mode);
                  gen("%", (yyvsp[-2].attributes).place, (yyvsp[0].attributes).place);                          
                }
#line 1410 "parser.tab.c"
    break;

  case 47: /* expression: MINUS expression  */
#line 192 "parser.y"
                { (yyval.attributes).place = newTemp(); (yyval.attributes).mode = strdup((yyvsp[0].attributes).mode);
                  insertNewSymbol((yyval.attributes).place, (yyval.attributes).mode);
                  gen("-", (yyvsp[0].attributes).place, "");                                    
                }
#line 1419 "parser.tab.c"
    break;

  case 48: /* expression: LPAREN expression RPAREN  */
#line 198 "parser.y"
                { (yyval.attributes).place = strdup((yyvsp[-1].attributes).place); (yyval.attributes).mode = strdup((yyvsp[-1].attributes).mode);     }
#line 1425 "parser.tab.c"
    break;

  case 49: /* expression: value  */
#line 200 "parser.y"
                { (yyval.attributes).place = strdup((yyvsp[0].attributes).place); (yyval.attributes).mode = strdup((yyvsp[0].attributes).mode);     }
#line 1431 "parser.tab.c"
    break;

  case 51: /* relop: LT  */
#line 204 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "RELOP";               }
#line 1437 "parser.tab.c"
    break;

  case 52: /* relop: GT  */
#line 205 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "RELOP";               }
#line 1443 "parser.tab.c"
    break;

  case 53: /* relop: LTE  */
#line 206 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "RELOP";               }
#line 1449 "parser.tab.c"
    break;

  case 54: /* relop: GTE  */
#line 207 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "RELOP";               }
#line 1455 "parser.tab.c"
    break;

  case 55: /* relop: EQUALS  */
#line 208 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "RELOP";               }
#line 1461 "parser.tab.c"
    break;

  case 56: /* relop: NEQUALS  */
#line 209 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "RELOP";               }
#line 1467 "parser.tab.c"
    break;

  case 57: /* value: INTLIT  */
#line 212 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "INT";                 }
#line 1473 "parser.tab.c"
    break;

  case 58: /* value: FLOATLIT  */
#line 213 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "FLOAT";               }
#line 1479 "parser.tab.c"
    break;

  case 59: /* value: CHARLIT  */
#line 214 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "CHAR";                }
#line 1485 "parser.tab.c"
    break;

  case 60: /* value: STRINGLIT  */
#line 215 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "STRING";              }
#line 1491 "parser.tab.c"
    break;

  case 61: /* value: ID  */
#line 216 "parser.y"
                {
                  (yyval.attributes).place = strdup(yytext); 
                  if(isUndeclared((yyval.attributes).place)) 
                    (yyval.attributes).mode = "";
                  else 
                    (yyval.attributes).mode = symbolTable[findSymbolPostion(yytext)].type;
                }
#line 1503 "parser.tab.c"
    break;

  case 62: /* value: TRUE  */
#line 223 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "BOOL";                }
#line 1509 "parser.tab.c"
    break;

  case 63: /* value: FALSE  */
#line 224 "parser.y"
                { (yyval.attributes).place = strdup(yytext); (yyval.attributes).mode = "BOOL";                }
#line 1515 "parser.tab.c"
    break;


#line 1519 "parser.tab.c"

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

#line 227 "parser.y"


int main (int argc, char *argv[]){
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
    displaySymbolTable();
    displayTriples();
	return flag;
}

void displayTriples() {
    printf("\n\nINDIRECT TRIPLES\n\nIndex\t\tOp\t\tArg1\t\tArg2\n-----\t\t--\t"
    "\t----\t\t----\n");
    for(int i = 0; i <= tripleNumber; ++i) {
        printf("%d\t\t%s\t\t%s\t\t%s\n", i, instructions[i].op, 
        instructions[i].arg1, instructions[i].arg2);
    }
}

void displaySymbolTable() {
    printf("\n\nSYMBOL TABLE\n\nName\t\tType\t\tLine\t\tCol\n----\t\t----\t\t"
    "----\t\t---\n");
    for(int i = 0; i <= symbolNumber; ++i) {
        printf("%s\t\t%s\t\t%d\t\t%d\n", symbolTable[i].name, 
        symbolTable[i].type, symbolTable[i].line, symbolTable[i].col);
    }
}

void yyerror (char const *str) {
    fprintf(stderr,"Line: %d | Col: %d | Error: %s\n",line, col, str);
}

void insertNewSymbol(char* name, char* type) {
    int i = findSymbolPostion(name);
    if (i == -1) {
        symbolNumber++;
        symbolTable[symbolNumber].name = strdup(name);
        symbolTable[symbolNumber].type = strdup(type);
        symbolTable[symbolNumber].line = line;
        symbolTable[symbolNumber].col = col;
    }
    else  {
        char *errorMsg = malloc(128);
        snprintf(errorMsg, 128, "Redeclaration of symbol %s "
        "first declared at line: %d, col: %d\n", symbolTable[i].name,
        symbolTable[i].line, symbolTable[i].col);
        yyerror(errorMsg);
    }
}

int findSymbolPostion(char *name) {
    for(int i = 0; i <= symbolNumber; ++i) {
        if(strcmp(name, symbolTable[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

char* newTemp() {
    tripleNumber++;
    int length = snprintf( NULL, 0, "%d", tripleNumber );
    char* numBuf = malloc( length + 1 );
    snprintf( numBuf, length + 1, "%d", tripleNumber );
    char tempName[5] = "T";
    strcat(tempName, numBuf);
    return strdup(tempName);
}

void gen(char* op, char *arg1, char *arg2) {
    instructions[tripleNumber].op = strdup(op);
    instructions[tripleNumber].arg1 = strdup(arg1);
    instructions[tripleNumber].arg2 = strdup(arg2);
}

int isSameType(char* type1, char* type2) {
    if(strcmp(type1, type2) == 0)
        return 1;
    yyerror("Type mismatch during assignment\n");
    return 0;
}

int isUndeclared(char* name) {
    if(findSymbolPostion(name) == -1) {
        char *errorMsg = malloc(128);
        snprintf(errorMsg, 128, "Undeclared name %s ", name);
        yyerror(errorMsg);
        return 1;
    }
    return 0;
}


