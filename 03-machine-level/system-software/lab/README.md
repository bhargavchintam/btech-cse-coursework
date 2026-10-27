# System Software Lab

The lab is in three parts: LEX programs (Part A), YACC programs (Part B), and C system programs
(Part C). Build with the system flex / bison / gcc.

## Part A — LEX (`lab/lex/`)
| Program | Does | Run |
|---|---|---|
| wc.l | count lines, words, characters | `./wc < input` |
| vowels_consonants.l | count vowels and consonants | `./vc < input` |
| count_numbers.l | count +/− integers and fractions | `./num < input` |
| keywords_identifiers.l | recognize C keywords vs identifiers | `./ki < input.c` |
| comment_lines.l | count single/multi-line comments | `./cm < input.c` |
| valid_identifier.l | classify tokens as valid identifiers | `./vid < input` |
| tokens.l | tokenize a C program | `./tok < input.c` |
| capitalize_words.l | capitalize the first letter of each word | `./cap < input` |
| count_printf_scanf.l | count printf and scanf statements | `./ps < input.c` |
| operators_operands.l | count operators and operands | `./oo < input` |
| char_types.l | count letters, digits, spaces, specials | `./ct < input` |
| count_word.l | count occurrences of a given word | `./cw word < input` |

Build each: `flex x.l && gcc lex.yy.c -o x`

## Part B — YACC (`lab/yacc/`)
| Program | Does |
|---|---|
| calculator.y (+.l) | evaluate an arithmetic expression with precedence |
| valid_expr.y (+.l) | test whether an arithmetic expression is valid |
| valid_variable.y (+.l) | recognize a valid C variable |
| valid_declaration.y (+.l) | recognize a valid declaration `int a, b, c ;` |
| anbn.y | recognize the grammar aⁿbⁿ, n ≥ 1 |
| ambn.y | recognize the grammar aᵐbⁿ, m,n ≥ 1 |
| anb.y | recognize the grammar aⁿb |
| nested_paren.y | recognize balanced/nested parentheses |

Build with a lexer: `yacc -d x.y && flex x.l && gcc y.tab.c lex.yy.c -o x`
Build with an inline lexer: `yacc -d x.y && gcc y.tab.c -o x`

## Part C — C system programs (`lab/c/`)
| Program | Does | Input files |
|---|---|---|
| pass1.c | pass 1 of a two-pass assembler (SYMTAB, length) | input.txt, optab.txt |
| pass2.c | pass 2: object program (H/T/E records) | intermediate.txt, symtab.txt, optab.txt |
| macro_processor.c | expand macro definitions/invocations | macro_input.txt |
| absolute_loader.c | load an object program into memory | obj.txt |

Build each: `gcc -std=c99 -Wall x.c -o x`. Run pass1 before pass2 (pass1 writes the intermediate and symtab files pass2 reads). On the COPY example pass2 emits:
```
H^COPY  ^001000^000012
T^001000^0F^031009^18100C^0C100F^000005^000001
E^001000
```
