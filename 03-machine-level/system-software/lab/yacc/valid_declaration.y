/* recognize a valid variable declaration.  yacc -d valid_declaration.y && flex valid_declaration.l && gcc y.tab.c lex.yy.c -o vd && ./vd */
%{
#include<stdio.h>
int yylex(void);
void yyerror(const char *s);
int valid = 1;
%}
%token TYPE ID
%%
decl : TYPE idlist ';' '\n'   { return 0; }
     ;
idlist : ID
       | idlist ',' ID
       ;
%%
void yyerror(const char *s){ valid = 0; }
int main()
{
    printf("enter a declaration: ");
    yyparse();
    printf(valid ? "valid declaration\n" : "invalid declaration\n");
    return 0;
}
