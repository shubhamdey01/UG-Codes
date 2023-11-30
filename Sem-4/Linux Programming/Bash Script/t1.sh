#!/bin/bash

echo 'passwd' :
read -s x
if [ $x == "shubham" ]; then
   for i in {1..10}; do
      echo 5 x $i = 5*$i
   done
else
   for i in {1..10}; do
      echo 2 x $i = 2*$i
   done
fi

