/* count operators and operands in an expression.  flex operators_operands.l && gcc lex.yy.c -o oo && ./oo < input */
%{
int op = 0, opd = 0;
%}
%%
[0-9]+(\.[0-9]+)?        { opd++; }
[a-zA-Z_][a-zA-Z0-9_]*   { opd++; }
[-+*/%=]                 { op++; }
.|\n                     { }
%%
int yywrap(){ return 1; }
int main()
{
    yylex();
    printf("Operators = %d\n", op);
    printf("Operands  = %d\n", opd);
    return 0;
}
