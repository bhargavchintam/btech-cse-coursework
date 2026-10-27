/* desk calculator with precedence.  yacc -d calculator.y && flex calculator.l && gcc y.tab.c lex.yy.c -o calc && ./calc */
%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
line : expr '\n'      { printf("= %d\n", $1); return 0; }
     ;
expr : expr '+' expr  { $$ = $1 + $3; }
     | expr '-' expr  { $$ = $1 - $3; }
     | expr '*' expr  { $$ = $1 * $3; }
     | expr '/' expr  { $$ = $1 / $3; }
     | '(' expr ')'   { $$ = $2; }
     | NUM            { $$ = $1; }
     ;
%%
void yyerror(const char *s){ fprintf(stderr, "invalid expression\n"); }
int main(){ return yyparse(); }
