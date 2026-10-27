/* classify whitespace-separated tokens as valid/invalid identifiers.  flex valid_identifier.l && gcc lex.yy.c -o vid && ./vid < input */
%{
%}
%%
[a-zA-Z_][a-zA-Z0-9_]*   { printf("%-12s valid identifier\n", yytext); }
[0-9]+[a-zA-Z0-9_]*      { printf("%-12s invalid identifier\n", yytext); }
[^ \t\n]+                { printf("%-12s invalid\n", yytext); }
.|\n                     { }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
