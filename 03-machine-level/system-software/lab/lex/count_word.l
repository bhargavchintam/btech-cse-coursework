/* count occurrences of a given word.  flex count_word.l && gcc lex.yy.c -o cw && ./cw the < input */
%{
#include<string.h>
char *target;
int count = 0;
%}
%%
[a-zA-Z]+   { if(strcmp(yytext, target) == 0) count++; }
.|\n        { }
%%
int yywrap(){ return 1; }
int main(int argc, char **argv)
{
    if(argc < 2){ printf("usage: cw word < input\n"); return 1; }
    target = argv[1];
    yylex();
    printf("'%s' occurs %d times\n", target, count);
    return 0;
}
