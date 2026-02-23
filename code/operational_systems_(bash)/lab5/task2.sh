#!/bin/bash
DESTINATION="$HOME/tmp"
if [ ! -d "$DESTINATION" ]
then
	mkdir -p "$DESTINATION"
fi

if [ -n "$1" ]
then
	FILE="$1"
else
	read -p "Enter File Name to Copy: " FILE
fi

if [ ! -f "$FILE" ]
then
	echo "No File Named $FILE"
	exit 1
fi

cp "$FILE" "$DESTINATION"

echo "File '$FILE' has been copied to '$DESTINATION'"
