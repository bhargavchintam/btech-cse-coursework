/* recognize tokens of a C program.  flex tokens.l && gcc lex.yy.c -o tok && ./tok < input.c */
%{
#include<string.h>
char *keys[] = {"int","float","char","double","void","if","else","while","for",
                "do","return","struct","const","printf","scanf",0};
int iskey(char *s){ int i; for(i=0;keys[i];i++) if(!strcmp(keys[i],s)) return 1; return 0; }
%}
%%
[ \t\n]+                { }
[0-9]+(\.[0-9]+)?       { printf("%-10s number\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("%-10s %s\n", yytext, iskey(yytext) ? "keyword" : "identifier"); }
"=="|"!="|"<="|">="|"&&"|"\|\|"   { printf("%-10s operator\n", yytext); }
[-+*/%=<>]              { printf("%-10s operator\n", yytext); }
[;,(){}\[\]]            { printf("%-10s symbol\n", yytext); }
.                       { }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
