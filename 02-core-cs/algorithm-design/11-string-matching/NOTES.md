# String matching

Given a text T of length n and a pattern P of length m (m <= n), find where P occurs in
T - either the first match or all of them. The alphabet is fixed and small (ASCII here).
Every program below reports every match position, 0-indexed.

## Brute force / naive
Line the pattern up at shift i = 0, compare left to right; on a mismatch slide one step
right and start over. No preprocessing. Worst case Theta(nm) - e.g. "aaaa...b" searched
in "aaaa...a". Usually much better on random text. (01_naive.cpp)

## Rabin-Karp
Compare hashes instead of characters. Hash the pattern once, hash the first window of the
text, then ROLL the hash one position at a time (drop the leading char, add the trailing
one) so each step is O(1). Only when two hashes match do you verify character by character
- that guards against a hash collision (a spurious hit). Average O(n+m), worst Theta(nm)
if everything collides. (02_rabin_karp.cpp)

## Knuth-Morris-Pratt
Never re-examine a text character. Precompute the prefix / failure function of the pattern:
pi[i] = length of the longest proper prefix of P[0..i] that is also a suffix. On a mismatch
after matching q characters, jump the pattern back to pi[q-1] instead of to 0 - the text
index never moves backward. Preprocessing O(m), search O(n), total O(n+m). (03_kmp.cpp)

## Horspool
A simpler cousin of Boyer-Moore. Preprocess a shift table over the alphabet: for the
character c that lines up with the LAST pattern character, shift[c] = distance to c's
rightmost occurrence in the first m-1 characters (or m if c is absent). Compare the aligned
window right to left; then jump by shift[that last text char]. Average sub-linear, worst
Theta(nm). (04_horspool.cpp)

## Boyer-Moore
Compare right to left and use two rules, taking the bigger jump:
- bad-symbol: on a mismatch at pattern index j against text char c, shift so the rightmost
  c in the pattern lines up (or past it, if c is not in the pattern).
- good-suffix: reuse the suffix that already matched.
This file implements a clean bad-symbol version. On long natural-language text Boyer-Moore
is usually the fastest of the lot. (05_boyer_moore.cpp)

Horspool, Boyer-Moore and KMP are all input enhancement (chapter 6): the cost goes into
preprocessing the PATTERN, then the search flies.

## Complexity
```
algorithm       preprocessing     search (worst)    search (average)
--------------------------------------------------------------------
brute force     -                 Theta(nm)         O(n+m)
Rabin-Karp      Theta(m)          Theta(nm)         O(n+m)
KMP             Theta(m)          Theta(n)          Theta(n)
Horspool        Theta(m+A)        Theta(nm)         sub-linear
Boyer-Moore     Theta(m+A)        Theta(nm)*        sub-linear
```
A = alphabet size. (*) full Boyer-Moore with both rules is Theta(n) in the worst case; the
bad-symbol-only version here can drop to Theta(nm) on a bad input, same as Horspool.
