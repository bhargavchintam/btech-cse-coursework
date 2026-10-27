# Association rules

Market basket analysis: given a pile of transactions (each a set of items a customer bought together),
find rules like {beer} -> {diaper} that say "people who buy the left side tend to buy the right side".
Unsupervised — no labels, we just look for items that co-occur more than chance.

Toy data in datasets/transactions.csv, 5 baskets:

    1  bread milk
    2  bread diaper beer eggs
    3  milk diaper beer cola
    4  bread milk diaper beer
    5  bread milk diaper cola

## The three numbers

For an itemset X, support is the fraction of transactions that contain X:

    support(X) = count(X) / N

A rule is A -> B where A and B are disjoint itemsets. Its support and confidence:

    support(A -> B)    = support(A ∪ B)
    confidence(A -> B) = support(A ∪ B) / support(A)

Confidence is just a conditional probability P(B | A): out of the baskets with A, how many also had B.
Problem with confidence: if B is popular on its own, a high confidence can be misleading. Lift fixes that:

    lift(A -> B) = confidence(A -> B) / support(B) = support(A ∪ B) / (support(A) * support(B))

- lift > 1: A and B show up together MORE than if they were independent (positively correlated)
- lift = 1: independent, the rule tells you nothing
- lift < 1: they avoid each other (negatively correlated)

On this data beer -> diaper has confidence 1.0 (every beer basket also has a diaper) and lift 1.25, so
buying beer really does pull diaper up. bread -> milk has confidence 0.75 but lift 0.94 (< 1) — milk is so
common that bread actually makes it slightly *less* likely than chance.

## Frequent itemsets

Fix a min_support threshold; an itemset is "frequent" if its support >= min_support. With min_support = 0.6
that means a count of at least 3 out of 5. Counting by hand:

    | itemset          | count | frequent? |
    | bread            |   4   | yes       |
    | milk             |   4   | yes       |
    | diaper           |   4   | yes       |
    | beer             |   3   | yes       |
    | eggs             |   1   | no        |
    | cola             |   2   | no        |
    | {bread, milk}    |   3   | yes       |
    | {bread, diaper}  |   3   | yes       |
    | {milk, diaper}   |   3   | yes       |
    | {diaper, beer}   |   3   | yes       |
    | {bread, milk, diaper} | 2 | no       |

So L1 = {bread, milk, diaper, beer} and L2 = those four pairs. No frequent 3-itemset. (In the internal I
forgot {bread, diaper} — it's in baskets 2, 4, 5 so it counts, don't skip it.)

## Apriori

The whole trick is the **apriori property** (a.k.a. downward closure):

> If an itemset is frequent, then every one of its subsets is frequent too.
> Equivalently — if a subset is infrequent, the itemset can't be frequent, so throw it out early.

That lets us build up level by level instead of testing all 2^d itemsets (brute force in 05 does test all of
them, only to confirm Apriori got the same answer).

Loop:
1. L1 = frequent single items (scan the data, count, keep count >= min_count).
2. Candidate generation (apriori-gen): join L_k with itself — merge two frequent k-itemsets that share
   their first k-1 items into a (k+1)-itemset.
3. Prune: drop any candidate that has a k-subset which is NOT in L_k (downward closure — no point counting it).
4. Scan the data, count the survivors, keep the frequent ones = L_{k+1}.
5. Repeat until a level is empty.

The prune step is what makes it cheap: we never even count a candidate if one of its subsets already failed.

## FP-growth

Apriori rescans the database once per level, which hurts on big data. FP-growth scans it twice, total:
- pass 1: count items, keep the frequent ones, sort them by frequency (descending).
- pass 2: insert each transaction (filtered to frequent items, in that sorted order) into an **FP-tree** —
  a prefix tree where shared prefixes share nodes and each node carries a count. A header table links all
  the nodes for the same item.

Then mine recursively: for each item (least frequent first), read its **conditional pattern base** (the
prefix paths leading to it), build a smaller **conditional FP-tree** from those paths, and recurse. No
candidate generation at all — the frequent itemsets fall out of the tree. Same answer as Apriori, just a
different route (04 cross-checks the two on this data — they match).

## Rule generation

Frequent itemsets only tell you *what* co-occurs; the rules come after. For each frequent itemset F with
|F| >= 2, split it every possible way into A and B = F \ A (both non-empty), and keep the rule A -> B when
confidence >= min_conf. Support is already known (it's support(F)); confidence is support(F)/support(A),
which is cheap because support(A) was computed at an earlier level. Then report lift so weak-but-popular
rules can be spotted and dropped.
