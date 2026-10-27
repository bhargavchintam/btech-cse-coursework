/* count vowels and consonants.  flex vowels_consonants.l && gcc lex.yy.c -o vc && ./vc < input */
%{
int v = 0, c = 0;
%}
%%
[aeiouAEIOU]   { v++; }
[a-zA-Z]       { c++; }
.|\n           { }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Vowels = %d\n", v);
    printf("Consonants = %d\n", c);
    return 0;
}
