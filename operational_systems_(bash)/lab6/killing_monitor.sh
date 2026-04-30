#!/bin/bash
DURATION=${1:-60}   
INTERVAL=${2:-5}
CPU_THRESHOLD=${3:-20}

END_TIME=$(( $(date +%s) + DURATION ))

echo -e "CPU Monitor\nDuration: $DURATION s\nInterval: $INTERVAL s\nCPU Threshold: $CPU_THRESHOLD%"

while (( $(date +%s) < END_TIME ))
do
    echo "Time: $(date +"%H:%M:%S")"

    ps -eo pid,pcpu,pmem,user,comm --sort=-pcpu \
      | awk -v thr="$CPU_THRESHOLD" '$2 > thr && $4 != "root" { printf "%s %s%% %s%% %s %s\n", $1,$2,$3,$4,$5 }'

    for pid in $(ps -eo pid,pcpu,user --sort=-pcpu \
                  | awk -v thr="$CPU_THRESHOLD" '$2 > thr && $3 != "root" {print $1}')
    do
        read -p "Kill PID: $pid? [y/N]: " answer
        if [[ "$answer" =~ ^[Yy]$ ]]; then
            kill -TERM "$pid" 2>/dev/null
            echo "Sent SIGTERM for PID '$pid'"
        fi
    done

    sleep $INTERVAL
done

