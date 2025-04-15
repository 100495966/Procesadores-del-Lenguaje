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
#line 4 "trad3.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()
#include <stdbool.h>          // declaraciones para formatear el programa de lisp

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
// PROTOTIPOS DE FUNCIONES
void format_lisp_function(const char *);
int search_local_var(char *local_var);
void add_local_var(char *var_name);
char *get_var_name(char *var_name);
void clear_local_vars();

char temp [2048] ;
// Para añadir el nombre de la función a las variables locales
char * current_function_name = NULL;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr
//#define YYDEBUG 1


#line 123 "trad3.tab.c"

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

#include "trad3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PUTS = 9,                       /* PUTS  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NEQ = 14,                       /* NEQ  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 29,                /* UNARY_SIGN  */
  YYSYMBOL_30_ = 30,                       /* '!'  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* ']'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_axioma_programa = 40,           /* axioma_programa  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_dec_variables = 42,             /* dec_variables  */
  YYSYMBOL_var_list = 43,                  /* var_list  */
  YYSYMBOL_var_decl = 44,                  /* var_decl  */
  YYSYMBOL_dec_funciones = 45,             /* dec_funciones  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_funciones = 47,                 /* funciones  */
  YYSYMBOL_funcion = 48,                   /* funcion  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_argumentos = 50,                /* argumentos  */
  YYSYMBOL_r_argumentos = 51,              /* r_argumentos  */
  YYSYMBOL_procedimiento = 52,             /* procedimiento  */
  YYSYMBOL_proc_argumentos = 53,           /* proc_argumentos  */
  YYSYMBOL_proc_r_argumentos = 54,         /* proc_r_argumentos  */
  YYSYMBOL_axioma_codigo = 55,             /* axioma_codigo  */
  YYSYMBOL_sentencia = 56,                 /* sentencia  */
  YYSYMBOL_var_list_local = 57,            /* var_list_local  */
  YYSYMBOL_var_decl_local = 58,            /* var_decl_local  */
  YYSYMBOL_inicializacion = 59,            /* inicializacion  */
  YYSYMBOL_inc_dec = 60,                   /* inc_dec  */
  YYSYMBOL_inc_dec_operadores = 61,        /* inc_dec_operadores  */
  YYSYMBOL_elems = 62,                     /* elems  */
  YYSYMBOL_r_elems = 63,                   /* r_elems  */
  YYSYMBOL_elem = 64,                      /* elem  */
  YYSYMBOL_expresion = 65,                 /* expresion  */
  YYSYMBOL_termino = 66,                   /* termino  */
  YYSYMBOL_operando = 67                   /* operando  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    30,     2,     2,     2,    28,     2,     2,
      35,    36,    26,    24,    32,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      22,    21,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    89,    94,    95,   100,   102,   107,   109,
     111,   116,   116,   122,   123,   126,   126,   131,   132,   136,
     137,   141,   144,   145,   149,   150,   155,   156,   160,   162,
     164,   165,   167,   169,   171,   173,   175,   177,   179,   184,
     185,   190,   193,   196,   201,   204,   207,   208,   209,   210,
     211,   214,   218,   219,   224,   226,   230,   231,   233,   235,
     237,   239,   241,   243,   245,   247,   249,   251,   253,   255,
     257,   261,   262,   263,   267,   269,   271,   273,   274
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "PUTS", "PRINTF", "AND", "OR",
  "EQ", "NEQ", "LE", "GE", "IF", "ELSE", "FOR", "RETURN", "'='", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_SIGN", "'!'", "';'",
  "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "axioma_programa", "$@1", "dec_variables", "var_list", "var_decl",
  "dec_funciones", "$@2", "funciones", "funcion", "$@3", "argumentos",
  "r_argumentos", "procedimiento", "proc_argumentos", "proc_r_argumentos",
  "axioma_codigo", "sentencia", "var_list_local", "var_decl_local",
  "inicializacion", "inc_dec", "inc_dec_operadores", "elems", "r_elems",
  "elem", "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,     6,    11,   -99,   -16,   -17,    -6,   -99,    19,    24,
      26,     2,     6,    10,   -99,    51,    19,   -99,   -29,    15,
      15,    24,    24,   -99,   314,   -99,   -99,    27,   -99,   -99,
      57,    28,   -99,    24,    24,   -99,   -99,   -99,    92,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,   -99,    73,    42,    57,   160,    43,   208,   -99,
     348,   332,   362,   362,    97,    97,    97,    97,    29,    29,
     -99,   -99,   -99,    49,    47,    50,   -99,   -99,    24,   -99,
      80,   -99,   -99,    53,   208,    87,    63,   -99,   -99,    49,
     -13,    88,    58,    61,    62,    65,    66,    24,    67,    71,
      63,    63,   -99,    24,    24,   -12,    79,    81,    24,   106,
     120,    24,   123,   230,   -99,   -99,   -99,    91,   251,   184,
      24,   127,   -99,    88,   124,    95,   100,   142,   138,   130,
     -99,   -99,   -99,   141,   314,   129,   -99,   140,   148,    40,
     143,   178,    24,    24,   -99,    63,   -99,   -99,   153,   158,
     314,    63,   -99,   272,   293,   154,   162,    40,   -99,   163,
     187,   -99,   -99,   -99,   158,   185,   181,   168,   -99,   176,
     201,   177,    63,   117,    63,   179,   -99,   -99,   -99,   -99,
     -99,   212,   188,   -99,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     8,     0,     6,     1,    13,     0,
       0,     4,     0,     0,     3,     0,    13,    75,    74,     0,
       0,     0,     0,    77,    10,    56,    71,     0,     5,     7,
      17,     0,    14,     0,    22,    72,    73,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,    17,     0,     0,    24,    78,
      62,    63,    65,    64,    67,    69,    66,    68,    57,    58,
      59,    60,    61,    19,     0,     0,    76,    21,     0,    23,
       0,    18,    15,     0,    24,     0,    26,    11,    25,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    26,    20,     0,     0,    41,     0,    39,     0,     0,
       0,     0,     0,     0,    37,    16,    27,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
      38,    12,    28,     0,    43,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    42,    26,    31,    55,     0,    52,
      54,    26,    44,     0,     0,     0,     0,     0,    51,     0,
       0,    29,    33,    32,    52,    34,     0,     0,    53,     0,
       0,     0,    26,     0,    26,     0,    46,    47,    48,    49,
      50,     0,     0,    35,    45,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   205,   213,   -99,   -99,   -99,   211,   -99,
     -99,   173,   149,   -85,   -99,   145,   -98,   -99,   114,   -99,
     -99,   -99,   -99,   -99,    75,    90,    -9,   -99,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     3,     5,     6,    14,   101,    15,    16,
      86,    54,    81,    23,    57,    79,    99,   100,   106,   107,
     129,   167,   181,   148,   158,   149,   150,    25,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    98,   116,   117,    33,     9,    34,     1,   103,   120,
       4,     7,    37,    38,    11,    98,    98,    10,    17,    18,
     104,   121,    34,    13,    56,    58,    12,    17,    18,    27,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    17,    18,    30,   147,   155,    19,    20,
      22,    35,    36,   159,    21,    49,    50,    51,    31,    22,
      98,    52,    53,    55,    19,    20,    98,    90,    91,    84,
      21,    92,    93,    94,   175,    22,   182,    73,    74,    77,
      95,    80,    96,    97,    82,    85,    83,    98,   113,    98,
      87,    89,   105,   108,   118,   119,   109,   110,   114,   124,
     111,   112,   127,    39,    40,    41,    42,    43,    44,   115,
     122,   134,   125,   123,    45,    46,    47,    48,    49,    50,
      51,    47,    48,    49,    50,    51,   126,   128,    59,   131,
     135,   138,   139,   153,   154,    39,    40,    41,    42,    43,
      44,   176,   177,   178,   179,   180,    45,    46,    47,    48,
      49,    50,    51,    39,    40,    41,    42,    43,    44,   141,
     137,   142,   143,   144,    45,    46,    47,    48,    49,    50,
      51,    39,    40,    41,    42,    43,    44,   145,   140,   146,
     151,   152,    45,    46,    47,    48,    49,    50,    51,   156,
     157,   166,   162,   163,    76,    39,    40,    41,    42,    43,
      44,   165,   170,   169,   171,   173,    45,    46,    47,    48,
      49,    50,    51,   172,   174,   184,    28,   183,   133,    39,
      40,    41,    42,    43,    44,    29,   185,    32,    75,    88,
      45,    46,    47,    48,    49,    50,    51,   136,   102,   168,
      78,    39,    40,    41,    42,    43,    44,   164,     0,     0,
       0,     0,    45,    46,    47,    48,    49,    50,    51,     0,
       0,   130,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,    50,    51,
       0,     0,   132,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      51,     0,     0,   160,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
      50,    51,     0,     0,   161,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,    50,    51,    39,     0,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      51,    41,    42,    43,    44,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    43,    44,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      51
};

static const yytype_int16 yycheck[] =
{
       9,    86,   100,   101,    33,    21,    35,     5,    21,    21,
       4,     0,    21,    22,    31,   100,   101,    33,     3,     4,
      33,    33,    35,     4,    33,    34,    32,     3,     4,     3,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     3,     4,    35,     6,   145,    24,    25,
      35,    19,    20,   151,    30,    26,    27,    28,     7,    35,
     145,    34,     5,    35,    24,    25,   151,     4,     5,    78,
      30,     8,     9,    10,   172,    35,   174,     4,    36,    36,
      17,    32,    19,    20,    37,     5,    36,   172,    97,   174,
      37,     4,     4,    35,   103,   104,    35,    35,    31,   108,
      35,    35,   111,    11,    12,    13,    14,    15,    16,    38,
      31,   120,     6,    32,    22,    23,    24,    25,    26,    27,
      28,    24,    25,    26,    27,    28,     6,     4,    36,    38,
       3,    36,    32,   142,   143,    11,    12,    13,    14,    15,
      16,    24,    25,    26,    27,    28,    22,    23,    24,    25,
      26,    27,    28,    11,    12,    13,    14,    15,    16,    21,
      36,    31,    21,    34,    22,    23,    24,    25,    26,    27,
      28,    11,    12,    13,    14,    15,    16,    37,    36,    31,
      37,     3,    22,    23,    24,    25,    26,    27,    28,    36,
      32,     4,    38,    31,    34,    11,    12,    13,    14,    15,
      16,    38,    21,    18,    36,     4,    22,    23,    24,    25,
      26,    27,    28,    37,    37,     3,    11,    38,    34,    11,
      12,    13,    14,    15,    16,    12,    38,    16,    55,    84,
      22,    23,    24,    25,    26,    27,    28,   123,    89,   164,
      32,    11,    12,    13,    14,    15,    16,   157,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    11,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    40,    42,     4,    43,    44,     0,    41,    21,
      33,    31,    32,     4,    45,    47,    48,     3,     4,    24,
      25,    30,    35,    52,    65,    66,    67,     3,    42,    43,
      35,     7,    47,    33,    35,    67,    67,    65,    65,    11,
      12,    13,    14,    15,    16,    22,    23,    24,    25,    26,
      27,    28,    34,     5,    50,    35,    65,    53,    65,    36,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,     4,    36,    50,    34,    36,    32,    54,
      32,    51,    37,    36,    65,     5,    49,    37,    54,     4,
       4,     5,     8,     9,    10,    17,    19,    20,    52,    55,
      56,    46,    51,    21,    33,     4,    57,    58,    35,    35,
      35,    35,    35,    65,    31,    38,    55,    55,    65,    65,
      21,    33,    31,    32,    65,     6,     6,    65,     4,    59,
      31,    38,    31,    34,    65,     3,    57,    36,    36,    32,
      36,    21,    31,    21,    34,    37,    31,     6,    62,    64,
      65,    37,     3,    65,    65,    55,    36,    32,    63,    55,
      31,    31,    38,    31,    64,    38,     4,    60,    63,    18,
      21,    36,    37,     4,    37,    55,    24,    25,    26,    27,
      28,    61,    55,    38,     3,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      44,    46,    45,    47,    47,    49,    48,    50,    50,    51,
      51,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    59,    60,    61,    61,    61,    61,
      61,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    67,    67,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     4,     1,     3,     1,     4,
       3,     0,     9,     0,     2,     0,     8,     0,     3,     0,
       4,     4,     0,     2,     0,     3,     0,     2,     4,     7,
       3,     5,     7,     7,     7,    11,    11,     2,     3,     1,
       3,     1,     4,     3,     3,     5,     1,     1,     1,     1,
       1,     2,     0,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     2,     2,     1,     1,     4,     1,     3
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
  case 2: /* $@1: %empty  */
#line 89 "trad3.y"
                          { printf("%s", yyvsp[0].code); }
#line 1331 "trad3.tab.c"
    break;

  case 3: /* axioma_programa: dec_variables $@1 dec_funciones  */
#line 90 "trad3.y"
                                        { ; }
#line 1337 "trad3.tab.c"
    break;

  case 4: /* dec_variables: %empty  */
#line 94 "trad3.y"
                                                             { yyval.code = gen_code ("") ; }
#line 1343 "trad3.tab.c"
    break;

  case 5: /* dec_variables: INTEGER var_list ';' dec_variables  */
#line 95 "trad3.y"
                                                 { sprintf (temp, "%s%s", yyvsp[-2].code, yyvsp[0].code) ; 
                                                   yyval.code = gen_code (temp) ;}
#line 1350 "trad3.tab.c"
    break;

  case 6: /* var_list: var_decl  */
#line 100 "trad3.y"
                                        { sprintf (temp, "%s\n", yyvsp[0].code) ; 
                                          yyval.code = gen_code (temp) ;}
#line 1357 "trad3.tab.c"
    break;

  case 7: /* var_list: var_decl ',' var_list  */
#line 102 "trad3.y"
                                                { sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ; 
                                          yyval.code = gen_code (temp) ;  }
#line 1364 "trad3.tab.c"
    break;

  case 8: /* var_decl: IDENTIF  */
#line 107 "trad3.y"
                                                { sprintf (temp, "(setq %s 0)", yyvsp[0].code) ; 
                                          yyval.code = gen_code (temp) ; }
#line 1371 "trad3.tab.c"
    break;

  case 9: /* var_decl: IDENTIF '[' NUMBER ']'  */
#line 109 "trad3.y"
                                        { sprintf (temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ; 
                                          yyval.code = gen_code (temp) ; }
#line 1378 "trad3.tab.c"
    break;

  case 10: /* var_decl: IDENTIF '=' expresion  */
#line 111 "trad3.y"
                                                   { sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                          yyval.code = gen_code (temp) ; }
#line 1385 "trad3.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 116 "trad3.y"
                                                                        { current_function_name = gen_code("main");
                                                                          clear_local_vars(); }
#line 1392 "trad3.tab.c"
    break;

  case 12: /* dec_funciones: funciones MAIN '(' argumentos ')' '{' $@2 axioma_codigo '}'  */
#line 118 "trad3.y"
                                                                        { sprintf (temp, "(defun main (%s)\n%s)", yyvsp[-5].code, yyvsp[-1].code) ; 
                                                                          format_lisp_function(temp); }
#line 1399 "trad3.tab.c"
    break;

  case 13: /* funciones: %empty  */
#line 122 "trad3.y"
              { ; }
#line 1405 "trad3.tab.c"
    break;

  case 14: /* funciones: funcion funciones  */
#line 123 "trad3.y"
                                { ; }
#line 1411 "trad3.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 126 "trad3.y"
                                                                         { current_function_name = gen_code(yyvsp[-4].code);
                                                                            clear_local_vars(); }
#line 1418 "trad3.tab.c"
    break;

  case 16: /* funcion: IDENTIF '(' argumentos ')' '{' $@3 axioma_codigo '}'  */
#line 128 "trad3.y"
                                                                         { sprintf (temp, "(defun %s (%s)\n%s)\n", yyvsp[-7].code, yyvsp[-5].code, yyvsp[-1].code) ; 
                                                                            format_lisp_function(temp); }
#line 1425 "trad3.tab.c"
    break;

  case 17: /* argumentos: %empty  */
#line 131 "trad3.y"
                                           { yyval.code = gen_code(""); }
#line 1431 "trad3.tab.c"
    break;

  case 18: /* argumentos: INTEGER IDENTIF r_argumentos  */
#line 132 "trad3.y"
                                           { sprintf (temp, "%s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                             yyval.code = gen_code (temp) ; }
#line 1438 "trad3.tab.c"
    break;

  case 19: /* r_argumentos: %empty  */
#line 136 "trad3.y"
                                                { yyval.code = gen_code(""); }
#line 1444 "trad3.tab.c"
    break;

  case 20: /* r_argumentos: ',' INTEGER IDENTIF r_argumentos  */
#line 137 "trad3.y"
                                                { sprintf (temp, " %s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                                 yyval.code = gen_code (temp) ; }
#line 1451 "trad3.tab.c"
    break;

  case 21: /* procedimiento: IDENTIF '(' proc_argumentos ')'  */
#line 141 "trad3.y"
                                                  { sprintf (temp, "(%s%s%s)", yyvsp[-3].code, (strcmp("", yyvsp[-1].code) != 0) ? " " : "", yyvsp[-1].code) ; 
                                                    yyval.code = gen_code (temp) ; }
#line 1458 "trad3.tab.c"
    break;

  case 22: /* proc_argumentos: %empty  */
#line 144 "trad3.y"
                                            { yyval.code = gen_code(""); }
#line 1464 "trad3.tab.c"
    break;

  case 23: /* proc_argumentos: expresion proc_r_argumentos  */
#line 145 "trad3.y"
                                            { sprintf (temp, "%s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                              yyval.code = gen_code (temp) ; }
#line 1471 "trad3.tab.c"
    break;

  case 24: /* proc_r_argumentos: %empty  */
#line 149 "trad3.y"
                                               { yyval.code = gen_code(""); }
#line 1477 "trad3.tab.c"
    break;

  case 25: /* proc_r_argumentos: ',' expresion proc_r_argumentos  */
#line 150 "trad3.y"
                                               { sprintf (temp, " %s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                                 yyval.code = gen_code (temp) ; }
#line 1484 "trad3.tab.c"
    break;

  case 26: /* axioma_codigo: %empty  */
#line 155 "trad3.y"
                                       { yyval.code = gen_code(""); }
#line 1490 "trad3.tab.c"
    break;

  case 27: /* axioma_codigo: sentencia axioma_codigo  */
#line 156 "trad3.y"
                                       { sprintf (temp, "%s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                         yyval.code = gen_code (temp) ; }
#line 1497 "trad3.tab.c"
    break;

  case 28: /* sentencia: IDENTIF '=' expresion ';'  */
#line 160 "trad3.y"
                                                                                            { sprintf (temp, "(setf %s %s)\n", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ; 
                                                                                                yyval.code = gen_code (temp) ; }
#line 1504 "trad3.tab.c"
    break;

  case 29: /* sentencia: IDENTIF '[' expresion ']' '=' expresion ';'  */
#line 162 "trad3.y"
                                                                                            { sprintf (temp, "(setf (aref %s %s) %s)\n", get_var_name(yyvsp[-6].code), yyvsp[-4].code, yyvsp[-1].code) ; 
                                                                                                yyval.code = gen_code (temp) ; }
#line 1511 "trad3.tab.c"
    break;

  case 30: /* sentencia: INTEGER var_list_local ';'  */
#line 164 "trad3.y"
                                                                                            { yyval.code = gen_code (yyvsp[-1].code) ; }
#line 1517 "trad3.tab.c"
    break;

  case 31: /* sentencia: PUTS '(' STRING ')' ';'  */
#line 165 "trad3.y"
                                                                                            { sprintf (temp, "(print \"%s\")\n", yyvsp[-2].code) ;  
                                                                                                yyval.code = gen_code (temp) ; }
#line 1524 "trad3.tab.c"
    break;

  case 32: /* sentencia: PRINTF '(' STRING ',' elems ')' ';'  */
#line 167 "trad3.y"
                                                                                            { sprintf (temp, "%s", yyvsp[-2].code) ;  
                                                                                                yyval.code = gen_code (temp) ; }
#line 1531 "trad3.tab.c"
    break;

  case 33: /* sentencia: WHILE '(' expresion ')' '{' axioma_codigo '}'  */
#line 169 "trad3.y"
                                                                                            {  sprintf (temp, "(loop while %s do\n%s)\n", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                                                yyval.code = gen_code (temp) ; }
#line 1538 "trad3.tab.c"
    break;

  case 34: /* sentencia: IF '(' expresion ')' '{' axioma_codigo '}'  */
#line 171 "trad3.y"
                                                                                            { sprintf (temp, "(if %s\n(progn\n%s)\n)\n", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                                                yyval.code = gen_code (temp) ; }
#line 1545 "trad3.tab.c"
    break;

  case 35: /* sentencia: IF '(' expresion ')' '{' axioma_codigo '}' ELSE '{' axioma_codigo '}'  */
#line 173 "trad3.y"
                                                                                            { sprintf (temp, "(if %s\n(progn\n%s)\n(progn\n%s)\n)\n", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                                                                                yyval.code = gen_code (temp) ; }
#line 1552 "trad3.tab.c"
    break;

  case 36: /* sentencia: FOR '(' inicializacion ';' expresion ';' inc_dec ')' '{' axioma_codigo '}'  */
#line 175 "trad3.y"
                                                                                            { sprintf (temp, "%s(loop while %s do\n%s%s)\n", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                                                                                yyval.code = gen_code (temp) ; }
#line 1559 "trad3.tab.c"
    break;

  case 37: /* sentencia: procedimiento ';'  */
#line 177 "trad3.y"
                                                                                            { sprintf (temp, "%s\n", yyvsp[-1].code) ;
                                                                                                yyval.code = gen_code(temp); }
#line 1566 "trad3.tab.c"
    break;

  case 38: /* sentencia: RETURN expresion ';'  */
#line 179 "trad3.y"
                                                                                            { sprintf (temp, "(return-from %s %s)\n", current_function_name, yyvsp[-1].code) ;
                                                                                                yyval.code = gen_code(temp); }
#line 1573 "trad3.tab.c"
    break;

  case 39: /* var_list_local: var_decl_local  */
#line 184 "trad3.y"
                                                    { yyval.code = gen_code(yyvsp[0].code); }
#line 1579 "trad3.tab.c"
    break;

  case 40: /* var_list_local: var_decl_local ',' var_list_local  */
#line 185 "trad3.y"
                                                            { sprintf (temp, "%s%s", yyvsp[-2].code, yyvsp[0].code) ; 
                                                      yyval.code = gen_code (temp) ;  }
#line 1586 "trad3.tab.c"
    break;

  case 41: /* var_decl_local: IDENTIF  */
#line 190 "trad3.y"
                                                { add_local_var(yyvsp[0].code);
                                          sprintf (temp, "(setq %s_%s 0)\n", current_function_name, yyvsp[0].code) ; 
                                          yyval.code = gen_code (temp) ; }
#line 1594 "trad3.tab.c"
    break;

  case 42: /* var_decl_local: IDENTIF '[' NUMBER ']'  */
#line 193 "trad3.y"
                                        { add_local_var(yyvsp[-3].code);
                                          sprintf (temp, "(setq %s_%s (make-array %d))\n", current_function_name, yyvsp[-3].code, yyvsp[-1].value) ; 
                                          yyval.code = gen_code (temp) ; }
#line 1602 "trad3.tab.c"
    break;

  case 43: /* var_decl_local: IDENTIF '=' expresion  */
#line 196 "trad3.y"
                                                { add_local_var(yyvsp[-2].code);
                                          sprintf (temp, "(setq %s_%s %s)\n", current_function_name, yyvsp[-2].code, yyvsp[0].code) ; 
                                          yyval.code = gen_code (temp) ; }
#line 1610 "trad3.tab.c"
    break;

  case 44: /* inicializacion: IDENTIF '=' NUMBER  */
#line 201 "trad3.y"
                                         { sprintf (temp, "(setq %s %d)\n", get_var_name(yyvsp[-2].code), yyvsp[0].value) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1617 "trad3.tab.c"
    break;

  case 45: /* inc_dec: IDENTIF '=' IDENTIF inc_dec_operadores NUMBER  */
#line 204 "trad3.y"
                                                          { sprintf (temp, "(setf %s (%s %s %d))\n", get_var_name(yyvsp[-4].code), yyvsp[-1].code, get_var_name(yyvsp[-2].code), yyvsp[0].value) ; 
                                                            yyval.code = gen_code (temp) ; }
#line 1624 "trad3.tab.c"
    break;

  case 46: /* inc_dec_operadores: '+'  */
#line 207 "trad3.y"
                           { yyval.code = gen_code ("+") ; }
#line 1630 "trad3.tab.c"
    break;

  case 47: /* inc_dec_operadores: '-'  */
#line 208 "trad3.y"
                           { yyval.code = gen_code ("-") ; }
#line 1636 "trad3.tab.c"
    break;

  case 48: /* inc_dec_operadores: '*'  */
#line 209 "trad3.y"
                           { yyval.code = gen_code ("*") ; }
#line 1642 "trad3.tab.c"
    break;

  case 49: /* inc_dec_operadores: '/'  */
#line 210 "trad3.y"
                           { yyval.code = gen_code ("/") ; }
#line 1648 "trad3.tab.c"
    break;

  case 50: /* inc_dec_operadores: '%'  */
#line 211 "trad3.y"
                           { yyval.code = gen_code ("%") ; }
#line 1654 "trad3.tab.c"
    break;

  case 51: /* elems: elem r_elems  */
#line 214 "trad3.y"
                         { sprintf (temp, "%s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                           yyval.code = gen_code (temp) ;}
#line 1661 "trad3.tab.c"
    break;

  case 52: /* r_elems: %empty  */
#line 218 "trad3.y"
                               { yyval.code = gen_code ("") ; }
#line 1667 "trad3.tab.c"
    break;

  case 53: /* r_elems: ',' elem r_elems  */
#line 219 "trad3.y"
                               { sprintf (temp, "%s%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                  yyval.code = gen_code (temp); }
#line 1674 "trad3.tab.c"
    break;

  case 54: /* elem: expresion  */
#line 224 "trad3.y"
                       { sprintf (temp, "(princ %s)\n", yyvsp[0].code) ; 
                         yyval.code = gen_code (temp) ;}
#line 1681 "trad3.tab.c"
    break;

  case 55: /* elem: STRING  */
#line 226 "trad3.y"
                       { sprintf (temp, "(princ \"%s\")\n", yyvsp[0].code) ;
                         yyval.code = gen_code (temp) ;}
#line 1688 "trad3.tab.c"
    break;

  case 56: /* expresion: termino  */
#line 230 "trad3.y"
                                         { yyval.code = gen_code(yyvsp[0].code); }
#line 1694 "trad3.tab.c"
    break;

  case 57: /* expresion: expresion '+' expresion  */
#line 231 "trad3.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1701 "trad3.tab.c"
    break;

  case 58: /* expresion: expresion '-' expresion  */
#line 233 "trad3.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1708 "trad3.tab.c"
    break;

  case 59: /* expresion: expresion '*' expresion  */
#line 235 "trad3.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1715 "trad3.tab.c"
    break;

  case 60: /* expresion: expresion '/' expresion  */
#line 237 "trad3.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1722 "trad3.tab.c"
    break;

  case 61: /* expresion: expresion '%' expresion  */
#line 239 "trad3.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1729 "trad3.tab.c"
    break;

  case 62: /* expresion: expresion AND expresion  */
#line 241 "trad3.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1736 "trad3.tab.c"
    break;

  case 63: /* expresion: expresion OR expresion  */
#line 243 "trad3.y"
                                         { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1743 "trad3.tab.c"
    break;

  case 64: /* expresion: expresion NEQ expresion  */
#line 245 "trad3.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1750 "trad3.tab.c"
    break;

  case 65: /* expresion: expresion EQ expresion  */
#line 247 "trad3.y"
                                         { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1757 "trad3.tab.c"
    break;

  case 66: /* expresion: expresion '<' expresion  */
#line 249 "trad3.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1764 "trad3.tab.c"
    break;

  case 67: /* expresion: expresion LE expresion  */
#line 251 "trad3.y"
                                         { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1771 "trad3.tab.c"
    break;

  case 68: /* expresion: expresion '>' expresion  */
#line 253 "trad3.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1778 "trad3.tab.c"
    break;

  case 69: /* expresion: expresion GE expresion  */
#line 255 "trad3.y"
                                         { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1785 "trad3.tab.c"
    break;

  case 70: /* expresion: '!' expresion  */
#line 257 "trad3.y"
                                         { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                            yyval.code = gen_code (temp) ; }
#line 1792 "trad3.tab.c"
    break;

  case 71: /* termino: operando  */
#line 261 "trad3.y"
                                                   { yyval.code = gen_code(yyvsp[0].code); }
#line 1798 "trad3.tab.c"
    break;

  case 72: /* termino: '+' operando  */
#line 262 "trad3.y"
                                                   { yyval.code = gen_code(yyvsp[0].code); }
#line 1804 "trad3.tab.c"
    break;

  case 73: /* termino: '-' operando  */
#line 263 "trad3.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1811 "trad3.tab.c"
    break;

  case 74: /* operando: IDENTIF  */
#line 267 "trad3.y"
                                            { sprintf (temp, "%s", get_var_name(yyvsp[0].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1818 "trad3.tab.c"
    break;

  case 75: /* operando: NUMBER  */
#line 269 "trad3.y"
                                            { sprintf (temp, "%d", yyvsp[0].value) ;
                                              yyval.code = gen_code (temp) ; }
#line 1825 "trad3.tab.c"
    break;

  case 76: /* operando: IDENTIF '[' expresion ']'  */
#line 271 "trad3.y"
                                            { sprintf (temp, "(aref %s %s)", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ; 
                                              yyval.code = gen_code (temp) ; }
#line 1832 "trad3.tab.c"
    break;

  case 77: /* operando: procedimiento  */
#line 273 "trad3.y"
                                            { yyval.code = gen_code(yyvsp[0].code); }
#line 1838 "trad3.tab.c"
    break;

  case 78: /* operando: '(' expresion ')'  */
#line 274 "trad3.y"
                                            { yyval.code = gen_code(yyvsp[-1].code); }
#line 1844 "trad3.tab.c"
    break;


#line 1848 "trad3.tab.c"

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

#line 278 "trad3.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{   
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}

// Función backend para modificar código LISP
void format_lisp_function(const char * input) {
    int indentLevel = 0;
    int n = strlen(input);
    int i = 0;
    bool inString = false;
    char currentLine[1024];
    bool pendingIndent = false;
    bool ifFound = false;
    bool prognFound = false;

    while (i < n) {
        int pos = 0;
        // Acumula caracteres hasta encontrar un salto de línea o fin de string.
        while (i < n && input[i] != '\n') {
            currentLine[pos++] = input[i++];
        }
        currentLine[pos] = '\0';
        i++; // Salta el caracter '\n'

        // Se omite espacio inicial para determinar el primer carácter significativo.
        int k = 0;
        while (currentLine[k] == ' ' || currentLine[k] == '\t') {
            k++;
        }
        
        // Si la línea empieza con ')', se reduce el nivel de indentación para ella.
        int lineIndent = indentLevel;
        if (currentLine[k] == ')') {
            lineIndent = indentLevel - 1;
            if (lineIndent < 0)
                lineIndent = 0;
        }
        
        // Imprime espacios de indentación (4 espacios por nivel).
        for (int j = 0; j < lineIndent; j++) {
            printf("    ");
        }
        printf("%s\n", currentLine);

        // Detectar if y progn para incrementar indentación adecuadamente
        char buffer[256];
        int bufferPos = 0;
        inString = false;
        prognFound = false;
        ifFound = false;
        
        // Actualiza indentLevel recorriendo la línea, ignorando los paréntesis dentro de cadenas.
        for (int j = 0; j < pos; j++) {
            char c = currentLine[j];
            
            if (c == '\"') {
                // Si no se trata de un comilla escapada, se cambia el estado.
                if (j == 0 || currentLine[j - 1] != '\\')
                    inString = !inString;
            }
            
            if (!inString) {
                // Acumular caracteres para detectar tokens
                if (isalpha(c) || c == '-') {
                    if (bufferPos < 255) {
                        buffer[bufferPos++] = c;
                        buffer[bufferPos] = '\0';
                    }
                } else {
                    // Verificar si encontramos "if" o "progn"
                    if (strcmp(buffer, "if") == 0) {
                        ifFound = true;
                    } else if (strcmp(buffer, "progn") == 0) {
                        prognFound = true;
                    }
                    bufferPos = 0;
                    buffer[0] = '\0';
                }
                
                if (c == '(') {
                    indentLevel++;
                    // Si después de un paréntesis encontramos "if" o "progn",
                    // aumentamos el nivel de indentación en la siguiente línea
                } else if (c == ')') {
                    indentLevel--;
                }
            }
            
            // Prevenir que indentLevel se vuelva negativo.
            if (indentLevel < 0)
                indentLevel = 0;
        }
        
        // Ajustar nivel de indentación para el contenido de if y progn
        if (ifFound || prognFound) {
        }
    }
}

// Estructura para la tabla local de variables
typedef struct s_local_var {
    char *name;  // Nombre de la variable local
} t_local_var;

// Tabla para almacenar variables locales de la función actual
t_local_var local_vars[100];  // Limitado a 100 variables locales
int local_var_count = 0;      // Contador de variables en la tabla

// Función para buscar si una variable está en la tabla local
int search_local_var(char *local_var) {
    for (int i = 0; i < local_var_count; i++) {
        if (strcmp(local_vars[i].name, local_var) == 0) {
            return 1;  // La variable está en la tabla (es local)
        }
    }
    return 0;  // La variable no está en la tabla (es global)
}

// Función para agregar una variable a la tabla local
void add_local_var(char *var_name) {
    if (!search_local_var(var_name) && (local_var_count < 100)) {
        // Agregar la variable a la tabla
        local_vars[local_var_count].name = gen_code(var_name);
        local_var_count++;
    }
    return;
}

// Función para obtener el nombre completo de una variable
// (concatenado con función si es local, o el nombre original si es global)
char *get_var_name(char *var_name) {
    if (search_local_var(var_name)) {
        sprintf(temp, "%s_%s", current_function_name, var_name);
        return gen_code(temp);
    }
    return var_name; // Es global, devolver sin modificar
}

// Función para limpiar la tabla local (al salir de una función)
void clear_local_vars() {
    // No liberamos memoria ya que gen_code usa my_malloc
    local_var_count = 0;
}

/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",        PUTS, 
    "printf",      PRINTF, 
    "while",       WHILE,
    "&&",          AND,
    "||",          OR,
    "==",          EQ,
    "!=",          NEQ,
    "<=",          LE,
    ">=",          GE,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "return",      RETURN,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        
        return (0) ;
    }
    
    return c ;
}


int main ()
{   
    //yydebug = 1;
    yyparse () ;
}
