#!/bin/bash
echo "In Natural Order: $@"

if [ $# -eq 4 ]
then
	echo "In Order As 1 3 2 4: "$1" "$3" "$2" "$4""
fi

for argument in $(printf "%s\n" "$@" | sort)
do
	echo "$argument"
done
