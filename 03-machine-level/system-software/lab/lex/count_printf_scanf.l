/* count printf and scanf statements.  flex count_printf_scanf.l && gcc lex.yy.c -o ps && ./ps < input.c */
%{
int p = 0, s = 0;
%}
%%
"printf"   { p++; }
"scanf"    { s++; }
.|\n       { }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("printf statements = %d\n", p);
    printf("scanf statements  = %d\n", s);
    return 0;
}
