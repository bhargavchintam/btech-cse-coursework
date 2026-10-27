/* validate an arithmetic expression.  yacc -d valid_expr.y && flex valid_expr.l && gcc y.tab.c lex.yy.c -o ve && ./ve */
%{
#include<stdio.h>
int yylex(void);
void yyerror(const char *s);
int valid = 1;
%}
%token NUM ID
%left '+' '-'
%left '*' '/'
%%
line : expr '\n'      { return 0; }
     ;
expr : expr '+' expr
     | expr '-' expr
     | expr '*' expr
     | expr '/' expr
     | '(' expr ')'
     | NUM
     | ID
     ;
%%
void yyerror(const char *s){ valid = 0; }
int main()
{
    yyparse();
    printf(valid ? "valid expression\n" : "invalid expression\n");
    return 0;
}
