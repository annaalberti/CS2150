#!/bin/bash

## get the number e
read e

##do it 5 times
for i in {1,2,3,4,5} ; do
    RUNNING_TIME=`./a.out $e | tail -1`
    echo "$RUNNING_TIME"
    TOTAL_TIME=$(( TOTAL_TIMEM+RUNNING_TIME ))
done

#divide by 5
AVERAGE_TIME=$(( TOTAL_TIME/5 ))

echo $(( TOTAL_TIME/5 ))
