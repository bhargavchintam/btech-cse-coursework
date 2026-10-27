# Data exploration

Before mining anything you look at the data — the centre of each column, its spread, whether it's skewed,
whether two columns move together. That's descriptive statistics / EDA, and it decides how you clean and
transform later: a skewed column may want a log, an outlier may need capping, two highly-correlated columns
are redundant. Every stat here is written from scratch and checked against numpy / statistics / scipy.

## Central tendency
Where the middle of the data sits.
- mean = sum / n. Uses every value, but one huge value drags it (not robust).
- median = middle of the sorted data (average of the two middle values when n is even). Robust to outliers.
- mode = the most frequent value. The only one of the three that also works on nominal data.

    mean   = (1/n) sum x_i
    median = middle of sorted x
    mode   = arg max frequency

Rule of thumb: mean > median usually means a right (positive) tail; mean < median a left tail.

## Dispersion
How spread out the values are — two columns can share a mean and look nothing alike.
- range = max - min. One number, throws away everything in between, sensitive to outliers.
- variance = average squared distance from the mean.
- std = sqrt(variance), back in the original units.
- IQR = Q3 - Q1, the spread of the middle 50%, ignores the tails so it's robust.

    var(pop)    = (1/n)     sum (x_i - mean)^2     <- numpy default (ddof=0)
    var(sample) = (1/(n-1)) sum (x_i - mean)^2     <- statistics.variance, np.cov

The n vs n-1 thing bites every time: numpy's var/std divide by n, but np.cov divides by n-1. Check the ddof.

## Five-number summary and quartiles
min, Q1, median, Q3, max. Q1 is the 25th percentile, Q3 the 75th. Percentile by linear interpolation (the
way numpy does it): rank = p/100 * (n-1), then interpolate between the two nearest sorted values. The
1.5*IQR rule flags outliers:

    lower fence = Q1 - 1.5*IQR
    upper fence = Q3 + 1.5*IQR

anything past a fence is a suspected outlier — exactly what the whiskers of a boxplot draw.

## Skewness (and kurtosis)
Skewness = which way the tail leans.

    skew = m3 / m2^(3/2),   m_k = (1/n) sum (x - mean)^k

skew > 0 right/positive tail (income, waiting times), skew < 0 left tail, ~0 symmetric. Kurtosis = how heavy
the tails are; scipy reports EXCESS kurtosis = m4/m2^2 - 3, so 0 is normal-like and positive means heavier
tails / more outliers.

## Correlation vs covariance
Both say how two columns move together.
- covariance = (1/(n-1)) sum (x-mx)(y-my). The sign gives the direction, but the size depends on the units,
  so you can't compare covariances across different pairs.
- correlation (Pearson) = cov / (std_x * std_y). Same idea, scaled to [-1, 1], unit-free.

    r = sum (x-mx)(y-my) / sqrt( sum(x-mx)^2 * sum(y-my)^2 )

r = +1 perfect up, -1 perfect down, 0 no linear relation. Correlation is NOT causation, and r only sees
LINEAR structure — a perfect U-shape can still give r ~ 0.

## What the plots show
- histogram: the distribution of one column — modes, skew, gaps. Bin count changes the story.
- boxplot: the five-number summary drawn as a box (Q1..Q3) with a median line and 1.5*IQR whiskers; dots
  past the whiskers are outliers. Good for comparing a numeric column across groups side by side.

> Mean for the centre, std for the spread — but eyeball the histogram first, the summary numbers hide a
> bimodal column completely.

| measure | robust to outliers? | works on |
| mean    | no  | interval/ratio |
| median  | yes | ordinal and up |
| mode    | yes | any, incl nominal |
| range   | no  | interval/ratio |
| IQR     | yes | ordinal and up |
| std     | no  | interval/ratio |
