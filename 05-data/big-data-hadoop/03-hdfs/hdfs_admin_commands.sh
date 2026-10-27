#!/bin/bash
# admin / health commands - run as hdfs superuser

# cluster report: capacity, live/dead datanodes
hdfs dfsadmin -report

# safe mode - check status, enter, leave
hdfs dfsadmin -safemode get
hdfs dfsadmin -safemode enter
hdfs dfsadmin -safemode leave

# filesystem check with block and location details
hdfs fsck /user/hadoop -files -blocks -locations
