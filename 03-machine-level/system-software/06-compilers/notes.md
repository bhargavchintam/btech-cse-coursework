# Unit 6 — Compilers (Introduction)

## Phases of a compiler
| Phase | Job |
|---|---|
| **Lexical analysis** | source → stream of tokens (removes spaces/comments) |
| **Syntax analysis (parsing)** | tokens → parse tree, checks grammar |
| **Semantic analysis** | type checking, scope rules |
| **Intermediate code** | machine-independent form (e.g. three-address code) |
| **Optimization** | improve the intermediate code |
| **Code generation** | produce target/assembly code |

The **symbol table** and **error handler** interact with every phase.

## Analysis vs synthesis
Front end (**analysis**) breaks the source down and checks it; back end (**synthesis**) builds the target program.

## Grammars
A grammar is (V, T, P, S): variables, terminals, productions, start symbol. Programming languages use **context-free grammars** (CFG). A **parse tree** shows how a string is derived; ambiguity = more than one parse tree for one string.

## Lexical vs syntax analysis
- Lexical analysis uses **regular expressions** (recognized by finite automata) — this is what **LEX** generates.
- Syntax analysis uses **context-free grammars** (recognized by pushdown automata) — this is what **YACC** generates.

## Solved
**1. Output of the lexical analyzer?** A stream of tokens (and it fills the symbol table).

**2. Which phase catches `int x; x = "hi";`?** Semantic analysis — a type mismatch, not a grammar error.
