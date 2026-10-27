/* recognize balanced/nested parentheses.  yacc -d nested_paren.y && gcc y.tab.c -o np && ./np */
%{
#include<stdio.h>
int yylex(void);
void yyerror(const char *s);
int ok = 1;
%}
%%
line : p '\n'   { return 0; }
     ;
p : '(' p ')' p
  | /* empty */
  ;
%%
void yyerror(const char *s){ ok = 0; }
int yylex(void){ return getchar(); }
int main()
{
    printf("enter a parenthesis string: ");
    yyparse();
    printf(ok ? "balanced\n" : "not balanced\n");
    return 0;
}
