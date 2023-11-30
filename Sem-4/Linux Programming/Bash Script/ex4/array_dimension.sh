#!/bin/bash

#This script shows how to 
#store words of a string into an array,
#How to store length of that array
#How to access all elements
#C-style for loop using integer
#check for existence of a file

echo "Give the array elements"
read ar
read -ra lst <<< $ar #Store words from $ar into the array lst.
let len=${#lst[@]} # Store the length of lst into an integer len.
if [ $len == 0 ]; then
  echo "List is empty"
else
  echo "Number of elements are "$len
  for (( i=0; i<$len; i++ )) # For loop in "C" style
  do
    echo ${lst[$i]}
    fname="${lst[$i]}.txt"
    if ! [ -e $fname ]; then
       echo "file "$fname" does not exist under "`pwd`
    fi
  done
fi
