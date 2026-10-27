# Data preprocessing

Real data is dirty. Rows have missing cells, typos, values in different units, duplicate records, the odd
sensor reading that's way off. If you feed that straight into a mining algorithm you get garbage out — a
k-means centroid drifts to an outlier, a distance is dominated by whichever column has the biggest numbers.
So before any mining you clean and reshape the data. Rough rule people quote: this step eats most of the
project's time.

## Data quality problems
- missing values — a blank cell (NaN). Sensor failed, the person skipped the field, join didn't match.
- noise — random error on top of the true value. Rounding, a shaky measurement.
- outliers — a value far from the rest. Sometimes a real extreme, sometimes a mistake.
- inconsistency — "Male"/"M"/"1" for the same thing, or age = -3.
- duplicates — the same record twice, which double-weights it.

## Missing values
Two ways out: drop or impute.
- drop the row (`dropna`). Easy, but you lose whole records — bad when lots of rows have at least one hole.
- impute = fill the gap with a guess:
  - mean — for a roughly symmetric numeric column.
  - median — for a skewed column, since the mean gets pulled by the tail.
  - mode — the most frequent value, the only choice for a categorical column.

Imputing keeps the row but shrinks the column's variance a little (you added values sitting at the centre).

## Noisy data — binning and smoothing
Binning sorts the values and drops them into buckets, then replaces each value using its bucket so small
wobbles get flattened.
- equal-width: cut the value RANGE into k equal intervals. Simple, but a skewed column dumps everything in
  one bin.
- equal-depth (equal-frequency): each bin holds the same COUNT of points. Handles skew better.

Then smooth inside each bin:
- by bin mean — every value becomes the bin's mean.
- by bin median — becomes the bin's median.
- by bin boundaries — each value snaps to whichever end (min or max of the bin) it's nearer.

## Normalization / scaling
Put columns on a comparable scale so no single column bullies the distance just because its units are big
(marks 0-100 vs studyhours 0-6).

    min-max     x' = (x - min) / (max - min)          -> [0, 1]
    z-score     x' = (x - mean) / std                 -> mean 0, std 1
    decimal     x' = x / 10^j,  j = digits in max|x|  -> [-1, 1]

- min-max keeps the shape but is sensitive to an outlier (one huge max squashes everyone else near 0).
- z-score (standardization) centres at 0, spread 1. Doesn't bound the range, but robust to the min/max.
- decimal scaling just shifts the decimal point — crude but quick.

## Discretization
Turn a continuous column into a few categories — Marks into low / med / high. Some algorithms want discrete
inputs (ID3 decision tree, the categorical Naive Bayes), and buckets are easier to read in a rule. You pick
the cut points by hand (< 60 low, < 80 med, else high) or let equal-width / equal-depth choose them.

## Encoding
Algorithms do maths, so text categories have to become numbers.
- label encoding — map each category to an integer: Sunny->2, Overcast->0, Rain->1. One column, compact. But
  it invents an order (2 > 1 > 0) that isn't real for nominal data, which can mislead a distance model.
- one-hot — one 0/1 column per category. No fake ordering, but the table gets wide when a column has many
  levels. Fine for Outlook (3 levels), painful for a "city" column with hundreds.

Use label for tree models and for ordered categories; one-hot for nominal columns going into distance /
linear models.

## Sampling
Work with a subset when the full data is too big.
- simple random — every row an equal chance, no repeats.
- systematic — sort, then take every k-th row from a random start. Fast, but breaks if the data has a
  hidden period matching k.
- stratified — split by a class (PlayTennis Yes/No), sample within each so the class ratio is kept. Matters
  when one class is rare, else a plain random sample might miss it.

> Preprocess first, mine second. Half the "the algorithm is wrong" complaints in the internal were really
> an unscaled column or a NaN nobody dropped.

| problem        | fix                            |
| missing value  | drop row / impute mean-med-mode|
| different units| min-max, z-score, decimal      |
| noise          | binning + smoothing            |
| text category  | label / one-hot encoding       |
| too much data  | random / systematic / stratified|
