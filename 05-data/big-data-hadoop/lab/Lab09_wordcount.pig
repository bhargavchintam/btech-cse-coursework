-- word count in pig

lines = LOAD '/user/hadoop/input.txt' AS (line:chararray);

words = FOREACH lines GENERATE FLATTEN(TOKENIZE(line)) AS word;

grouped = GROUP words BY word;

counts = FOREACH grouped GENERATE group AS word, COUNT(words) AS cnt;

ordered = ORDER counts BY cnt DESC;

DUMP ordered;
