/* recognize the grammar a^m b^n, m,n >= 1.  yacc -d ambn.y && gcc y.tab.c -o ambn && ./ambn */
%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char *s);
int ok = 1;
%}
%token A B
%%
line : as bs '\n'   { return 0; }
     ;
as : as A
   | A
   ;
bs : bs B
   | B
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
    printf("enter a string of a's followed by b's: ");
    yyparse();
    printf(ok ? "valid (a^m b^n)\n" : "invalid\n");
    return 0;
}
