/* count letters, digits, whitespace and special characters.  flex char_types.l && gcc lex.yy.c -o ct && ./ct < input */
%{
int letters = 0, digits = 0, spaces = 0, special = 0;
%}
%%
[a-zA-Z]   { letters++; }
[0-9]      { digits++; }
[ \t\n]    { spaces++; }
.          { special++; }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Letters = %d\n", letters);
    printf("Digits  = %d\n", digits);
    printf("Spaces  = %d\n", spaces);
    printf("Special = %d\n", special);
    return 0;
}
