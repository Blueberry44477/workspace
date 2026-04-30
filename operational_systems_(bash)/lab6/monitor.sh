#!/bin/bash
COUNT=${1:-5}
INTERVAL=${2:-5}
DURATION=$((COUNT * INTERVAL))
CPU_LOADS=()
echo -e "Iterations Amount: $COUNT\nInterval: $INTERVAL\nDuration: $DURATION"

for ((i = 0; i < COUNT; i++))
do
	LOAD=$(top -bn1 | grep "Cpu(s)" | awk '{print 100 - $8}')
	CPU_LOADS+=("$LOAD")
	echo "[$(date +"%H:%M:%S")] Load: ${LOAD}%"
	sleep $INTERVAL
done


