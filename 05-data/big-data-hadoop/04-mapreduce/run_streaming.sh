#!/bin/bash
# run the streaming word count

# on the cluster it goes through the hadoop-streaming jar:
# hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.1.1.jar \
#   -input /user/hadoop/wc/input \
#   -output /user/hadoop/wc/output \
#   -mapper streaming_mapper.py \
#   -reducer streaming_reducer.py \
#   -file streaming_mapper.py \
#   -file streaming_reducer.py

# local test without hadoop - same map | sort | reduce chain
cat input.txt | python3 streaming_mapper.py | sort | python3 streaming_reducer.py
