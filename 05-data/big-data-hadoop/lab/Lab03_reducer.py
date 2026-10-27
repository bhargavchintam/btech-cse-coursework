#!/usr/bin/env python3
# wordcount reducer - reads the sorted mapper output

import sys

current_word = None
current_count = 0

for line in sys.stdin:
    line = line.strip()
    word, count = line.split('\t', 1)
    count = int(count)

    if current_word == word:
        current_count += count
    else:
        if current_word is not None:
            print('%s\t%s' % (current_word, current_count))
        current_word = word
        current_count = count

if current_word is not None:
    print('%s\t%s' % (current_word, current_count))
