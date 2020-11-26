lex:
%{
#include<stdio.h>
#include "y.tab.h"
%}
WS [ \t]*
EOL [\n]*
DT ("int"|"float"|"void")
ID [a-zA-Z][a-zA-Z0-9_ \.]*
STMT {WS}[a-zA-Z0-9\.\,\{\}\[\]"\"" \(\)]*{WS}[;]{WS}{EOL}
%%
{WS}"#include"{WS}"<"{WS}{ID}{WS}">"{WS}{EOL} {return ENT;}
{WS}{DT}{WS}"main()"{WS}{EOL} {return HEAD;}
{EOL}{STMT}*{EOL} {return DEF;}
{EOL}{WS}"{"{WS}{EOL} {return OB;}
{EOL}{WS}"}"{WS}{EOL} {return CB;}
%%
yacc:
%{
#include<stdio.h>
%}
%token HEAD ENT OB DEF CB
%%
expr: e {printf("VALID C PROGRAM\n");};
  e : ENT HEAD OB DEF CB;
%%
main()
{
 printf("ENTER THE INPUT : \n");
 yyparse();
}
yyerror()
{
 printf("INVALID C PROGRAM\n");
}
