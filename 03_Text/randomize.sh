#!/bin/bash

alias echo="/bin/echo -e"


if [ -z "$1" ]; then
    echo "Missing the sleep duration parameter"
    exit 1
fi
delay=$1

IFS="\n"
TMPFILE=$(mktemp)
echo $TMPFILE

row=0
while read -r line; do
	for (( i=0; i<${#line}; i++ )); do
		sym=${line:$i:1}
		if [[ ! $sym = *[[:space:]]* ]]
		then
			echo $sym $row $i >> $TMPFILE
		fi	
	done
	row=$((row + 1))
done

shuf < $TMPFILE -o $TMPFILE
clear

while read -r line; do
	IFS=" " read -r sym row col <<< $line
	tput cup $row $col
	echo $sym
	sleep $delay
done < $TMPFILE
tput cup $row 0

rm -f $TMPFILE
