# Advanced topics

Grab-bag folder for the last unit: outlier detection, web mining, text mining, ensembles, and a quick word on
stream/graph mining. Nothing here is a whole new dataset — mostly small embedded examples plus the iris subset.

## Outlier / anomaly detection

An outlier is a point that doesn't fit the pattern of the rest. Could be a data-entry error, or the interesting
thing you're actually looking for (fraud, a faulty sensor). Three ways we did it:

Statistical (z-score). Assume the column is roughly normal, standardise it, flag anything too many sigmas out:

    z = (x - mean) / std      flag if |z| > 3

Only sensible if the data is bell-shaped. And the mean/std are themselves dragged around by the outlier, so with
a tiny sample a single huge value can hide (it inflates std and its own z drops). Fine for the injected-250 mark.

Distance / IQR. Distribution-free, uses the quartiles instead of mean/std:

    IQR = Q3 - Q1
    flag if x < Q1 - 1.5*IQR  or  x > Q3 + 1.5*IQR

Same 1.5 rule that draws the whiskers on a boxplot. More robust than z-score because quartiles don't move much
when one point goes crazy.

Density (LOF idea). Local Outlier Factor: compare how dense a point's neighbourhood is vs. its neighbours'
neighbourhoods. A point sitting in a sparse patch while its neighbours sit in dense patches gets LOF > 1 and is
an outlier. The nice part is it's *local* — it catches a point that's odd for its region even if globally it
looks average. (Uses the KNN distance from folder 04.)

| method   | assumes           | robust? |
|----------|-------------------|---------|
| z-score  | normal-ish        | no      |
| IQR      | nothing           | yes     |
| LOF      | nothing (density) | yes     |

> Rule of thumb: z-score for clean numeric columns, IQR when you don't trust the shape, LOF for the weird cases.

## Web mining

Mining the web splits into three:
- structure mining — the link graph (who links to whom). PageRank lives here.
- content mining — the actual text/images on the pages (this is really text mining, below).
- usage mining — the server logs / clickstreams, what users actually did.

PageRank (structure). A page is important if important pages link to it. Random surfer: mostly follows links,
but with probability 1-d he teleports to a random page (d = 0.85 damping):

    PR(p) = (1-d)/N + d * sum over q->p of PR(q)/outdeg(q)

Solve it by power iteration — start every page at 1/N and apply the formula until the ranks stop moving. The
teleport term is what keeps it from getting stuck in a dead-end and guarantees it converges. The ranks are a
probability distribution so they sum to 1. In 03_pagerank.py page C is linked from A, B and D, so it ends up
highest; D has no inlinks so it bottoms out at (1-d)/N.

## Text mining

Text is unstructured, so first turn a document into a vector. Bag of words: throw away order, just count which
words appear. Vocabulary = all distinct words, each doc = a vector of counts.

Raw counts over-reward common words ("the" appears everywhere and means nothing), so weight by TF-IDF:

    tf(t, d)  = count of t in d / length of d
    idf(t)    = log( N / df(t) )          df = number of docs containing t
    tfidf     = tf * idf

The idf punishes words that show up in lots of documents. A word in *every* document has df = N so
idf = log(N/N) = log(1) = 0, and its tf-idf is 0 in every doc — exactly what 04_tfidf.py shows for "the". So
tf-idf keeps the words that are frequent in *this* doc but rare across the corpus, which are the ones that
actually characterise it.

## Ensemble methods

One model is often weak; combining many usually beats any single one. Two main recipes:

Bagging (bootstrap aggregating). Draw B bootstrap samples (sample rows with replacement), train a model on each,
then average / majority-vote the predictions. The bootstrap decorrelates the models so the vote cancels their
individual variance. Works best with unstable, high-variance learners like deep trees — a decision stump is the
toy version I used in 05_bagging.py.

Boosting. Train models in sequence, each one focusing on the rows the previous ones got wrong (AdaBoost reweights
the misclassified points, then combines the weak learners with weights). Bagging is parallel and cuts variance;
boosting is sequential and cuts bias. Boosting can overfit noisy data, bagging basically can't.

Random forest. Bagging + trees, with one extra trick: at each split the tree only looks at a random subset of the
features. That stops every tree from splitting on the same one dominant feature, so the trees are less alike and
the vote is stronger. sklearn does this in 06_random_forest_sklearn.py, and the feature-importances confirm the
petal measurements carry the iris subset (same story as the single tree in folder 06).

## Stream and graph mining (just a mention)

Stream mining = data arrives too fast/too big to store, so you make one pass and keep only a summary (sliding
windows, sketches, reservoir sampling). Graph mining = patterns *in* a graph — communities, frequent subgraphs,
centrality — the social-network / web-graph side of things, PageRank being one example.
