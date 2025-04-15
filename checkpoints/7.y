// Esteban Gómez Buitrago, Nicolás Alejandro Cuesta García, Grupo 102
// 100485446@alumnos.uc3m.es 100495966@alumnos.uc3m.es

%{                          // SECCION 1 Declaraciones de C-Yacc

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
void format_lisp_program(const char *);

char temp [2048] ;

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
#define YYDEBUG 1

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el comienzo del proc. main
%token WHILE         // identifica el bucle main
%token PUTS          // identifica el comienzo de la función puts
%token PRINTF        // identifica el comienzo de la función printf
%token AND           // identifica AND (&&)
%token OR            // identifica OR (||)
%token EQ            // identifica EQ (==)
%token NEQ           // identifica NEQ (!=)
%token LE            // identifica LE (<=)
%token GE            // identifica GE (>=)
%token IF            // identifica IF
%token ELSE          // identifica ELSE
%token FOR           // identifica FOR

%right '='                    // es la ultima operacion que se debe realizar
%left OR
%left AND
%left EQ NEQ
%left '<' LE '>' GE     
%left '+' '-'                 // menor orden de precedencia
%left '*' '/' '%'             // orden de precedencia intermedio
%right UNARY_SIGN '!'         // mayor orden de precedencia //REVIEW

%%                            // Seccion 3 Gramatica - Semantico

super_axioma_programa: 
            axioma_programa  {  $$.code = gen_code($1.code);
                                format_lisp_program($$.code); } //TODO
            ;

axioma_programa: 
            dec_variables dec_funciones    { sprintf(temp, "%s%s", $1.code, $2.code); 
                                             $$.code = gen_code(temp); }
            ;

dec_variables: 
 				{ $$.code = gen_code(""); }
            | INTEGER var_list ';' dec_variables { sprintf (temp, "%s%s", $2.code, $4.code) ; 
                                                   $$.code = gen_code (temp) ;} 
            ;  

var_list:
   		    IDENTIF                 { sprintf (temp, "(setq %s 0)\n", $1.code) ; 
                                      $$.code = gen_code (temp) ; }
 		    | IDENTIF '=' NUMBER    { sprintf (temp, "(setq %s %d)\n", $1.code, $3.value) ; 
                                      $$.code = gen_code (temp) ; }
 		    | var_decl ',' var_list   { sprintf (temp, "%s%s\n", $1.code, $3.code) ; 
                                      $$.code = gen_code (temp) ;  } 
            ;

var_decl:
   		    IDENTIF                 { sprintf (temp, "(setq %s 0)", $1.code) ; 
                                      $$.code = gen_code (temp) ; }
 		    | IDENTIF '=' NUMBER    { sprintf (temp, "(setq %s %d)", $1.code, $3.value) ; 
                                      $$.code = gen_code (temp) ; }
            ;

dec_funciones:   
            MAIN '(' ')' '{' axioma_codigo '}'	{ sprintf (temp, "(defun main ()\n%s)", $5.code) ; 
                                                    $$.code = gen_code (temp); }
            ;

/*
funciones:                                                               { $$.code = gen_code(""); }
            | funciones IDENTIF '(' argumentos ')' '{' axioma_codigo '}' { sprintf (temp, "%s(defun %s (%s)\n%s)\n", $1.code, $2.code, $4.code, $7.code) ; 
                                                                           $$.code = gen_code (temp) ; }
            ;
		
argumentos:                                { $$.code = gen_code(""); }
            | r_argumentos INTEGER IDENTIF { sprintf (temp, "%s%s", $1.code, $3.code) ; 
                                             $$.code = gen_code (temp) ; } 
            ;

r_argumentos:                                  { $$.code = gen_code(""); }
            | r_argumentos INTEGER IDENTIF ',' { sprintf (temp, "%s%s ", $1.code, $3.code) ; 
                                                 $$.code = gen_code (temp) ; } 
            ;
*/

axioma_codigo:    	
                                           { $$.code = gen_code(""); }
            | sentencia axioma_codigo  { sprintf (temp, "%s%s", $1.code, $2.code) ; 
                                        $$.code = gen_code (temp) ; }
        	;

sentencia:    IDENTIF '=' expresion ';'                                                 { sprintf (temp, "(setq %s %s)\n", $1.code, $3.code) ; 
                                                                                            $$.code = gen_code (temp) ; }
            | PUTS '(' STRING ')' ';'                                                   { sprintf (temp, "(print \"%s\")\n", $3.code) ;  
                                                                                            $$.code = gen_code (temp) ; }
            | PRINTF '(' STRING ',' elems ')' ';'                                       { sprintf (temp, "%s", $5.code) ;  
                                                                                            $$.code = gen_code (temp) ; }
            | WHILE  '(' expresion ')' '{' axioma_codigo '}'                            {  sprintf (temp, "(loop while %s do\n%s)\n", $3.code, $6.code) ;
                                                                                            $$.code = gen_code (temp) ; }
            | IF  '(' expresion ')' '{' axioma_codigo '}'                               {  sprintf (temp, "(if %s\n(progn\n%s)\n)\n", $3.code, $6.code) ;
                                                                                            $$.code = gen_code (temp) ; }
            | IF  '(' expresion ')' '{' axioma_codigo '}' ELSE '{' axioma_codigo '}'    {  sprintf (temp, "(if %s\n(progn\n%s)\n(progn\n%s)\n)\n", $3.code, $6.code, $10.code) ;
                                                                                            $$.code = gen_code (temp) ; }
            ;

elems:       
            elem r_elems { sprintf (temp, "%s%s", $1.code, $2.code) ; 
                           $$.code = gen_code (temp) ;}
            ;

r_elems:                       { $$.code = gen_code ("") ; }
            | ',' elem r_elems { sprintf (temp, "%s%s", $2.code, $3.code) ; 
                                  $$.code = gen_code (temp); }
            ;

elem:       
             expresion { sprintf (temp, "(princ %s)\n", $1.code) ; 
                         $$.code = gen_code (temp) ;}
            | STRING   { sprintf (temp, "(princ %s)\n", $1.code) ;
                         $$.code = gen_code (temp) ;}
            ;

expresion:      termino                  { $$.code = gen_code($1.code); }
            |   expresion '+' expresion  { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '-' expresion  { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '*' expresion  { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '/' expresion  { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '%' expresion  { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion AND expresion  { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion OR expresion  { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion NEQ expresion  { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion EQ expresion  { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '<' expresion  { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion LE expresion  { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '>' expresion  { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion GE expresion  { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   '!' expresion           { sprintf (temp, "(not %s)", $2.code) ; //REVIEW
                                            $$.code = gen_code (temp) ; }   
            ;

termino:        operando                           { $$.code = gen_code($1.code); }                          
            |   '+' operando %prec UNARY_SIGN      { $$.code = gen_code($2.code); }
            |   '-' operando %prec UNARY_SIGN      { sprintf (temp, "(- %s)", $2.code) ;
                                                     $$.code = gen_code (temp) ; } 
            ;

operando:       IDENTIF                  { sprintf (temp, "%s", $1.code) ;
                                           $$.code = gen_code (temp) ; }
            |   NUMBER                   { sprintf (temp, "%d", $1.value) ;
                                           $$.code = gen_code (temp) ; }
            |   '(' expresion ')'        { $$.code = gen_code($2.code); }
            ;


%%                            // SECCION 4    Codigo en C

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
void format_lisp_program(const char * input) {
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
    yydebug = 1;
    yyparse () ;
}
