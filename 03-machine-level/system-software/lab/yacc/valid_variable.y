/* recognize a valid C variable (identifier).  yacc -d valid_variable.y && flex valid_variable.l && gcc y.tab.c lex.yy.c -o vv && ./vv */
%{
#include<stdio.h>
int yylex(void);
void yyerror(const char *s);
int valid = 1;
%}
%token LETTER DIGIT
%%
start : LETTER seq '\n'   { return 0; }
      ;
seq : LETTER seq
    | DIGIT seq
    | /* empty */
    ;
%%
void yyerror(const char *s){ valid = 0; }
int main()
{
    printf("enter a variable name: ");
    yyparse();
    printf(valid ? "valid variable\n" : "invalid variable\n");
    return 0;
}
