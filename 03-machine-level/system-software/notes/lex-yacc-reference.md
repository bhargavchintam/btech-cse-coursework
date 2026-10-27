# LEX & YACC quick reference

## LEX regular expressions
| Pattern | Meaning |
|---|---|
| `.` | any char except newline |
| `*` `+` `?` | zero+, one+, optional |
| `[abc]` `[^abc]` | class, negated class |
| `[a-z]` | range |
| `a|b` | a or b |
| `"..."` | literal |
| `{n,m}` | n to m repetitions |
| `^` `$` | start / end of line |
| `\n \t` | newline, tab |

`[a-zA-Z_][a-zA-Z0-9_]*` identifier · `[0-9]+` integer · `[0-9]+\.[0-9]+` real

## LEX variables
`yytext` matched text · `yyleng` its length · `yylval` value to YACC · `yyin`/`yyout` files · `ECHO` print yytext

## LEX structure
```
%{ C %}          %%          %%
definitions      rules       user code
```

## YACC declarations
`%token NAME` · `%left`/`%right`/`%nonassoc` (precedence, later = higher) · `%start rule` · `%%` separates sections

## YACC values
`$$` result of the rule · `$1 $2 …` right-hand-side symbols · `yyerror(s)` on a parse error · `yyparse()` runs the parser

## Build commands
```
flex prog.l && gcc lex.yy.c -o prog                 # LEX only
yacc -d prog.y && flex prog.l && gcc y.tab.c lex.yy.c -o prog   # LEX + YACC
```
`yacc -d` also writes `y.tab.h` (token defines) for the lexer to include.
