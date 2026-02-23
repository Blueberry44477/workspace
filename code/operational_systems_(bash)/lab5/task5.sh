#!/bin/bash
if [ $# -eq 0 ]
then
	read -p "Enter File Destination: " FILE
else
	FILE="$1"
fi

if [ ! -f "$FILE" ]
then
	echo "No File '$FILE'"
	exit 1
fi

echo -e "1 - Copy File\n2 - Delete File\n3 - Print to Terminal"
read -p "Choice: " choice

case "$choice" in
	1)
		read -p "Enter Copying Destination: " DESTINATION
		if cp "$FILE" "$DESTINATION"
		then
			echo "File '$file' copied to '$DESTINATION'"
		else
			echo "Error"
		fi
		;;
	2)
		rm -f "$FILE"
		echo "File '$FILE' deleted"
		;;
	3)
		cat "$FILE"
		;;
esac
