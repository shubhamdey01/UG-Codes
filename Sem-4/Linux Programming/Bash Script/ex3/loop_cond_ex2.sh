#!/bin/bash

#This script reads a filename, checks for its existence, and reads 
#each line of the file into a variable. Then, it extracts each word 
#of the line into an array; and displays the first two elements, 
#assuming that each line is a name. 

#print "Give the filename containing students names"
echo "Give the filename containing students names"

#take a filename from standard input
read fname
echo $fname

# Check if any regular file with filename exists. If not, then print 
# "Student list file not found"
if [ ! -f "$fname" ]; then
  echo "Student list file not found"
  exit 0
else
  # Else, read lines from the file $fname, and store each word of the line
  # into an array, and display elements 1 followed by 0.

  while read -r line; do
    strn=(`echo $line | tr ';' ' '`)
    echo ${strn[1]}" "${strn[0]}
  done < $fname
fi
