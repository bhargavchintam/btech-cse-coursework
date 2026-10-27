/* recognize the grammar a^n b^n, n >= 1.  yacc -d anbn.y && gcc y.tab.c -o anbn && ./anbn */
%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char *s);
int ok = 1;
%}
%token A B
%%
line : s '\n'   { return 0; }
     ;
s : A s B
  | A B
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
    printf("enter a string of a's and b's: ");
    yyparse();
    printf(ok ? "valid (a^n b^n)\n" : "invalid\n");
    return 0;
}
