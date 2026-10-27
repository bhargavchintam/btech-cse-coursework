%{
#include "y.tab.h"
#include<string.h>
%}
%%
"int"|"float"|"char"|"double"   { return TYPE; }
[a-zA-Z_][a-zA-Z0-9_]*          { return ID; }
[ \t]                           { }
[,;]                            { return yytext[0]; }
\n                              { return '\n'; }
.                               { return yytext[0]; }
%%
int yywrap(){ return 1; }
