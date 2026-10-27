/* recognize the grammar a^n b, n >= 0 (n a's then a single b).  yacc -d anb.y && gcc y.tab.c -o anb && ./anb */
%{
#include<stdio.h>
int yylex(void);
void yyerror(const char *s);
int ok = 1;
%}
%token A B
%%
line : s B '\n'   { return 0; }
     ;
s : A s
  | /* empty */
  ;
%%
void yyerror(const char *s){ ok = 0; }
int yylex(void)
{
    int c = getchar();
    if(c == 'a') return A;
    if(c == 'b') return B;
    return c;
}
int main()
{
    printf("enter a string: ");
    yyparse();
    printf(ok ? "valid (a^n b)\n" : "invalid\n");
    return 0;
}
