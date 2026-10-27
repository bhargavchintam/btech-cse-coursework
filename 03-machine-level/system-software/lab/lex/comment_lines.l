/* count single-line and multi-line comments.  flex comment_lines.l && gcc lex.yy.c -o cm && ./cm < input.c */
%{
int sl = 0, ml = 0;
%}
%x COMMENT
%%
"//".*         { sl++; }
"/*"           { ml++; BEGIN(COMMENT); }
<COMMENT>"*/"  { BEGIN(INITIAL); }
<COMMENT>.|\n  { }
.|\n           { }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Single line comments = %d\n", sl);
    printf("Multi line comments  = %d\n", ml);
    return 0;
}
