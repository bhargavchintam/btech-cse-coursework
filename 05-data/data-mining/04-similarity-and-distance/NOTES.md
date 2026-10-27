# Similarity and distance

Lots of mining methods (KNN, k-means, hierarchical clustering, DBSCAN) only need one thing from the data:
how close are two rows. That closeness is called **proximity** and it comes in two flavours that are just
opposites of each other:

- **similarity** s -> high when the two objects are alike (usually in [0, 1], 1 = identical)
- **dissimilarity / distance** d -> high when they are far apart (0 = identical, no upper bound in general)

So a lot of the time you convert between them, e.g. cosine distance = 1 - cosine similarity. Pick whichever
the algorithm wants.

## Distance for numeric data

A proper distance (a metric) has to satisfy: d(a,a)=0, d(a,b) >= 0, it's symmetric d(a,b)=d(b,a), and the
triangle inequality d(a,c) <= d(a,b)+d(b,c). Euclidean/Manhattan/Chebyshev all do. Cosine similarity does
NOT (it's a similarity, not a distance) and plain Jaccard on sets isn't a metric either.

**Euclidean (L2)** — straight line distance, the usual one:

    d(a, b) = sqrt( sum_i (a_i - b_i)^2 )

Sanity check I always use: [0,0] to [3,4] is 5 (the 3-4-5 triangle).

**Manhattan (L1)** — sum of the axis steps, like walking city blocks:

    d(a, b) = sum_i |a_i - b_i|

**Minkowski (Lp)** — the general form, both of the above are special cases:

    d(a, b) = ( sum_i |a_i - b_i|^p ) ^ (1/p)

    p = 1   -> Manhattan
    p = 2   -> Euclidean
    p = inf -> supremum / Chebyshev

**Supremum (L-inf, Chebyshev)** — as p goes to infinity the biggest coordinate difference dominates and the
whole thing collapses to:

    d(a, b) = max_i |a_i - b_i|

One thing the lecturer hammered: scale first. If one feature is 0-1000 and another is 0-1, the big one owns
the distance and the small one may as well not exist. So min-max or z-score (the 02-preprocessing folder)
before you measure. Same warning as in the KNN notes.

## Similarity for binary data and sets

For 0/1 attributes count the matches. Say for two objects, q = both 1, r = 1 then 0, s = 0 then 1, t = both 0.

**Simple Matching Coefficient** — counts the 0-0 matches too:

    SMC = (q + t) / (q + r + s + t)

**Jaccard** — ignores the 0-0 matches (t), because for sparse data "both absent" isn't interesting (two
shoppers who both DIDN'T buy caviar aren't similar for that reason):

    J = q / (q + r + s)

On sets that's just intersection over union:

    J(A, B) = |A ∩ B| / |A ∪ B|

Check: {1,2,3} and {2,3,4} share {2,3} out of {1,2,3,4} = 2/4 = 0.5.

## Cosine similarity — for documents / vectors

For text (bag-of-words / TF-IDF vectors) the vectors are long and sparse and their length depends on document
size, so you compare the *angle* not the distance:

    cos(a, b) = (a . b) / (||a|| * ||b||)

1 = same direction, 0 = orthogonal (no shared words), and it only cares about direction so [1,1,1] and
[2,2,2] come out 1.0. Cosine distance = 1 - cos.

## Hamming distance

Number of positions where two equal-length strings / bit vectors differ:

    "karolin" vs "kathrin" -> 3

Used for categorical/binary strings and error-correcting codes. For 0/1 vectors it's just r + s from above
(the mismatches).

## When to use which

| measure    | data           | notes                                        |
|------------|----------------|----------------------------------------------|
| Euclidean  | numeric        | default; scale features first                |
| Manhattan  | numeric        | less sensitive to outliers than L2           |
| Chebyshev  | numeric        | worst single-coordinate gap (grid moves)     |
| Cosine     | text / vectors | orientation not magnitude; sparse high-dim   |
| Jaccard    | sets / binary  | presence/absence, skips 0-0 matches          |
| SMC        | binary         | use when 0-0 IS meaningful (symmetric attrs) |
| Hamming    | strings/binary | count of differing positions                 |

> Distance is what the algorithm actually sees. Choose it wrong and even a good clustering method gives junk.

Got a Jaccard-vs-SMC question wrong in the internal once — I used SMC on sparse market-basket data and let the
0-0 matches inflate the similarity. For sparse presence/absence it should be Jaccard.
