# Introduction to Data Mining

Data mining = digging useful, non-obvious patterns out of large data. It is NOT plain querying (that just
hands back what you already stored) and NOT one statistic on ten rows — it's the (semi-)automatic search
through big data for structure nobody put there on purpose: groups, rules, predictions, odd cases. The proper
name for the whole workflow is KDD (Knowledge Discovery in Databases); data mining is really just the mining
STEP of KDD, but in practice people say "data mining" for the entire thing.

## KDD process
Raw data -> knowledge in five steps:

    1. Selection       pick the relevant rows/columns, build the target dataset
    2. Preprocessing   clean it: missing values, noise, duplicates, wrong types
    3. Transformation  make it mining-ready: normalize, encode, reduce dimensions
    4. Data mining     run the algorithm (Apriori, k-means, decision tree, ...)
    5. Interpretation  evaluate the patterns, keep the valid/useful ones, present them

Most of the effort (people say ~70-80%) is steps 1-3. The clever algorithm in step 4 is the small part.
03_kdd_pipeline.py walks students.csv through all five stages and prints what each one produced.

## Data mining vs data warehouse / OLAP
- A data warehouse is a big integrated store of historical data (subject-oriented, cleaned, read-mostly).
  It HOLDS data.
- OLAP = On-Line Analytical Processing: interactive slice / dice / roll-up / drill-down over that warehouse.
  You ask questions you already have in mind ("sales by region by quarter"). It SUMMARISES data.
- Data mining DISCOVERS the patterns you didn't ask for ("these products sell together", "these customers
  will churn"). OLAP is user-driven and verifies a hypothesis; mining is data-driven and generates one.

The warehouse is often the clean source the mining runs on, so the two sit right next to each other.

## Kinds of data (attribute types)
Which stats and which algorithm you can use depends on the attribute type:

| type     | ordered? | equal gaps? | true zero? | example |
| nominal  | no       | no          | no         | species, Outlook, gender |
| ordinal  | yes      | no          | no         | Temperature Hot/Mild/Cool, grades |
| interval | yes      | yes         | no         | Celsius temp, calendar year |
| ratio    | yes      | yes         | yes        | length, weight, Age, Marks |

nominal + ordinal are categorical (qualitative); interval + ratio are numeric (quantitative). The catch on
interval: no true zero, so ratios are meaningless — 20 C is not "twice as hot" as 10 C. 02_data_types.py
tags every column of iris_subset and play_tennis with its type and a one-line reason.

## Kinds of patterns
- Association — values that co-occur (market basket, Apriori): {diaper} -> {beer}.
- Classification — predict a known label from features (decision tree, Naive Bayes, KNN). Supervised.
- Clustering — group similar rows with NO labels (k-means, hierarchical). Unsupervised.
- Outlier / anomaly detection — the points that fit no pattern (fraud, faults). Often the interesting ones.
- (also regression for numeric prediction, and sequential patterns over time.)

## Applications
Market-basket and recommendation, credit scoring and churn, fraud / intrusion detection, medical diagnosis,
search and text mining, bioinformatics. Basically anywhere there's more data than a human can eyeball.

## Issues and challenges
- Data quality: missing values, noise, inconsistency — garbage in, garbage out.
- Scalability: the algorithm has to cope with millions of rows / high dimensions.
- High dimensionality and the "curse of dimensionality" (distances stop meaning much).
- Overfitting: a pattern that fits THIS data but doesn't generalise.
- Picking the interesting patterns — an algorithm can spit out thousands of trivial or spurious rules.
- Privacy and mis-use of personal data.

> Data mining ~= step 4, KDD = the whole pipeline. Got that distinction wrong in the internal once — the
> examiner wanted "data mining is one step of KDD", not "the same thing".
