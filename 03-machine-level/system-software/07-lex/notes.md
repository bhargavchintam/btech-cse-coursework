# Unit 7 — LEX (Lexical Analyzer Generator)

## What LEX does
LEX (flex) takes a specification of **patterns** (regular expressions) and generates a C lexical analyzer, `yylex()`, that reads input and runs the action for each matched pattern.

## Structure of a LEX program
```
%{  C declarations  %}
   definitions
%%
   pattern   { action }
   ...
%%
   user C code (main, yywrap)
```
The three sections are separated by `%%`.

## Useful variables and rules
- `yytext` — the matched text; `yyleng` — its length.
- `yylval` — value passed to YACC.
- **Longest match** wins; on a tie, the **rule listed first** wins.
- `int yywrap(){ return 1; }` tells LEX there is no more input at EOF.

## Regular expressions
`.` any char (not newline), `*` zero or more, `+` one or more, `?` optional, `[ ]` class, `[^ ]` negated, `|` or, `{n,m}` repetition, `\` escape, `^`/`$` line anchors.
`[a-zA-Z_][a-zA-Z0-9_]*` = a C identifier. `[0-9]+(\.[0-9]+)?` = an integer or real number.

## Building
```
flex prog.l
gcc lex.yy.c -o prog
./prog < input
```

The `lab/lex/` folder has the programs — word count, vowels/consonants, keyword vs identifier, comment counting, tokenizer, and so on.

## Solved
**1. What does `yytext` hold?** The exact string matched by the current pattern.

**2. Two rules match the same length — which fires?** The one written earlier in the file.
