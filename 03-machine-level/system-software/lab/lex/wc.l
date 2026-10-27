/* count lines, words and characters.  flex wc.l && gcc lex.yy.c -o wc && ./wc < input */
%{
int lines = 0, words = 0, chars = 0;
%}
%%
\n          { lines++; chars++; }
[^ \t\n]+   { words++; chars += yyleng; }
.           { chars++; }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Lines = %d\n", lines);
    printf("Words = %d\n", words);
    printf("Characters = %d\n", chars);
    return 0;
}
