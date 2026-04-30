#!/bin/bash
if [ "$#" -eq 0 ]
then
	echo "Wrong Usage"
	exit 1
elif [ "$1" = "-f" ]
then
	if [ -f "$2" ]
	then
		SITES=$(cat "$2")
	else
		echo "No File $2"
		exit 1
	fi
else
	SITES="$@"
fi

for site in $SITES
do
	if ping -c 1 -W 3 "$site" &> /dev/null
	then
		echo "$site is available"
	else
		echo "$site is not available"
	fi
done


