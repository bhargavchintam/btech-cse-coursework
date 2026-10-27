/* recognize C keywords and identifiers.  flex keywords_identifiers.l && gcc lex.yy.c -o ki && ./ki < input.c */
%{
#include<string.h>
int kw = 0, id = 0;
char *keys[] = {"int","float","char","double","void","if","else","while","for",
                "do","return","switch","case","break","continue","struct","const",
                "long","short","unsigned","signed","static","sizeof",0};
int iskey(char *s)
{
    int i;
    for(i = 0; keys[i]; i++)
        if(!strcmp(keys[i], s)) return 1;
    return 0;
}
%}
%%
[a-zA-Z_][a-zA-Z0-9_]*  { if(iskey(yytext)){ kw++; printf("%-10s keyword\n", yytext); }
                          else { id++; printf("%-10s identifier\n", yytext); } }
[0-9]+                  { }
.|\n                    { }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Keywords = %d, Identifiers = %d\n", kw, id);
    return 0;
}
