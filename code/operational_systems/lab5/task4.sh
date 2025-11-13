#!/bin/bash
DESTINATION="$HOME/safe"

if [ $# -eq 0 ]
then 
	echo "Usage: -skip for deletion without unnessesary steps"
fi

if [ ! -d "$DESTINATION" ]
then
	mkdir -p "$DESTINATION"
fi

if [ "$1" = "-skip" ]
then
	shift
	for file in "#@"
	do
		if [ -f "$file" ]
		then	
			rm -f "$file"
			echo "Deleted: '$file'"
		else
			echo "Not Found: '$file'"
		fi
	done
fi

for file in "$@"
do 
	if [ -f "$file" ]
	then
		cp "$file" "$DESTINATION"
		echo "File '$file' copied to '$DESTINATION'"
		rm -f "$file"
		echo "File '$file' deleted"
	else
		echo "File '$file' not found"
	fi
done
