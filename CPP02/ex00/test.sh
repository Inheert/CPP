#!/bin/bash

#echo "Ligne à modifier (ID=12345)"
total=$1
count=$2
cppFile=$3
compiledFile=$4

if [ $count == 1 ]; then
	echo ""
fi

echo -ne "\033[2K" # Effacer la ligne

./compiler $total $count $cppFile $compiledFile
