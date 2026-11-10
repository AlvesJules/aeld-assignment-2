#!/bin/sh
# Script looking for a chain of character passed in parameter in a directory passed in parameter
# Author: Jules Alves

if [ "$#" != 2 ]; then #check the parameters exist
	exit 1
fi
#Touch "$2"
mkdir -p "$(dirname "$1")"
touch "$1"
rm "$1"
echo "$2" >> "$1"
