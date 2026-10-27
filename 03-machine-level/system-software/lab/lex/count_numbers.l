/* count positive/negative integers and fractions.  flex count_numbers.l && gcc lex.yy.c -o num && ./num < input */
%{
int pi = 0, ni = 0, pf = 0, nf = 0;
%}
%%
-[0-9]+\.[0-9]+      { nf++; }
[+]?[0-9]+\.[0-9]+   { pf++; }
-[0-9]+             { ni++; }
[+]?[0-9]+          { pi++; }
.|\n                { }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Positive integers  = %d\n", pi);
    printf("Negative integers  = %d\n", ni);
    printf("Positive fractions = %d\n", pf);
    printf("Negative fractions = %d\n", nf);
    return 0;
}
