-- classic word count in pig

lines = LOAD '/home/hadoop/data/input.txt' AS (line:chararray);

-- split each line into words and flatten the bag into rows
words = FOREACH lines GENERATE FLATTEN(TOKENIZE(line)) AS word;

grouped = GROUP words BY word;

counts = FOREACH grouped GENERATE group AS word, COUNT(words) AS cnt;

ordered = ORDER counts BY cnt DESC;

DUMP ordered;

STORE ordered INTO '/home/hadoop/out/wordcount' USING PigStorage(',');
