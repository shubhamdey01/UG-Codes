#!/bin/bash
echo "printing all tokens from a command output 
for i in `cat abc.c` 
do
  echo $i
done
echo "Give a password to continue
# read silently (like password)
read -s x
#echo $x
if [ $x == "Passwd" ]; then
  # reading a list of strings
  echo "Read a list of strings"
  read lst
  for i in ${lst[@]}; do
    echo $i
  done
else
  echo "Wrong password"
fi
# loop through tokens from cat command 
