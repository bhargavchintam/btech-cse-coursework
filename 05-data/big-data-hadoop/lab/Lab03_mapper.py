#!/usr/bin/env python3
# wordcount mapper - emits word\t1

import sys

for line in sys.stdin:
    line = line.strip()
    for word in line.split():
        print('%s\t%s' % (word, 1))
