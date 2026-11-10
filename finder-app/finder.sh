#!/bin/sh
# Script looking for a chain of character passed in parameter in a directory passed in parameter
# Author: Jules Alves

if [ "$#" != 2 ]; then
    exit 1
fi
if [ ! -d "$1" ]; then
    exit 1
fi

numberOfFiles=$(find "$1" -type f | wc -l)
numberOfLines=$(grep -r "$2" "$1" | wc -l)
echo "The number of files are $numberOfFiles and the number of matching lines are $numberOfLines"
exit 0
