# Unit 8 — YACC (Yet Another Compiler-Compiler)

## What YACC does
YACC (bison) takes a **context-free grammar** with actions and generates a parser, `yyparse()`, that uses **bottom-up shift-reduce** parsing (LALR). It calls `yylex()` — usually a LEX-generated lexer — to get tokens.

## Structure of a YACC program
```
%{  C declarations  %}
   %token, %left, %right   (declarations)
%%
   rule : body { action } ;
   ...
%%
   C code (yyerror, main)
```

## Grammar rules
```
expr : expr '+' expr   { $$ = $1 + $3; }
     | NUM             { $$ = $1; }
     ;
```
`$$` is the result of the rule, `$1 $2 $3 …` are the components. `%left '+' '-'` then `%left '*' '/'` sets precedence (later = higher) and associativity, which resolves the ambiguity of the expression grammar.

## LEX + YACC together
- `yacc -d prog.y` generates `y.tab.c` and `y.tab.h` (the token definitions).
- the lexer `#include "y.tab.h"` and `return`s those tokens.
- build: `yacc -d prog.y && flex prog.l && gcc y.tab.c lex.yy.c -o prog`.

## Shift-reduce parsing
The parser **shifts** input tokens onto a stack and **reduces** the top of the stack when it matches a rule's right-hand side, until only the start symbol remains. Conflicts: **shift-reduce** and **reduce-reduce** (resolved by precedence, or a grammar fix).

The `lab/yacc/` folder has the programs — calculator, expression validation, a^n b^n, valid variable, balanced parentheses, valid declaration.

## Solved
**1. What does `yacc -d` generate?** `y.tab.c` (the parser) and `y.tab.h` (token `#define`s for the lexer).

**2. `$1` in an action?** The value (yylval / sub-rule result) of the first symbol on the right-hand side.
