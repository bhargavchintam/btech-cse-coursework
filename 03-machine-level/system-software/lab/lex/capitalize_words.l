/* capitalize the first letter of each word.  flex capitalize_words.l && gcc lex.yy.c -o cap && ./cap < input */
%{
#include<ctype.h>
%}
%%
[a-zA-Z]+   { printf("%c%s", toupper(yytext[0]), yytext + 1); }
.|\n        { printf("%s", yytext); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
